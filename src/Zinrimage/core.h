/****************************************************************************/
/* core.h *             Core Library                                        */
/***************                                                            */
/* LIBRARY : core                                                           */
/* COMMENT : provides numerous tools such as a library for linear algebra   */
/* (mainly 2D and 3D vectors) as well as routines for h andling kd-trees     */
/* AUTHOR : hd + jm                                                         */
/****************************************************************************/
#ifndef __CORE__
#define __CORE__

#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>

#include <string.h>
#include <strings.h>
#include <stdlib.h>
#include <malloc.h>
#include <math.h>

#if (defined _SGI_) || (defined _SOLARIS_) || (defined _LINUX_) 
  extern FILE     *popen(const char *, const char *);
  extern int      pclose(FILE *);
#endif

#ifdef _LINUX_
  void bcopy (void *src, void *dest, int n);
  void bzero(void *s, int n);
#endif

#define SQR(x) ((x)*(x))
#ifndef MAX
#define MAX(x,y) (( (x) > (y) )? (x): (y))
#endif
#ifndef MIN
#define MIN(x,y) (( (x) < (y) )? (x): (y))
#endif

#ifndef ABS
#define ABS(x) ( ((x)>0) ? (x): (-x))
#endif

#ifndef M_PI
#define M_PI       3.1415926535897932385E0
#endif

#ifndef M_PI_2
#define M_PI_2     1.5707963267948966192E0 
#endif

#ifndef M_SQRT2
#define M_SQRT2    1.4142135623730950488E0 
#endif

/* Boolean Values */
#define true 1
#define false 0

/* The minimum values for double in order
   to make the comparison a==0.0 */
#define MIN_DOUBLE_SQR 1e-10
#define MIN_DOUBLE 1e-5

/* This is the threshold to get an acceptable range point when using 
   normal constraint for the closest point. The dot product between 
   the normal at the point and the normal at the vertex must be greater than 
   DOT_NORMAL_MIN */
#define DOT_NORMAL_MIN 0.1


#define FILENAME_LENGTH 200
/* The length of filenames */


#define VERSION_CORE 1.0
/* Libcore Version */

/* Macros to define 2D arrays */
#define CREATE_ARRAY2D(TYPE)                             \
{                                                        \
  TYPE **fbuf, *p;                                       \
  int i;                                                 \
                                                         \
  fbuf = (TYPE **) malloc(nrows*sizeof(TYPE *));         \
  p = (TYPE *) malloc(nrows*ncols*sizeof(TYPE));         \
  for (i = 0; i <nrows; ++i)                             \
    {                                                    \
      fbuf[i] = p;                                       \
      p += ncols;                                        \
    }                                                    \
  return fbuf;                                           \
}

/* Macros to define 3D arrays */
/* here we assume that sizeof(TYPE *) == sizeof(TYPE **) == sizeof(TYPE ***),
   otherwise, this code will cause some alignement problems */
#define CREATE_ARRAY3D(TYPE)                             \
{                                                        \
  TYPE  ***ibuf, **p, *buffer;                           \
  int i, j;                                              \
                                                         \
  ibuf = (TYPE ***) malloc(nd* sizeof(TYPE **)+ nd*nr*sizeof(TYPE *));\
  p = (TYPE **) (ibuf + nd);                             \
  buffer = (TYPE *) malloc(nr*nc*nd * sizeof(TYPE));     \
  for (i = 0; i < nd; ++i)                               \
    {                                                    \
      ibuf[i] = p;                                       \
      p += nr;                                           \
    }                                                    \
  for (i = 0; i < nd; ++i)                               \
    {                                                    \
      for(j = 0; j < nr; ++j)                            \
	{                                                \
	  ibuf[i][j] = (TYPE *) buffer;                  \
	  buffer += nc;                                  \
	}                                                \
    }                                                    \
  return ibuf;                                           \
}


typedef unsigned char byte;
/* byte type is useful for code readability*/


typedef int DISPLAY_LIST;
/* a type to store OpenGL display lists */


typedef void* POINTER;
/* Generic Pointer */


typedef short int BOOLEAN;
/* Boolean type . Do not use a "enum type" to avoid numerous casting */

/* ============ BOUNDING BOX ===================*/
typedef double BOUNDINGBOX[6];
/* A  3D bounding box type in the order xmin, ymin, zmin, xmax, ymax, zmax */


/* ============ FUNCTION PROTOTYPE ===================*/
typedef void (*FUNCT) ();
/* Definition of a function that returns void */

 /* ============ KD TREE ===================*/
typedef struct point_kd {
  struct point_kd *right; /* The right son */
  struct point_kd *left; /* The left son */
  double *v; /* The multidimensionnal array */
  int row,col; /* The row and col of the point it originates from */
} KD_TREE_NODE;
/* the data structure of a node of a kd_tree */

 typedef KD_TREE_NODE* PTRKD_TREE_NODE;
/* defines PTRKD_TREE_NODE as a pointer to a structure KD_TREE_NODE*/

typedef struct point_liste{
  double *v; /* the n-dimensional array (3 or 6 ) */
  int row,col; /* associated information */
  struct point_liste *following;
  struct point_liste *previous;
} KD_TEMP_ITEM;
/* A structure where is store the temmporary information of a kd-tree <BR>
   before calling create_kd_tree() */

typedef KD_TEMP_ITEM* PTRKD_TEMP_ITEM;
/* defines PTRKD_TEMP_ITEM as a pointer to a structure KD_TEMP_ITEM*/


