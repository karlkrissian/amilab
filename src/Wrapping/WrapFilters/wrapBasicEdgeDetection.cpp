/*
 *  wrapBasicEdgeDetection.cpp
 *  AMILab
 *
 *  Created by administrador on 09/03/10.
 *  
 *	Some tests of basic edge detection filters
 *
 */

#include "wrapBasicEdgeDetection.h"
#include "wrapfunctions.hpp"
#include <cmath>
#include "inrimage.hpp"
#include "paramlist.h"

//Auxiliar procedure for convolve an InrImage (2D)
void convolve2DImage(InrImage *input, InrImage::ptr& output, float m[3][3])
{
	int h, w;
	int width = input->DimX();
	int height = input->DimY();
	float value;
	for (h=0;h<height;h++) // row
    {
    	for (w=0;w<width;w++) // colum = w+h*wdth
			{
				value = 0;
				if ((w >= 1) && (w < width-1) && (h >=1) && (h < height-1)) //Caso general, en el interior de la imagen
				{
					value=  ((*input)(w-1, h-1, 0))*m[0][0];//1
					value+= ((*input)(w,   h-1, 0))*m[0][1];//2
					value+= ((*input)(w+1, h-1, 0))*m[0][2];//3
					value+= ((*input)(w-1, h,   0))*m[1][0];//4
					value+= ((*input)(w,   h,   0))*m[1][1];//5
					value+= ((*input)(w+1, h,   0))*m[1][2];//6
					value+= ((*input)(w-1, h+1, 0))*m[2][0];//7
					value+= ((*input)(w,   h+1, 0))*m[2][1];//8
					value+= ((*input)(w+1, h+1, 0))*m[2][2];//9
				}
				else //Tratamiento de los bordes y las esquinas. Está marcado con * los elementos que "se salen por fuera"
				{
					if ((w == 0) && (h == 0)) // Esquina superior izquierda.
					{
						value=  ((*input)(w,   h,		0))*m[0][0];//1*
						value+= ((*input)(w,   h,		0))*m[0][1];//2*
						value+= ((*input)(w+1, h,		0))*m[0][2];//3*
						value+= ((*input)(w,   h,		0))*m[1][0];//4*
						value+= ((*input)(w,   h,		0))*m[1][1];//5
						value+= ((*input)(w+1, h,		0))*m[1][2];//6
						value+= ((*input)(w,   h+1, 0))*m[2][0];//7*
						value+= ((*input)(w,   h+1, 0))*m[2][1];//8
						value+= ((*input)(w+1, h+1, 0))*m[2][2];//9
					}
					if ((w == width-1) && (h == 0)) // Esquina superior derecha.
					{
						value=  ((*input)(w-1, h,		0))*m[0][0];//1*
						value+= ((*input)(w,   h,		0))*m[0][1];//2*
						value+= ((*input)(w,   h,		0))*m[0][2];//3*
						value+= ((*input)(w-1, h,		0))*m[1][0];//4
						value+= ((*input)(w,	 h,		0))*m[1][1];//5
						value+= ((*input)(w,   h,   0))*m[1][2];//6*
						value+= ((*input)(w-1, h+1, 0))*m[2][0];//7
						value+= ((*input)(w,   h+1, 0))*m[2][1];//8
						value+= ((*input)(w,   h+1, 0))*m[2][2];//9*
					}
					if ((h == height-1) && (w == 0)) // Esquina inferior izquierda.
					{
						value=  ((*input)(w,   h-1, 0))*m[0][0];//1*
						value+= ((*input)(w,   h-1, 0))*m[0][1];//2
						value+= ((*input)(w+1, h-1, 0))*m[0][2];//3
						value+= ((*input)(w,   h,   0))*m[1][0];//4*
						value+= ((*input)(w,   h,   0))*m[1][1];//5
						value+= ((*input)(w+1, h,   0))*m[1][2];//6
						value+= ((*input)(w,   h,   0))*m[2][0];//7*
						value+= ((*input)(w,   h,   0))*m[2][1];//8*
						value+= ((*input)(w+1, h,   0))*m[2][2];//9*                       
					}
					if ((h == height-1) && (w == width-1)) // Esquina inferior derecha.
					{
						value=  ((*input)(w-1, h-1, 0))*m[0][0];//1
						value+= ((*input)(w,   h-1, 0))*m[0][1];//2
						value+= ((*input)(w,   h-1, 0))*m[0][2];//3*
						value+= ((*input)(w-1, h,   0))*m[1][0];//4
						value+= ((*input)(w,   h,   0))*m[1][1];//5
						value+= ((*input)(w,   h,   0))*m[1][2];//6*
						value+= ((*input)(w-1, h,   0))*m[2][0];//7*
						value+= ((*input)(w,   h,   0))*m[2][1];//8*
						value+= ((*input)(w,   h,   0))*m[2][2];//9*
					}
					if ((h == 0) && (w < width-1) && (w > 0)) // Borde superior.
					{
						value=  ((*input)(w-1, h,   0))*m[0][0];//1*
						value+= ((*input)(w,   h,   0))*m[0][1];//2*
						value+= ((*input)(w+1, h,   0))*m[0][2];//3*
						value+= ((*input)(w-1, h,   0))*m[1][0];//4
						value+= ((*input)(w,   h,   0))*m[1][1];//5
						value+= ((*input)(w+1, h,   0))*m[1][2];//6
						value+= ((*input)(w-1, h+1, 0))*m[2][0];//7
						value+= ((*input)(w,   h+1, 0))*m[2][1];//8
						value+= ((*input)(w+1, h+1, 0))*m[2][2];//9
					}
					if ((h == height-1) && (w > 0) && (w < width-1)) // Borde inferior.
					{
						value=  ((*input)(w-1, h-1, 0))*m[0][0];//1
						value+= ((*input)(w,   h-1, 0))*m[0][1];//2
						value+= ((*input)(w+1, h-1, 0))*m[0][2];//3
						value+= ((*input)(w-1, h,   0))*m[1][0];//4
						value+= ((*input)(w,   h,   0))*m[1][1];//5
						value+= ((*input)(w+1, h,   0))*m[1][2];//6
						value+= ((*input)(w-1, h,   0))*m[2][0];//7*
						value+= ((*input)(w,   h,   0))*m[2][1];//8*
						value+= ((*input)(w+1, h,   0))*m[2][2];//9*
					}
					if ((h != 0) && (h < height-1) && (w == 0)) // Borde izquierdo.
					{
						value=  ((*input)(w,   h-1, 0))*m[0][0];//1*
						value+= ((*input)(w,   h-1, 0))*m[0][1];//2
						value+= ((*input)(w+1, h-1, 0))*m[0][2];//3
						value+= ((*input)(w,   h,   0))*m[1][0];//4*
						value+= ((*input)(w,   h,   0))*m[1][1];//5
						value+= ((*input)(w+1, h,   0))*m[1][2];//6
						value+= ((*input)(w,   h+1, 0))*m[2][0];//7*
						value+= ((*input)(w,   h+1, 0))*m[2][1];//8
						value+= ((*input)(w+1, h+1, 0))*m[2][2];//9                        
					}
					if ((h != 0) && (h < height-1) && (w == width-1)) // Borde derecho.
					{
						value=  ((*input)(w-1, h-1, 0))*m[0][0];//1
						value+= ((*input)(w,   h-1, 0))*m[0][1];//2
						value+= ((*input)(w,   h-1, 0))*m[0][2];//3*
						value+= ((*input)(w-1, h,   0))*m[1][0];//4
						value+= ((*input)(w,   h,   0))*m[1][1];//5
						value+= ((*input)(w,   h,   0))*m[1][2];//6*
						value+= ((*input)(w-1, h+1, 0))*m[2][0];//7
						value+= ((*input)(w,   h+1, 0))*m[2][1];//8
						value+= ((*input)(w,   h+1, 0))*m[2][2];//9*                        
					}
				}
				output->BufferPos(w, h, 0);
				output->FixeValeur(value);
		}
	}
}
//Apply a mask to an image
/* void convolution_image(float *red_canal_input, float *green_canal_input, float *blue_canal_input, float *red_output, float *green_output, float *blue_output, int width, int height, float m[3][3])
{
	//Convolves every image's channel
	convolution_channel(red_canal_input, red_output, width, height, m);
	convolution_channel(green_canal_input, green_output, width, height, m);
	convolution_channel(blue_canal_input, blue_output, width, height, m);
} */


