/*
 * Parameters of the PDE Optical Flow technique 
 */

#ifndef AMI_OPTIC_FLOW_PDE_PARAM_H
#define AMI_OPTIC_FLOW_PDE_PARAM_H

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

enum SmoothingFunction {
  phi_x,     // phi(x)=x, standard minimization of the square of the gradient norm
  phi_sqrt_x // phi(x)=sqrt(x+epsilon), square root normalization
};

enum GradientComputation {
  grad_max,     // gradient is calculated using the maximal absolute 
                // value with the neighbors in each direction
  grad_inv,     // gradient is calculated with a local 3x3 mask (only 2D), 
                // which is invariant under rotation as much as possible
  grad_spline 
};

enum InterpolationType {
  linear, // linear interpolation
  spline  // spline interpolation
};

enum BoundaryType {
  boundary_border, // The points at the border are set to the values of their inside neighbor
  boundary_point_outside // creates a mask of the pixels (or voxels) that
                        // point outside the image domain and extrapole their values
                        // from their neighbors
};

//-----------------------------------------------------------------------
class PDEOpticFlowParam 
{
  public:
    
  enum SmoothingFunction   Phi;
  
  enum GradientComputation GradComp;

  enum InterpolationType InterpType;

  enum BoundaryType BoundType;

  int spline_degree;
  
  // impose the incompressibility as a constraint of the Energy
  int EnergyConstraint;
  // constant A to stabilize the solenoidal projection of the Energy gradient
  float A_EnergyProjection; 

  // if the solenoidal projection is active
  int SolenoidalProjection; 
  // constant A to stabilize the solenoidal projection of the flow
  float A_FlowProjection; 
  
  // if the smoothing constraint is applied to the total displacement or to
  // the additional displacement
  int global_constraint;
  
  // If the gradient is computed on the smoothed image
  int smooth_gradient;
  
  // Symmetric formulation
  int symmetric;
  
  // parameter of the initial optical flow function
  // smoothing coefficients (like Gaussian convolution)
  float beta[3];
  
  // coefficient for the smoothing term of the energy
  ami_v3f alfa;
  
  // Zoom factor in each dimension
  int zoom_factor[3];

  float temporal_alpha;
  
  // Tolerance threshold for Gauss-Seidel iterations
  float TOL_GaussSeidel;
  
  // Number of scales in the Pyramidal computation
  int Nscales;
  
  // Tolerance threshold for the scale iterations
  float TOL_Scales;
  
  // Different way to calculate the gradient of the energy
  int gradient_type;
      
  // Alpha normalization?
  int normalize_alpha;
  
  // Epsilon for the normalization of alpha
  float alpha_normalization_epsilon;

  // Constructor
  PDEOpticFlowParam()
  {
    int i;
    
    A_EnergyProjection = 10;
    A_FlowProjection = 0.01;

    Phi=phi_x;
    GradComp=grad_max;

    InterpType=linear;

    BoundType = boundary_border;

    spline_degree = 2;

    EnergyConstraint=0;
    SolenoidalProjection=0;
    global_constraint=1;
    smooth_gradient=1;
    symmetric=0;
    
    for(i=0;i<3;i++) {
      beta[i]=0.25;
      alfa[i]=2.0;
      zoom_factor[i]=2;
    }

    temporal_alpha=2.0;
    
    TOL_GaussSeidel=1E-5;
    Nscales=3;
    TOL_Scales=1E-2;
    gradient_type=0;

    normalize_alpha=1;
    alpha_normalization_epsilon=1E-2;

  }
  
  void SetTemporalAlpha(float ta) { this->temporal_alpha=ta; }
  float GetTemporalAlpha()  const { return this->temporal_alpha;  }

  void SetSmoothingFunction(enum SmoothingFunction sf) { this->Phi=sf; }
  enum SmoothingFunction GetSmoothingFunction()  const { return this->Phi;  }
  
