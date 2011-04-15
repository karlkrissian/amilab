
#ifndef ami_format_h
#define ami_format_h

/**
 * Very light weighted interface for string formating
 * The GetString() function should only be used when the object is allocated!
 */
namespace ami
{
  
  class AmiString; 
    
  class format
  {
    // Trick here to avoid includes ...
    void* _boost_format;
    AmiString* _st;

  public:
      format(const char* st);
      ~format();
      format& operator%(const char* st);
      format& operator%(const int& val);
      format& operator%(const float& val);
      format& operator%(const double& val);
      const char* GetString() const;
  };
}

#endif //ami_format_h
