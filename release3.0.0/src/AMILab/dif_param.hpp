// Fichier dif_param.hpp
//
// Karl KRISSIAN
//
// Sophia Antipolis, le 4-10-96


#ifndef _DIF_param_hpp_

#define _DIF_param_hpp_

#include "style.hpp"
#include "chaine.hpp"

#define MODE_1D 1
#define MODE_2D 2
#define MODE_3D 3

// differents types de processus
#define _DIF_NORMAL    1
#define _DIF_FLOT      2
#define _DIF_FLOT_DEMI 3

// differents types de diffusion 
#define _DIF_GERIG      1
#define _DIF_CATTE      2
#define _DIF_DIR        3
#define _DIF_DIV_E1     4
#define _DIF_WEICKERT   5
#define _DIF_REHAUSS    6
#define _DIF_CATTE_SEP  7
#define _DIF_AMSS       8
#define _DIF_EMSS       9
#define _DIF_KARL      10

// differents types de fonctions 
#define _DIF_EXP     1
#define _DIF_RAT     2
#define _DIF_Geman   3
#define _DIF_Green   4
#define _DIF_Aubert  5
#define _DIF_Rudin   6
#define _DIF_Essai   7

// types d'attache aux donnees
#define _DIF_attach_bruit_blanc 0
#define _DIF_attach_speckle     1

/*
struct ParamDiff {

    int    type_diffusion;
    int    type_function;
    int    dimension;
    int    steps;

    float      kappa;
    float      alpha;
    float      dt;
    float      sigma;

    t_3Point  h;

}
*/

struct t_3Point { float x; float y; float z; };
#define UNKNOWN -1


//=====================================================
class ParamDiff
//     =========
{

public:

    int    type_processus;
    int    type_diffusion;
    int    type_function;
    unsigned char   Normalise;
    int    dimension;
    int    steps;
    unsigned char   diff_finies; // Calcul par differences finies
    int    type_attach;

    float      kappa;
    float      alpha;
    float      beta;
    float      dt;
    float      sigma;
    float      sigma2;

    float      Imin; // intensite minimale pour laquelle on fait les calculs

    t_3Point  h;


    unsigned char   Expressions;
    Chaine    Exp_Cgradient; // expression du coefficient du gradient
    Chaine    Exp_Ctangente; // expression du coeff de la tangente (en 2D).
    Chaine    Exp_Ce1;       // expression du coeff de e1
    Chaine    Exp_Ce2;       // expression du coeff de e2

    unsigned char   ExpressionFonctionDiffusion;
    Chaine    Exp_FonctionDiffusion; // expression de la fonction de diffusion

    Chaine    Tests;
    Chaine    Tests_vecteur;

    unsigned char   Diff_successives;
    unsigned char   Diff_image;
    Chaine    Diff_nom_image;

    // Memorise l'�volution toutes les test_evol it�rations
    int    test_evol;

    int    SauveFluxIter;

    Chaine    ImageDiffusion;

    unsigned char   verbose;

   ParamDiff() {}
  //           ---------
  
  ~ ParamDiff() {}
  //           ---------

  void InitDefauts() 
  //   -----------
  {

    type_processus = UNKNOWN;
    type_diffusion = UNKNOWN;
    type_function  = UNKNOWN;
    Normalise      = false;
    dimension      = UNKNOWN;
    diff_finies    = false;
    verbose        = false;
    type_attach    = UNKNOWN;

    steps  = 10;
    kappa  = 1.0;
    alpha  = 1.0;
    beta   = 0.0;
    sigma  = 1.0;
    sigma2 = -1.0; // -1 signifie non utilise par defaut
    dt = (float)(0.0);

    Imin = -10;

    h.x = h.y = h.z = 1.0;

    Expressions   = false;
    Exp_Cgradient = "1";
    Exp_Ctangente = "1";
    Exp_Ce1       = "1";
    Exp_Ce2       = "1";

    ExpressionFonctionDiffusion   = false;
    Exp_FonctionDiffusion = "1";

    Tests = "";
    Tests_vecteur = "";
  
    Diff_successives  = false;
    Diff_image        = false;
    Diff_nom_image    = "";

    SauveFluxIter     = -1;

    test_evol         = 0;

    ImageDiffusion    = "";

  }

}; // ParamDiff


#endif // _DIF_param_hpp_







