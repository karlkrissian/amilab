/**
 * *************************************************************************
 *
 * \file THIS FILE IMPLEMENTS THE STADISTICS METHODS.
 * \author Agustin Salgado (asalgado@dis.ulpgc.es)
 * \date 6-11-2005
 *
 * *************************************************************************
*/

#ifndef AMI_FLUID_STADISTICS_H
#define AMI_FLUID_STADISTICS_H

#include <string>
#include <vector>
#include <fstream>

#include <math.h>

#include "ami_prototypes.h"


/**
 * Ami_discrete_angular_error. It computes the average angular error of a set of pixels.
 *
 * \param U1  First U image.
 * \param V1  First V image.
 * \param U2  Second U image.
 * \param V2  Second V imagea.
 * \param nx  Image width.
 * \param ny  Image height.
 * \param xinit  X origin.
 * \param yinit  Y origin.
 * \param dis_x  X displacement.
 * \param dis_y  Y displacement.
 * \param Npixels  Number of pixels with non NULL values.
 * \param NULL_VALUE  Null value.
 * \param Ocl  Mask with the valid pixels.
 *
 * \return Return the average angular error of a set of pixels..
 */
template <class real, class image>
real ami_discrete_angular_error(const image &U1, const image &V1,
		  const image &U2, const image &V2, int nx, int ny,
      int xinit, int yinit, int dis_x, int dis_y,
		  int &Npixels, const real &NULL_VALUE, const image &Ocl ) {

    real sum = 0.0;
    real N = 0.0;

    real NON = 0.0;

    for(int y = yinit; y < ny; y+=dis_y)
      for(int x = xinit; x < nx; x+=dis_x) {

          if ( U1[x + y * nx] != NULL_VALUE && V1[x + y * nx] != NULL_VALUE
            && U2[x + y * nx] != NULL_VALUE && V2[x + y * nx] != NULL_VALUE
            && Ocl[x + y * nx] != NULL_VALUE ) {

    	        real num  = U1[x + y * nx] * U2[x + y * nx] +
                          V1[x + y * nx] * V2[x + y * nx] + 1.0;

	            real den1 = U1[x + y * nx] * U1[x + y * nx] +
                          V1[x + y * nx] * V1[x + y * nx] + 1.0;

    	        real den2 = U2[x + y * nx] * U2[x + y * nx] +
                          V2[x + y * nx] * V2[x + y * nx] + 1.0;

	            real den  = sqrt((double)den1 * den2);

              if(num < den && den > 0.00001) {

                  sum += acos( (double)num/den );
                  N += 1.0;
              }

          } // If UV_NULL_VALUE

//       } // If mix/max

    }    // For

    Npixels = (int) N;


    if (N > 0.0001)
      return (sum * 180.0) / (N * 3.1415926);
    else
      return 9999.0;
}



/**
 * Ami_discrete_euclidean_error. It computes the average euclidean error of a set of pixels.
 *
 * \param U1  First U image.
 * \param V1  First V image.
 * \param U2  Second U image.
 * \param V2  Second V imagea.
 * \param nx  Image width.
 * \param ny  Image height.
 * \param xinit  X origin.
 * \param yinit  Y origin.
 * \param dis_x  X displacement.
 * \param dis_y  Y displacement.
 * \param Npixels  Number of pixels with non NULL values.
 * \param NULL_VALUE  Null value.
 * \param Ocl  Mask with the valid pixels.
 *
 * \return Return the average angular error of a set of pixels.
 *
 */
template <class real, class image>
real ami_discrete_euclidean_error(const image &U1, const image &V1,
		  const image &U2, const image &V2, int nx, int ny,
      int xinit, int yinit, int dis_x, int dis_y,
		  int &Npixels, const real &NULL_VALUE, const image &Ocl ) {

    real sum = 0.;
    real N = 0.;

    for(int y = yinit; y < ny; y+=dis_y)
      for(int x = xinit; x < nx; x+=dis_x) {

          if ( U1[x + y * nx] != NULL_VALUE && V1[x + y * nx] != NULL_VALUE
            && U2[x + y * nx] != NULL_VALUE && V2[x + y * nx] != NULL_VALUE
            && Ocl[x + y * nx] != NULL_VALUE ) {

      	        real U = U1[x + y * nx] - U2[x + y * nx];
	              real V = V1[x + y * nx] - V2[x + y * nx];

      	        sum += sqrt(U * U + V * V);

      	        N += 1;

           } // If UV_NULL_VALUE

//        } // If mix/max

    }    // For

    Npixels = (int) N;

    if (N > 0)
      return sum / N;
    else
      return 9999.0;

}



