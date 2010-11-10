
#ifndef _TestClass_h_
#define _TestClass_h_

class TestClass
{
  private:
    int val;

  public:
    TestClass(int a) {val=a;}
    int GetVal() const { return val; }
    void SetVal(const int& v) { val=v; }
    TestClass operator+(const TestClass& t2)
    { return TestClass(val+t2.val); }
};

#endif // _TestClass_h_
