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

#include "paramlist.h"
class DessinImage;
class SurfacePoly;
class Viewer3D;

ParamList::~ParamList()
{
  if (GB_debug)
    cerr << "Destructor of ParamList" << endl;
  // deleting the pointers!!!
  for(int i=0;i<num_param;i++) {
    switch(type[i]) {
      case type_image       :FreeMemory<InrImage>(i);       break;
      case type_float       :FreeMemory<float>(i);          break;
      case type_int         :FreeMemory<int>(i);            break;
      case type_uchar       :FreeMemory<unsigned char>(i);  break;
      case type_string      :FreeMemory<string>(i);         break;
      case type_imagedraw   :FreeMemory<DessinImage>(i);    break;
      case type_surface     :FreeMemory<SurfacePoly>(i);    break;
      case type_surfdraw    :FreeMemory<Viewer3D>(i);       break;
/* TODO: implement these clases ...
      case type_ami_function:FreeMemory<AMIFunction>(i);    break;
      case type_paramwin    :FreeMemory<ParamBox>(i);       break;
      case type_matrix      :FreeMemory<FloatMatrix>(i);    break;
      case type_gltransform :FreeMemory<GLTransfMatrix>(i); break;
      case type_array       : FreeMemory<VarArray>(i);      break;
      case type_file     :
        // TODO: create a file class where the destructor closes the file 
        // for a cleaner implementation ...
        fclose( (*(boost::shared_ptr<FILE>*) _pointer).get()); 
        break;
*/
      default       : printf("ParamList::~ParamList()\n type not deleted"); break;
    } // end switch
  } // end for
}


unsigned char ParamList::AddParam( vartype t, void* paramp, unsigned char ref) {
    if (num_param<MAX_PARAM-2) {
        params[num_param]    = paramp;
        type[num_param]      = t;
        reference[num_param] = ref;
        num_param++;
        return 1;
    } else {
        fprintf(stderr,"ParamList::AddParam() \t too many parameters \n");
        return 0;
    }
}

void* ParamList::GetParam(int i)    {
    if (i<0) {
        fprintf(stderr,"ParamList:: GetParam() negative param number \n");
        return params[0];
    }
    if (i>=num_param) {
        fprintf(stderr,"ParamList:: GetParam()  param number too high \n");
        return params[num_param-1];
    }
    return params[i];
}


unsigned char ParamList::GetParam( int num, void*& paramp, vartype& t, bool needed ) {
    if ((num>=0)&&(num<num_param)) {
        paramp = params[num];
        t      = type[num];
        return 1;
    } else {
        if (needed)
          cerr << "ParamList::GetParam()\t bad parameter number\n" << endl;
        return 0;
    }
}