/**
 * Ami_bias_optic_flow. FUNCTION TO COMPUTE THE BIAS BETWEEN 2 OPTIC FLOW ESTIMATION.WE TAKE INTO ACCOUNT ONLY NON ZERO VELOCITY
 *
 * \param U1  First U image.
 * \param V1  First V image.
 * \param U2  Second U image.
 * \param V2  Second V imagea.
 * \param width  Image width.
 * \param height  Image height.
 * \param Npixels  Number of pixels with non NULL values.
 * \param NULL_VALUE  Null value.
 * \param Ocl  Mask with the valid pixels. 
 *
 * \return Return the BIAS value of a set of pixels.
 *
 */     
template <class real, class image>
real ami_bias_optic_flow(const image &U1, const image &V1,
		  const image &U2, const image &V2, int width, int height, int &Npixels, const real &NULL_VALUE, const image &Ocl ) 
// double ami_bias_optic_flow(float **u1,float **v1,float **u2,float **v2,int width,int height,int *Npixels)
{
    real bias = 0.0;

    for( int m=0; m<width*height; m++ ) {

      if ( U1[m] != NULL_VALUE && V1[m] != NULL_VALUE
        && U2[m] != NULL_VALUE && V2[m] != NULL_VALUE
        && Ocl[m] != NULL_VALUE ) {


            bias += sqrt( U2[m]*U2[m] + V2[m]*V2[m] )  -  sqrt( U1[m]*U1[m] + V1[m]*V1[m] );

            Npixels++;
       }    
    }


    if( Npixels > 0 ) return(bias/Npixels);
    else return(0.);

}

// ..........................................................................


/**
 * Ami_rmsvd_optic_flow. FUNCTION TO COMPUTE THE RMSVD BETWEEN 2 OPTIC FLOW ESTIMATION. WE TAKE INTO ACCOUNT ONLY NON ZERO VELOCITY
 *
 * \param U1  First U image.
 * \param V1  First V image.
 * \param U2  Second U image.
 * \param V2  Second V imagea.
 * \param width  Image width.
 * \param height  Image height.
 * \param Npixels  Number of pixels with non NULL values.
 * \param NULL_VALUE  Null value.
 * \param Ocl  Mask with the valid pixels. 
 *
 * \return Return the RMSVD value of a set of pixels.
 *
 */
template <class real, class image>
real ami_rmsvd_optic_flow(const image &U1, const image &V1,
		  const image &U2, const image &V2, int width, int height, int &Npixels, const real &NULL_VALUE, const image &Ocl ) 
// double ami_rmsvd_optic_flow(float **u1,float **v1,float **u2,float **v2,int width,int height,int *Npixels)
{
    real bias = 0.0;

    for( int m=0; m<width*height; m++ ) {

         if ( U1[m] != NULL_VALUE && V1[m] != NULL_VALUE
           && U2[m] != NULL_VALUE && V2[m] != NULL_VALUE
           && Ocl[m] != NULL_VALUE ) {


            bias += sqrt( (U2[m]-U1[m]) * (U2[m]-U1[m]) + (V2[m]-V1[m]) * (V2[m]-V1[m]) );
            //bias+=sqrt((u2[0][m]-u1[0][m])*(u2[0][m]-u1[0][m])+(v2[0][m]-v1[0][m])*(v2[0][m]-v1[0][m]));

            Npixels++;
       }
    }


    if( Npixels > 0 ) return(bias/Npixels);
    else return(0.);

}


// ..........................................................................


/**
 * Ami_nrmsvd_optic_flow. FUNCTION TO COMPUTE THE NRMSVD BETWEEN 2 OPTIC FLOW ESTIMATION. WE TAKE INTO ACCOUNT ONLY NON ZERO VELOCITY
 *
 * \param U1  First U image.
 * \param V1  First V image.
 * \param U2  Second U image.
 * \param V2  Second V imagea.
 * \param width  Image width.
 * \param height  Image height.
 * \param Npixels  Number of pixels with non NULL values.
 * \param NULL_VALUE  Null value.
 * \param Ocl  Mask with the valid pixels. 
 *
 * \return Return the NRMSVD value of a set of pixels.
 *
 */