//Now, edge detection functions

//Compute Roberts edge detection (Roberts' method has a good localization but is noise sensitive)
InrImage* wrapRoberts(ParamList* p)
{
	//Roberts' masks
	float gradrow[3][3] = {
													{0,0,0},
													{0,0,1},
													{0,-1,0}
												};
	
	float gradcol[3][3] = {
													{-1,0,0},
													{0,1,0},
													{0,0,0}
												};
	
	//Information
	char functionname[] = "wrapRoberts";
    char description[]=" \n\
	Compute the Roberts' edge detection \n\
	\n\
	";
    char parameters[] =" \n\
	Parameters:\n\
	input image: Scalar float input image\n\
	";
	
	//Input and output images. We return output
	InrImage *input;
	InrImage *output;
	InrImage::ptr row;
	InrImage::ptr column;
	int n = 0;
	
	//Takes the image from paramlist
	if (!get_val_ptr_param<InrImage>(input, p, n)) HelpAndReturnNULL;
	
	row    = InrImage::ptr(new InrImage(WT_FLOAT, "rowResult.ami.gz", input));
	column = InrImage::ptr(new InrImage(WT_FLOAT,"columnResult.ami.gz", input));
	output = new InrImage( WT_FLOAT, "RobertsResult.ami.gz", input);
	row->InitZero();
	column->InitZero();
	output->InitZero();
	
	//Make convolution
	convolve2DImage(input, row, gradrow);
	convolve2DImage(input, column, gradcol);
	
	float cx, cy, modgrad;
	//Fill the result image
	for (int x=0; x<input->DimX(); x++) {
		for (int y=0; y<input->DimY(); y++) {
			output->BufferPos(x, y, 0);
			cx = (*row)(x,y,0);
			cy = (*column)(x,y,0);
			modgrad = sqrt((cx*cx)+(cy*cy));
			output->FixeValeur(modgrad);
		}
	}
	
	//	delete row;
	//	delete column;
	return output;
}//wrapRoberts

