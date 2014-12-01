/*
    ==================================================
    Software : AMILab
    Authors  : Karl Krissian
               Sara Arencibia
    Email    : karl@bwh.harvard.edu
               darkmind@gmail.com

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

#include "amilab_messages.h"
#include "AMILabConfig.h"

#ifdef AMI_USE_ITK

#include <stddef.h>

#include "itkImage.h"
#include "itkImageIOBase.h"
#include "itkImageFileWriter.h"
#include "itkImageLinearConstIteratorWithIndex.h"
#include <itkRGBPixel.h>
#include <itkRGBAPixel.h>

#endif // AMI_USE_ITK

#include "paramlist.h"
#include "wrapfunctions.hpp" 
#include "wrapitkWrite.h"
#include "wrapConversion.tpp"

#include "ami_itkWrite.h"
#include "message_dialog.h"


//-----------------------------------------------------------------------
void wrap_itkWrite(ParamList* p)
{

#ifdef AMI_USE_ITK

  char functionname[] = "itkWrite";
  char description[]=" \n\
        Use itk Writer factory to write an image file\n\
      ";
  char parameters[] =" \n\
          Parameters:\n\
          InrImage:\n\
          string: filename\n\
      ";
  
  InrImage* input = NULL;
  std::string*  fname = NULL;
  int n=0;
  
  if (!get_val_ptr_param<InrImage>( input,  p, n)) HelpAndReturn;
  if (!get_val_ptr_param<std::string>  ( fname,  p, n)) HelpAndReturn;

  itkWrite(input,*fname);

#else
  fprintf(stderr," ITK not available, you need to compile with ITK ...\n");
#endif // else ifdef AMI_USE_ITK

} // itkWrite()