typedef struct {
  PTRKD_TREE_NODE top_node; /* First node */
  PTRKD_TEMP_ITEM top_item;/* first item of the temporary list */
  PTRKD_TEMP_ITEM last_item;/* last item of the temporary list */
  int dimension; /* Either 3 (position) or 6 (position and normal) */
} RKD_TREE;
/* a data structure where are stored the information on the kd_tree */

typedef RKD_TREE* PTRKD_TREE;
/* defines PTRKD_TREE as a pointer to a structure RKD_TREE*/

typedef enum {
 ALONG_NORMAL_DIRECTION,
 ALONG_OPPOSITE_NORMAL_DIRECTION,
 DO_NOT_USE_NORMAL_DIRECTION
} USE_NORMAL_DIRECTION;
/* Information about the normal direction */

/* ============ VECT ===================*/

typedef struct { /* The VECT structure */
  double x; /* the x coordinate */
  double y; /* the y coordinate */
  double z; /* the z coordinate */
} VECT;
/* the 3D vector data structure */

/* ============ VECT2D ===================*/
typedef struct { /* The VECT structure */
  double x; /* the x coordinate */
  double y; /* the y coordinate */
} VECT2D;
/* the 3D vector data structure */

/* ============ MAT[][] ===================*/
typedef double** MAT;
/* General matrix format */

/* ============ MATRIX[][] ===================*/
/* Matrix definition that suits GL definition */
typedef float MATRIX[4][4];
/* Modeling matrix used in OpenGL */

/* ============ ROTATION[][] ===================*/
typedef double ROTATION[3][3];
/* Rotation matrix */

/* ============ PROJECTION[][] ===================*/
typedef double PROJECTION[3][4];
/* Projection matrices */


typedef unsigned int Object_Type;

typedef enum {
  ASCII,  /* write 2simplex mesh in ascii format */
  BINARY  /* write 2simplex mesh in binary format */
} Write_Mode;
/* Mode for writting 2-simplex meshes files */

typedef struct Type_List_Elt_Struct {
  Object_Type object;                                /* Object_Type element */
  struct Type_List_Elt_Struct *following, *previous; /* linkage */
} Type_List_Elt;
/* One element of an Object_Type list */

typedef Type_List_Elt * Type_List_Elt_Ptr;
/* Pointer to an Object_Type list element */

typedef struct Type_List_Struct {
  Type_List_Elt_Ptr first, last; /* first and last list element */
  int count;                     /* number of elements in list */
} Type_List;
/* Object_Type list */

typedef Type_List *Type_List_Ptr;
/* Pointer to Object_Type list */

/* Declaration of function prototypes */

/* Definition of procedures in vect.c */
#define  vect_null() vect_coordinates(0.,0.,0.) 
/* 
the vector (0.0,0.0,0.0) 
*/

#define  vect2D_null() vect2D_coordinates(0.,0.)

MAT create_square_mat (int n);
/* allocate a square matrix of size  n x n */ 
MAT create_mat (int n /* The number of rows*/ , int m /* the number of columns */);
/* allocate a matrix of size  n x m */ 

void free_mat(MAT m /* The matrix to be freed */);
/* free the memory allocated in matrix m */

MAT null_square_mat (int n /* The size of the square matrix*/);
/* allocate a square matrix of size  n x n  <BR> and fills it with zeros */ 

MAT null_mat (int/* The number of rows*/ , int/* the number of columns */);
/* allocate a  matrix of size  n x m  <BR> and fills it with zeros */ 

MAT id_mat (int /* the size of the square matrix */);
/* allocate a square matrix of size  n x n  <BR> and initializes it as the identity matrix */ 

void matcpy (MAT m1 /* The destination matrix */,
	     MAT m2 /* the source matrix */, 
	     int n /* the number of rows */,
	     int m /* The number of columns */);
/* Copies matrix the contents of m2 into matrix m1 <BR>
the two matrices must be of same size n x m <BR> 
and must have been previously allocated */

void add_mat (MAT m1 /* First matrix operand*/, MAT m2 /* Second matrix operand*/, 
	      MAT m12 /* The resulting matrix m12 = m1 + m2*/, int n /* The number of rows*/, 
	      int m/* the number of columns */);
/* adds two matrices m1 and m2 and writes the result in m12 <BR> the two matrices must be of same size n x m <BR> 
and must  have been previously allocated */

void addeq_mat (MAT m1 /* The matrix to be incremented*/, MAT m2 /* The operand matrix*/, 
		int n/* The number of rows*/,
		int m/* the number of columns */);
/* increment matrix m1 by m2 : m1+=m2 <BR> the two matrices must be of same size n x m <BR> 
and must  have been previously allocated */

void diff_mat (MAT m1/* First matrix operand*/, MAT m2/* Second matrix operand*/, 
	       MAT m12/* The resulting matrix m12 = m1 - m2*/, int n/* The number of rows*/, 
	       int m/* the number of columns */);
/* substract two matrices m1 and m2 and writes the result in m12 <BR> the two matrices must be of same size n x m <BR> 
and must  have been previously allocated */

void diffeq_mat (MAT m1/* The matrix to be decremented*/, MAT m2/* The operand matrix*/, 
		 int n/* The number of rows*/, int m/* the number of columns */);
/* decrement matrix m1 by m2 : m1-=m2 <BR> the two matrices must be of same size n x m <BR> 
and must  have been previously allocated */

VECT mul_mat_vect3 (MAT m /* The 3x3 matrix */, VECT v /* A 3D vector */ );
/* Returns a vector, product of m by v */

VECT mul_hmat_vect (MAT m /* The 3x4 homogeneous matrix */, VECT v/* A 3D vector */  );
/* Returns a vector, product of m by v */

