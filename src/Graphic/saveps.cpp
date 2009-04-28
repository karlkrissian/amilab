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
//
// Fichier saveps.cpp
//
// Karl Krissian       Sophia Antipolis, le 26-05-98
//
// Inspir� du programme "xv"
// version simplifi�e
//

#include "style.hpp"

#include "saveps.hpp"


static void psColorImage( FILE* fp);


//------------------------------------------------------------------------
//
// Variables ext�rieures
// ---------------------
//
//   cpic (donnees couleurs de l'ecran)
//   r g b (tableaux de 256 octets, pour chaque couleur de la palette)
//
//   REVDATE
//   filename
//   colorType
//   cWIDE cHIGH (largeur, hauteur)
//   pos_inx pos_iny (position sur la page (en inch))
//   psizex  psizey ( taille de la page en inchs)
//   sz_inx  sz_iny (largeur, hauteur sur la page en inch)
//
//   numcols (nombre de couleurs ??, inutile)
//
//
/*
void writePS( const char* filename, XImage* image, XColor* colors, int colorType)
//   -------


{

  

    FILE *fp;
    int   i, j, q, err, rpix, gpix, bpix; //, nc;
    int   iw, ih, ox, oy, slen, lwidth, bits, colorps, w, h;
    byte *inpix, *bwpic; //, *rmap, *gmap, *bmap;
//    unsigned long outbytes = 0;

    // Taille de l'image sur la page
    // Il faudrait respecter les proportions ...
    float  sz_inx, sz_iny;
    // position sur la page
    float  pos_inx = 0.5, pos_iny = 0.5;


  Si image->format != ZPixmap Alors
    printf("writePS()\tLe format d'image doit etre ZPixmap\n");
    return; 
  FinSi

  Si image->bits_per_pixel != 8 Alors
    printf("writePS()\t il faut 8 bits par pixel\n");
    return; 
  FinSi

  inpix = (unsigned char*) image->data;
  w     = image->width;  
  h     = image->height;
//  w = cWIDE;  h = cHIGH;

  sz_inx = 4.0;
  sz_iny = sz_inx / w * h;


  bwpic = NULL;
//  rmap = r;  gmap = g;  bmap = b;
//  nc = numcols;

  fp = fopen( filename, "w");
  if (!fp) {
    printf("writePS()\tCan't write file '%s'\n",filename);
    return;
  }

//  bwpic = HandleBWandReduced(colorType, &nc, &rmap, &gmap, &bmap);
//  if (bwpic) inpix = bwpic;    

  // printed image will have size iw,ih (in picas) 
  iw = (int) (sz_inx * 72.0 + 0.5);
  ih = (int) (sz_iny * 72.0 + 0.5);   

  // compute offset to bottom-left of image (in picas) 
  ox = (int) (pos_inx * 72.0 + 0.5);
  oy = (int) ((psizey - (pos_iny + sz_iny)) * 72.0 + 0.5);


  // write PostScript header 

  fprintf(fp,"%%!PS-Adobe-2.0 EPSF-2.0\n");
  fprintf(fp,"%%%%Title: %s\n",filename);
  fprintf(fp,"%%%%Creator: XV %s  -  by John Bradley\n",REVDATE);

  // j'enleve le mode landscape
  fprintf(fp,"%%%%BoundingBox: %d %d %d %d\n", ox, oy, ox+iw, oy+ih);

  fprintf(fp,"%%%%Pages: 1\n");
  fprintf(fp,"%%%%DocumentFonts:\n");
  fprintf(fp,"%%%%EndComments\n");


  switch (colorType) {
    case F_FULLCOLOR: slen = w*3;      bits = 8;  colorps = 1;  break;
    case F_GREYSCALE: slen = w;        bits = 8;  colorps = 0;  break;
    default:  printf("writePS()\tunknown colorType in writePS()\n"); 
              return; 
  }

  fprintf(fp,"%%%%EndProlog\n\n");

  fprintf(fp,"%%%%Page: 1 1\n\n");

  fprintf(fp,"%% remember original state\n");
  fprintf(fp,"/origstate save def\n\n");

  fprintf(fp,"%% build a temporary dictionary\n");
  fprintf(fp,"20 dict begin\n\n");

  fprintf(fp,"%% define string to hold a scanline's worth of data\n");
  fprintf(fp,"/pix %d string def\n\n", slen);

  fprintf(fp,"%% lower left corner\n");
  fprintf(fp,"%d %d translate\n\n",ox,oy);

  fprintf(fp,"%% size of image (on paper, in 1/72inch coords)\n");
  fprintf(fp,"%d %d scale\n\n",iw,ih);

  // if we're using color, make sure 'colorimage' is defined 
  if (colorps) psColorImage(fp);

  fprintf(fp,"%d %d %d\t\t\t%% dimensions of data\n",w,h,bits);
  fprintf(fp,"[%d 0 0 %d 0 %d]\t\t%% mapping matrix\n", w, -h, h);

  fprintf(fp,"{currentfile pix readhexstring pop}\n");
  if (colorps) fprintf(fp,"false 3 colorimage\n");
          else fprintf(fp,"image\n");

  //
  //------------- Ecriture de l'image ----------------------------
  //

  err = 0;

  for (i=0; i<h && err != EOF; i++) {
//    int rlen;
    lwidth = 0;
    putc('\n',fp);

    for (j=0; j<w && err != EOF; j++) {
      //      rpix = rmap[*inpix];
      //      gpix = gmap[*inpix];
      //      bpix = bmap[*inpix];      
      rpix = colors[*inpix].red   / 256;
      gpix = colors[*inpix].green / 256;
      bpix = colors[*inpix].blue  / 256;
	  
      if (colorps) { 
        err = fprintf(fp,"%02x%02x%02x",rpix,gpix,bpix);
        lwidth+=6;
      }
      
      else {  // greyscale 
        q = (rpix*21 + gpix*32 + bpix*11) / 64;
	//        err = fprintf(fp,"(%2d,%2d,%2d)", rpix,gpix,bpix);
        err = fprintf(fp,"%02x", q);
        lwidth+=2;
      }

      if (lwidth>70) { putc('\n',fp); lwidth = 0; }
      inpix++;
    }
  }

  fprintf(fp,"\n\nshowpage\n\n");

  fprintf(fp,"%% stop using temporary dictionary\n");
  fprintf(fp,"end\n\n");

  fprintf(fp,"%% restore original state\n");
  fprintf(fp,"origstate restore\n\n");
  fprintf(fp,"%%%%Trailer\n");

//  if (bwpic) free(bwpic);

  if (fclose(fp) == EOF) {
    printf("writePS()\tCan't close file '%s'\n",filename);
    return;
  }


} // writePS()
*/


