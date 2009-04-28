
/*
extern "C" {
extern void _TOP_LinGaussFilDir1();
}
*/

static void _T_LinearGaussFilDirMask(t_ImagePtr theIm,  t_ImagePtr MaskIm, e_SepFilterParPtr par, int dir, t_ImagePtr resIm);

static void _T_LinGaussFilDir1Mask( t_ImagePtr theIm, t_ImagePtr MaskIm, 
				    e_SepFilterParPtr par, int dir, t_3rdFiltersPtr filter, 
				    t_ImagePtr anIm, t_3IPointPtr vDer );


//----------------------------------------------------------------------
static void _TOP_LinGaussFilDir2( t_ImagePtr im,  t_ImagePtr MaskIm,  
				  e_SepFilterParPtr par, t_ImagePtr res, t_3rdFiltersPtr filter, 
				  reeltype *bf, int m, int M, 
				  int inc, int size, int pos )

{
  int i,bSize,p;
  reeltype      *resP;
  unsigned char *maskP;
  
  register double value;
  register reeltype v;
  register reeltype *dptr;
  register reeltype *ptr;
  register int j;
  
  /* start to load the values */
  
  bSize= M - m + 1;
  ptr= filter-> im;
  
  for( j= m; j <= M; j++ ){
    
    p= j % size;
    if ( p <  0 ) p += size;                /* avoid side effects, p in 0..size-1 */
    
    switch( im-> type ){
      
    case TYPEIM_256:
      *ptr++ = 
	*(((unsigned char *) im-> buf) + pos + p * inc) / 255.0;
      break;
      
    case TYPEIM_FLOAT:
      *ptr++ = *(((reeltype *) im-> buf) + pos + p * inc);
      break;
    }
  }
  
  /* compute all values */
  
  resP  = ((reeltype *)      res   -> buf) + pos;
  maskP = ((unsigned char *) MaskIm-> buf) + pos;
  
  for( i=0; i<  size; i++ ){
    
    // if ((*maskP)>128) {
      ptr= filter-> im;
      dptr= bf;
      value= 0.0;
      
      for( j=0; j <  bSize; j++ ){
	v= *ptr; *ptr= *(ptr+1); ptr++;
	value += (double) (*(dptr++) * v);
      }
      //  }
	//  else value = 0.0;
      
    switch( par-> mode ){
      
    case MODE_SET:  *resP  = (reeltype) value;           break;
    case MODE_ADD:  *resP += (reeltype) value;           break;
    case MODE_ADD2: *resP += (reeltype) (value * value); break;
    }
    
    resP  += inc;
    maskP += inc;
    
    p= (i + M + 1) % size;
    if ( p <  0 ) p += size;
    
    switch( im-> type ){            /* load next image value */
      
    case TYPEIM_256:
      filter-> im[bSize-1]= 
	*(((unsigned char *) im-> buf)+pos+p*inc) / 255.0;
      break;
      
    case TYPEIM_FLOAT:
      filter-> im[bSize-1]= *(((reeltype *) im-> buf)+pos+p*inc);
      break;
    }
  }
}

//----------------------------------------------------------------------
static void _TOP_LinGaussFilDir1( t_ImagePtr theIm,  t_ImagePtr MaskIm, 
				  e_SepFilterParPtr par, int dir, t_3rdFiltersPtr filter, t_ImagePtr resIm,
				  t_3IPointPtr vDer )