  void SetGradientComputation(enum GradientComputation gc) { this->GradComp=gc; }
  enum GradientComputation GetGradientComputation() const  { return this->GradComp; }

  void SetInterpolationType(enum InterpolationType it) { this->InterpType=it; }
  enum InterpolationType GetInterpolationType() const  { return this->InterpType; }
  
  void SetSplineDegree(int sd)  { this->spline_degree=sd; }
  int  GetSplineDegree() const  { return this->spline_degree; }

  void SetBoundaryType(enum BoundaryType bt) { this->BoundType=bt; }
  enum BoundaryType GetBoundaryType() const  { return this->BoundType; }

  void SetSolenoidalProjection(int sp)  { this->SolenoidalProjection=sp; }
  int  GetSolenoidalProjection() const  { return this->SolenoidalProjection; }
  
  void SetEnergyConstraint(int ec)  { this->EnergyConstraint=ec; }
  int  GetEnergyConstraint() const  { return this->EnergyConstraint; }
  
  void  SetAEnergyProj(float a)  { this->A_EnergyProjection=a; }
  float GetAEnergyProj() const  { return this->A_EnergyProjection; }

  void  SetAFlowProj(float a)  { this->A_FlowProjection=a; }
  float GetAFlowProj() const   { return this->A_FlowProjection; }

  void SetGlobalConstraint(int gc)  { this->global_constraint=gc; }
  int  GetGlobalConstraint() const  { return this->global_constraint; }
  
  void SetSmoothGradient(int sg)  { this->smooth_gradient=sg; }
  int  GetSmoothGradient() const  { return this->smooth_gradient; }
  
  void SetSymmetric(int s) { this->symmetric =s; }
  int GetSymmetric() const { return this->symmetric; }
  
  void SetBeta( float bx, float by, float bz) 
  { 
    this->beta[0]=bx;
    this->beta[1]=by;
    this->beta[2]=bz;
  }
  const float* GetBeta() const { return this->beta; }
  
  void SetAlpha( float ax, float ay, float az) 
  { 
    this->alfa[0]=ax;
    this->alfa[1]=ay;
    this->alfa[2]=az;
  }
  const float* GetAlpha() const { return this->alfa; }
  
  void SetZoomFactor( int zx, int zy, int zz) 
  { 
    this->zoom_factor[0]=zx;
    this->zoom_factor[1]=zy;
    this->zoom_factor[2]=zz;
  }
  const int* GetZoomFactor() const { return this->zoom_factor; }
  
  void  SetToleranceGaussSeidel(float TGS) { this->TOL_GaussSeidel=TGS;    }
  float GetToleranceGaussSeidel()  const  { return this->TOL_GaussSeidel; }
  
  void SetNbScales(int nsc) { this->Nscales=nsc;    }
  int  GetNbScales()  const { return this->Nscales; }
  
  void  SetToleranceScales(float TSC) { this->TOL_Scales=TSC;    }
  float GetToleranceScales() const    { return this->TOL_Scales; }
  
  void SetGradientType(int gt) { this->gradient_type=gt;     }
  int  GetGradientType() const { return this->gradient_type; }

  void SetNormalizeAlpha(int s) { this->normalize_alpha =s; }
  int GetNormalizeAlpha() const { return this->normalize_alpha; }
  
