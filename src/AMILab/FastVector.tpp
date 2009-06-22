// Define fast operations on vectors using SSE operations



// for float inputs
// vectors of same sizes and types: to check !!!
// size is multiple of 4 ...
// and aligned !!!
#define FVECTOR_POINT_OPERATION_SSE(type,op) \
  template <class VT, class ST> \
  void FVector_##op##_##type##_sse( FVector<VT,ST>& v1, FVector<VT,ST>& v2, \
                               FVector<VT,ST>& res) \
  { \
    ST  nLoop = v1.GetSize()/ 4; \
    __m128* pSrc1 = (__m128*) v1.GetData(); \
    __m128* pSrc2 = (__m128*) v2.GetData(); \
    __m128* pDest = (__m128*) res.GetData(); \
    ST i; \
    for ( i=0; i < nLoop; i++ ) \
        *pDest++ = _mm_##op##_ps(*pSrc1++, *pSrc2++); \
  }

#define FVECTOR_POINT_OPERATION_SSE_UUA(type,op) \
  template <class VT, class ST> \
  void FVector_##op##_##type##_sse_uua( FVector<VT,ST>& v1, FVector<VT,ST>& v2, \
                               FVector<VT,ST>& res) \
  { \
    ST  nLoop = v1.GetSize()/ 4; \
    VT* pSrc1 = v1.GetData(); \
    VT* pSrc2 = v2.GetData(); \
    __m128* pDest = (__m128*) res.GetData(); \
    ST i; \
    for ( i=0; i < nLoop; i++ ) { \
        *pDest++ =  _mm_##op##_ps(_mm_loadu_ps(pSrc1), _mm_loadu_ps(pSrc2)); \
        pSrc1+=4; \
        pSrc2+=4; \
    } \
  }

#define FVECTOR_POINT_OPERATION_SSE_AUA(type,op) \
  template <class VT, class ST> \
  void FVector_##op##_##type##_sse_aua( FVector<VT,ST>& v1, FVector<VT,ST>& v2, \
                               FVector<VT,ST>& res) \
  { \
    ST  nLoop = v1.GetSize()/ 4; \
    __m128* pSrc1 = (__m128*) v1.GetData(); \
    VT* pSrc2 = v2.GetData(); \
    __m128* pDest = (__m128*) res.GetData(); \
    ST i; \
    for ( i=0; i < nLoop; i++ ) { \
        *pDest++ =  _mm_##op##_ps(*pSrc1++, _mm_loadu_ps(pSrc2)); \
        pSrc2+=4; \
    } \
  }

// for float inputs
// vectors of same sizes and types: to check !!!
// size is multiple of 4 ...
#define FVECTOR_POINT_OPERATION(opname,op) \
  template <class VT, class ST> \
  void FVector_##opname( FVector<VT,ST>& v1, FVector<VT,ST>& v2, \
                    FVector<VT,ST>& res) \
  { \
    ST  nLoop = v1.GetSize(); \
    VT* pSrc1 =  v1.GetData(); \
    VT* pSrc2 =  v2.GetData(); \
    VT* pDest =  res.GetData(); \
    ST i; \
    for ( i=0; i < nLoop; i++ ) \
        *pDest++ = *pSrc1++ op *pSrc2++; \
  }

FVECTOR_POINT_OPERATION(add,+)
FVECTOR_POINT_OPERATION(sub,-)

#ifdef __SSE__
FVECTOR_POINT_OPERATION_SSE(float,add)
FVECTOR_POINT_OPERATION_SSE(float,sub)

FVECTOR_POINT_OPERATION_SSE_UUA(float,add)
FVECTOR_POINT_OPERATION_SSE_UUA(float,sub)

FVECTOR_POINT_OPERATION_SSE_AUA(float,add)
FVECTOR_POINT_OPERATION_SSE_AUA(float,sub)
#endif