void trans_square_mat (MAT m /* The square matrix*/ , int n /* The size of the square matrix */);
/* transpose matrix m of size n x n */

void mul_mat (MAT m1 /* First operand matrix of size n x m*/, 
	      MAT m2 /* Second operand matrix of size m x l */, 
	      MAT m12 /* Resulting matrix of size n x l */, 
	      int n /* The number of rows of m1 and m12 */, 
	      int m /* The number of columns of m1 and the number of rows of m2 */, 
	      int l /* The number of columns of m2 and m12 */);
/* Multiplies the matrices m1 and m2 and stores the result in m12 
   <BR> the three matrices must be of same size n x m <BR> 
   and must  have been previously allocated */

void invert_mat4 (MAT m /* The 4  x 4 matrix to be inverted */, 
		  MAT inv_m /* The 4  x 4 inverse matrix of m */);
/* Inverse  the 4  x 4 matrix m and stores the result in inv_m
    <BR> produces a exit(-1) when the determinant is close to zero */

void invert_mat3 (MAT m/* The 3  x 3 matrix to be inverted */,
		  MAT inv_m /* The 3  x 3 inverse matrix of m */);
/* Inverse  the 3  x 3 matrix m and stores the result in inv_m
    <BR> produces a exit(-1) when the determinant is close to zero */

void compute_eigen_vector (MAT m/* The symmetric matrix of size n x n*/ , 
			   int n /* The size of the matrix */, 
			   MAT eigenvec /* The array of eigen vectors */, 
			   double *eigenval /* The array of eigenvalues */);
/* use the Jacobi method to compute the eigenvalues and eigenvectors  <BR>
   of the symmteric matrix m of size n x n */

void print_matrix (MAT mat /* The matrix of size n x m to be printed */, 
		   int n /* The number of rows  */, 
		   int m /* The number of columnss  */);
/* Prints on stderr the values of matrix mat */

void mul_scal_mat (MAT mat  /* The matrix of size n x m to be scaled */, 
		   double k /* The scale factor */, 
		   int n/* The number of rows  */, int m/* The number of columns  */);
/* Multiplies each element of matrix mat by scalar k <BR> Stores the result in mat */

void div_scal_mat (MAT mat/* The matrix of size n x m to be scaled */ , 
		   double k /* The scale factor */, 
		   int n/* The number of rows  */, int m/* The number of columns  */);
/* Divides each element of matrix mat by scalar k <BR> Stores the result in mat */

VECT spherical  (double r /* Radius*/,double phi /* Polar angle */, double theta/* The azimuth*/);
/* Return a 3D vector given its spherical coordinates <BR> phi is between [-Pi, +Pi]  
   <BR>  theta is between [-Pi/2. +Pi/2] */

VECT add_vect (VECT v1 /* First vector operand */,VECT /* Second vector operand */);
/* Adds vector v2 with v1 and returns the sum */

VECT diff_vect (VECT v1/* First vector operand */,VECT v2  /* Second vector operand */);
/* Substracts vector v2 to v1 and returns the difference */

VECT div_vect (VECT v /* Vector to be scaled */,double d /* scaling factor */);
/* Divides each component of v by d and returns the result */

VECT mul_vect (VECT v /* Vector to be scaled */,double d /* scaling factor */);
/* Multiplies each component of v by d and returns the result */

void addeq_vect (VECT *v1 /* The pointer of the vector to be incremented */,
		 VECT v2 /* The operand */);
/* Increments vector v1 by vector v2 <BR> Equivalent to v1+=v2 */


void diffeq_vect (VECT *v1 /* The pointer of the vector to be incremented */,
		  VECT v2 /* The operand */);
/* Decrements vector v1 by vector v2 <BR> Equivalent to v1-=v2 */

void muleq_vect (VECT *v1/* The pointer of the vector to be scaled */,
		 double d/* The scale factor */);
/* Multiplies each component of  vector v1 by d <BR> Equivalent to v1*=d */

void diveq_vect (VECT *v1/* The pointer of the vector to be scaled */,
		 double d/* The scale factor */);
/* Divides each component of  vector v1 by d <BR> Equivalent to v1/=d */

VECT opposite_vect (VECT v /* The operand */ );
/* Returns the opposite of vector v */

VECT abs_vect (VECT v /* The operand */);
/* Returns a vector whose coordinates are <BR> the absolute value of the coordinates of v */

double norm_vect (VECT v /* The operand */);
/* Returns the euclidean norm of vector v */

double norm_sqr (VECT v /* The input vector */);
/* Returns the square of the euclidean norm of vector v */

VECT vectorial_product (VECT v1 /* The first operand */,
			VECT v2 /* The second operand */);
/* Returns the vectorial product (cross-product) of v1 and v2 */

VECT normal_vect (VECT v1 /* The first operand */ ,
		  VECT v2 /* The second operand */);
/* return the normal vector of v1 and v2  <BR> First computes the vectorial product v1 x v2 <BR>
   Then divides the result with the norm of the vectorial  product 
   <BR> Return vect_null() is the  two vectors are colinear */

double dot_product (VECT v1 /* The first operand */,VECT v2  /* The second operand */);
/* returns the dot product of v1 and v2 */

double triple_product (VECT v1/* The first operand */,
		       VECT v2/* The second operand */,
		       VECT v3/* The third operand */);
/* Computes the triple product between v1, v2 and v3  <BR> 
   it is computed as the determinant of the matrix made of the three columns vectors */

void print_vect (VECT v/* a 3D vector */);
/* Prints on Stdout the 3 components of v */

VECT vect_coordinates (double x /* First coordinate */,
		       double y /* Second coordinate */ ,
		       double z /* Third coordinate */);
