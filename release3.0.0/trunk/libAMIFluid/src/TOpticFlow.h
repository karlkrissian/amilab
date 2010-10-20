/****************************************************************************
**
**  TOpticFlow.h:  Fichero que implementa el m�odo de flujo �tico 
**                 teniendo en cuenta el tiempo.
**
*****************************************************************************/

#ifndef _TOPTICFLOW_
#define _TOPTICFLOW_

#include <vector>
#include <namespace.h>


BEGIN_AMI_UTIL 

template <class real>
class TOpticFlow {

  public:

    template <class image>
    void memory_free( image &images, image &u, image &v );

    
    template <class TImage, class image>
    void img2pixel(const TImage &I, image &img, int &w, int &h);

    
    template <class TImage, class image>
    void pixel2img(const image &img, TImage &I, int w, int h);

    
    template <class image>
    void normalizar(const image &img, image &imgout, int size);

    
    void itoa( std::string &numero, int n, int pos = 2);


// ------------------------------------

//    template <class image>
//    void Calcular_Error( vector<std::string> &str, const vector<image> &u, const vector<image> &v, int w, int h, int NFRAMES );
    
    float swab(float v);

    float getval(int f, int i, int j);

    int yosemiteflow();


// ....................................

};



// ************************************************************************************
// ************************************************************************************

template <class real> template<class image>
void TOpticFlow<real>::memory_free( image &images, image &u, image &v )
{

   for( typename std::vector<real *>::iterator i = images.begin(); i != images.end(); i++)
        delete [](*i);

   for( typename std::vector<real *>::iterator i = u.begin(); i != u.end(); i++)
        delete [](*i);

   for( typename std::vector<real *>::iterator i = v.begin(); i != v.end(); i++)
        delete [](*i);

}


// ....................

template <class real> template <class TImage, class image>
void TOpticFlow<real>::img2pixel(const TImage &I, image &img, int &w, int &h)
{
       w = I.width();
       h = I.height();

       //copiamos la imagen;
        for(int i = 0; i < h; i++)
            for(int j = 0; j < w; j++)  {

                img[i * w + j] = (real) I[i][j];
            }

//                img[i * w + j] = (real) (0.33 * k[j*3] + 0.56 * k[j*3+1] + 0.11 * k[j*3+2]); I[i][j];
}


// ....................

template <class real> template <class TImage, class image>
void TOpticFlow<real>::pixel2img(const image &img, TImage &I, int w, int h) {

       I.resize( w, h );

       //copiamos la imagen;
        for(int i = 0; i < h; i++)
            for(int j = 0; j < w; j++)  {

                 I[i][j] = (real) img[i * w + j];
            }

//                img[i * w + j] = (real) (0.33 * k[j*3] + 0.56 * k[j*3+1] + 0.11 * k[j*3+2]); I[i][j];
}


// ....................

template <class real> template <class image>
void TOpticFlow<real>::normalizar(const image &img, image &imgout, int size) {

       const real max = *(std::max_element(&img[0], &img[size]));
       const real min = *(std::min_element(&img[0], &img[size]));

       if(max != min)
          for(int i = 0; i < size; i++)    {

            real v = (img[i] - min) * 255.0 / (max - min);
            if (v < 0) v = 0;
            else if (v > 255) v = 255;
            imgout[i] = v;
          }

//          MaxBar->Max = (int) max + 1; MinBar->Max = (int) max + 1; MaxBar->Position = (int) max + 1;
//          MaxBar->Min = (int) min - 1; MinBar->Min = (int) min - 1; MinBar->Position = (int) min - 1;
}

// ....................

// Funci� que cambia una ristra incrementando el velor de "n"
//  void itoa(char *numero, int n, int pos = 2) {
template <class real> 
void TOpticFlow<real>::itoa( std::string &numero, int n, int pos )
{
      numero[pos] = ((char) (n % 10 + '0'));
      n /= 10;
      numero[pos - 1] = ((char) (n % 10 + '0'));
  }

// ....................





// ************************************************************************************
// ************************************************************************************
// ************************************************************************************

template <class real>
float TOpticFlow<real>::TOpticFlow::swab(float v){

  unsigned char *ptb;
  unsigned char res[4];

  ptb = (unsigned char*) &v;

  res[0] = ptb[3];
  res[1] = ptb[2];
  res[2] = ptb[1];
  res[3] = ptb[0];

  return *((float*) res);
}


template <class real>
float TOpticFlow<real>::getval(int f, int i, int j)
{
  float v;
  printf("un float = %d\n",sizeof(float));
  
    if ( read(f,&v,sizeof(float))!= sizeof(float) )
      printf("Read Error: %d %d\n",i,j);
      
  return swab(v);
}


template <class real>
int TOpticFlow<real>::yosemiteflow() {

    char name[20] = "new_correct_yos";
    int fp;

/*    if((fp=open(name, O_RDONLY,0x01C0))<0)
      {
          std::cout << "Error creating the flow file %s\n" << name << "\n";
          exit(1);
      }
*/

    int totx1 = (int)getval(fp,-1,-1);
    std::cout << "totx1=" <<totx1;

    int toty1 = (int)getval(fp,-1,-2);
    std::cout << " toty1= "<<toty1;

    int nx = (int)getval(fp,-1,-1);
    std::cout << " numx1= " << nx;

    int ny = (int)getval(fp,-1,-2);
    std::cout << " numy1 = " << ny;

    int offx1 = (int)getval(fp,-1,-1);
    std::cout << " offx1 = " << offx1;

    int offy1 = (int)getval(fp,-1,-2);
    std::cout << " offy1= " << offy1 << "\n";


    int size = nx * ny;
    real *u = new real[size];
    real *v = new real[size];

    for( int i = 0; i < size; i++ ) {
     // for( int jj = 0; jj < ny; jj++ ){
              //float u, v;
              //read(fp,&x,sizeof(int));
              //read(fp,&y,sizeof(int));
              read(fp,&(u[i]),sizeof(float));
              read(fp,&(v[i]),sizeof(float));
              u[i] = swab(u[i]);
              v[i] = swab(v[i]);
              //if(u[i] == 0)  ShowMessage("continuar...") ;;
              std::cout << i << ":" <<u[i] << "\n";
             // }
      }

    close(fp);

    NM_AMI_FILE::save_uv<real>(u, v, nx, ny, "yosemite.uv");
    delete []u;
    delete []v;

    printf("\n file %s created with the flow computed in the \n", name);
    printf("format of Barron et al. ftp site: ftp.csd.uwo.ca/pub/vision \n \n");

}


END_AMI_UTIL


#endif

// ************************************************************************************
// ************************************************************************************
// ************************************************************************************
// ************************************************************************************