  void  SetAlphaNormEpsilon(float ep) { this->alpha_normalization_epsilon=ep;    }
  float GetAlphaNormEpsilon() const    { return this->alpha_normalization_epsilon; }


// -----------------------------------------------------------------------------------
// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// -----------------------------------------------------------------------------------

/**
 * .
 *
 */

template<class out>
int save_parameter_file( out &print = std::cout /*descriptor del fichero*/ )
{
/*
    std::ofstream ofs( ofn );

    if ( ofs.is_open() )  {
*/

   setlocale(LC_NUMERIC,"C");
   print << "# ########################################################"  << std::endl;
   print << "# ################## Parameters test file ################"  << std::endl;
   print << "# ########################################################"  << std::endl;
   print << "# "  << std::endl;
   print << "# "  << std::endl;

// .......................................

   print << "# SmoothingFunction: ( phi_x, phi_sqrt_x )"  << std::endl;
   print << Phi  << std::endl;
   print << "# "  << std::endl;

   print << "# GradientComputation: ( grad_max, grad_inv, grad_spline )"  << std::endl;
   print << GradComp  << std::endl;
   print << "# "  << std::endl;

   print << "# InterpolationType: ( linear, spline )"  << std::endl;
   print << InterpType  << std::endl;
   print << "# "  << std::endl;

   print << "# BoundaryType: ( boundary_border, boundary_point_outside )"  << std::endl;
   print << BoundType  << std::endl;
   print << "# "  << std::endl;

   print << "# spline_degree"  << std::endl;
   print << spline_degree << std::endl;
   print << "# "  << std::endl;

// .......................................

   print << "# impose the incompressibility as a constraint of the Energy (EnergyConstraint)"  << std::endl;
   print << EnergyConstraint  << std::endl;
   print << "# "  << std::endl;

   print << "# if the solenoidal projection is active (SolenoidalProjection)"  << std::endl;
   print << SolenoidalProjection  << std::endl;
   print << "# "  << std::endl;

   print << "# if the smoothing constraint is applied to the total displacement or to"  << std::endl;
   print << "# the additional displacement (global_constraint)"  << std::endl;
   print << global_constraint  << std::endl;
   print << "# "  << std::endl;

   print << "# If the gradient is computed on the smoothed image (smooth_gradient)"  << std::endl;
   print << smooth_gradient  << std::endl;
   print << "# "  << std::endl;

   print << "# Symmetric formulation (symmetric)"  << std::endl;
   print << symmetric  << std::endl;
   print << "# "  << std::endl;

// .......................................

   print << "# parameter of the initial optical flow function"  << std::endl;
   print << "# smoothing coefficients (like Gaussian convolution) (beta[3])"  << std::endl;
   print <<  beta[0] << " " << beta[1] << " " << beta[2] << std::endl;
   print << "# "  << std::endl;

   print << "# coefficient for the smoothing term of the energy (alfa[3])"  << std::endl;
   print <<  alfa[0] << " " << alfa[1] << " " << alfa[2] << std::endl;
   print << "# "  << std::endl;

   print << "# Zoom factor in each dimension (zoom_factor[3])"  << std::endl;
   print <<  zoom_factor[0] << " " << zoom_factor[1] << " " << zoom_factor[2] << std::endl;
   print << "# "  << std::endl;

   print << "# temporal_alpha"  << std::endl;
   print << temporal_alpha  << std::endl;
   print << "# "  << std::endl;

// .......................................

   print << "# Tolerance threshold for Gauss-Seidel iterations (TOL_GaussSeidel)"  << std::endl;
   print << TOL_GaussSeidel  << std::endl;
   print << "# "  << std::endl;

   print << "# Number of scales in the Pyramidal computation (Nscales)"  << std::endl;
   print << Nscales  << std::endl;
   print << "# "  << std::endl;

   print << "# Tolerance threshold for the scale iterations (TOL_Scales)"  << std::endl;
   print << TOL_Scales  << std::endl;
   print << "# "  << std::endl;

   print << "# Different way to calculate the gradient of the energy (gradient_type)"  << std::endl;
   print << gradient_type  << std::endl;
   print << "# "  << std::endl;

   print << "# Alpha normalization? (normalize_alpha)"  << std::endl;
   print << normalize_alpha  << std::endl;
   print << "# "  << std::endl;

   print << "# Epsilon for the normalization of alpha (alpha_normalization_epsilon)"  << std::endl;
   print << alpha_normalization_epsilon  << std::endl;
   print << "# "  << std::endl;

   print << "# Constant added to stabilize the solenoidal projection of the energy gradient "  << std::endl;
   print << A_EnergyProjection  << std::endl;
   print << "# "  << std::endl;

   print << "# Constant added to stabilize the solenoidal projection of the flow "  << std::endl;
   print << A_FlowProjection  << std::endl;
   print << "# "  << std::endl;

// .......................................

/*
        ofs.close();
    }
    else
    {
       std::cerr << "Error opening file:  " << ofn << std::endl;
       return -1;
    }
*/

    return 0;
}

// -----------------------------------------------------------------------------------
// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// -----------------------------------------------------------------------------------


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

