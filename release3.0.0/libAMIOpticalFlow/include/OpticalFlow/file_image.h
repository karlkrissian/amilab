#ifndef FILE_IMAGE_H
#define FILE_IMAGE_H

#include <string>

using namespace std;

template <class Function>
void save_image ( const Function & img, const std::string & filename) {

  FILE *fd;

  if((fd = fopen (filename.c_str(), "w")) == NULL) {

    cerr << "Error al escribir en fichero " + filename << endl;
    exit(0);

  }
  else {

    std::string header;

    int nx   = img.width();
    int ny   = img.height();
    int size = nx * ny;

    char dx[20], dy[20];

    sprintf(dx, "%d", nx);
    sprintf(dy, "%d", ny);

    header = (string) "#UV {\n dimx " + dx + " dimy " + dy + "\n}\n";

    int i = header.size();

    header.resize(255);

    int j = header.size();

    fill(&header[i-1], &header[j-1], ' ');

    fwrite ( header.c_str(), sizeof(char), 255, fd);
    fwrite ( img.begin(), sizeof(real), size, fd );

    fclose(fd);

  }
}



template <class Function>
void read_image ( Function & img, const std::string & filename) {

  FILE *fd;

  if((fd = fopen (filename.c_str(), "r")) == NULL) {

    cerr << "Error al leer del fichero " + filename << endl;
    exit(0);

  }
  else {

    int  dimx = 0, dimy = 0;

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
	dimx = atoi(palabra.c_str());
      }
      else if (readdimy) {
	readdimy = false;
	dimy = atoi(palabra.c_str());
      }
      else if(palabra == "dimx") readdimx = true;
      else if(palabra == "dimy") readdimy = true;

      i = pos;
      //quitamos huecos en blanco
      while(*i == ' ') i++;

    }

    img.resize(dimx, dimy);

    fread ( img.begin(),  sizeof(real), dimx * dimy, fd);

    fclose(fd);
  }
}


#endif
