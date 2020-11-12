#include <iostream>
using namespace std;
#define nl "\n"
class complex
{
private:
    double real;
    double imaginary;
    bool is_Negative;
public:
    complex(double,double);
    ~complex();
};

complex::complex(double x = 0,double y = 0)
{
    this->real = real;
    this->imaginary = imaginary;
}

complex::~complex()
{
}