//-------------------------------------------------------------------------
static void psColorImage( FILE* fp)
//          ------------
{
  /* spits out code that checks if the PostScript device in question
     knows about the 'colorimage' operator.  If it doesn't, it defines
     'colorimage' in terms of image (ie, generates a greyscale image from
     RGB data) */


  fprintf(fp,"%% define 'colorimage' if it isn't defined\n");
  fprintf(fp,"%%   ('colortogray' and 'mergeprocs' come from xwd2ps\n");
  fprintf(fp,"%%     via xgrab)\n");
  fprintf(fp,"/colorimage where   %% do we know about 'colorimage'?\n");
  fprintf(fp,"  { pop }           %% yes: pop off the 'dict' returned\n");
  fprintf(fp,"  {                 %% no:  define one\n");
  fprintf(fp,"    /colortogray {  %% define an RGB->I function\n");
  fprintf(fp,"      /rgbdata exch store    %% call input 'rgbdata'\n");
  fprintf(fp,"      rgbdata length 3 idiv\n");
  fprintf(fp,"      /npixls exch store\n");
  fprintf(fp,"      /rgbindx 0 store\n");
  fprintf(fp,"      /grays npixls string store  %% str to hold the result\n");
  fprintf(fp,"      0 1 npixls 1 sub {\n");
  fprintf(fp,"        grays exch\n");
  fprintf(fp,"        rgbdata rgbindx       get 20 mul    %% Red\n");
  fprintf(fp,"        rgbdata rgbindx 1 add get 32 mul    %% Green\n");
  fprintf(fp,"        rgbdata rgbindx 2 add get 12 mul    %% Blue\n");
  fprintf(fp,"        add add 64 idiv      %% I = .5G + .31R + .18B\n");
  fprintf(fp,"        put\n");
  fprintf(fp,"        /rgbindx rgbindx 3 add store\n");
  fprintf(fp,"      } for\n");
  fprintf(fp,"      grays\n");
  fprintf(fp,"    } bind def\n\n");

  fprintf(fp,"    %% Utility procedure for colorimage operator.\n");
  fprintf(fp,"    %% This procedure takes two procedures off the\n");
  fprintf(fp,"    %% stack and merges them into a single procedure.\n\n");
  
  fprintf(fp,"    /mergeprocs { %% def\n");
  fprintf(fp,"      dup length\n");
  fprintf(fp,"      3 -1 roll\n");
  fprintf(fp,"      dup\n");
  fprintf(fp,"      length\n");
  fprintf(fp,"      dup\n");
  fprintf(fp,"      5 1 roll\n");
  fprintf(fp,"      3 -1 roll\n");
  fprintf(fp,"      add\n");
  fprintf(fp,"      array cvx\n");
  fprintf(fp,"      dup\n");
  fprintf(fp,"      3 -1 roll\n");
  fprintf(fp,"      0 exch\n");
  fprintf(fp,"      putinterval\n");
  fprintf(fp,"      dup\n");
  fprintf(fp,"      4 2 roll\n");
  fprintf(fp,"      putinterval\n");
  fprintf(fp,"    } bind def\n\n");

  fprintf(fp,"    /colorimage { %% def\n");
  fprintf(fp,"      pop pop     %% remove 'false 3' operands\n");
  fprintf(fp,"      {colortogray} mergeprocs\n");
  fprintf(fp,"      image\n");
  fprintf(fp,"    } bind def\n");
  fprintf(fp,"  } ifelse          %% end of 'false' case\n");
  fprintf(fp,"\n\n\n");

} // pscolor()
