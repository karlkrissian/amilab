
#include <string>
#include <iostream>

#ifndef _TestClass_h_
#define _TestClass_h_

// Template class
template<class T>
class TemplateClass
{
  public:
    T value;
};

//TemplateClass<int> _Template_int;

// Test normal class
class TestClass
{
  private:
    int val;
    std::string comment;

  public:
    TestClass(int a) {val=a;}
    int GetVal() const { return val; }
    void SetVal(const int& v) { val=v; }
    TestClass operator+(const TestClass& t2)
    { return TestClass(val+t2.val); }

    void SetComment(const char* c) {
      comment=c;
    }
    
    std::string GetComment() {
      return comment;
    }
    
    void PrintComment() {
      std::cout << "comment = " << comment << std::endl;
    }
};

// Test inheritence
class ClassBase1
{
  public:
    void Method1() 
    { 
      std::cout << "ClassBase1::Method1\n" << std::endl; 
    }
};

// first level
class ClassBase2 : public ClassBase1
{
  public:
    void Method2() 
    { 
      std::cout << "ClassBase2::Method2\n" << std::endl; 
    }
};

// second level
class ClassBase3 : public ClassBase2
{
  public:
    void Method3() 
    { 
      std::cout << "ClassBase3::Method3\n" << std::endl; 
    }
};

#endif // _TestClass_h_