/* Return vector of coordinate (x,y,z) */

VECT normalized_vect (VECT v /* A 3D vector */);
/* Returns the vector of euclidean norm 1 having the same direction as v  <BR> 
   Do not check if the vector is null  <BR> May cause a segmentation fault */

double max_coordinate (VECT v  /* A 3D vector */);
/* Returns the maximum of the three coordinates of v */

void make_rotation_vect (VECT axis /* Axis of rotation . It must be of euclidean norm 1 */,
			 double angle /* Angle of rotation in radian */,
			 VECT *v0 /* Pointer towards the vector rotation of first axis (x)*/ ,
			 VECT *v1 /* Pointer towards the vector rotation of second axis (y)*/,
			 VECT *v2 /* Pointer towards the vector rotation of third axis (z)*/);
/* Transforms a rotation vector into a matrix of rotation  <BR> 
   The rotation is given by its axis and the angle of rotation  <BR>  
   The rotation matrix is stored with the image of the three axis (x,y,z) <BR> 
   (v0,v1,v2) are the three lines of the associated rotation matrix */

BOOLEAN equal_vect (VECT v1 /* First operand */,
		    VECT v2/* First operand */);
/* returns true if v1==v2; false otherwise */


/* ==================================*/
/*Definition of procedures in vect2D.c*/
/* ==================================*/

VECT2D add_vect2D (VECT2D v1 /* The first operand */,VECT2D v2 /* The second operand */);
/* Returns the sum  v1 + v2 */

VECT2D diff_vect2D (VECT2D v1 /* The first operand */,VECT2D v2 /* The second operand */);
/* Returns the difference  v1 + v2 */

VECT2D div_vect2D (VECT2D v1 /* The 2D vector to be scaled*/ ,double k /* The scale factor */);
/* Divides the coordinates of v1 by k and returns the result */

VECT2D mul_vect2D (VECT2D v1 /* The 2D vector to be scaled*/,double k /* The scale factor */);
/* Multiplies the coordinates of v1 by k and returns the result */

void addeq_vect2D (VECT2D *v1 /* The pointer of the vector to be incremented */,VECT2D v2 /* The operand */);
/* Increments vector v1 by vector v2 <BR> Equivalent to v1+=v2 */

void diffeq_vect2D (VECT2D *v1 /* The pointer of the vector to be decremented */,
		    VECT2D v2 /* The operand */);
/* Decrements vector v1 by vector v2 <BR> Equivalent to v1-=v2 */

void muleq_vect2D (VECT2D *v1/* The pointer of the vector to be scaled */,
		   double d/* The scale factor */);
/* Multiplies each component of  vector v1 by d <BR> Equivalent to v1*=d */

void diveq_vect2D (VECT2D *v1/* The pointer of the vector to be scaled */,
		   double d/* The scale factor */);

VECT2D opposite_vect2D (VECT2D v /* The operand */);
/* Returns the opposite of vector v */

VECT2D abs_vect2D (VECT2D v /* The operand */);
/* Returns a vector whose coordinates are <BR> the absolute value of the coordinates of v */

double norm_vect2D (VECT2D v /* The operand */);
/* Returns the euclidean norm of vector v */

double norm_sqr2D (VECT2D v /* The input vector */);
/* Returns the square of the euclidean norm of vector v */

VECT2D orthogonal_vect2D (VECT2D v /* a 2D Vector */);
/* Returns the vector with the same norm than v <BR> 
   and directly orthogonal to v */

double dot_product2D (VECT2D v1 /* The first operand */,VECT2D v2  /* The second operand */);
/* returns the dot product of v1 and v2 */

void print_vect2D (VECT2D v/* a 2D vector */);
/* Prints on Stdout the 3 components of v */

VECT2D vect2D_coordinates (double x /* First coordinate */,double y /* Second coordinate */);
/* Return vector of coordinate (x,y) */

VECT2D normalized_vect2D (VECT2D v /* A 2D vector */);
/* Returns the vector of euclidean norm 1 having the same direction as v  <BR> 
   Do not check if the vector is null  <BR> May cause a segmentation fault */

double max_coordinate2D (VECT2D v  /* A 2D vector */);
/* Returns the maximum of the three coordinates of v */

BOOLEAN equal_vect2D (VECT2D v1 /* First operand */,VECT2D v2/* First operand */);
/* returns true if v1==v2; false otherwise */

/* In libperso.c */
void cramer (float a00 /* element of the matrix A[0][0] */,
	     float a01 /* element of the matrix A[0][1] */,
	     float b0 /* first coordinate of B[0] */,
	     float a10 /* element of the matrix A[1][0] */,
	     float a11 /* element of the matrix A[1[1] */,
	     float b1 /* second coordinate of B[1] */,
	     float *x1 /* first coordinate of the solution X[0]*/,
	     float *x2 /* second coordinate of the solution X[1]*/);
/* Compute the solution of the 2x2 linear system A X = B  <BR>
   All parameters are considered as floats  <BR> Do not check if the determinant is null */

double dcramer (double a00 /* element of the matrix A[0][0] */,
		double a01 /* element of the matrix A[0][1] */,
		double b0 /* first coordinate of B[0] */,
		double a10 /* element of the matrix A[1][0] */,
		double a11 /* element of the matrix A[1[1] */,
		double b1 /* second coordinate of B[1] */,
		double *x1 /* first coordinate of the solution X[0]*/,
		double *x2 /* second coordinate of the solution X[1]*/);
/* Compute the solution of the 2x2 linear system A X = B  <BR>
   All parameters are considered as double  <BR> Do not check if the determinant is null */

