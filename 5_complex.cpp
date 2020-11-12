#include <iostream>
using namespace std;
#define nl "\n"
class complex
{
private:
    double real;
    double imaginary;
public:
    // Operator OverLoading
    complex operator+(const complex&);
    complex operator-(const complex&);
    complex operator*(const complex&);
    complex operator/(const complex&);
    complex operator*(const double&);
    complex operator!();
    
    // Getter and Setters
    double getReal() const;
    double getImaginary() const;
    void setReal(double);
    void setImaginary(double);

    // Constructor and Destructor
    complex(double,double);
    ~complex();
};

complex::complex(double x = 0,double y = 0)
{
    this->real = x;
    this->imaginary = y;
}

complex::~complex()
{
}

double complex::getReal() const {
    return this->real;
}

double complex::getImaginary() const {
    return this->imaginary;
}

complex complex::operator!(){
    complex c1(this->getReal(),(-1 * this->getImaginary()));
    return c1;
}

complex complex::operator+(const complex& c1){
    complex c2(this->getReal() + c1.getReal()  , this->getImaginary() + c1.getImaginary());
    return c2;    
}

complex complex::operator-(const complex& c1){
    complex c2(this->getReal() - c1.getReal()  , this->getImaginary() - c1.getImaginary());
    return c2;    
}

complex complex::operator*(const complex& c1){
    double real = (this->getReal() * c1.getReal());
    real += -(this->getImaginary() * c1.getImaginary());
    double imaginary = this->getReal() * c1.getImaginary();
    imaginary += (this->getImaginary() * c1.getReal());
    complex c2(real,imaginary);
    return c2;    
}

complex complex::operator*(const double& d){
    complex c2(this->getReal() * d  , this->getImaginary() * d);
    return c2;    
}

complex complex::operator/(const complex& c1){
    double denominator = (c1.getReal() * c1.getReal()) - (c1.getImaginary() * -(c1.getImaginary()));
    denominator = 1/denominator;
    // To Break Constant-ness simply;
    complex cx = c1;
    complex numerator = ((*this) * (!cx));
    return (numerator * denominator);
}

void Print(complex c1){
    double img  = c1.getImaginary();
    cout<<c1.getReal()<<((img<0) ? " - " : " + ")<<((img < 0) ? -img : img)<<" i\n";
}


int main(){
    complex c1(1,2) , c2(-12,-5) ,
    c3 = c1 + c2;
    Print(c3);
    c3 = c1 - c2;
    Print(c3);
    c3 = c1 * c2;
    Print(c3);
    c3 = c1 / c2;
    Print(c3);
}