
#include "amilab_messages.h"
#include "DefineClass.hpp"
#include "Variable.hpp"
#include <math.h>
#include <boost/pointer_cast.hpp>
#include <boost/format.hpp>

//#include "MainFrame.h"
#include "func_imagebasictools.h"

#include "AmiMessage.h"
#include "CommonConfigure.h"
COMMON_VAR_IMPORT AmiMessage GB_AmiMessage;

#include "DriverBase.h"
#include "LanguageBaseConfigure.h"
LanguageBase_VAR_IMPORT DriverBase::ptr  GB_DriverBase;

//extern MainFrame*    GB_main_wxFrame;

#define NEW_SMARTPTR(type, var, value) \
  boost::shared_ptr<type> var(new type(value));

#define RETURN_VARPTR(type,  value) \
  boost::shared_ptr<type> newval(new type(value)); \
  return Variable<type>::ptr( new Variable<type>(newval));

#include "inrimage.hpp"
#include "wrap_ami_ImageExtent_L_float_G_.h"
//#include "wrap_DessinImage.h"
#include "wrap_ImageViewerBase.h"
#include "wrapfunctions.hpp"
#include "amiImageExtent.h"

// TODO: should be defined as functions ...
#define UNARYOP_IMAGE(im,operator)      \
  {   \
    InrImage::ptr res;                           \
    if (im.use_count()==1) res = im; \
    else {\
      res = InrImage::ptr(new InrImage( im->GetFormat(),\
                                        im->GetVDim(),\
                                        (std::string("unaryop_")+im->GetName()).c_str(),\
                                        im.get()));\
      (*res) = (*im);\
    }\
    int       i;                            \
    InrImageIteratorBase::ptr res_it(res->CreateIterator());\
    res_it->InitBuffer();                       \
    if (res->ScalarFormat()) {             \
      do {                                \
      res_it->SetDoubleValue( operator(res_it->GetDoubleValue()) );   \
      } while ((*res_it)++);             \
    } else {                                                \
      for(i=0;i<res->GetVDim();i++) {                 \
        res_it->InitBuffer();                       \
        do {                                 \
        res_it->SetDoubleValue( i, operator(res_it->GetDoubleValue(i)) );   \
        } while ((*res_it)++);  \
      }                                   \
    }                                       \
    return Variable<InrImage>::ptr( new Variable<InrImage>(res)); \
  }


#define IMAGE_OP_EXPR(im,operator,expr)      \
  {       \
    InrImage::ptr res;                          \
    if (im.use_count()==1) res = im; \
    else {\
      res = InrImage::ptr(new InrImage( im->GetFormat(),\
                                        im->GetVDim(),\
                                        (im->GetName()+std::string("_op_expression")).c_str(),\
                                        im.get()));\
      (*res) = (*im);\
    }\
    int       i;                                           \
    double    val = expr;                                  \
    InrImageIteratorBase::ptr res_it(res->CreateIterator());\
    res_it->InitBuffer();                                     \
    if( res->ScalarFormat() ){                           \
      do {                                              \
        res_it->SetDoubleValue(res_it->GetDoubleValue() operator val); \
      } while ((*res_it)++);             \
    }else{                                                  \
      do {                                              \
        for(i=0;i<res->GetVDim();i++) {                         \
          res_it->SetDoubleValue(i,res_it->GetDoubleValue(i) operator val);  \
        }                                            \
      } while((*res_it)++);              \
    }                                                  \
    return Variable<InrImage>::ptr( new Variable<InrImage>(res)); \
  }