void polynom_2degre_solution(double a/* coefficient of the monomial of 2nd order*/,
			     double b/* coefficient of the monomial of 1st order*/,
			     double c/* coefficient of the monomial of 0th order*/,
			     double *x1 /* First root*/,
			     double *x2 /* Second root */,
			     int *nb_roots/* The number of roots*/);
/* Computes the roots of the polynom of 2nd order : ax*x+b*x+c=0  <BR> 
   Stores the number of roots in nb_roots and the roots in x1 and x2 */

int max_list(int *list /* The array of integer values */,
	     int size/* The number of items in list */);
/* returns the max value of the array  of integers */

int min_list(int *list /* The array of integer values */,
	     int size/* The number of items in list */);
/* returns the min value of the array  of integers */

int mean_list(int *list /* The array of integer values */,
	      int size/* The number of items in list */);
/* returns the mean value of the array  of integers */

int median_list(int *list /* The array of integer values */,
		int size/* The number of items in list */);
/* returns the median value of the array  of integers */

double median_dlist(double *list /* The array of double values */,
		    int size/* The number of items in list */);
/* returns the median value of the array of doubles */

void give_main_direction(int drow /* Gives the direction in row drow= row2- row1*/,
			 int dcol /* Gives the direction in col dcol= col2- col1*/,
			 int *direction /* the computed direction closer to (drow,dcol) */,
			 int *second_direction/* the other direction closer to (drow,dcol) */);
/* Given a direction (drow,dcol) returns two indices of the two closest direction <BR>
   This is used in the 2D Bresenham line drawing algorithm <BR>
   The direction indices  are related to the following array <BR>
static int direction[2][16] = { <BR>
  { 0 ,-1,-1,-2,-1,-2,-1,-1,0,1,1,2,1,2 ,1 ,1 }, <BR>
  { -1,-2,-1,-1,0 ,1 ,1 ,2 ,1,2,1,1,0,-1,-1, -2} <BR>
}; */

int sign(int val/* any integer*/);
/* Returns the sign of val  <BR> 1 if (val &gt 0)  <BR> -1 if (val &lt 0)  <BR> 0 if (val == 0) */

double  signd(double val /* any double*/);
/* Returns as double the sign of val  <BR> 1 if (val &gt 0)  <BR> -1 if (val &lt 0)  <BR> 0 if (val == 0) */

int myfloor(double val /* any double*/ );
/* Returns (int) val if (val &get 0) and ((int) val) - 1 if (val &lt 0) <BR>
   used because there are many problems with the floor function (due to rint()) */

void ConvertShorts(unsigned int *array/* any array of shorts stored in an array of unsigned int */,
		   long size/* The number of shorts in the array */);
/* Swap the bytes of an array of short stored in an array of ints <BR>
Used for conversion Little Endian <--> Big Endian */

void ConvertShorts2(unsigned short *array/* any array of shorts */, 
		    long size/* The number of shorts in the array */);
/* Swap the bytes of an array of shorts  <BR>
Used for conversion Little Endian <--> Big Endian */


void ConvertLongs(unsigned int *array/* any array of ints (32 bits) */, 
		  long size/* The number of ints in the array */);
/* Swap the bytes of an array of ints  <BR>
Used for conversion Little Endian <--> Big Endian */

char *check_file_extension(char *name/* file name*/, 
			   char *extension /* Extension to be removed */);
/* Check if the string name ends with the suffix extension. <BR>
   If it is the case, removes the suffix from the string name (puts a \0) */

/* kd_tree.c */
void create_kd_tree (PTRKD_TREE kd1 /* The kd_tree to be created*/,
		     int max_dimension/* The dimension to be used for the creation of the kd-tree (3 or 6 )*/);
/* Given a kd-tree with its node, build the efficient data structure <BR>
   for finding the closest point <BR> The dimension of the data structure is controlled by max_dimension */

void free_kd_tree (PTRKD_TREE kd1/* Any kd-tree*/);
/* Free kd1 and its nodes */

PTRKD_TREE kd_tree_alloc ();
/* Allocate the memory for the structure kd-tree */

void add_temp_item_position(PTRKD_TREE kd1 /* A kd-tree*/,
			    VECT position /* A 3D position vector */, 
			    int row /* eventually store the row index associated with position */,
			    int col/* eventually store the column index associated with position */);
/* Create a node associated with the vector position <BR> 
   store as additional information the (row,col) associated with vector position <BR>
   This is essentially useful for range images */

void add_temp_item_position_normal (PTRKD_TREE kd1/* A kd-tree*/,
				    VECT position /* A 3D position vector */, 
				    VECT normal /* A 3D normal vector */, 
				    int row /* eventually store the row index associated with position */, 
				    int col /* eventually store the column index associated with position */);
/* Create a node associated with the two vectors position and normal<BR> 
   store as additional information the (row,col) associated with vector position <BR>
   This is essentially useful for range images */

BOOLEAN search_closest_point_kd_tree(PTRKD_TREE kd1 /* A kd-tree*/,
				     VECT position /* The position from which we compute the distance */,
				     VECT normal /* The normal vector from which we compute the distance */, 
				     double radius /* The maximum radius at which we are searching */,
				     int *row /* The row index of the closest point */, 
				     int *col /*The col index of the closest point */);
/* Returns the indices (row,col) of the closest point from (position,normal) <BR>
   if (kd1->dimension==3) then it only uses the position information <BR>
   radius is used as a bound on the maximum distance from (position,normal) <BR>
   if there are no points such that its distance is less than radius then returns false <BR>
   else returns true */


