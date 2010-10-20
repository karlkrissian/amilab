#ifndef NAME_SPACES_H
#define NAME_SPACES_H


//Namespace principal. Solo se deben incluir aqui las clases
//que no tengan cabida en alguno de los otros namespaces. 
#define BEGIN_AMI        namespace ami{ 


//Namespace para las clases de fichero. Aqui se deben incluir
//las clases que guardan y leen desde fichero (disco)
//Ej: file_3d, file_uv, file_2d, etc.
#define BEGIN_AMI_FILE   namespace ami{namespace file{


//Namespace para metodos de calibracion y sus clases
//necesarias
//Ej: fundamental_matrix, dlt, projective_matrix, RANSAC
#define BEGIN_AMI_CALIB  namespace ami{namespace calibration{


//Namespace para los metodos que se desarrollan en el grupo.
//Normalmente los metodos que se publican en revistas o
//se envían a congresos.
//Ej: stereo_flow, optic_flow, etc.
#define BEGIN_AMI_METHOD namespace ami{ namespace method{


//Namespace para los programas que tengan interfaz grafica.
//Utilidades que sirvan para visualizar (resultados, imagenes).
//Ej: ami_view, XMegaWave, play3d, etc, vrml_view.
#define BEGIN_AMI_VISUAL namespace ami{namespace visual{


//Namespace para aquellas clases que sirven de apoyo a los
//metodos que desarrollamos y que no se pueden colocar en
//los otros namespaces (como el de MATH, CALIB o FILE)
//Ej: harris, gradiente, zoom, thresold, etc.
#define BEGIN_AMI_UTIL   namespace ami{namespace util{


//Namespace para las funciones matematicas y metodos numericos.
//Ej: Gauss, Levenberg-Marquart, SVD, etc. Algebra lineal y
//no lineal.
#define BEGIN_AMI_MATH   namespace ami{namespace math{

//Namespace para las clases relacionadas con reconstruccion 3D.
//Ej: vrml, form3d, etc.
#define BEGIN_AMI_3D     namespace ami{namespace _3d{



//para poner al final de la declaracion de las clases...

#define END_AMI }
#define END_AMI_FILE   }} //end ami file namespace
#define END_AMI_CALIB  }} //end ami calibration namespace
#define END_AMI_METHOD }} //end ami method namespace
#define END_AMI_VISUAL }} //end ami visual namespace
#define END_AMI_UTIL   }} //end ami util namespace
#define END_AMI_MATH   }} //end ami math namespace
#define END_AMI_3D     }} //end ami 3d namespace


//para utilizar cuando se declaren los objetos
#define NM_AMI        ami
#define NM_AMI_FILE   ami::file        //para usar ami file namespace
#define NM_AMI_CALIB  ami::calibration //para usar calibration namespace
#define NM_AMI_METHOD ami::method      //para usar method namespace
#define NM_AMI_VISUAL ami::visual      //para usar visual namespace
#define NM_AMI_UTIL   ami::util        //para usar util namespace 
#define NM_AMI_MATH   ami::math        //para usar math namespace
#define NM_AMI_3D     ami::_3d         //para usar 3d namespace


#endif
