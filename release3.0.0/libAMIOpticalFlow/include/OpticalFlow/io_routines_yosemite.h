/*--------------------------------------------------------------------------*/

template <class itype>
void read_pgm_header
(
    char  *filename,        /* in     : name of pgm file */
    long  *header_end_pos,  /* in+out : position of header end */
    itype *nx,              /* out    : size in x-direction */
    itype *ny               /* out    : size in y-direction */
)
/* reads PGM header */
{
    char row[80]; /* read buffer */
    FILE *file;   /* file pointer */

    printf("\n Trying to read file %s ...",filename);
    
    /* try to open file */
    file = fopen(filename,"r");
    
    /* if file not found */
    if (file==NULL)
    {
	printf("... FAILED");
	printf("\n\n PROGRAM ABORTED !!! \n\n");
	exit(0);
    }
    
    /* read header */
    fgets (row, 300, file);
    fgets (row, 300, file);
    while (row[0]=='#') fgets(row, 300, file);

    /* read image dimensions */
    sscanf (row, "%d %d", (int)nx, (int)ny);
    fgets (row, 300, file);   

    /* determine end of header */
    *header_end_pos=ftell(file);

    /* close file */
    fclose(file);
}    

/* -------------------------------------------------------------------------- */

template <class fptype, class itype>
void read_pgm_data
(
    char   *filename,      /* in   : name of PGM file */
    long   data_start_pos, /* in   : position of data start */
    fptype **u,            /* out  : image */  
    itype  nx,             /* in   : size in x-direction */
    itype  ny,             /* in   : size in y-direction */
    itype  bx,             /* in   : boundary in x-direction */
    itype  by              /* in   : boundary in y-direction */
)

/* reads PGM data */

{
    itype i,j;  /* loop variables */
    FILE *file; /* file pointer */
    
    /* open file */
    file = fopen(filename,"r");
    
    /* start at begin of data */
    fseek(file,data_start_pos,SEEK_SET);

    /* read image data */
    for (j=by; j<ny+by; j++)
	for (i=bx; i<nx+bx; i++)
	{
	    u[i][j] = (fptype) getc (file);	    
	}    

    /* close file */
    fclose(file);
  
    printf("... SUCCESS");     
}



//-------------------------------------------------------------------------- 
template <class itype>
void write_pgm_blank_header
(
    char *filename,  /* in  : file name */  
    itype  nx,       /* in  : size in x-direction */
    itype  ny        /* in  : size in y-direction */
)

/* writes blank PGM header */

{

    FILE *file; /* file pointer */
    
    printf("\n Trying to write file %s ...",filename);
    
    /* try to open file */    
    file = fopen (filename, "w");
    
    /* if file not found -> break */
    if (file==NULL)
    {
	printf("... FAILED");
	printf("\n\n PROGRAM ABORTED !!! \n\n");
	exit(0);
    }
    
    /* write out header */
    fprintf (file, "P5 \n");   
    fprintf (file, "%d %d \n255\n", (int)nx, (int)ny);
    
    /* close file */
    fclose(file);
}
    

/* -------------------------------------------------------------------------- */

template <class fptype, class itype>
void write_pgm_data
(
    char *filename, /* in : file name */
    fptype **u,     /* in : image */
    itype  nx,      /* in : size in x-direction */
    itype  ny,      /* in : size in y-direction */
    itype  bx,      /* in : boundary in x-direction */
    itype  by       /* in : boundary in y-direction */
)    

/* writes PGM data */

{
    
    FILE *file;  /* file pointer */
    itype i,j;   /* loop variables */
    fptype help; /* tmp variable */
    unsigned char byte; /* variable for conversion */

    /* open file */    
    file = fopen (filename, "a");

    /* write image data */
    for (j=by; j<ny+by; j++)
	for (i=bx; i<nx+bx; i++)
	{
	    help = u[i][j];
	    if (help < 0.0)
		byte = (unsigned char)(0.0);
	    else if (help > 255.0)
		byte = (unsigned char)(255.0);
	    else
		byte = (unsigned char)(help);
	    fwrite (&byte, sizeof(unsigned char), 1, file);
	}

    /* close file */
    fclose(file);
    
    printf("... SUCCESS");
}

/* -------------------------------------------------------------------------- */


template <class fptype, class itype>
void read_barron_data
(
    const char *filename, /* in  : file name */
    fptype **u,     /* out : x-component of vector data */
    fptype **v,     /* out : y-component of vector data */
    itype  nx,      /* in  : size in x-direction */
    itype  ny,      /* in  : size in y-direction */
    itype  bx,      /* in  : boundary in x-direction */
    itype  by       /* in  : boundary in y-direction */      
)