/* array.c */
long int **create_long_int_array(int nrows /*number of rows*/, int ncols /* number of columns*/);
/* Returns a 2D array of long integer <BR>
 It is allocated with macro CREATE_ARRAY2D <BR>
 as two memory blocs : one for the array of pointers <BR>
 one for the array of data <BR>
 Therefore must be freed with  free(array[0][0]) and free(array) */

int **create_int_array(int nrows /*number of rows*/, int ncols /* number of columns*/);
/* Returns a 2D array of (signed) integer <BR>
 It is allocated with macro CREATE_ARRAY2D <BR>
 as two memory blocs : one for the array of pointers <BR>
 one for the array of data <BR>
 Therefore must be freed with  free(array[0][0]) and free(array) */

unsigned short int **create_short_int_array(int nrows /*number of rows*/, int ncols /* number of columns*/);
/* Returns a 2D array of unsigned short integer <BR>
 It is allocated with macro CREATE_ARRAY2D <BR>
 as two memory blocs : one for the array of pointers <BR>
 one for the array of data <BR>
 Therefore must be freed with  free(array[0][0]) and free(array) */

float **create_float_array(int nrows /*number of rows*/, int ncols /* number of columns*/);
/* Returns a 2D array of floats <BR>
 It is allocated with macro CREATE_ARRAY2D <BR>
 as two memory blocs : one for the array of pointers <BR>
 one for the array of data <BR>
 Therefore must be freed with  free(array[0][0]) and free(array) */

double **create_double_array(int nrows /*number of rows*/, int ncols /* number of columns*/);
/* Returns a 2D array of double <BR>
 It is allocated with macro CREATE_ARRAY2D <BR>
 as two memory blocs : one for the array of pointers <BR>
 one for the array of data <BR>
 Therefore must be freed with  free(array[0][0]) and free(array) */

unsigned char **create_char_array(int nrows /*number of rows*/, int ncols /* number of columns*/);
/* Returns a 2D array of char <BR>
 It is allocated with macro CREATE_ARRAY2D <BR>
 as two memory blocs : one for the array of pointers <BR>
 one for the array of data <BR>
 Therefore must be freed with  free(array[0][0]) and free(array) */

unsigned short int  ***create_short_volume_array(int nrows /*number of rows*/, 
						 int ncols /* number of columns*/, 
						 int nplanes /* the number of slices */);
/* Returns a 3D array of short integer <BR>
   It is allocated with macro CREATE_ARRAY3D <BR>
   as two memory blocs : one for the array of pointers <BR>
   one for the array of data <BR>
   Therefore must be freed with  free(array[0][0][0]) and free(array) */

int  ***create_int_volume_array(int nrows /*number of rows*/,
				int ncols /* number of columns*/, 
				int nplanes /* the number of slices */);
/* Returns a 3D array of integer <BR>
   It is allocated with macro CREATE_ARRAY3D <BR>
   as two memory blocs : one for the array of pointers <BR>
   one for the array of data <BR>
   Therefore must be freed with  free(array[0][0][0]) and free(array) */

unsigned char  ***create_char_volume_array(int nrows /*number of rows*/, 
					   int ncols /* number of columns*/, 
					   int nplanes /* the number of slices */);
/* Returns a 3D array of char <BR>
   It is allocated with macro CREATE_ARRAY3D <BR>
   as two memory blocs : one for the array of pointers <BR>
   one for the array of data <BR>
   Therefore must be freed with  free(array[0][0][0]) and free(array) */

double  ***create_double_volume_array(int nrows /*number of rows*/, 
				      int ncols /* number of columns*/, 
				      int nplanes /* the number of slices */);
/* Returns a 3D array of double <BR>
   It is allocated with macro CREATE_ARRAY3D <BR>
   as two memory blocs : one for the array of pointers <BR>
   one for the array of data <BR>
   Therefore must be freed with  free(array[0][0][0]) and free(array) */


float  ***create_float_volume_array(int nrows /*number of rows*/, 
				    int ncols /* number of columns*/, 
				    int nplanes /* the number of slices */);
/* Returns a 3D array of float <BR>
   It is allocated with macro CREATE_ARRAY3D <BR>
   as two memory blocs : one for the array of pointers <BR>
   one for the array of data <BR>
   Therefore must be freed with  free(array[0][0][0]) and free(array) */


long int  ***create_long_int_volume_array(int nrows /*number of rows*/, 
					  int ncols /* number of columns*/, 
					  int nplanes /* the number of slices */);
/* Returns a 3D array of long integer <BR>
   It is allocated with macro CREATE_ARRAY3D <BR>
   as two memory blocs : one for the array of pointers <BR>
   one for the array of data <BR>
   Therefore must be freed with  free(array[0][0][0]) and free(array) */

/* interaction.c */
void set_matrix_identity(MATRIX m/* A matrix*/);
/* set matrix m to identity */

void set_array_identity(ROTATION R/* A rotation matrix */);
/* set rotation matrix R to identity */

void update_rotation (ROTATION R1/* A rotation matrix*/,
		      ROTATION R2/* Another rotation matrix */);
/* Multiplies the two rotation matrices R1 and R2 and store <BR> 
   the result in R1 */

VECT rotate_vector (VECT v /* A 3D vector */, ROTATION  R/* A rotation matrix */);
/* Returns the vectorial rotation of v by rotation matrix R */

void get_screen_rotation(ROTATION  R/* A rotation matrix */,
			 double angle_x /* The angle of rotation around X (in degrees)*/,
			 double angle_y /* The angle of rotation around Y (in degrees)*/,
			 double angle_z /* The angle of rotation around Z (in degrees)*/);
/* Writes in R, the rotation matrix corresponding to angle around X,Y,Z axis*/

