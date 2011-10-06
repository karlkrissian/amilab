
#include "CommonConfigure.h"

#include "Pile.hpp"
#include "Erreurs.hpp"
#include "AmiMessage.h"

COMMON_VAR_EXPORT unsigned char GB_AfficheWarning = false;
COMMON_VAR_EXPORT unsigned char GB_AfficheErreur  = false;
COMMON_VAR_EXPORT unsigned char GB_debug;
COMMON_VAR_EXPORT unsigned char GB_debug_opengl;
COMMON_VAR_EXPORT unsigned char GB_verbose;
COMMON_VAR_EXPORT unsigned char GB_nofile;
COMMON_VAR_EXPORT Pile<NomMethode*> GB_pile_nom_methode((NomMethode*)NULL);
COMMON_VAR_EXPORT AmiMessage   GB_AmiMessage;