//Compute Prewit, Sobel or Frei-Chen edge detection
InrImage* wrapPSF(ParamList* p)
{	
	//Information
	char functionname[] = "wrapPSF";
    char description[]=" \n\
	Compute Prewit (k=1), Sobel (k=2) or Frei-Chen (k=3) \n\
	edge detection \n\
	\n\
	";
    char parameters[] =" \n\
	Parameters:\n\
	input image: Scalar float input image\n\
	k: one of the following values: 1, 2 or 3\n\
	(correspondig to Prewit, Sobel or Frei-Chen respectively)\n\
	";
	
	InrImage *input;
	InrImage *output;
	InrImage::ptr row;
	InrImage::ptr column;
	int n = 0;
	int k = 0;
	float Hf[3][3];
	float Hc[3][3];
	if (!get_val_ptr_param<InrImage>(input, p, n)) HelpAndReturnNULL;
	if (!get_int_param(k, p, n)) HelpAndReturnNULL;
	
	//Depending of k value:
	/*
	 k == 1	-> Prewit (sensitive to horizontal and vertical edges)
	 k == 2	-> Sobel (more sensitive that Prewit to diagonal edges)
	 k == 3 -> Frei-Chen (for same gradient in horizontal, vertical and diagonal edges)
	 */
	
	switch (k) {
		case 1: //Prewit
			//Row
			Hf[0][0] = 1/(2+1.0);		Hf[0][1] = 0;		Hf[0][2] = -1/(2+1.0);
			Hf[1][0] = 1.0/(2+1.0);	Hf[1][1] = 0;		Hf[1][2] = -1.0/(2+1.0);
			Hf[2][0] = 1/(2+1.0);		Hf[2][1] = 0;		Hf[2][2] = -1/(2+1.0);
			
			//Column
			Hc[0][0] = -1/(2+1.0);	Hc[0][1] = -1.0/(2+1.0);	Hc[0][2] = -1/(2+1.0);
			Hc[1][0] = 0;						Hc[1][1] = 0;							Hc[1][2] = 0;
			Hc[2][0] = 1/(2+1.0);		Hc[2][1] = 1.0/(2+1.0);		Hc[2][2] = 1/(2+1.0);
			
			break;
		case 2: //Sobel
			//Row
			Hf[0][0] = 1/(2+2.0);		Hf[0][1] = 0;		Hf[0][2] = -1/(2+2.0);
			Hf[1][0] = 2.0/(2+2.0);	Hf[1][1] = 0;		Hf[1][2] = -2.0/(2+2.0);
			Hf[2][0] = 1/(2+2.0);		Hf[2][1] = 0;		Hf[2][2] = -1/(2+2.0);
			
			//Column
			Hc[0][0] = -1/(2+2.0);	Hc[0][1] = -2.0/(2+2.0);	Hc[0][2] = -1/(2+2.0);
			Hc[1][0] = 0;						Hc[1][1] = 0;							Hc[1][2] = 0;
			Hc[2][0] = 1/(2+2.0);		Hc[2][1] = 2.0/(2+2.0);		Hc[2][2] = 1/(2+2.0);
			
			break;
		case 3:	//Frei-Chen
			//Row
			Hf[0][0] = 1/(2+sqrt(2.0));					Hf[0][1] = 0;		Hf[0][2]=-1/(2+sqrt(2.0));
			Hf[1][0] = sqrt(2.0)/(2+sqrt(2.0));	Hf[1][1] = 0;		Hf[1][2] = -(sqrt(2.0))/(2+sqrt(2.0));
			Hf[2][0] = 1/(2+sqrt(2.0));					Hf[2][1] = 0;		Hf[2][2] = -1/(2+sqrt(2.0));
			
			//Column
			Hc[0][0] = -1/(2+sqrt(2.0));			Hc[0][1]=-(sqrt(2.0))/(2+sqrt(2.0));		Hc[0][2]=-1/(2+sqrt(2.0));
			Hc[1][0] = 0;											Hc[1][1] = 0;														Hc[1][2] = 0;
			Hc[2][0] = 1/(2+sqrt(2.0));				Hc[2][1] = sqrt(2.0)/(2+sqrt(2.0));			Hc[2][2] = 1/(2+sqrt(2.0));
		
			break;

		default:
			HelpAndReturnNULL;
			break;
	}
	
	
	
	row = InrImage::ptr(new InrImage(WT_FLOAT, "rowResult.ami.gz", input));
	column = InrImage::ptr(new InrImage(WT_FLOAT, "columnResult.ami.gz", input));
	output = new InrImage( WT_FLOAT, "PSFResult.ami.gz", input);
	row->InitZero();
	column->InitZero();
	output->InitZero();
	
	//Make convolution
	convolve2DImage(input, row, Hf);
	convolve2DImage(input, column, Hc);
	
	float cx, cy, modgrad;
	for (int x=0; x<input->DimX(); x++) {
		for (int y=0; y<input->DimY(); y++) {
			output->BufferPos(x, y, 0);
			cx = (*row)(x,y,0);
			cy = (*column)(x,y,0);
			modgrad = sqrt((cx*cx)+(cy*cy));
			output->FixeValeur(modgrad);
		}
	}
	
	//	delete(row);
	//	delete(column);
	return output;
}//wrapPSF