{
        int i,j,k;
        int tx,ty,tz;
        reeltype *bf;

	//printf("_TOP_LinGaussFilDir1()\n");

        E_ERRN( (par-> mode != MODE_SET) && 
                (par-> mode != MODE_ADD) && 
                (par-> mode != MODE_ADD2), E_ERRFATAL, "_TOP_LinearGaussFilDir1",
                "unsupported image mode");

        E_ERRN( resIm-> type != TYPEIM_FLOAT, E_ERRFATAL, "_TOP_LinearGaussFilDir1",
                "wrong type for output image" );

        E_ERRN( (theIm-> type != TYPEIM_256) && 
                        (theIm-> type != TYPEIM_FLOAT), E_ERRFATAL,"_TOP_LinearGaussFilDir1",
                "wrong type for input image" );

        tx= resIm-> tx;
        ty= resIm-> ty;
        tz= resIm-> tz;

        bf= filter-> d[vDer-> x][vDer-> y][vDer-> z];

        switch( dir ){
    
                case DIRECT_X:

                        for( k=0; k<  tz; k++ ){

                                if ( par-> verb ){
                                        sprintf( tmpStr1, " plane no %d\r", k );
                                        T_Mess( tmpStr1, NULL );
                                        }

                                for( j=0; j<  ty; j++ ){

                                        _TOP_LinGaussFilDir2( theIm, MaskIm, par, resIm, filter,
                                                bf, filter-> mx, filter-> Mx,
                                                1, tx, j * tx + k * tx * ty );
                                        }
                        }
                break;
    
                case DIRECT_Y:

                        for( k=0; k<  tz; k++ ){

                                if ( par-> verb ){
                                        sprintf( tmpStr1, " plane no %d\r", k );
                                        T_Mess( tmpStr1, NULL );
                                        }

                                for( i=0; i<  tx; i++ ){

                                        _TOP_LinGaussFilDir2( theIm, MaskIm, par, resIm, filter,
                                                bf, filter-> my, filter-> My,
                                                tx, ty, i + k * tx * ty );
                                        }
                        }
                break;
    
                case DIRECT_Z:

                        for( j=0; j<  ty; j++ ){
                        
                                if ( par-> verb ){
                                        sprintf( tmpStr1, " plane no %d\r", j );
                                        T_Mess( tmpStr1, NULL );
                                }

                                for( i=0; i<  tx; i++ ){

                                        _TOP_LinGaussFilDir2( theIm, MaskIm, par, resIm, filter,
                                                bf, filter-> mz, filter-> Mz,
                                                tx*ty, tz, i + j * tx );
                                        }
                        }
                        break;
    
                default: 
                        E_XERRN(E_ERRUNKNOWN,"_TOP_LinearGaussFilDir1","unknown direction");
                        break;
                }
        }

//----------------------------------------------------------------------

static void _T_InitLinearGaussFil( t_3rdFiltersPtr filter, int size, reeltype sigma, reeltype scale, int direct, int mode )

{
  T_DefaultFilters( filter );
  
  filter-> tx= 1;
  filter-> ty= 1;
  filter-> tz= 1;
  filter-> sx= 1.0;
  filter-> sy= 1.0;
  filter-> sz= 1.0;
  
  switch( direct ){
    
  case DIRECT_X:
    
    filter-> tx= size;
    filter-> sx= sigma;
    filter-> scale.x= scale;
    break;
    
  case DIRECT_Y:
    
    filter-> ty= size;
    filter-> sy= sigma;
    filter-> scale.y= scale;
    break;
    
  case DIRECT_Z:
    
    filter-> tz= size;
    filter-> sz= sigma;
    filter-> scale.z= scale;
    break;
    
  default: 
    
    E_XERRN( E_ERRMISMATCH, "_T_InitLinearGaussFil", 
            "unknown direction" );
    break;
  }
  
  filter-> normModes= mode;
  
  T_InitFilters( filter );
  E_ISERRN( "_T_InitLinearGaussFil", NULL );
}

//----------------------------------------------------------------------

void E_SepFilterMask( t_ImagePtr theIm, t_ImagePtr MaskIm, e_SepFilterParPtr par, t_ImagePtr resIm )

