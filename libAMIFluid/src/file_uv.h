#ifndef _FILE_UV_H
#define _FILE_UV_H

#include <string>
#include <stdio.h>
#include <iostream>
#include <stdlib.h>

#include <namespace.h>

//using namespace std;

BEGIN_AMI_FILE

// Funciones para leer y escribir ficheros de flujo optico (u,v) en binario
// Los ficheros empiezan con un header de 255 caracteres
// continuan con la matriz U en binario y luego con V


template <class real, class image>
void save_uv ( const image & u, const image & v, int nx, int ny,
	       const std::string & filename) {

  FILE *fd;

  if((fd = fopen (filename.c_str(), "wb")) == NULL) {

    std::cerr << "Error al escribir en fichero " + filename << std::endl;
    exit(0);

  }
  else {

    std::string header;

    int size = nx * ny;

    char dx[20], dy[20];

    sprintf(dx, "%d", nx);
    sprintf(dy, "%d", ny);

    header = (std::string) "#UV {\n dimx " + dx + " dimy " + dy + "\n}\n";

    int i = header.size();

    header.resize(255);

    int j = header.size();

    std::fill(&header[i-1], &header[j-1], ' ');

    fwrite ( header.c_str(), sizeof(char), 255, fd);
    fwrite ( &u[0], sizeof(real), size, fd );
    fwrite ( &v[0], sizeof(real), size, fd );

    fclose(fd);

  }
}




void read_size_uv (int &nx, int &ny, const std::string & filename) {

#ifndef WIN32
	FILE *fd;

  if((fd = fopen (filename.c_str(), "rb")) == NULL) {

    std::cerr << "Error al leer del fichero " + filename << std::endl;
    exit(0);

  }
  else {

    std::string header;

    header.resize(255);

    fread ( &header[0], sizeof(char), 255, fd );

    bool readdimx = false, readdimy = false;

    std::string::iterator i   = header.begin();

    std::string::iterator fin = header.end();

    while( *i != '}' && i != header.end()) {

		std::string::iterator pos = find(i, fin, ' ');

      std::string palabra(i, pos);

      if(readdimx) {
	      readdimx = false;
         nx = atoi(palabra.c_str());
      }
      else if (readdimy) {
	     readdimy = false;
	     ny = atoi(palabra.c_str());
      }
      else if(palabra == "dimx") readdimx = true;
      else if(palabra == "dimy") readdimy = true;

      i = pos;
      //quitamos huecos en blanco
      while(*i == ' ') i++;

    }
    fclose(fd);
  }
#else
	cerr << "read_size_uv() disabled for windows " z<< endl;
#endif
}




template<class real, class image>
void read_uv(image & u, image & v, int &nx, int &ny,
              const std::string & filename) {

  FILE *fd;

  if((fd = fopen (filename.c_str(), "rb")) == NULL) {

    std::cerr << "Error al leer del fichero " + filename << std::endl;
    exit(0);

  }
  else {

    std::string header;

    header.resize(255);

    fread ( &header[0], sizeof(char), 255, fd );

    bool readdimx = false, readdimy = false;

    std::string::iterator i   = header.begin();

    std::string::iterator fin = header.end();

    while( *i != '}' && i != header.end()) {

      std::string::iterator pos = find(i, fin, ' ');

      std::string palabra(i, pos);

      if(readdimx) {
	      readdimx = false;
         nx = atoi(palabra.c_str());
      }
      else if (readdimy) {
	     readdimy = false;
	     ny = atoi(palabra.c_str());
      }
      else if(palabra == "dimx") readdimx = true;
      else if(palabra == "dimy") readdimy = true;

      i = pos;
      //quitamos huecos en blanco
      while(*i == ' ') i++;

    }

    fread (&u[0], sizeof(real), nx * ny, fd);
    fread (&v[0], sizeof(real), nx * ny, fd);

    fclose(fd);
  }
}
   

END_AMI_FILE

#endif