//Compute the Gradient edge detection
InrImage* wrapGradient(ParamList* p)
{
	//Gradient's masks
	double sqrt_2 = sqrt(2.0);
	float gradx[3][3]={	{-(2-sqrt_2)/4.,      0.,     (2-sqrt_2)/4.},
											{(-2*(sqrt_2-1))/4.,  0., (2*(sqrt_2-1))/4.},
											{-(2-sqrt_2)/4.,      0.,     (2-sqrt_2)/4.}};
	
	float grady[3][3]={	{ -(2-sqrt_2)/4.,  (-2*(sqrt_2-1))/4., -(2-sqrt_2)/4.},
											{             0.,                  0.,              0.},
											{  (2-sqrt_2)/4.,   (2*(sqrt_2-1))/4.,  (2-sqrt_2)/4.}};
	
	//Information
	char functionname[] = "wrapGradient";
    char description[]=" \n\
	Compute the Gradient edge detection \n\
	\n\
	";
    char parameters[] =" \n\
	Parameters:\n\
	input image: Scalar float input image\n\
	";
	
	InrImage *input;
	InrImage *output;
	InrImage::ptr row;
	InrImage::ptr column;
	int n = 0;
	
	if (!get_val_ptr_param<InrImage>(input, p, n)) HelpAndReturnNULL;
	
	row = InrImage::ptr(new InrImage(WT_FLOAT, "rowResult.ami.gz", input));
	column = InrImage::ptr(new InrImage(WT_FLOAT, "columnResult.ami.gz", input));
	output = new InrImage( WT_FLOAT, "GradientResult.ami.gz", input);
	row->InitZero();
	column->InitZero();
	output->InitZero();
	
	//Make convolution
	convolve2DImage(input, row, gradx);
	convolve2DImage(input, column, grady);
	
	float cx, cy, modgrad;
	for (int x=0; x<input->DimX(); x++) {
		for (int y=0; y<input->DimY(); y++) {
			output->BufferPos(x, y, 0);
			cx = (*row)(x,y,0);
			cy = (*column)(x,y,0);
			modgrad = sqrt((cx*cx)+(cy*cy));
			output->FixeValeur(modgrad);
		}
	}
	
	//	delete(row);
	//	delete(column);
	return output;
}//wrapGradient

//Computes the Laplace edge detection
InrImage* wrapLaplace(ParamList* p)
{
	//Laplace's mask
	float lap[3][3]={	{1./3,  1./3, 1./3},
		{1./3, -8./3, 1./3},
		{1./3,  1./3, 1./3}};
	
	//Information
	char functionname[] = "wrapLaplace";
    char description[]=" \n\
	Compute the Laplace edge detection \n\
	\n\
	";
    char parameters[] =" \n\
	Parameters:\n\
	input image: Scalar float input image\n\
	";
	
	InrImage *input;
	InrImage *output;
	InrImage::ptr temp;
	int n = 0;
	
	if (!get_val_ptr_param<InrImage>(input, p, n)) HelpAndReturnNULL;
	
	output = new InrImage( WT_FLOAT, "LaplaceResult.ami.gz", input);
	temp = InrImage::ptr(new InrImage(WT_FLOAT, "temporal.ami.gz", input));
	output->InitZero();
	temp->InitZero();
	//Make convolution
	convolve2DImage(input, temp, lap);
	(*output)=(*temp);
	return output;
}//wrapLaplace