void get_world_rotation (MATRIX M/* The 4 x 4 matrix (used in OpenGL) */,
			 ROTATION R1 /* A given rotation matrix*/,
			 ROTATION R2 /* The resulting rotation matrix */);
/* Computes R2= M * M1 * M1t where M1t is the transposed matrix of M <BR>
   R2 is the rotation matrix in the world coordinates (linked to M) <BR>
   while R1 us the rotation matrix in the screen coordinate */

void moment_to_rotation (VECT v/* a rotation vector*/,
			 ROTATION R /* The resulting rotation matrix */);
/* Transforms the rotation vector v into a rotation matrix R <BR>
   the axis of rotation is given by normalized_vect(v) and <BR>
   the angle by norm_vect(v) */

void update_modeling_matrix (MATRIX M /* The matrix to be updated */,
			     ROTATION R /* The rotation to apply on M */);
/* Computes M = M * R <BR>
   used for rotation the modeling matrix M */

VECT map_to_screen (VECT T /* A 3D vector */,
		    MATRIX M /* The modeling matrix */);
/* Returns M*T  where T is a 4D vector (Tx,Ty,Tz,0.0)*/

/*----------------------------- io_format.c -------------------------*/
Type_List_Ptr CreateTypeList ();
/* Create a new list of Object_Type elements */

void DeleteTypeList (Type_List_Ptr list);
/* Delete a list of Object_Type elements */

Type_List_Elt_Ptr FirstListElt (Type_List_Ptr list /* list */);
/* Returns first element of list */

Type_List_Elt_Ptr LastListElt (Type_List_Ptr list /* list */);
/* Returns last element of list */

void AddTypeListElt (Type_List_Ptr list /* list to be extended */,
		     Object_Type object /* object to add to list */);
/* Add new element to list if it does not already exist in it */

void RemoveTypeListElt (Type_List_Ptr list /* list to be shrinked */,
			Type_List_Elt_Ptr object /* object element to remove */);
/* Remove an element from list if it can be found in it */


BOOLEAN FlexPrintf (FILE * file /* file pointer */, 
		    Write_Mode wmode /* either binary or ASCII*/, 
		    char *string /* a format string indicating what to print : use the same syntax as fprintf ()*/, ...);
/* Prints a certain number of parameters that are controled by the format string : use the same syntax as fprintf() */


void WriteInt (FILE * file /* file pointer */,  
	       Write_Mode wmode /* either binary or ASCII*/, int val);
/* write an integer in a file */

void WriteUnsignedInt (FILE * file /* file pointer */,  
		    Write_Mode wmode /* either binary or ASCII*/, unsigned int val );
/* write an unsigned integer in a file */

void WriteOctal (FILE * file /* file pointer */,  
		    Write_Mode wmode /* either binary or ASCII*/, int val );
/* write an octal integer in a file */

void WriteHexa (FILE * file /* file pointer */,  
		    Write_Mode wmode /* either binary or ASCII*/, int val );
/* write an hexadecimaal value in a file */

void WriteHEXA (FILE * file /* file pointer */,  
		    Write_Mode wmode /* either binary or ASCII*/, int val );
/* write an haxadecimaal value with capital letters in a file */

void WriteFloat (FILE * file /* file pointer */,  
		    Write_Mode wmode /* either binary or ASCII*/, double val );
/* write a float value in a file */

void WriteExp (FILE * file /* file pointer */,  
		    Write_Mode wmode /* either binary or ASCII*/, double val );
/* write a exponential value in a file */

void WriteEXP (FILE * file /* file pointer */,  
		    Write_Mode wmode /* either binary or ASCII*/, double val );
/* write a exponential value with capital letters in a file */

void WriteUnsignedChar (FILE * file /* file pointer */,  
		    Write_Mode wmode /* either binary or ASCII*/, int val );
/* write an unsigned char value in a file */

void WriteASCIIUnsignedChar (FILE * file /* file pointer */,  
		    Write_Mode wmode /* either binary or ASCII*/, int val );
/* write an ASCII unsigned char value in a file */

void WriteString (FILE * file /* file pointer */,  
		    Write_Mode wmode /* either binary or ASCII*/, char *val );
/* write a string  value in a file */

void WritePointer (FILE * file /* file pointer */,  
		    Write_Mode wmode /* either binary or ASCII*/, void *val );
/* write a pointer (memory address) value in a file */

void WriteLongInt (FILE * file /* file pointer */,  
		    Write_Mode wmode /* either binary or ASCII*/, long int val );
/* writes a long integer value in a file */

void WriteUnsignedLongInt (FILE * file /* file pointer */,  
		    Write_Mode wmode /* either binary or ASCII*/, unsigned long int val );
/* writes an unsigned  long integer value in a file */

void WriteLongOctal (FILE * file /* file pointer */,  
		    Write_Mode wmode /* either binary or ASCII*/, long int val );
/* writes a long ioctal integer value in a file */

void WriteLongHexa (FILE * file /* file pointer */,  
		    Write_Mode wmode /* either binary or ASCII*/, long int val );
/* writes a long hexadecimal  integer value in a file */

void WriteLongHEXA (FILE * file /* file pointer */,  
		    Write_Mode wmode /* either binary or ASCII*/, long int val );
/* writes a long hexadecimal  integer with capital letters value in a file */

void WriteDouble (FILE * file /* file pointer */,  
		    Write_Mode wmode /* either binary or ASCII*/, double val );
/* writes a double  floating point value in a file */

void WriteShortInt (FILE * file /* file pointer */,  
		    Write_Mode wmode /* either binary or ASCII*/, short int val );
/* writes a short integer value in a file */