/* reads barron file */

{
    FILE *file;    /* file pointer */
    float help;    /* tmp variable */
    float helpu;   /* tmp variable */
    float helpv;   /* tmp variable */
    //float **uref;  /* tmp array */
    //float **vref;  /* tmp array */
    itype i,j;     /* loop variabeles */
    itype nxref_and_offsetx; /* size in x-direction with crop offset */
    itype nyref_and_offsety; /* size in y-direction with crop offset */
    itype nxref_no_offsetx;  /* size in x-direction without crop offset */
    itype nyref_no_offsety;  /* size in y-direction without crop offset */
    itype offsetx; /* cropped offset in x-direction */
    itype offsety; /* cropped offset in y-direction */


    printf("\n Trying to read barron %s ...",filename);
    
    /* try to open file */
    file = fopen(filename,"r");
    
    /* if file not found */
    if (file==NULL)
    {
	printf("... FAILED");
	printf("\n\n PROGRAM ABORTED !!! \n\n");
	exit(0);
    }

    /* read header */
    /* nxref_and_offset should be nxref_no_offset = 2 * offsetx */
    /* nyref_and_offset should be nyref_no_offset = 2 * offsety */
    fread (&help, sizeof(float), 1, file);
    nxref_and_offsetx  = (itype) help;
    fread (&help, sizeof(float), 1, file);
    nyref_and_offsety  = (itype) help;
    fread (&help, sizeof(float), 1, file);
    nxref_no_offsetx  = (itype) help;
    fread (&help, sizeof(float), 1, file);
    nyref_no_offsety  = (itype) help;
    fread (&help, sizeof(float), 1, file);
    offsetx = (itype) help;
    fread (&help, sizeof(float), 1, file);
    offsety = (itype) help;       

    /* compare dimensions for consistency */
    if ((nx!=nxref_no_offsetx)||(ny!=nyref_no_offsety))
    {
	printf("... WRONG DIMENSIONS");
	printf("\n\n PROGRAM ABORTED !!! \n\n");
	exit(0);
    }
    /* read barron data */
    for (j = 0; j < nyref_and_offsety; j++)
	for (i = 0; i < nxref_and_offsetx; i++)
	{
	    fread(&helpu, sizeof(float), 1, file);
	    fread(&helpv, sizeof(float), 1, file);

	    if ((i>=offsetx)&&(i<nxref_no_offsetx+offsetx)&&
		(j>=offsety)&&(j<nyref_no_offsety+offsety))
	    {	    
		u[i+bx+offsetx][j+by+offsety] = (fptype) helpu;	     	  	  
		v[i+bx+offsetx][j+by+offsety] = (fptype) helpv; 	       
	    }    
	}
 
    /* close file */
    fclose(file);

    printf("... SUCCESS");
}

/* -------------------------------------------------------------------------- */

template <class fptype, class itype>
void write_barron_data
(
    char *filename, /* in : file name */
    fptype **u,     /* in : x-component of vector data */
    fptype **v,     /* in : y-component of vector data */
    itype  nx,      /* in : size in x-direction */
    itype  ny,      /* in : size in y-direction */
    itype  bx,      /* in : boundary in x-direction */
    itype  by       /* in : boundary in y-direction */       
)

/* writes barron file */

{
    FILE *file;   /* file pointer */
    float help;   /* tmp variable */
    itype i,j;    /* loop variables */ 
    itype offset; /* border size to crop (set fixed to 0) */ 

    printf("\n Trying to write barron file %s ...",filename);
    
    /* try to open file */
    file = fopen(filename,"w");
    
    /* if file not found */
    if (file==NULL)
    {
	printf("... FAILED");
	printf("\n\n PROGRAM ABORTED !!! \n\n");
	exit(0);
    }
    
    /* write header */
    help = nx;
    fwrite (&help, 4, 1, file);
    help = ny;
    fwrite (&help, 4, 1, file);
    offset=0;
    help = nx - 2 * offset;
    fwrite (&help, 4, 1, file);
    help = ny - 2 * offset;
    fwrite (&help, 4, 1, file);
    help = offset;
    fwrite (&help, 4, 1, file);
    fwrite (&help, 4, 1, file);

    /* write data */
    for (j=by; j<ny+by; j++)
	for (i=bx; i<nx+bx; i++)
	{
	    help = (float)u[i][j];
	    fwrite (&help, 4, 1, file);
	    
	    help = (float)v[i][j];
	    fwrite (&help, 4, 1, file);
	}
       
    /* close file */
    fclose(file);
    
    printf("... SUCCESS");
}

/* -------------------------------------------------------------------------- */
