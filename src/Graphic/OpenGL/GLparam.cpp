

#include "couleur.hpp"
#include "GLparam.hpp"

void GLMaterialParam::GLSet()
{

    //printf("GLSet() Begin \n");
    
     GLfloat params[4];
    GLenum colormat_mode=0;

    switch(_colormaterial_mode) {
    case COLORMATERIALMODE_EMISSION: colormat_mode=GL_EMISSION; break;
    case COLORMATERIALMODE_AMBIENT:  colormat_mode=GL_AMBIENT; break;
    case COLORMATERIALMODE_DIFFUSE:  colormat_mode=GL_DIFFUSE; break;
    case COLORMATERIALMODE_SPECULAR: colormat_mode=GL_SPECULAR; break;
    case COLORMATERIALMODE_AMBIENT_AND_DIFFUSE: colormat_mode=GL_AMBIENT_AND_DIFFUSE; break;
    }

   //printf("GLSet() colormaterial \n");
   
   Si _colormaterial Alors
      glColorMaterial (GL_FRONT, colormat_mode);
      glEnable(GL_COLOR_MATERIAL);
      //printf("Color material enabled \n");
    Sinon
      glDisable( GL_COLOR_MATERIAL);
      //printf("Color material disabled \n");
    FinSi

   //printf("GLSet() material \n");

    SetGLfloat(&_ambient, params);
    glMaterialfv(GLenum_face(_face_ambient),  GL_AMBIENT,  params);

    SetGLfloat(&_diffuse, params);
    glMaterialfv(GLenum_face(_face_diffuse),  GL_DIFFUSE,  params);

/*
    SetGLfloat(&_diffuse, params);
    glMaterialfv(GLenum_face(_face_diffuse),  GL_AMBIENT_AND_DIFFUSE,  params);
    */
    
    SetGLfloat(&_specular, params);
    glMaterialfv(GLenum_face(_face_specular), GL_SPECULAR, params);
    
    SetGLfloat(&_emission, params);
    glMaterialfv(GLenum_face(_face_emission), GL_EMISSION, params);

    glMaterialf( GLenum_face(_face_shininess), GL_SHININESS, 
		 (GLfloat) _shininess);


  //printf("GLSet() End \n");

}


void GLTransfMatrix::Print()
  {
    this->Save(stdout);

  }

  void GLTransfMatrix::Save(FILE* f)
  {
    int i,j;

    // rotation
    fprintf(f,"Rotation:\n");
    for (i=0;i<4;i++) {
      for(j=0;j<4;j++) {
	fprintf(f,"%.9lg \t",_rotation[j][i]);
      }
      fprintf(f,"\n");
    }
    // translation
    fprintf(f,"Translation:\n");
    for (i=0;i<3;i++) {
	fprintf(f,"%.9g \t",_translation[i]);
    }
      fprintf(f,"\n");
    // scale
    fprintf(f,"Scale:\n");
    for (i=0;i<3;i++) {
	fprintf(f,"%.9lg \t",_scale[i]);
    }
      fprintf(f,"\n");
  }

  void GLTransfMatrix::Load(FILE* f)
  {
    int i,j;
    // rotation
    fscanf(f,"Rotation:\n");

    for (i=0;i<4;i++) {
      for(j=0;j<4;j++) {
	if (fscanf(f,"%lg \t",&_rotation[j][i])==0)
	  fprintf(stderr,"GLTransfMatrix::Load() \t error fscanf() \n");
      }
      fscanf(f,"\n");
    }
    // translation
    fscanf(f,"Translation:\n");
    for (i=0;i<3;i++) {
      fscanf(f,"%g \t",&_translation[i]);
    }
      fscanf(f,"\n");
    // scale
    fscanf(f,"Scale:\n");
    for (i=0;i<3;i++) {
	fscanf(f,"%lg \t",&_scale[i]);
    }
      fscanf(f,"\n");

  }

 GLProjParam::GLProjParam()
  { 
    left  = bottom =  -1.0;
    right = top    =   1.0;

    _near = -10.0;
    _far  =  10.0;

    type_proj = PROJ_ORTHO;

    eye_distance = 3.0;

    win_width = win_height = -1;

    _picking = false;
    _pick_cursorx = _pick_cursory = 0;
  }

void GLProjParam::SetProjection()
{

    
        float l,r,t,b;
        GLint viewport[4];
    
    Si win_width>win_height Alors
        l  = (left+(right-left)*(1.0-1.0*win_width/win_height)/2.0);
        r  = (left+(right-left)*(1.0+1.0*win_width/win_height)/2.0);
        b  = bottom;
        t  = top;
    Sinon
        l  = left;
        r  = right;
        b  = (bottom+(top-bottom)*(1.0-1.0*win_height/win_width)/2.0);
        t  = (bottom+(top-bottom)*(1.0+1.0*win_height/win_width)/2.0);
    FinSi
    
    glMatrixMode(GL_PROJECTION);
    
    glLoadIdentity();
    
    Si _picking Alors
        glGetIntegerv(GL_VIEWPORT,viewport);
        gluPickMatrix(_pick_cursorx,viewport[3]-_pick_cursory,5,5,viewport);
    FinSi
    
    switch ( type_proj ){
        case PROJ_ORTHO:
        glOrtho( (GLdouble)  l, 
            (GLdouble)  r, 
            (GLdouble)  b, 
            (GLdouble)  t, 
            (GLdouble)  _near+eye_distance, 
            (GLdouble)  _far+eye_distance);
        break;
    
        case PROJ_PERSP:
        double view_ratio;
        double near_value=_near;
        double far_value=_far;
        if (_near<=-eye_distance) {
          near_value=-eye_distance+0.1;
        }
        if (_far<=near_value) {
          far_value=near_value+0.1;
        }
        view_ratio = eye_distance/(near_value+eye_distance);
        glFrustum( (GLdouble)  l/view_ratio, 
            (GLdouble)  r/view_ratio, 
            (GLdouble)  b/view_ratio, 
            (GLdouble)  t/view_ratio, 
            (GLdouble)  near_value+eye_distance,
            (GLdouble)  far_value+eye_distance);
        break;
    } // end switch

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt( 0.0, 0.05,  (GLdouble) eye_distance, 
                0.0, 0.0, 0.0,
                0.0, 1.0, 0.0);
    
    Si _picking AlorsFait glInitNames();
    

}


GLFogParam::GLFogParam()
{
    _enabled = false;
    _fogmode = FOG_LINEAR; 
    
    _density = 0.5;
    _start   = -0.5;
    _end     = 1.0;
    
    _use_bg_color = true;
    _bg_color = NULL;
    _color.FixeValeur(255,255,255);
}

void GLFogParam::SetGLfloat( ClasseCouleur* coul, GLfloat* params)
{
    params[0] = (GLfloat) (1.0*coul->Red()  / 255.0);
    params[1] = (GLfloat) (1.0*coul->Green()/ 255.0);
    params[2] = (GLfloat) (1.0*coul->Blue() / 255.0);
    params[3] = 1.0;
}