void WriteUnsignedShortInt (FILE * file /* file pointer */,  
		    Write_Mode wmode /* either binary or ASCII*/, unsigned short int val );
/* writes an unsigned short integer value in a file */

void WriteShortOctal (FILE * file /* file pointer */,  
		    Write_Mode wmode /* either binary or ASCII*/, short int val );
/* writes a short octal integer value in a file */

void WriteShortHexa (FILE * file /* file pointer */,  
		    Write_Mode wmode /* either binary or ASCII*/, short int val );
/* writes a short hexadecimal  integer value in a file */

void WriteShortHEXA (FILE * file /* file pointer */,  
		    Write_Mode wmode /* either binary or ASCII*/, short int val );
/* writes a short hexadecimal  integer with capital letters value in a file */


BOOLEAN FlexScanf (FILE * file /* file pointer */,  
		    Write_Mode wmode /* either binary or ASCII*/, 
		   int swap  /* whether the bytes should be swapped*/ , 
		   char *string /* a string indicating what to scan with the same format as scanf*/
		   , ... /* a variable number of arguments */);
/* scan in a file for a certain number of parameters that are stored in a list val. 
   Use the same syntax as fscanf() */

void Swap (void *ptr /* a pointer of an chunk of memory */, 
	   unsigned int size /* the size of the block of memory. The size must be an even number  */ );
/* swaps the bytes of a block of a given size. Used when having binary data of whrong endianness */

void ReadInt (FILE * file /* file pointer */,  
		    Write_Mode wmode /* either binary or ASCII*/, BOOLEAN swap /* whether the bytes should be swapped*/, int *val );
/* read an integer in a file */

void ReadUnsignedInt (FILE * file /* file pointer */,  
		    Write_Mode wmode /* either binary or ASCII*/, BOOLEAN swap /* whether the bytes should be swapped*/, unsigned int *val );
/* read an unsigned integer in a file */

void ReadOctal (FILE * file /* file pointer */,  
		    Write_Mode wmode /* either binary or ASCII*/, BOOLEAN swap /* whether the bytes should be swapped*/, int *val );
/* read an octal integer in a file */

void ReadHexa (FILE * file /* file pointer */,  
		    Write_Mode wmode /* either binary or ASCII*/, BOOLEAN swap /* whether the bytes should be swapped*/, int *val );
/* read an haxadecimaal value in a file */

void ReadFloat (FILE * file /* file pointer */,  
		    Write_Mode wmode /* either binary or ASCII*/, BOOLEAN swap /* whether the bytes should be swapped*/, float *val );
/* read a float value in a file */

void ReadUnsignedChar (FILE * file /* file pointer */,  
		    Write_Mode wmode /* either binary or ASCII*/, BOOLEAN swap /* whether the bytes should be swapped*/, unsigned char *val );
/* read an unsigned char value in a file */

void ReadString (FILE * file /* file pointer */,  
		    Write_Mode wmode /* either binary or ASCII*/, char *val );
/* read a string  value in a file */

void ReadPointer (FILE * file /* file pointer */,  
		    Write_Mode wmode /* either binary or ASCII*/, BOOLEAN swap /* whether the bytes should be swapped*/, void **val );
/* read a pointer (memory address) value in a file */

void ReadLongInt (FILE * file /* file pointer */,  
		    Write_Mode wmode /* either binary or ASCII*/, BOOLEAN swap /* whether the bytes should be swapped*/, long int *val );
/* reads a long integer value in a file */

void ReadUnsignedLongInt (FILE * file /* file pointer */,  
		    Write_Mode wmode /* either binary or ASCII*/, BOOLEAN swap /* whether the bytes should be swapped*/,
			       unsigned long int *val );
/* reads an unsigned  long integer value in a file */

void ReadLongOctal (FILE * file /* file pointer */,  
		    Write_Mode wmode /* either binary or ASCII*/, BOOLEAN swap /* whether the bytes should be swapped*/, long int *val );
/* reads a long ioctal integer value in a file */

void ReadLongHexa (FILE * file /* file pointer */,  
		    Write_Mode wmode /* either binary or ASCII*/, BOOLEAN swap /* whether the bytes should be swapped*/, long int *val );
/* reads a long hexadecimal  integer value in a file */

void ReadDouble (FILE * file /* file pointer */,  
		    Write_Mode wmode /* either binary or ASCII*/, BOOLEAN swap /* whether the bytes should be swapped*/, double *val );
/* reads a double  floating point value in a file */

void ReadShortInt (FILE * file /* file pointer */,  
		    Write_Mode wmode /* either binary or ASCII*/, BOOLEAN swap /* whether the bytes should be swapped*/, short int *val );
/* reads a short integer value in a file */

void ReadUnsignedShortInt (FILE * file /* file pointer */,  
		    Write_Mode wmode /* either binary or ASCII*/, BOOLEAN swap /* whether the bytes should be swapped*/,
			   unsigned short int *val );
/* reads an unsigned short integer value in a file */

void ReadShortOctal (FILE * file /* file pointer */,  
		     Write_Mode wmode /* either binary or ASCII*/, BOOLEAN swap /* whether the bytes should be swapped*/, short int *val );
/* reads a short octal integer value in a file */

void ReadShortHexa (FILE * file /* file pointer */,  
		    Write_Mode wmode /* either binary or ASCII*/, BOOLEAN swap /* whether the bytes should be swapped*/, short int *val );
/* reads a short hexadecimal  integer value in a file */

void ReadASCIIUnsignedChar (FILE * file /* file pointer */,  
			    Write_Mode wmode /* either binary or ASCII*/, char val );   
/* read an ASCII unsigned char value in a file */


#ifdef __cplusplus
}
#endif

#endif





