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

#include "FloatMatrix.hpp"
#include <iostream>

FloatMatrix&  FloatMatrix::operator =(const float n)
{
    int i,j;
    for(i=0;i<this->n1;i++)
    for(j=0;j<this->n2;j++)
      this->m[i][j]=n;
    return *this;
}


FloatMatrix* FloatMatrix::Transpose()
{
  int i,j;
  FloatMatrix* res;
  res = new FloatMatrix(this->n2,this->n1);
  Pour(i,0,this->n2-1)
    Pour(j,0,this->n1-1)
      (*res)[i][j]=this->m[j][i];
    FinPour
  FinPour
  return res;
}


std::string FloatMatrix::PrintToString() const{
  std::string res;
  int i,j;
  for(i=0;i<this->n1;i++) {
    for(j=0;j<this->n2;j++) {
      if ((j==0)&&(i==0))  
        res += "[ "; 
      else 
        res += "  "; 
      res += (boost::format("%3.3f") % this->m[i][j]).str();
    }
    if (i<this->n1-1)
      res += "\n";
    else
      res += " ]\n";
  }
  return res;
}

void FloatMatrix::PrintSelf() const {
  std::cout << PrintToString() << std::endl;
}


FloatMatrix& FloatMatrix::operator =(FloatMatrix* mat)
{
  int i,j;

  if ((mat->Rows()==this->Rows())&&(mat->Cols()==this->Cols()))
    {
      for(i=0;i<this->n1;i++)
	for(j=0;j<this->n2;j++)
	  this->m[i][j]=(*mat)[i][j];
    }
  else
    fprintf(stderr,"Error\tFloatMatrix::operator =, matrices of different dimensions.\n");

  return *this;
}




FloatMatrix* Multiply( FloatMatrix* m1, FloatMatrix* m2)
{
  int i,j,k;
  FloatMatrix* res= new FloatMatrix(m1->n1,m2->n2);
  (*res) = 0.0;
  m1->PrintSelf();
  m2->PrintSelf();

  if (m1->n2!=m2->n1)
    {
      fprintf(stderr,"FloatMatrix::*, pb of dimensions\n");
      return res;
    }

  for(i=0;i<m1->n1;i++)
  for(j=0;j<m2->n2;j++) 
    for(k=0;k<m1->n2;k++)
      (*res)(i,j)+=(*m1)(i,k)*(*m2)(k,j);

  res->PrintSelf();
  return res;
}