template <class real, class image>
real ami_nrmsvd_optic_flow(const image &U1, const image &V1,
		  const image &U2, const image &V2, int width, int height, int &Npixels, const real &NULL_VALUE, const image &Ocl ) 
// double ami_nrmsvd_optic_flow(float **u1,float **v1,float **u2,float **v2,int width,int height,int *Npixels)
{
    real bias = 0.0, norm = 0.0;

    for( int m=0; m<width*height; m++ ) {

         if ( U1[m] != NULL_VALUE && V1[m] != NULL_VALUE
           && U2[m] != NULL_VALUE && V2[m] != NULL_VALUE
           && Ocl[m] != NULL_VALUE ) {


            bias += sqrt( (U2[m]-U1[m]) * (U2[m]-U1[m]) + (V2[m]-V1[m]) * (V2[m]-V1[m]) );
            norm += sqrt( U1[m]*U1[m] + V1[m]*V1[m] );
            
            //bias+=sqrt((u2[0][m]-u1[0][m])*(u2[0][m]-u1[0][m])+(v2[0][m]-v1[0][m])*(v2[0][m]-v1[0][m]));
            //norm += sqrt(u1[0][m]*u1[0][m]+v1[0][m]*v1[0][m]);
            
            Npixels++;
       }
    }

    if( norm > 0 && Npixels > 0 ) return(bias/norm);
    else return(0.);

}



// ..........................................................................
// ..........................................................................
// ..........................................................................
// ..........................................................................
// ..........................................................................


/**
 *
 * Fill_mask. Function to create a mask which represents the non NULL pixels of a set of ascii files.
 *
 * \param imgs  List of images.
 * \param mask  Mask image.
 * \param width  Image width.
 * \param height  Image height.
 * \param nimgs  Number of images.
 * \param NULL_VALUE  Null value.
 *
 * \return Return the number of pixels with non NULL values.
 */
template <class real, class image>
int fill_mask(const std::vector<image> &imgs, const image &mask,
          int width, int height, int nimgs, const real &NULL_VALUE )
{
    int N = 0;

    for(int i=0; i<width*height; i++)  {

        for(int k=0; k<nimgs; k++)  {

          if ( imgs[k][i] == NULL_VALUE )    mask[i] = NULL_VALUE;

        }

        if ( mask[i] != NULL_VALUE )   N++;
    }

    return N;
}


// *************************************************************************
// *************************************************************************


/**
 * Ami_create_latex_table. Create a table latex with the data stored in a vector.
 *
 * \param ofs  Output File.
 * \param tags Tags of the Ascii files.
 * \param data  Data struture which stored the stadistics results.
 * \param stadistics_name  Name of the stadistic method.
 *
 * \return Return an integer. (0 = OK, -1 = Output file error)
 */
template <class stadistics>
int ami_create_latex_table( std::ofstream &ofs, const std::vector<std::string> &tags,
                            const stadistics &data, int Npixel, const std::string &stadistic_name )
{
    //ofs.setf( ios::basefield,   ios::hex );
    //ofs.fill('0');

    ofs.setf( std::ios::adjustfield, std::ios::left );
    ofs.setf( std::ios::floatfield,  std::ios::fixed );

    ofs.precision(4); // 8);
    ofs.width(14); //18);

   // ------------------

    int num_methods = tags.size();

    // .....................................................................

    ofs << "\\begin{table}" << std::endl;
    ofs << "\\begin{center}" << std::endl;

      // ........

    ofs << "\\begin{tabular}{";

    for (int i=0; i<num_methods+1; i++)  ofs << "|c";

    ofs << "|}" << std::endl;

      // ........

 // Header

     ofs << "\\hline \\textbf{" << stadistic_name << "}";

     for (int i=0; i<num_methods; i++)  ofs << "  & \\textbf{" <<  tags[i] << "}";
     //ofs << "  & " << tags[i];

     ofs << "  \\\\" << std::endl;


      // ........

     ofs << "\\hline" << std::endl;

      // ........


 // Body
     for (int i=0; i<num_methods; i++) {

        ofs << "\\hline  \\textbf{" <<  tags[i] << "}";

        for (int j=0; j<num_methods; j++)
            ofs << "  & " << data[i*num_methods +j];

        ofs << "  \\\\" << std::endl;
     }

      // ........


     ofs << "\\hline" << std::endl;
     ofs << "\\end{tabular}" << std::endl;
     ofs << "\\caption{  " << Npixel << " pixels used to compute " << stadistic_name << " value." << "} %" << std::endl;
     ofs << "\\label{_" <<  stadistic_name << "_tab}" << std::endl;
     ofs << "\\end{center}" << std::endl;
     ofs << "\\end{table}" << std::endl;


     ofs << "% #" << std::endl;
     ofs << "% #" << std::endl;

     return 0;
}


