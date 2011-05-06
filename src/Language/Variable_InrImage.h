
#ifndef _Variable_InrImage_h_
#define _Variable_InrImage_h_

#include "Variable.hpp"

class InrImage;

//------------------------------------------------------
//------- Variable<InrImage>
//------------------------------------------------------

/// Copy contents to new variable
template<> BasicVariable::ptr Variable<InrImage>::NewCopy() const;

// Arithmetic operators

/// +a
template<> BasicVariable::ptr Variable<InrImage>::operator +();

/*
/// prefix ++ operator ++a
template<> BasicVariable::ptr Variable<InrImage>::operator ++();

/// postfix ++ operator a++
template<> BasicVariable::ptr Variable<InrImage>::operator ++(int);
*/

/// -a
template<> BasicVariable::ptr Variable<InrImage>::operator -();

/*
/// prefix -- operator --a
template<> BasicVariable::ptr Variable<InrImage>::operator --();

/// postfix -- operator a--
template<> BasicVariable::ptr Variable<InrImage>::operator --(int);
*/


/// a+b
template<> BasicVariable::ptr Variable<InrImage>::operator +(const BasicVariable::ptr& b);

/// a+=b
template<> BasicVariable::ptr Variable<InrImage>::operator +=(const BasicVariable::ptr& b);

/// a-b
template<> BasicVariable::ptr Variable<InrImage>::operator -(const BasicVariable::ptr& b);

/*
/// a-=b
template<> BasicVariable::ptr Variable<InrImage>::operator -=(const BasicVariable::ptr& b);
*/

/// a*b
template<> BasicVariable::ptr Variable<InrImage>::operator *(const BasicVariable::ptr& b);


/*
 * /// a*=b
template<> BasicVariable::ptr Variable<InrImage>::operator *=(const BasicVariable::ptr& b);
*/

/// a/b
template<> BasicVariable::ptr Variable<InrImage>::operator /(const BasicVariable::ptr& b);

/*
/// a/=b
template<> BasicVariable::ptr Variable<InrImage>::operator /=(const BasicVariable::ptr& b);
*/

/*
/// a%b
template<> BasicVariable::ptr Variable<InrImage>::operator %(const BasicVariable::ptr& b);

/// a%=b
template<> BasicVariable::ptr Variable<InrImage>::operator %=(const BasicVariable::ptr& b);
*/

//  Comparison Operators

/// a<b
template<> BasicVariable::ptr Variable<InrImage>::operator <(const BasicVariable::ptr& b);

/// a<=b
template<> BasicVariable::ptr Variable<InrImage>::operator <=(const BasicVariable::ptr& b);

/// a>b
template<> BasicVariable::ptr Variable<InrImage>::operator >(const BasicVariable::ptr& b);

/// a>=b
template<> BasicVariable::ptr Variable<InrImage>::operator >=(const BasicVariable::ptr& b);

/// a!=b
template<> BasicVariable::ptr Variable<InrImage>::operator !=(const BasicVariable::ptr& b);

/// a==b
template<> BasicVariable::ptr Variable<InrImage>::operator ==(const BasicVariable::ptr& b);

// Logical operators
/*
template<> BasicVariable::ptr Variable<InrImage>::operator !();

template<> BasicVariable::ptr Variable<InrImage>::operator &&(const BasicVariable::ptr& b);

template<> BasicVariable::ptr Variable<InrImage>::operator ||(const BasicVariable::ptr& b);
*/

// Bitwise operators
/// in this case, for vectorial images, used for pointwise cross-product.
template<> BasicVariable::ptr Variable<InrImage>::operator ^(const BasicVariable::ptr& b);


// // Mathematical functions
// #define VAR_DECL_FUNC(type,fname) 
// template<> BasicVariable::ptr Variable<type>::m_##fname();

VAR_DECL_FUNC(InrImage,sin)
VAR_DECL_FUNC(InrImage,cos)
VAR_DECL_FUNC(InrImage,tan)
VAR_DECL_FUNC(InrImage,asin)
VAR_DECL_FUNC(InrImage,acos)
VAR_DECL_FUNC(InrImage,atan)
VAR_DECL_FUNC(InrImage,fabs)
VAR_DECL_FUNC(InrImage,round)
VAR_DECL_FUNC(InrImage,floor)
VAR_DECL_FUNC(InrImage,exp)
VAR_DECL_FUNC(InrImage,log)
VAR_DECL_FUNC(InrImage,ln)
VAR_DECL_FUNC(InrImage,norm)
VAR_DECL_FUNC(InrImage,sqrt)


/**
 *    The image conversion is done using the cast operator
 *    where basic_type can be one of the basic type accepted,
 *    currently:
 *    CHAR UCHAR SHORT USHORT FLOAT DOUBLE RGB FLOAT_VECTOR
 *
 *    Example(s):
 *      i = Image(FLOAT,10,10,10)
 *      j = (RGB) i
 * @param type 
 * @return 
 */
template<> BasicVariable::ptr Variable<InrImage>::BasicCast(const int& type);

/**
 * Array subscript operator, parameter must be numerical
        Description:
          Applied on RGB or vectorial images,
          returns the given component number of the image:

        Example(s):
          i = Image "test.jpg"
          ired   = i[0]
          igreen = i[1]
          iblue  = i[2]

          print ired(i.tx/2,i.ty/2); print "\n"
          print i(i.tx/2,i.ty/2,0,0); print "\n"
 * @param v, must have a numeric type
 * @return the corresponding part of the image
 */
template<>  BasicVariable::ptr Variable<InrImage>::operator[](const BasicVariable::ptr& v);


/*
/// (cond?a:b)
template<> BasicVariable::ptr Variable<InrImage>::TernaryCondition(const BasicVariable::ptr& v1, const BasicVariable::ptr&v2);
*/


/// Other operators
/// a=b

/**
 * Basic Assignment operator
 * if b is 
 * - a numerical value, sets the whole image to this value
 * - another image: copy image contents
 * @param b 
 * @return 
 */
template<> BasicVariable::ptr Variable<InrImage>::operator =(const BasicVariable::ptr& b);

/**
 * Tries to copy images, if the images don't have the same dimensions, creates a new image.
 * @param b 
 * @return 
 */
template<> BasicVariable::ptr Variable<InrImage>::left_assign(const BasicVariable::ptr& b);

#endif 
// _Variable_InrImage_h_
