
#ifdef AMI_USE_SSE
  #include <xmmintrin.h>
#endif
#include <string.h>
#include <iostream>
#include <string>
#include <boost/format.hpp>


namespace amilab {

template <class VType, class SizeType>
class ami_FVector 
{
    VType* data;
    bool data_allocated;
    SizeType allocated_size;
    SizeType size;
    typedef  SizeType sizetype;

  public:
    ami_FVector( SizeType s, const std::string& name="") 
    {
      std::cout << __func__ << " size = " << s << std::endl;
      data = (VType*) _mm_malloc (sizeof(VType)*s,16);
      allocated_size = s;
      size = 0;
    }
    
    void SetSize(SizeType s) 
    {
      if (s<0) s=0;
      if (s>allocated_size) s=allocated_size;
      size = s;
    }

    ami_FVector(VType* d, SizeType s, const std::string& name="", bool align = true) 
    {
      size = s;
      data = d;
      allocated_size = 0;
      if ((!IsAligned16())&&(align)) {
        //std::cout << name << " is not aligned" << std::endl;
        data = (VType*) _mm_malloc (sizeof(VType)*s,16);
        allocated_size = s;
        memcpy(data,d,sizeof(VType)*s);
      }
    }

    ~ami_FVector() {
      if (allocated_size>0)
        _mm_free(data);
    }
    
    void CopyData(VType* d,SizeType s) 
    { 
      if (s<=allocated_size) {
        memcpy(data,d,sizeof(VType)*s);
        size = s;
      }
      else
        std::cerr << __func__ 
                  << boost::format(" data bigger than vector %1% %2%")
                    % (int) s % (int) allocated_size
                  << std::endl;
    }
    VType* GetData() { return data; }
    VType* GetData(SizeType i) { return data+i; }
    const SizeType& GetSize() const { return size; }
    bool IsAligned16() { return (((unsigned long) data & 15) ==0); }
};


// addition between 2 vectors

// general code
/*
#define DECL_FVECTOR_POINT_OPERATION(op) \
  template <class VT, class ST> \
  void FVector_##op( ami_FVector<VT,ST>& v1, ami_FVector<VT,ST>& v2, \
                    ami_FVector<VT,ST>& res);

#define DECL_FVECTOR_POINT_OPERATION_SSE(type,op) \
  template <class VT, class ST> \
  void FVector_##op##_##type##_sse( ami_FVector<VT,ST>& v1, ami_FVector<VT,ST>& v2, \
                               ami_FVector<VT,ST>& res);

#define DECL_FVECTOR_POINT_OPERATION_SSE_UNALIGNED(type,op) \
  template <class VT, class ST> \
  void FVector_##op##_##type##_sse_unaligned( ami_FVector<VT,ST>& v1, ami_FVector<VT,ST>& v2, \
                               ami_FVector<VT,ST>& res);

DECL_FVECTOR_POINT_OPERATION(add)
DECL_FVECTOR_POINT_OPERATION(sub)

DECL_FVECTOR_POINT_OPERATION_SSE(float,add)
DECL_FVECTOR_POINT_OPERATION_SSE(float,sub)
*/

#include "FastVector.tpp"

}