/**
 * Ami_writeStadistics2file. Save in a file the stadistics results of varios methods.
 *
 * \param fns  Names of the Ascii files.
 * \param data  Data struture which stored the stadistics results.
 * \param stadistics_name  Name of the stadistics methods.
 * \param ofn  Output file.
 *
 * \return Return an integer. (0 = OK, -1 = Output file error)
 */
template <class stadistics, class pixels>
int ami_writeStadistics2file( const std::vector<std::string> &fns, const std::vector<std::string> &tags, const stadistics &data, const pixels &pix,
                          const std::vector<std::string> &stadistics_name, const char *ofn, bool write_latex=false )
{
    std::ofstream ofs( ofn );

    if ( ofs.is_open() )  {

      // ------------------

        //ofs.setf( ios::basefield,   ios::hex );
        //ofs.fill('0');

        ofs.setf( std::ios::adjustfield, std::ios::left );
        ofs.setf( std::ios::floatfield,  std::ios::fixed );

        ofs.precision(4); //8);
        ofs.width(14); //18);

      // ------------------

        int num_methods = fns.size();

      // Write the name of the stadistics used.
        ofs << "% # Number of methods / Number of stadistics" << std::endl;
        ofs << "%  " << num_methods << " " << data.size() << std::endl;

        ofs << "%  " << "#" << std::endl;

        for (int i=0; i<num_methods; i++)          ofs << "%  " << fns[i] << std::endl;

        // ..............................................


        ofs << "% # Stadistics results" << std::endl;

        for (int k=0; k<data.size(); k++) {

          if ( write_latex ) {

               ami_create_latex_table( ofs, tags, data[k], pix[k][0], stadistics_name[k] );
          }
          else {

             ofs << "# " << stadistics_name[k] << std::endl;

             for (int i=0; i<num_methods; i++) {

                for (int j=0; j<num_methods; j++) {

                     ofs << data[k][i*num_methods +j] << " ";
                 }

                ofs << std::endl;
              }

              ofs << "#" << std::endl;

          }  // if ( write_latex )

         }  // for


        // ..............................................


        ofs << "% # N. pixels" << std::endl;

        for (int k=0; k<pix.size(); k++) {

             ofs << "% ";

             for (int i=0; i<num_methods*num_methods; i++)       ofs << pix[k][i] << "  ";

             ofs << std::endl;
        }


        ofs << "% #" << std::endl;

        // ................

        ofs.close();

    }
    else
    {
       std::cerr << "Error opening file:  " << ofn << std::endl;
       return -1;
    }


    return 0;
}


// ....................


/**
 * Getdata. Read a line from a file
 *
 * \param ifs File.
 * \param line String (line) read from file.
 *
 * \return Return an integer. (0 = OK, -1 = EOF)
 */
int getdata( std::ifstream &ifs, std::string &line )
{
      while ( !ifs.eof() ) {

          getline( ifs, line );
          if ( line[0] == '#' )     continue;

//          std::cout << "line: " << line << std::endl;
          return 0;
      }

      return -1;
}


/**
 * Split_string. Split a string by the spaces.
 *
 * \param line String (line).
 * \param substrs Store the substrings.
 *
 * \return Return an integer. (0 = OK, -1 = ERROR)
 */
int split_string( std::string &line, std::vector<std::string> &substrs )
{
   int pos = 0;

   while ( pos < line.size() ) {

      int newpos = line.find( ' ', pos );
      std::string s = line.substr( pos, newpos - pos );

      if ( s.size() > 0 ) {

          //std::cout << "\tsubstr:  " << s << std::endl;
          substrs.push_back( line.substr( pos, newpos - pos ) );
      }

      pos = newpos+1;
   }

   return 0;
}



// ....................


