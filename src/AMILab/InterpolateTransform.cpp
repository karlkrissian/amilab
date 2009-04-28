
#include "wx/wxprec.h"
#ifdef __BORLANDC__
#pragma hdrstop
#endif
#ifndef WX_PRECOMP
#include "wx/wx.h"
#endif
#include "wx/glcanvas.h"

#include "InterpolateTransform.h"

void            Func_SaveTransform(GLTransfMatrix* glt1, char* name)
{
  FILE* transf;
  transf=fopen(name,"w");
  if (transf!=NULL) {
    glt1->Save(transf);
  }
  fclose(transf);
}

GLTransfMatrix* Func_ReadTransform(char* name)
{
  FILE* transf;
  GLTransfMatrix* newglt = new GLTransfMatrix();
  transf=fopen(name,"r");
  if (transf!=NULL) {
    newglt->Load(transf);
    fclose(transf);
    return newglt;
  }
  else {
    fprintf(stderr,"error reading %s \n",name);
    delete newglt;
    //fclose(transf);
    return NULL;
  }
}


GLTransfMatrix* Func_InterpolateTransform(GLTransfMatrix* glt1,GLTransfMatrix* glt2,float coeff)
{

  // Interpolate each part: translation, scale and rotation
  GLTransfMatrix* res = new GLTransfMatrix();
  res -> SetIdentity();

  // Translation
  GLfloat tr1[3];
  GLfloat tr2[3];
  
  glt1->GetTranslation(tr1);
  glt2->GetTranslation(tr2);

  //printf("tr1 = %f %f %f \n",tr1[0],tr1[1],tr1[2]);
  //printf("tr2 = %f %f %f \n",tr2[0],tr2[1],tr2[2]);
  

  res->SetTranslation( tr1[0]+ coeff*(tr2[0]-tr1[0]),
		       tr1[1]+ coeff*(tr2[1]-tr1[1]),
		       tr1[2]+ coeff*(tr2[2]-tr1[2]));

  res->GetTranslation(tr2);
  //  printf("tr = %f %f %f \n",tr2[0],tr2[1],tr2[2]);

  // Scale

  //  printf("sc1 = %f  \n",glt1->GetScale());
  //  printf("sc2 = %f  \n",glt2->GetScale());

  res->SetScale( glt1->GetScale()+ coeff*(glt2->GetScale()-glt1->GetScale()));
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

  res->SetRotation(rot1);

  return res;

}