#define IMAGE_OP_IMAGE(im1,im2,operator)    \
  {\
    if (im1->ScalarFormat()&&im2->ScalarFormat()) { \
      std::string newname = (boost::format("%1%_%2%_%3%")%im1->GetName()%#operator%im2->GetName()).str(); \
      InrImage::ptr res = InrImage::ptr(new InrImage(im1->_format,newname.c_str(),im1.get()));\
      InrImageIteratorBase::ptr im1_it(im1->CreateConstIterator());\
      InrImageIteratorBase::ptr im2_it(im2->CreateConstIterator());\
      InrImageIteratorBase::ptr res_it(res->CreateIterator());\
      im1_it->InitBuffer();                \
      im2_it->InitBuffer();                \
      res_it->InitBuffer();                \
      do{                           \
        res_it->SetDoubleValue(im1_it->GetDoubleValue() operator im2_it->GetDoubleValue()); \
        (*im1_it)++;               \
        (*im2_it)++;               \
      } while ((*res_it)++);      \
      return Variable<InrImage>::ptr( new Variable<InrImage>(res)); \
    } else \
      GB_AmiMessage.Error((boost::format("Both images should be scalar for operator %1%.") % #operator ).str()); \
      return Variable<InrImage>::ptr(); \
  }

#define IMAGE_OP_IMAGE_2(im1,im2,operator) \
  { \
    InrImage::ptr res( (*im1) operator (*im2));     \
    if (!res.get()){              \
      GB_AmiMessage.Error((boost::format("Error in operation %s \t IMAGE_OP_IMAGE_2 \n") % #operator).str().c_str()); \
    }                             \
    return Variable<InrImage>::ptr( new Variable<InrImage>(res)); \
  }


//------------------------------------------------------------------------------
Variable<InrImage>::ptr ImageOpScalar( InrImage::ptr im1, const double& val, 
                                       double(*opfunc)(const double&,const double&), 
                                       const std::string& name
                                      )
{
  // process each component 
  int vdim = im1->GetVDim();
  std::string newname = (boost::format("%1%_%2%_val")%im1->GetName()%name).str(); 

  InrImage::ptr res = InrImage::ptr(new InrImage(im1->_format,newname.c_str(),im1.get()));
  InrImageIteratorBase::ptr im1_it(im1->CreateConstIterator());
  InrImageIteratorBase::ptr res_it(res->CreateIterator());
  im1_it->InitBuffer();                
  res_it->InitBuffer();                
  do{                           
    for(int v=0;v<vdim;v++) {
      res_it->SetDoubleValue(v,opfunc(im1_it->GetDoubleValue(v),val)); 
    }
    (*im1_it)++;               
  } while ((*res_it)++);      
  return Variable<InrImage>::ptr( new Variable<InrImage>(res)); 
}


//------------------------------------------------------------------------------
Variable<InrImage>::ptr BinaryImageOperation( InrImage::ptr im1, InrImage::ptr im2, 
                                              double(*opfunc)(const double&,const double&), 
                                              const std::string& name
                                            )
{
  // process each component ???
  if ((!im1.get())||(!im2.get())) {
    GB_AmiMessage.Error((boost::format("Empty input image smart pointer.") ).str()); 
    return Variable<InrImage>::ptr(); 
  }
  
  if (im1->GetVDim() == im2->GetVDim()) { 
    int vdim = im1->GetVDim();
    std::string newname = (boost::format("%1%_%2%_%3%")%im1->GetName()%name%im2->GetName()).str(); 
    InrImage::ptr res = InrImage::ptr(new InrImage(im1->_format,newname.c_str(),im1.get()));
    InrImageIteratorBase::ptr im1_it(im1->CreateConstIterator());
    InrImageIteratorBase::ptr im2_it(im2->CreateConstIterator());
    InrImageIteratorBase::ptr res_it(res->CreateIterator());
    im1_it->InitBuffer();                
    im2_it->InitBuffer();                
    res_it->InitBuffer();                
    do{                           
      for(int v=0;v<vdim;v++) {
        res_it->SetDoubleValue(v,opfunc(im1_it->GetDoubleValue(v),im2_it->GetDoubleValue(v))); 
      }
      (*im1_it)++;               
      (*im2_it)++;               
    } while ((*res_it)++);      
    return Variable<InrImage>::ptr( new Variable<InrImage>(res)); 
  } else 
    GB_AmiMessage.Error((boost::format("Both images should have the same number of components for operator %1%.") % name ).str()); 
    return Variable<InrImage>::ptr(); 
}

//------------------------------------------------------
//------- Variable<InrImage>
//------------------------------------------------------

/// Copy contents to new variable
template<> AMI_DLLEXPORT BasicVariable::ptr Variable<InrImage>::NewCopy() const
{
  InrImage::ptr newval( new InrImage( Pointer()->GetFormat(),
                                      Pointer()->GetVDim(),
                                      Pointer()->GetName(),
                                      Pointer().get()));
  (*newval) = (*Pointer());
  Variable<InrImage>::ptr newvar(new Variable<InrImage>(newval));
  return newvar;
}


// Arithmetic operators

/// +a
template<> AMI_DLLEXPORT BasicVariable::ptr Variable<InrImage>::operator +()
{
  return NewReference();
}

/*
/// prefix ++ operator ++a
template<> AMI_DLLEXPORT BasicVariable::ptr Variable<InrImage>::operator ++()
{
  std::cout << "**" << std::endl;
  RETURN_VARPTR(InrImage,++RefValue());
}

/// postfix ++ operator a++
template<> AMI_DLLEXPORT BasicVariable::ptr Variable<InrImage>::operator ++(int)
{
  std::cout << "**" << std::endl;
  RETURN_VARPTR(InrImage,RefValue()++);
}
*/

/// -a
template<> AMI_DLLEXPORT BasicVariable::ptr Variable<InrImage>::operator -()
{
  UNARYOP_IMAGE(this->Pointer(), -); 
}

/*
/// prefix -- operator --a
template<> AMI_DLLEXPORT BasicVariable::ptr Variable<InrImage>::operator --()
{  RETURN_VARPTR(InrImage,--RefValue()); }

/// postfix -- operator a--
template<> AMI_DLLEXPORT BasicVariable::ptr Variable<InrImage>::operator --(int)
{  RETURN_VARPTR(InrImage,RefValue()--);  }
*/



/// a+b
template<> AMI_DLLEXPORT BasicVariable::ptr Variable<InrImage>::operator +(const BasicVariable::ptr& b)
{
  if (b->IsNumeric()) {
    IMAGE_OP_EXPR(Pointer(),+,b->GetValueAsDouble());
  }
  else
  if (b->Type()==type_image) {
    DYNAMIC_CAST_VARIABLE(InrImage,b,var_im2);
    IMAGE_OP_IMAGE_2(Pointer(),var_im2->Pointer(),+);
  } 
  else
    CLASS_ERROR("operation not defined");
  return this->NewReference(); 
}

/// a+=b
template<> AMI_DLLEXPORT BasicVariable::ptr Variable<InrImage>::operator +=(const BasicVariable::ptr& b)
{ 
//  if (b->IsNumeric()) {
//    RefValue() += b->GetValueAsDouble();

  if (b->Type()==type_image) {
    DYNAMIC_CAST_VARIABLE(InrImage,b,var_im2);
    if (var_im2.get()) {
      // copy option
      (*Pointer())+=(*var_im2->Pointer());
    } else {
      GB_AmiMessage.Error("Error, parameter of += operator points to NULL image\n");
    }
  } else
    CLASS_ERROR("operation not defined");
  return this->NewReference(); 
}

/// a-b
template<> AMI_DLLEXPORT BasicVariable::ptr Variable<InrImage>::operator -(const BasicVariable::ptr& b)
{
  if (b->IsNumeric()) {
    IMAGE_OP_EXPR(Pointer(),-,b->GetValueAsDouble());
  } 
  else
  if (b->Type()==type_image) {
    DYNAMIC_CAST_VARIABLE(InrImage,b,var_im2);
    IMAGE_OP_IMAGE_2(Pointer(),var_im2->Pointer(),-);
  } 
  else
    CLASS_ERROR("operation not defined");
  return this->NewReference(); 
}

/*
/// a-=b
template<> AMI_DLLEXPORT BasicVariable::ptr Variable<InrImage>::operator -=(const BasicVariable::ptr& b)
{ 
  if (b->IsNumeric()) {
    RefValue() -= b->GetValueAsDouble();
  } else
    CLASS_ERROR("operation not defined");
  return this->NewReference(); 
}
*/

/// a*b
template<> AMI_DLLEXPORT BasicVariable::ptr Variable<InrImage>::operator *(const BasicVariable::ptr& b)
{
  if (b->IsNumeric()) {
    IMAGE_OP_EXPR(Pointer(),*,b->GetValueAsDouble());
  }
  else
  if (b->Type()==type_image) {
    DYNAMIC_CAST_VARIABLE(InrImage,b,var_im2);
    IMAGE_OP_IMAGE_2(Pointer(),var_im2->Pointer(),*);
  } 
  else
    CLASS_ERROR("operation not defined");
  return this->NewReference(); 
}

/*
 * /// a*=b
template<> AMI_DLLEXPORT BasicVariable::ptr Variable<InrImage>::operator *=(const BasicVariable::ptr& b)
{ 
//  if (b->IsNumeric()) {
//    RefValue() += b->GetValueAsDouble();

  if (b->Type()==type_image) {
    DYNAMIC_CAST_VARIABLE(InrImage,b,var_im2);
    if (var_im2.get()) {
      // copy option
      (*Pointer())*=(*var_im2->Pointer());
    } else {
      GB_AmiMessage.Error("Error, parameter of += operator points to NULL image\n");
    }
  } else
    CLASS_ERROR("operation not defined");
  return this->NewReference(); 
}
*/

/// a/b
template<> AMI_DLLEXPORT BasicVariable::ptr Variable<InrImage>::operator /(const BasicVariable::ptr& b)
{
  if (b->IsNumeric()) {
    IMAGE_OP_EXPR(Pointer(),/,b->GetValueAsDouble());
  }
  else
  if (b->Type()==type_image) {
    DYNAMIC_CAST_VARIABLE(InrImage,b,var_im2);
    IMAGE_OP_IMAGE_2(Pointer(),var_im2->Pointer(),/);
  } 
  else
    CLASS_ERROR("operation not defined");
  return this->NewReference(); 
}

/*
/// a/=b
template<> AMI_DLLEXPORT BasicVariable::ptr Variable<InrImage>::operator /=(const BasicVariable::ptr& b)
{ 
  if (b->IsNumeric()) {
    RefValue() /= b->GetValueAsDouble();
  } else
    CLASS_ERROR("operation not defined");
  return this->NewReference(); 
}
*/

inline double Pointwise_Modulus(const double& a, const double& b) {
  return ((int) round(a)) % ((int) round(b));
}

/// a%b
template<> AMI_DLLEXPORT BasicVariable::ptr Variable<InrImage>::operator %(const BasicVariable::ptr& b)
{
  if (b->IsNumeric()) {
    return ImageOpScalar(Pointer(),b->GetValueAsDouble(),Pointwise_Modulus,"Mod");
  } 
  else 
    if (b->Type()==type_image) {
      DYNAMIC_CAST_VARIABLE(InrImage,b,var_im2);
      return BinaryImageOperation(Pointer(),var_im2->Pointer(),Pointwise_Modulus,"Mod");
    }
  else
    CLASS_ERROR("operation not defined");
  return this->NewReference(); 
}

/*
/// a%=b
template<> AMI_DLLEXPORT BasicVariable::ptr Variable<InrImage>::operator %=(const BasicVariable::ptr& b)
{ 
  if (b->IsNumeric()) {
    RefValue() =  ((int) round(Value())) % ((int) round(b->GetValueAsDouble()));
  } else
    CLASS_ERROR("operation not defined");
  return this->NewReference(); 
}
*/


//  Comparison Operators

/// a<b
template<> AMI_DLLEXPORT BasicVariable::ptr Variable<InrImage>::operator <(const BasicVariable::ptr& b)
{ 
  if (b->IsNumeric()) {
    IMAGE_OP_EXPR(Pointer(),<,b->GetValueAsDouble());
  } 
  else
  if (b->Type()==type_image) {
    DYNAMIC_CAST_VARIABLE(InrImage,b,var_im2);
    IMAGE_OP_IMAGE(Pointer(),var_im2->Pointer(),<);
  } 
  else
    CLASS_ERROR("operation not defined");
  return this->NewReference(); 
}

/// a<=b
template<> AMI_DLLEXPORT BasicVariable::ptr Variable<InrImage>::operator <=(const BasicVariable::ptr& b)
{ 
  if (b->IsNumeric()) {
    IMAGE_OP_EXPR(Pointer(),<=,b->GetValueAsDouble());
  }
  else
  if (b->Type()==type_image) {
    DYNAMIC_CAST_VARIABLE(InrImage,b,var_im2);
    IMAGE_OP_IMAGE(Pointer(),var_im2->Pointer(),<=);
  } 
  else
    CLASS_ERROR("operation not defined");
  return this->NewReference(); 
}

/// a>b
template<> AMI_DLLEXPORT BasicVariable::ptr Variable<InrImage>::operator >(const BasicVariable::ptr& b)
{ 
  if (b->IsNumeric()) {
    IMAGE_OP_EXPR(Pointer(),>,b->GetValueAsDouble());
  }
  else
  if (b->Type()==type_image) {
    DYNAMIC_CAST_VARIABLE(InrImage,b,var_im2);
    IMAGE_OP_IMAGE(Pointer(),var_im2->Pointer(),>);
  } 
  else
    CLASS_ERROR("operation not defined");
  return this->NewReference(); 
}

/// a>=b
template<> AMI_DLLEXPORT BasicVariable::ptr Variable<InrImage>::operator >=(const BasicVariable::ptr& b)
{ 
  if (b->IsNumeric()) {
    IMAGE_OP_EXPR(Pointer(),>=,b->GetValueAsDouble());
  }
  else
  if (b->Type()==type_image) {
    DYNAMIC_CAST_VARIABLE(InrImage,b,var_im2);
    IMAGE_OP_IMAGE(Pointer(),var_im2->Pointer(),>=);
  } 
  else
    CLASS_ERROR("operation not defined");
  return this->NewReference(); 
}

/// a!=b
template<> AMI_DLLEXPORT BasicVariable::ptr Variable<InrImage>::operator !=(const BasicVariable::ptr& b)
{ 
  if (b->IsNumeric()) {
    IMAGE_OP_EXPR(Pointer(),!=,b->GetValueAsDouble());
  }
  else
  if (b->Type()==type_image) {
    DYNAMIC_CAST_VARIABLE(InrImage,b,var_im2);
    IMAGE_OP_IMAGE(Pointer(),var_im2->Pointer(),!=);
  } 
  else
    CLASS_ERROR("operation not defined");
  return this->NewReference(); 
}

/// a==b
template<> AMI_DLLEXPORT BasicVariable::ptr Variable<InrImage>::operator ==(const BasicVariable::ptr& b)
{ 
  if (b->IsNumeric()) {
    IMAGE_OP_EXPR(Pointer(),==,b->GetValueAsDouble());
  }
  else
  if (b->Type()==type_image) {
    DYNAMIC_CAST_VARIABLE(InrImage,b,var_im2);
    IMAGE_OP_IMAGE(Pointer(),var_im2->Pointer(),==);
  } 
  else
    CLASS_ERROR("operation not defined");
  return this->NewReference(); 
}


// Logical operators

/*
template<> AMI_DLLEXPORT BasicVariable::ptr Variable<InrImage>::operator !() 
{
  RETURN_VARPTR(InrImage,!(Value()>0.5));
}

template<> AMI_DLLEXPORT BasicVariable::ptr Variable<InrImage>::operator &&(const BasicVariable::ptr& b) 
{
  if (b->IsNumeric()) {
    IMAGE_OP_EXPR(Pointer(),==,b->GetValueAsDouble());
    RETURN_VARPTR(InrImage,Value()&& (bool) (b->GetValueAsDouble()>0.5));
  } else
    CLASS_ERROR("operation not defined");
  return this->NewReference(); 
}

template<> AMI_DLLEXPORT BasicVariable::ptr Variable<InrImage>::operator ||(const BasicVariable::ptr& b) 
{
  if (b->IsNumeric()) {
    RETURN_VARPTR(InrImage,Value() || (bool) (b->GetValueAsDouble()>0.5));
  } else
    CLASS_ERROR("operation not defined");
  return this->NewReference(); 
}
*/

/// a^b
template<> AMI_DLLEXPORT BasicVariable::ptr Variable<InrImage>::operator ^(const BasicVariable::ptr& b)
{ 
  if (b->Type()==type_image) {
    DYNAMIC_CAST_VARIABLE(InrImage,b,var_im2);
    IMAGE_OP_IMAGE_2(Pointer(),var_im2->Pointer(),^);
  } 
  else
    CLASS_ERROR("operation not defined");
  return this->NewReference(); 
}

// Mathematical functions

#define VAR_IMPL_FUNC(type,fname,func) \
template<> AMI_DLLEXPORT BasicVariable::ptr Variable<type>::m_##fname() \
{ \
  UNARYOP_IMAGE(this->Pointer(), func); \
}

VAR_IMPL_FUNC(InrImage,  sin,  sin)
VAR_IMPL_FUNC(InrImage,  cos,  cos)
VAR_IMPL_FUNC(InrImage,  tan,  tan)
VAR_IMPL_FUNC(InrImage,  asin, asin)
VAR_IMPL_FUNC(InrImage,  acos, acos)
VAR_IMPL_FUNC(InrImage,  atan, atan)
VAR_IMPL_FUNC(InrImage,  fabs, fabs)
VAR_IMPL_FUNC(InrImage,  round,round)
VAR_IMPL_FUNC(InrImage,  floor,floor)
VAR_IMPL_FUNC(InrImage,  exp,  exp)
VAR_IMPL_FUNC(InrImage,  log,  log10)
VAR_IMPL_FUNC(InrImage,  ln,   log)
VAR_IMPL_FUNC(InrImage,  sqrt, sqrt)
//VAR_IMPL_FUNC(InrImage,  pow, pow)

//  norm(image)
template<> AMI_DLLEXPORT BasicVariable::ptr Variable<InrImage>::m_norm() 
{ 
  InrImage::ptr res ( Norm(*Pointer()));
  if (!res.get())
    fprintf(stderr,"Error computing the norm |image| \n");
  return Variable<InrImage>::ptr( new Variable<InrImage>(res)); 
}
//VAR_IMPL_FUNC(InrImage,  norm, fabs)

// Image Pixel Type Cast
template<> AMI_DLLEXPORT BasicVariable::ptr Variable<InrImage>::BasicCast(const int& type)
{
  InrImage::ptr res  ( new InrImage( (WORDTYPE) type, "castimage.ami.gz", Pointer().get()));
  (*res) = (*Pointer());
  return Variable<InrImage>::ptr( new Variable<InrImage>(res)); 
}


/**
 * operation Image[number]
 **/
BasicVariable::ptr Image_Brackets( Variable<InrImage> * const _this, int pos)
{
    InrImage::ptr im(_this->Pointer());
    InrImage::ptr res;
    if (pos<0) pos = 0;
    if (pos>=im->GetVDim()) pos = im->GetVDim()-1;
    std::string imname  = (boost::format("C%d_%s") % pos % _this->Name()).str();

    switch ( im->GetFormat() ){
        case WT_RGB:
        case WT_RGBA:
            res = InrImage::ptr(new InrImage(WT_UNSIGNED_CHAR,1,imname.c_str(),im.get()));
        break;
        case WT_FLOAT_VECTOR:
            res = InrImage::ptr(new InrImage(WT_FLOAT,1,imname.c_str(),im.get()));
        break;

        case WT_UNSIGNED_CHAR:
        case WT_UNSIGNED_INT:
        case WT_SIGNED_INT:
        case WT_UNSIGNED_SHORT:
        case WT_SIGNED_SHORT:
        case WT_FLOAT:
        case WT_DOUBLE:
            res = InrImage::ptr(new InrImage(im->_format,1,imname.c_str(),im.get()));
        break;

        default:
          GB_DriverBase->yyiperror(" operator [] does not handle this format \n");
          return BasicVariable::empty_variable; 
    }

    im->InitBuffer();
    res->InitBuffer();
    do {
      res->FixeValeur(im->VectValeurBuffer(pos));
      im->IncBuffer();
    } while (res->IncBuffer());
    return Variable<InrImage>::ptr( new Variable<InrImage>(res)); 
}

/**
 * Array subscript operator
 * @param v 
 * @return 
 */
template<> AMI_DLLEXPORT BasicVariable::ptr Variable<InrImage>::operator[](const BasicVariable::ptr& v)
{
  if (v->IsNumeric()) {
    int pos = (int) v->GetValueAsDouble();
    return Image_Brackets(this,pos);
  } 
  else {

    boost::shared_ptr<ami::ImageExtent<float> > extent;
    
    extent = AMILabType<ami::ImageExtent<float> >::GetValue(v);
    // try to get an image extent
    //GET_WRAPPED_TEMPLATE_OBJECT(ImageExtent, float ,v,extent);

/*
    DYNAMIC_CAST_VARIABLE(AMIObject, v, varobj) 
    boost::shared_ptr<ImageExtent<float> > extent; 
    if (varobj.get()) { 
      WrapClassBase::ptr wrapped_base(varobj->Pointer()->GetWrappedObject()); 
      WrapClass_ImageExtent::ptr wrapped_obj( 
        boost::dynamic_pointer_cast<WrapClass_ImageExtent >(wrapped_base)); 
      if (wrapped_obj.get())
        extent = wrapped_obj->_obj; 
    }
*/
    if (extent.get()) {
      InrImage::ptr im(Pointer());
      extent->SetRelative(im.get());
      InrImage::ptr res ( Func_SubImage( im.get(),
                  (int)  round((double)extent->Xmin()),
                  (int)  round((double)extent->Ymin()),
                  (int)  round((double)extent->Zmin()),
                  (int)  round((double)extent->Xmax()),
                  (int)  round((double)extent->Ymax()),
                  (int)  round((double)extent->Zmax())
                  ));
      if (!res.get()) {
        CLASS_ERROR("SubImage() failed ... ");
        return BasicVariable::ptr();
      }
      return Variable<InrImage>::ptr( new Variable<InrImage>(res)); 
    }
    else 
    {
      // try to get an image extent
      GET_WRAPPED_OBJECT(ImageViewerBase,v,draw);
      if (draw.get()) {

        //DessinImage::ptr draw = DessinImage::ptr(varimd->Pointer());
  
        int xmin,xmax;
        int ymin,ymax;
        int zmin,zmax;
        std::string comment;
    
        draw->GetZoom(xmin,ymin,zmin,xmax,ymax,zmax);
        ami::ImageExtent<float>* extent=
          new ami::ImageExtent<float>(xmin,xmax,ymin,ymax,zmin,zmax);
        extent->SetMode(ami::ImageExtent<float>::Relative); // relative extent
    
        comment = str(boost::format(" //  subvolume [%3d:%3d, %3d:%3d, %3d:%3d] ")
            % xmin % xmax % ymin % ymax % zmin % zmax);
        if (GB_DriverBase->InConsole()) 
          GB_AmiMessage.IncCommand(comment);

        InrImage::ptr im(Pointer());
        extent->SetRelative(im.get());
        InrImage::ptr res ( Func_SubImage( im.get(),
                    (int)  round((double)extent->Xmin()),
                    (int)  round((double)extent->Ymin()),
                    (int)  round((double)extent->Zmin()),
                    (int)  round((double)extent->Xmax()),
                    (int)  round((double)extent->Ymax()),
                    (int)  round((double)extent->Zmax())
                    ));
        if (!res.get()) {
          CLASS_ERROR("SubImage() failed ... ");
          return BasicVariable::ptr();
        }
        return Variable<InrImage>::ptr( new Variable<InrImage>(res)); 
      } 
      else
        CLASS_ERROR("operation not defined");
    }
  }
  return BasicVariable::empty_variable; 
}


/*
//
template<> AMI_DLLEXPORT
BasicVariable::ptr Variable<InrImage>::TernaryCondition(const BasicVariable::ptr& v1, const BasicVariable::ptr&v2)
{

  if (IsNumeric()) {
    if (GetValueAsDouble()>0.5) {
      return v1->NewReference();
    } else {
      return v2->NewReference();
    }
  } else
    CLASS_ERROR("operation not defined");
  return NewReference();
}
*/

/// Other operators
/// a=b
template<> AMI_DLLEXPORT 
BasicVariable::ptr Variable<InrImage>::operator =(const BasicVariable::ptr& b)
{
  CLASS_MESSAGE("begin");
  if (b->IsNumeric()) {
    Pointer()->InitImage(b->GetValueAsDouble());
  }
  else
  if (b->Type()==type_image) {
    DYNAMIC_CAST_VARIABLE(InrImage,b,var_im2);
    if (var_im2.get()) {
      // copy option
      if (!((*Pointer())=(*var_im2->Pointer()))) GB_AmiMessage.Error(" Error in images assignement\n");
    } else {
      GB_AmiMessage.Error("Error, empty variable as parameter of assignment operator\n");
    }
  } 
  else
    CLASS_ERROR("operation not defined");
  return this->NewReference(); 
}

/// operator <<=
template<> AMI_DLLEXPORT BasicVariable::ptr Variable<InrImage>::left_assign(const BasicVariable::ptr& b)
{
  if (b->Type() == type_image) {
    DYNAMIC_CAST_VARIABLE(InrImage, b, var_im2)
    InrImage::ptr i1(this->Pointer());
    InrImage::ptr imptr(var_im2->Pointer());
    bool can_skip_allocation = false;

    if (imptr.get()) {
      if (i1.get() != imptr.get()) {
        can_skip_allocation = 
          (i1->GetFormat() == imptr->GetFormat())&&
          (i1->GetVDim() == imptr->GetVDim());
        if (can_skip_allocation) {
          // first try the standard data copy
          can_skip_allocation = ((*i1) = (*imptr));
          if (can_skip_allocation) {
            // copy additional information here
            i1->SetTranslation(imptr->TrX(), imptr->TrY(), imptr->TrZ());
            i1->SetVoxelSize( imptr->VoxSizeX(),
                              imptr->VoxSizeY(),
                              imptr->VoxSizeZ());
          }
        }
        if (!can_skip_allocation) {
          // should be OK
          if (b->GetPtrCounter()==1) {
            _pointer = InrImage::ptr(imptr); 
          } else {
            // make a copy first
            BasicVariable::ptr copy(b->NewCopy());
            DYNAMIC_CAST_VARIABLE(InrImage, 
              copy, varim_copy)
            _pointer = varim_copy->Pointer();
          }
          //this->Init( this->Name().c_str(), imptr);
        } // end if (!can_skip_allocation)
      } // end if (i1.get()!=imptr)
    }
    else
      GB_AmiMessage.Error("assignment of NULL image\n");
  }
  else
    CLASS_ERROR("operation not defined");
  return this->NewReference();
}

