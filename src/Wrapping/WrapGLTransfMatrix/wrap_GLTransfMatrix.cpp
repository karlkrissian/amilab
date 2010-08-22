/**
 * C++ Interface: wrap_GLTransfMatrix
 *
 * Description: wrapping GLTransfMatrix
 *
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#include "wrap_GLTransfMatrix.h"

#include "VarContexts.hpp"
#include "wrapfunctions.hpp"
#include "ami_class.h"
#include "ami_object.h"
#include "ami_function.h"

#include "vtkwrap.h"
#include "FluidProject.h"
#include "Func_ReadCTALine.h"
#include "fonctions.h"

#define GET_PARAM(type,varname,defaultval) \
  type varname = defaultval; \
  if (!get_val_param<type>( varname, p, n)) \
    ClassHelpAndReturn;

#define GET_SMTPTR_PARAM(type,varname) \
  boost::shared_ptr<type> varname; \
  if (!get_val_smtptr_param<type>( varname, p, n)) \
    ClassHelpAndReturn;

#include "driver.h"

extern void CB_delete_variable( void* var);
extern void CB_delete_varlist( void* var);


//-------------------------------------------------------------------------
AMIObject::ptr AddWrap_GLTransfMatrix(  WrapClass_GLTransfMatrix::ptr& objectptr)
{
  // Create new instance of the class
  AMIObject::ptr amiobject( new AMIObject);
  amiobject->SetName("GLTransfMatrix");
  amiobject->SetWrappedObject(objectptr);
  objectptr->SetAMIObject(amiobject);
  objectptr->AddMethods( objectptr);
  return amiobject;
}

//----------------------------------------------------------
Variable<AMIObject>::ptr CreateVar_GLTransfMatrix( GLTransfMatrix* _obj)
{
  // Create smart pointer with own deleter
  GLTransfMatrix::ptr _obj_ptr(_obj);

  WrapClass_GLTransfMatrix::ptr _objp(new WrapClass_GLTransfMatrix(_obj_ptr));
  AMIObject::ptr amiobject(AddWrap_GLTransfMatrix(_objp));
  Variable<AMIObject>::ptr varres(
      new Variable<AMIObject>( amiobject));
  return varres;
}

//---------------------------------------------------
// Method that adds wrapping of GLTransfMatrix
//---------------------------------------------------

void  wrap_GLTransfMatrix::SetParametersComments() 
{
  return_comments = "A wrapped GLTransfMatrix object.";
}

//---------------------------------------------------
BasicVariable::ptr wrap_GLTransfMatrix::CallMember( ParamList* p)
{
  GLTransfMatrix* newglt = new GLTransfMatrix();

  BasicVariable::ptr res = CreateVar_GLTransfMatrix(newglt);

  return res;
}

//---------------------------------------------------
//  print
//---------------------------------------------------
void WrapClass_GLTransfMatrix::
      wrap_print::SetParametersComments() 
{ }
//---------------------------------------------------
BasicVariable::ptr WrapClass_GLTransfMatrix::
      wrap_print::CallMember( ParamList* p)
{
  GLTransfMatrix::ptr glmat(this->_objectptr->_obj);

  glmat->Print();

  return BasicVariable::ptr();
}

//---------------------------------------------------
//  save
//---------------------------------------------------
void WrapClass_GLTransfMatrix::
      wrap_save::SetParametersComments() 
{
  ADDPARAMCOMMENT_TYPE(string,"Image name.");
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_GLTransfMatrix::
      wrap_save::CallMember( ParamList* p)
{
  GLTransfMatrix::ptr glmat(this->_objectptr->_obj);
  FILE* transf;

  if (!p) ClassHelpAndReturn;
  int n=0;
  GET_PARAM(string,sImageName,"");

  if(sImageName != "")
  {
    //Func_SaveTransform(glmat.get(),sImageName.c_str());
    transf=fopen(sImageName.c_str(),"w");
    if (transf!=NULL)
      glmat->Save(transf);
    fclose(transf);
  }
  else
      ClassHelpAndReturn;

  return BasicVariable::ptr();
}

//---------------------------------------------------
//  read
//---------------------------------------------------
void WrapClass_GLTransfMatrix::
      wrap_read::SetParametersComments() 
{
  ADDPARAMCOMMENT_TYPE(string,"Image name.");
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_GLTransfMatrix::
      wrap_read::CallMember( ParamList* p)
{
  GLTransfMatrix::ptr glmat(this->_objectptr->_obj);
  FILE* transf;

  if (!p) ClassHelpAndReturn;
  int n=0;
  GET_PARAM(string,sImageName,"");

  if(sImageName != "")
  {
    //Func_ReadTransform(sImageName.c_str());
    transf=fopen(sImageName.c_str(),"r");
    if (transf!=NULL)
      glmat->Load(transf);
    else
      fprintf(stderr,"error reading %s \n",sImageName.c_str());
  }
  else
      ClassHelpAndReturn;

  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Interpolate
//---------------------------------------------------
void WrapClass_GLTransfMatrix::
      wrap_Interpolate::SetParametersComments() 
{
  //TODO
  ADDPARAMCOMMENT_TYPE(GLTransfMatrix,"A wrapped GLTransfMatrix object.");
  ADDPARAMCOMMENT_TYPE(float,"Interpolation coefficient");
  return_comments = "A wrapped GLTransfMatrix object.";
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_GLTransfMatrix::
      wrap_Interpolate::CallMember( ParamList* p)
{
  GLTransfMatrix::ptr glt1(this->_objectptr->_obj);

  if (!p) ClassHelpAndReturn;
  int n=0;
  CLASS_GET_OBJECT_PARAM(GLTransfMatrix,varglt2,glt2);
  if (!glt2.get()) ClassHelpAndReturn;
  GET_PARAM(float,coeff,0);

  // Interpolate each part: translation, scale and rotation
  GLTransfMatrix* newglt = new GLTransfMatrix();
  newglt -> SetIdentity();

  // Translation
  GLfloat tr1[3];
  GLfloat tr2[3];

  glt1->GetTranslation(tr1);
  glt2->GetTranslation(tr2);

  //printf("tr1 = %f %f %f \n",tr1[0],tr1[1],tr1[2]);
  //printf("tr2 = %f %f %f \n",tr2[0],tr2[1],tr2[2]);

  newglt->SetTranslation( tr1[0]+ coeff*(tr2[0]-tr1[0]),
                          tr1[1]+ coeff*(tr2[1]-tr1[1]),
                          tr1[2]+ coeff*(tr2[2]-tr1[2]));

  newglt->GetTranslation(tr2);
  //  printf("tr = %f %f %f \n",tr2[0],tr2[1],tr2[2]);

  // Scale

  //  printf("sc1 = %f  \n",glt1->GetScale());
  //  printf("sc2 = %f  \n",glt2->GetScale());

  newglt->SetScale( glt1->GetScale()+ coeff*(glt2->GetScale()-glt1->GetScale()));
  //  printf("sc  = %f  \n",res->GetScale());

  // Rotation

  // 1. Compute the rotation from glt1 to glt2
  GLdouble rot[4][4];
  GLdouble rot1[4][4];
  int i,j,k;
  // GLT2 * GLT1(-1)
  for(i=0;i<4;i++)
    for(j=0;j<4;j++)
      {
        rot[i][j] = 0;
        for (k=0;k<4;k++)
          rot[i][j] += glt2->_rotation[i][k]*glt1->_rotation[j][k];
      }

  // Decompose the rotation in 3 angles
  // cos(a+b) = cosa.cosb-sina.sinb
  // sin(a+b) = sina.cosb+cosa.sinb
  //
  //  1  0     0           sinb 0 cosb      cosc      -sinc  0
  //  0  cosa  -sina    x  0    1  0      x sinc       cosc  0
  //  0  sina  cosa        cosb 0 -sinb     0          0     1

  // cosb         0       -sinb
  // -sina.sinb   cosa   -cosb.sina
  // cosa.sinb    sina   cosb.cosa

  // (cosb.cosc)                 (-sinc.cosb)                 ( -sinb)
  // (-sina.sinb.cosc+cosa.sinc) (sina.sinb.sinc+cosa.cosc)   (-cosb.sina)
  // (cosa.sinb.cosc+sina.sinc)  (-cosa.sinb.sinc+sina.cosc)  (cosb.cosa)


  double cosa,sina,cosb,sinb,cosc,sinc;
  double a,b,c;
#define mat(i1,i2) rot[i1][i2]

  // we make the hypothesis that all the angles are within [-pi/2,pi/2]

  sinb = -mat(0,2);
  cosb = sqrt( 1 - sinb*sinb );

  Si fabsf(cosb) > 1E-3 Alors

    cosc =   mat(0,0) / cosb;
    sinc = - mat(0,1) / cosb;

    cosa =   mat(2,2) / cosb;
    sina = - mat(1,2) / cosb;

    a =  atan2( sina, cosa);
    b =  atan2( sinb, cosb);
    c =  atan2( sinc, cosc);

  Sinon
    // If sinb==1, we have
    // 0           0         -1
    // sin(c-a)    cos(c-a)   0
    // cos(c-a)    -sin(c-a)  0
    //
    // If sinb==-1, we have
    // 0           0         -1
    // sin(a+c)    cos(a+c)   0
    // -cos(a+c)   sin(a+c)   0

    a = 0;
    b = atan2( sinb, cosb);
    c = atan2( mat(1,0), mat(1,1));

  FinSi

  double a1,b1,c1;
  double ca,sa,cb,sb,cc,sc;
  a1 = a*coeff;
  b1 = b*coeff;
  c1 = c*coeff;

  ca = cos(a1); sa = sin(a1);
  cb = cos(b1); sb = sin(b1);
  cc = cos(c1); sc = sin(c1);

  //  rot
  rot[0][0] = cb*cc;           rot[0][1] = -sc*cb;          rot[0][2] = -sb;    rot[0][3] = 0;
  rot[1][0] = -sa*sb*cc+ca*sc; rot[1][1] = sa*sb*sc+ca*cc;  rot[1][2] = -cb*sa; rot[1][3] = 0;
  rot[2][0] = ca*sb*cc+sa*sc;  rot[2][1] = -ca*sb*sc+sa*cc; rot[2][2] = cb*ca;  rot[2][3] = 0;
  rot[3][0] = 0;               rot[3][1] = 0;               rot[3][2] = 0;      rot[3][3] = 1;

  // GLT * GLT1
  for(i=0;i<4;i++)
    for(j=0;j<4;j++)
      {
        rot1[i][j] = 0;
        for (k=0;k<4;k++)
          rot1[i][j] += rot[i][k]*glt1->_rotation[k][j];
      }

  newglt->SetRotation(rot1);

  BasicVariable::ptr res = CreateVar_GLTransfMatrix(newglt);
  return res;
}

//---------------------------------------------------
//  copy
//---------------------------------------------------
void WrapClass_GLTransfMatrix::
      wrap_copy::SetParametersComments() 
{
  return_comments="A copy of the GLTransfMatrix object within a new variable.";
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_GLTransfMatrix::
      wrap_copy::CallMember( ParamList* p)
{
  GLTransfMatrix::ptr glmat(this->_objectptr->_obj);

  GLTransfMatrix* newglt = new GLTransfMatrix();
  (*newglt) = (*glmat);
  return CreateVar_GLTransfMatrix( newglt );
}

//---------------------------------------------------
//  assign
//---------------------------------------------------
void WrapClass_GLTransfMatrix::
      wrap_assign::SetParametersComments() 
{
  ADDPARAMCOMMENT_TYPE(GLTransfMatrix,"A wrapped GLTransfMatrix object.");
  return_comments="A copy of the GLTransfMatrix object within a new variable.";
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_GLTransfMatrix::
      wrap_assign::CallMember( ParamList* p)
{
  GLTransfMatrix::ptr glmat(this->_objectptr->_obj);

  if (!p) ClassHelpAndReturn;
  int n=0;
  CLASS_GET_OBJECT_PARAM(GLTransfMatrix,varglt2,glt2);
  if (!glt2.get()) ClassHelpAndReturn;

  (*glmat) = (*glt2);

  return BasicVariable::ptr();
}