/**
 * Ami_readFile2Stadistics. Load from a file the stadistics results of various methods.
 *
 * \param ifn  Input file.
 * \param fns  Names of the Ascii files.
 * \param data  Data struture which stored the stadistics results.
 *
 * \return Return an integer. (0 = OK, -1 = Output file error)
 */
template <class stadistics, class pixels>
int ami_readFile2Stadistics( const char *ifn, std::vector<std::string> &fns, stadistics &data, pixels &pix )
{
    std::ifstream ifs( ifn );

    if ( ifs.is_open() )  {

      //char line[LINE_SIZE];
      std::string line;

      if ( getdata( ifs, line ) == -1 )  {

          std::cout << "ERROR. the stadistics file format is not valid." << std::endl;
          return -1;
      }

      // ..............................................

      // Read the name of the references files.
      int num_methods = 0, num_stadistics = 0;
      sscanf( line.c_str(), "%d %d", &num_methods, &num_stadistics );


      //std::cout << "line: " << line << std::endl;
      //std::cout << "Nmeth: " << num_methods << "   Numsta:  " << num_stadistics << std::endl;


      for (int i=0; i<num_methods; i++)  {

          if ( getdata( ifs, line ) == -1 )  {

              std::cout << "ERROR. the stadistics file format is not valid." << std::endl;
              return -1;
          }

	  fns.push_back( line );
      }

      // ..............................................
      // ..............................................

      for (int k=0; k<num_stadistics; k++) {

          //std::cout << "XXX:  "  << std::endl;

	  typename stadistics::value_type data_values(num_methods*num_methods);
	  data.push_back( data_values );

          for (int i=0; i<num_methods; i++) {

              if ( getdata( ifs, line ) == -1 )  {

                  std::cout << "ERROR. the stadistics file format is not valid." << std::endl;
                  return -1;
              }

              std::vector<std::string> substrs;
              split_string( line, substrs );

              for (int j=0; j<num_methods; j++) {

                    data[k][i*num_methods +j] = atof( substrs[j].c_str() );
              }

          }

      }


     // ..............................................

      for (int k=0; k<num_stadistics; k++) {

           if ( getdata( ifs, line ) == -1 )  {

                std::cout << "ERROR. the stadistics file format is not valid." << std::endl;
                return -1;
           }

	// ...................

	   typename pixels::value_type pix_values(num_methods*num_methods);
	   pix.push_back( pix_values );

	// ...................


           std::vector<std::string> substrs;
           split_string( line, substrs );

           for ( int i=0; i<num_methods*num_methods /*substrs.size()*/; i++ ) {

                pix[k][i] = (int) atof( substrs[i].c_str() );
           }

      }

      // ................	

      ifs.close();

    }
    else
    {
       std::cerr << "Error opening file:  " << ifn << std::endl;
       return -1;
    }


    return 0;
}

// ....................


/**
 * print_stadistics. Print the results though standard output.
 *
 * \param stadistics  Data struture which stored the stadistics results.
 * \param stadistics_name  Name of the stadistics methods. 
 * \param Npixels  Number of pixels computed in each test.
 * \param nmethods  Number of methods used in the tests.
 */
void print_stadistics( const std::vector< std::vector<real> > &stadistics, const std::vector<std::string> &stadistics_name,
                       const std::vector< std::vector<int>  > &Npixels, int nmethods )
{

   for (int k=0; k<stadistics_name.size(); k++)       std::cout << stadistics_name[k] << std::endl;

// ...................


   for (int k=0; k<stadistics.size(); k++) {

     // ...................

      for (int i=0; i<nmethods; i++) {

          for (int j=0; j<nmethods; j++)             std::cout << stadistics[k][i*nmethods +j] << " ";

          std::cout << std::endl;
      }

      std::cout << std::endl;

     // ...................

      std::cout << "Npixels" << std::endl;

      for (int i=0; i<nmethods; i++) {

           for (int j=0; j<nmethods; j++)      std::cout << Npixels[k][i*nmethods +j] << "  ";

           std::cout << std::endl;
       }

      std::cout << std::endl;

     // ...................

   }

}


#endif

//        if ( fabs( U1[x + y * nx] ) > min && fabs(U1[x + y * nx]) < max ) {

//          if ( U1[x + y * nx] != NULL_VALUE && V1[x + y * nx] != NULL_VALUE
//            && U2[x + y * nx] != NULL_VALUE && V2[x + y * nx] != NULL_VALUE ) {