{
  t_ImagePtr anIm;
  t_Image auxIm;
  
  if ( (resIm-> buf == NULL) || (resIm-> buf == theIm-> buf) ){
    T_CopyHeaderIm( resIm, & auxIm );
    T_AllocImage( & auxIm );
    anIm= & auxIm;
  }
  else anIm= resIm;
  E_REPERR( goto END_LinearGaussFil );
  
  if ( par-> verb ) T_Mess("filtering in X direction\n",NULL);
  if ((par-> vSize.x >  1) &&  (theIm-> tx >  1))
       _T_LinearGaussFilDirMask(theIm, MaskIm, par,DIRECT_X,anIm);
  else T_CopyImageBuffer( theIm, anIm );
  
  E_REPERR( goto END_LinearGaussFil );
  
  if ( par-> verb ) T_Mess("filtering in Y direction\n",NULL);
  if ((par-> vSize.y >  1) &&  (theIm-> ty >  1))
    _T_LinearGaussFilDirMask(anIm,MaskIm,par,DIRECT_Y,anIm);
  
  E_REPERR( goto END_LinearGaussFil );
  
  if ( par-> verb ) T_Mess("filtering in Z direction\n",NULL);
  if ((par-> vSize.z >  1) &&  (theIm-> tz >  1))
    _T_LinearGaussFilDirMask(anIm,MaskIm,par,DIRECT_Z,anIm);
  
  E_REPERR( goto END_LinearGaussFil );
  
 END_LinearGaussFil:
  
  if ( resIm != anIm ){
    T_FreeImage( resIm );
    resIm-> buf= anIm-> buf;
  }
  E_REPERR( T_FreeImage( resIm ) );
  E_ISERRN( "_T_LinearGaussFil", NULL );
}



//----------------------------------------------------------------------

static void _T_LinearGaussFilDirMask( t_ImagePtr theIm,  t_ImagePtr MaskIm, e_SepFilterParPtr par, int dir, t_ImagePtr resIm )
{
  int size= 0;
  reeltype sigma= 1.0;
        reeltype scale= 1.0;
  t_3IPoint vDer;
  t_ImagePtr anIm;
  t_Image auxIm;
  t_3rdFilters filter;
  
  if ( (resIm-> buf == NULL) || (resIm-> buf == theIm-> buf) ){
    T_CopyHeaderIm( resIm, & auxIm );
    T_AllocImage( & auxIm );
    anIm= & auxIm;
  }
  else anIm= resIm;
  
  T_3IForm( 0, 0, 0, & vDer );
  
  switch( dir ){
        case DIRECT_X:
                sigma= par-> vSigma.x;
                scale= par-> vScale.x;
                size= par-> vSize.x;
                vDer.x= par-> vDer.x;
                break;
        case DIRECT_Y:
                sigma= par-> vSigma.y;
                scale= par-> vScale.y;
                size= par-> vSize.y;
                vDer.y= par-> vDer.y;
                break;
        case DIRECT_Z:
                sigma= par-> vSigma.z;
                scale= par-> vScale.z;
                size= par-> vSize.z;
                vDer.z= par-> vDer.z;
                break;
                }
  
        _T_InitLinearGaussFil( & filter, size, sigma, scale, dir, par-> normModes );
        E_ISERRN( "_T_LinearGaussFilDir", NULL );

        filter.boardModes= par-> boardModes;

        _T_LinGaussFilDir1Mask( theIm, MaskIm, par, dir, & filter, anIm, & vDer );

        T_FreeFilters( & filter );
        if ( resIm != anIm ){
        T_FreeImage( resIm );
                resIm-> buf= anIm-> buf;
                }
        E_REPERR( T_FreeImage( resIm ) );
        E_ISERRN( "_T_LinearGaussFilDir", NULL );
}

//----------------------------------------------------------------------


static void _T_LinGaussFilDir1Mask( t_ImagePtr theIm, t_ImagePtr MaskIm, 
				    e_SepFilterParPtr par, int dir, t_3rdFiltersPtr filter, 
				    t_ImagePtr anIm, t_3IPointPtr vDer )

