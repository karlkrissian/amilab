/*
    ==================================================
    Software : AMILab
    Authors  : Karl Krissian
    Email    : karl@bwh.harvard.edu

    AMILab is a language for image processing
    ==================================================
    Copyright (C) 1996-2005  Karl Krissian

    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Lesser General Public
    License as published by the Free Software Foundation; either
    version 2.1 of the License, or (at your option) any later version.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public
    License along with this library; if not, write to the Free Software
    Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA

    ================================================== 
   The full GNU Lesser General Public License file is in Devel/Sources/Prog/LesserGPL_license.txt
*/


#include <stdio.h>
#include <stdlib.h>

// See web page http://www.dclunie.com/medical-image-faq/html/part4.html#MRGE for example

/*
                0   - int      - magic number = 0x494d4746 = "IMGF"
                4   - int      - byte displacement to pixel data
                8   - int      - width
                12  - int      - height
                16  - int      - depth (bits)
                20  - int      - compression (0=asis,1=rectangular,2=packed,
                                 3=compressed,4=compressed&packed)
                32  - int      - background shade to use for non-image
                54  - u_short  - 16 bit end_around_carry sum of pixels
                56  - int      - ptr to unique image identifier
                60  - int      - length of unique image identifier
                64  - int      - ptr to unpack header
                68  - int      - length of unpack header
                72  - int      - ptr to compression header
                76  - int      - length of compression header
                80  - int      - ptr to histogram header
                84  - int      - length of histogram header
                88  - int      - ptr to text plane
                92  - int      - length of text plane
                96  - int      - ptr to graphics plane
                100 - int      - length of graphics plane
                104 - int      - ptr to data base header
                108 - int      - length of data base header
                112 - int      - value to add to stored pixels
                116 - int      - ptr to user defined data
                120 - int      - length of user defined data
                124 - int      - ptr to suite header
                128 - int      - length of suite header
                132 - int      - ptr to exam header
                136 - int      - length of exam header
                140 - int      - ptr to series header
                144 - int      - length of series header
                148 - int      - ptr to image header
                152 - int      - length of image header


        image header - common to CT and MR:

                12  - short    - image number
                26  - float    - slice thickness mm
                30  - short    - matrix size - X
                32  - short    - matrix size - Y
                34  - float    - display field of view - X (mm)
                38  - float    - display field of view - Y (mm)
                42  - float    - image dimension - X
                46  - float    - image dimension - Y
                50  - float    - pixel size - X
                54  - float    - pixel size - Y
                58  - char[14] - pixel data ID
                72  - char[17] - iv contrast agent
                89  - char[17] - oral contrast agent

                126 - float    - image location
                130 - float    - image centre R mm (ie. X +ve to right)
                134 - float    - image centre A mm (ie. Y +ve to anterior)
                138 - float    - image centre S mm (ie. Z +ve to superior)
                154 - float    - image TLHC R mm (ie. X +ve to right)
                158 - float    - image TLHC A mm (ie. Y +ve to anterior)
                162 - float    - image TLHC S mm (ie. Z +ve to superior)
                166 - float    - image TRHC R mm (ie. X +ve to right)
                170 - float    - image TRHC A mm (ie. Y +ve to anterior)
                174 - float    - image TRHC S mm (ie. Z +ve to superior)
                178 - float    - image BRHC R mm (ie. X +ve to right)
                182 - float    - image BRHC A mm (ie. Y +ve to anterior)
                186 - float    - image BRHC S mm (ie. Z +ve to superior)


*/

#define OFFSET_HEADER                0
#define OFFSET_WIDTH                 8
#define OFFSET_HEIGHT               12
#define OFFSET_IMAGE_HEADER        148

// Image Header information
#define OFFSET_IH_DIM_X             42
#define OFFSET_IH_DIM_Y             46
#define OFFSET_IH_PIXEL_SIZE_X      50
#define OFFSET_IH_PIXEL_SIZE_Y      54
#define OFFSET_IH_SLICE_THICKNESS   26

#define OFFSET_IH_TOP_LEFT         154
#define OFFSET_IH_TOP_RIGHT        166
#define OFFSET_IH_BOT_RIGHT        178




template <class T>
T GetValue(char* buf,int offset)
{
  return *(T*)(buf+offset);
}


int Func_GenRead(char* fname)
{
  int filesize;
  char *inbuff;
  char *imheaderbuf;
  FILE  *fp;
  


  if ( (fp = fopen (fname, "r" )) == NULL)  {
    fprintf(stderr,"Can't open file! %s\n",fname);
    return 0;
  }

  fseek(fp, 0L, 2);
  filesize = ftell(fp);
  fseek(fp, 0L, 0);

  if (filesize<1)  {
    fprintf(stderr,"File %s is empty!\n",fname);
    return 0;
  }

  inbuff=(char *)calloc((size_t)filesize,(size_t)1);
  if (inbuff==NULL)   {
    fprintf(stderr,"Can't allocate %d bytes of memory.\n",filesize);
    return 0;
  }

  /* read data*/
  if ((int)fread(inbuff,(size_t)1,(size_t)filesize,fp)!=filesize)  {
    fprintf(stderr,"Error reading file! %s\n",fname);
    return 0;
  }
  fclose(fp);

  printf("\n IMAGE %s INFO \n ----------\n", fname);

  printf(" Magic  \t = %4s\n",inbuff);
  printf(" Width  \t = %d\n",GetValue<unsigned int>(inbuff,OFFSET_WIDTH));
  printf(" Height \t = %d\n",GetValue<unsigned int>(inbuff,OFFSET_WIDTH));

  printf("\n HEADER INFO \n ----------\n");

  imheaderbuf = inbuff+GetValue<unsigned int>(inbuff,OFFSET_IMAGE_HEADER);

  printf(" Dim X \t = %f\n",GetValue<float>(imheaderbuf,OFFSET_IH_DIM_X));
  printf(" Dim Y \t = %f\n",GetValue<float>(imheaderbuf,OFFSET_IH_DIM_Y));

  printf(" Size X \t = %f\n",GetValue<float>(imheaderbuf,OFFSET_IH_PIXEL_SIZE_X));
  printf(" Size Y \t = %f\n",GetValue<float>(imheaderbuf,OFFSET_IH_PIXEL_SIZE_Y));
  printf(" Slice thickness \t = %f\n",GetValue<float>(imheaderbuf,OFFSET_IH_SLICE_THICKNESS));

  printf(" Top_Left \t = [ %f , %f , %f ] \n",
	 GetValue<float>(imheaderbuf,OFFSET_IH_TOP_LEFT),
	 GetValue<float>(imheaderbuf,OFFSET_IH_TOP_LEFT+4),
	 GetValue<float>(imheaderbuf,OFFSET_IH_TOP_LEFT+8)
	 );

  printf(" Top_Right \t = [ %f , %f , %f ] \n",
	 GetValue<float>(imheaderbuf,OFFSET_IH_TOP_RIGHT),
	 GetValue<float>(imheaderbuf,OFFSET_IH_TOP_RIGHT+4),
	 GetValue<float>(imheaderbuf,OFFSET_IH_TOP_RIGHT+8)
	 );

  printf(" Bot_Right \t = [ %f , %f , %f ] \n",
	 GetValue<float>(imheaderbuf,OFFSET_IH_BOT_RIGHT),
	 GetValue<float>(imheaderbuf,OFFSET_IH_BOT_RIGHT+4),
	 GetValue<float>(imheaderbuf,OFFSET_IH_BOT_RIGHT+8)
	 );


  free(inbuff);

  return 1;

}