		  std::getline( ifs, line );
          if ( line[0] == '#' )     continue;

          std::cout << "line: " << line.c_str() << std::endl;
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

   while ( pos < (int)line.size() ) {

      int newpos = line.find( ' ', pos );
      std::string s = line.substr( pos, newpos - pos );

      if ( s.size() > 0 ) {

          //std::cout << "\tsubstr:  " << s << std::endl;
          substrs.push_back( line.substr( pos, newpos - pos ) );
      }

      pos = newpos+1;

      if ( newpos == -1 ) return -1;
   }

   return 0;

}


// ....................

/**
 * Load_parameter_file. Load from a file the pde parameters.
 *
 * \param ifn  Input file name.
 *
 * \return Return an integer. (0 = OK, -1 = Output file error)
 */

int load_parameter_file( const std::string ifn )
{

    setlocale(LC_NUMERIC,"C");
    std::vector<std::string> substrs;
    std::ifstream ifs(  ifn.c_str() );

    if ( ifs.is_open() )  {

      //char line[LINE_SIZE];
      std::string line;

      if ( getdata( ifs, line ) == -1 )  {

          std::cout << "ERROR. the stadistics file format is not valid." << std::endl;
          return -1;
      }

// .......................................

      //int tmp = 0;

      // SmoothingFunction: ( phi_x, phi_sqrt_x ).
      this->Phi = (SmoothingFunction) atoi(line.c_str());

      if ( getdata( ifs, line ) == -1 )  { std::cout << "ERROR read the parameter file." << std::endl;   return -1; }


      // GradientComputation: ( grad_max, grad_inv, grad_spline ).
      this->GradComp = (GradientComputation) atoi(line.c_str());

      if ( getdata( ifs, line ) == -1 )  { std::cout << "ERROR read the parameter file." << std::endl;   return -1; }


      // InterpolationType: ( linear, spline ).
      this->InterpType = (InterpolationType) atoi(line.c_str());

      if ( getdata( ifs, line ) == -1 )  { std::cout << "ERROR read the parameter file." << std::endl;   return -1; }


      // BoundaryType: ( boundary_border, boundary_point_outside ).
      this->BoundType = (BoundaryType) atoi(line.c_str());

      if ( getdata( ifs, line ) == -1 )  { std::cout << "ERROR read the parameter file." << std::endl;   return -1; }


      // spline_degree.
      spline_degree =  atoi(line.c_str());

      if ( getdata( ifs, line ) == -1 )  { std::cout << "ERROR read the parameter file." << std::endl;   return -1; }

// .......................................


      // impose the incompressibility as a constraint of the Energy.
      EnergyConstraint =  atoi(line.c_str());

      if ( getdata( ifs, line ) == -1 )  { std::cout << "ERROR read the parameter file." << std::endl;   return -1; }


      // if the solenoidal projection is active.
      SolenoidalProjection =  atoi(line.c_str());

      if ( getdata( ifs, line ) == -1 )  { std::cout << "ERROR read the parameter file." << std::endl;   return -1; }


      // if the smoothing constraint is applied to the total displacement or to
      // the additional displacement.
      global_constraint =  atoi(line.c_str());

      if ( getdata( ifs, line ) == -1 )  { std::cout << "ERROR read the parameter file." << std::endl;   return -1; }


      // If the gradient is computed on the smoothed image.
      smooth_gradient =  atoi(line.c_str());

      if ( getdata( ifs, line ) == -1 )  { std::cout << "ERROR read the parameter file." << std::endl;   return -1; }


      // Symmetric formulation.
      symmetric =  atoi(line.c_str());

      if ( getdata( ifs, line ) == -1 )  { std::cout << "ERROR read the parameter file." << std::endl;   return -1; }


// .......................................

      // parameter of the initial optical flow function
      // smoothing coefficients (like Gaussian convolution).
      split_string( line, substrs );

      beta[0] = atof( substrs[0].c_str() );
      beta[1] = atof( substrs[1].c_str() );
      beta[2] = atof( substrs[2].c_str() );

      substrs.clear();

      if ( getdata( ifs, line ) == -1 )  { std::cout << "ERROR read the parameter file." << std::endl;   return -1; }


      // coefficient for the smoothing term of the energy.
      split_string( line, substrs );

      alfa[0] = atof( substrs[0].c_str() );
      alfa[1] = atof( substrs[1].c_str() );
      alfa[2] = atof( substrs[2].c_str() );

      substrs.clear();

      if ( getdata( ifs, line ) == -1 )  { std::cout << "ERROR read the parameter file." << std::endl;   return -1; }


      // Zoom factor in each dimension.
      split_string( line, substrs );

      zoom_factor[0] = atoi( substrs[0].c_str() );
      zoom_factor[1] = atoi( substrs[1].c_str() );
      zoom_factor[2] = atoi( substrs[2].c_str() );

      substrs.clear();

      if ( getdata( ifs, line ) == -1 )  { std::cout << "ERROR read the parameter file." << std::endl;   return -1; }


      // temporal_alpha.
      temporal_alpha = atof( line.c_str() );

      if ( getdata( ifs, line ) == -1 )  { std::cout << "ERROR read the parameter file." << std::endl;   return -1; }

// .......................................

      // Tolerance threshold for Gauss-Seidel iterations.
      TOL_GaussSeidel = atof( line.c_str() );

      if ( getdata( ifs, line ) == -1 )  { std::cout << "ERROR read the parameter file." << std::endl;   return -1; }


      // Number of scales in the Pyramidal computation.
      Nscales = atoi( line.c_str() );

      if ( getdata( ifs, line ) == -1 )  { std::cout << "ERROR read the parameter file." << std::endl;   return -1; }


      // Tolerance threshold for the scale iterations.
      TOL_Scales = atof( line.c_str() );

      if ( getdata( ifs, line ) == -1 )  { std::cout << "ERROR read the parameter file." << std::endl;   return -1; }


      // Different way to calculate the gradient of the energy.
      gradient_type =  atoi(line.c_str());

      if ( getdata( ifs, line ) == -1 )  { std::cout << "ERROR read the parameter file." << std::endl;   return -1; }


      // Alpha normalization?.
      normalize_alpha =  atoi(line.c_str());

      if ( getdata( ifs, line ) == -1 )  { std::cout << "ERROR read the parameter file." << std::endl;   return -1; }


      // Epsilon for the normalization of alpha.
      alpha_normalization_epsilon =  atof(line.c_str());

      if ( getdata( ifs, line ) == -1 )  { std::cout << "ERROR read the parameter file." << std::endl;   return -1; }


      // Constant added to stabilize the solenoidal projection of the energy gradient.
      A_EnergyProjection =  atof(line.c_str());

      if ( getdata( ifs, line ) == -1 )  { std::cout << "ERROR read the parameter file." << std::endl;   ifs.close(); return -1; }

      // Constant added to stabilize the solenoidal projection of the flow 

      A_FlowProjection =  atof(line.c_str());

      if ( getdata( ifs, line ) == -1 )  { std::cout << "ERROR read the parameter file." << std::endl;   ifs.close(); return -1; }

// .......................................

      // ................	

      ifs.close();

    }
    else
    {
       std::cerr << "Error opening file:  " << ifn.c_str() << std::endl;
       return -1;
    }


    return 0;
}

// ....................

};


#endif // AMI_OPTIC_FLOW_PDE_PARAM_H