{
        reeltype value;
	unsigned char* maskptr;
        int i,j,k;


	//printf("_T_LinGaussFilDir1Mask()\n");
        /* check for optimization routines */
	/*
        if ( (anIm-> type == TYPEIM_FLOAT) && 
                 ((par-> mode == MODE_SET) ||
                  (par-> mode == MODE_ADD) ||
                  (par-> mode == MODE_ADD2)) && 
                 ((theIm-> type == TYPEIM_FLOAT) ||
                  (theIm-> type == TYPEIM_256)) && 
                (filter-> boardModes == 0)  ){

                _TOP_LinGaussFilDir1( theIm, MaskIm, par, dir, filter, anIm, vDer );    
                return;
                }
	*/
        maskptr = (unsigned char*) (MaskIm->buf);

        switch( dir ){
    
        case DIRECT_X:
          //printf("DIRECT_X \n");
	  for( k=0; k<  anIm-> tz; k++ ){
	    
	    if ( par-> verb ){
	      sprintf( tmpStr1, " plane no %d\r", k );
	      T_Mess( tmpStr1, NULL );
	    }
	    
	    for( j=0; j<  anIm-> ty; j++ ){
	      T_LoadFilter(0,j,k,theIm,filter);
	      for( i=0; i<  anIm-> tx; i++ ){
                //if ((i==22)&&(j==4)&&(k==30))
                //  printf("mask = %d \n", *maskptr);
		if (*maskptr++ > 128) {
  		  value= T_ApplyFilters(filter,vDer-> x,vDer-> y,vDer-> z);
		  T_Set3Point( i,j,k, anIm, value, par-> mode );
                }
		T_ShiftFilter1D(i,j,k,theIm,filter,DIRECT_X,PLUS);
		E_ISERRN( "_T_LinGaussFilDir1", NULL );
	      }
	    }
	  }
        break;
    
        case DIRECT_Y:
          //printf("DIRECT_Y \n");
	  
	  for( k=0; k<  anIm-> tz; k++ ){
	    if ( par-> verb ){
	      sprintf( tmpStr1, " plane no %d\r", k );
	      T_Mess( tmpStr1, NULL );
	    }
	    for( i=0; i<  anIm-> tx; i++ ){
	      T_LoadFilter(i,0,k,theIm,filter);
	      for( j=0; j<  anIm-> ty; j++ ){
		//if (*maskptr++ > 128) {
		  value= T_ApplyFilters(filter,vDer-> x,vDer-> y,vDer-> z);
		  T_Set3Point( i,j,k, anIm, value, par-> mode );
		  //}
		T_ShiftFilter1D(i,j,k,theIm,filter,DIRECT_Y,PLUS);
		E_ISERRN( "_T_LinGaussFilDir1", NULL );
	      }
	    }
	  }
	  break;
	  
        case DIRECT_Z:
	  //          printf("DIRECT_Z \n");
	  for( j=0; j<  anIm-> ty; j++ ){
	    if ( par-> verb ){
	      sprintf( tmpStr1, " plane no %d\r", j );
	      T_Mess( tmpStr1, NULL );
	    }
	    for( i=0; i<  anIm-> tx; i++ ){
	      T_LoadFilter(i,j,0,theIm,filter);
	      for( k=0; k<  anIm-> tz; k++ ){
		//if (*maskptr++ > 128) {
		  value= T_ApplyFilters(filter,vDer-> x,vDer-> y,vDer-> z);
		  T_Set3Point( i,j,k, anIm, value, par-> mode );
		  //}
		T_ShiftFilter1D(i,j,k,theIm,filter,DIRECT_Z,PLUS);
		E_ISERRN( "_T_LinGaussFilDir1", NULL );
	      }
	    }
	  }
	  break;
		
        default: E_SETERR(E_ERRUNKNOWN,"_T_LinearGaussFilDir","unknown direction");
	  break;
	}
	
        E_ISERRN( "_T_LinGaussFilDir1", NULL );
}


