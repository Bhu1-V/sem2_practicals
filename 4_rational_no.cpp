#include <iostream>
using namespace std;
#define rn Rational_No
#define nl "\n"


class Rational_No
{
  private:
    int p;
    int q;
    bool is_negative;
    double value;
    void calValue();
    int _getGCF();
  public:
    void setP(int p);
    int getP() const;
    void setQ(int q);
    int getQ() const;    
    Rational_No(int,int);
    bool isValid();
    ~Rational_No();
    bool isNegative();
    double getValue () const;
    void simplyfy();
    Rational_No operator+(const Rational_No&);
    Rational_No operator- (const Rational_No&);
    Rational_No operator* (const Rational_No&);
    Rational_No operator/ (const Rational_No&);
    bool operator==(const Rational_No&);
    bool operator!=(const Rational_No&);
    void operator++ ();
    void operator-- ();
    void operator++ (int);
    void operator-- (int);
    friend ostream& operator<< (ostream& out , const rn& r1);
    friend istream & operator>> (istream& in , rn& r1);
};
Rational_No:: ~Rational_No(){
    // cout<<"Deleted Your Rational No. {"<<this->getP()<<"/"<<this->getQ()<<"}\n"; 
}

Rational_No:: Rational_No(int p = 1,int q = 1)
{
    this->is_negative = false;
    try{
        this->is_negative = (p<0);
        this->p = p < 0 ? -p : p;
        if(q != 0){
            this->q = q < 0 ? -q : q;
            this->is_negative = (q < 0) ? !this->is_negative : this->is_negative; 
            this->calValue();
            this->simplyfy(); 
            // cout<<"Created Your Rational No. {"<<this->getP()<<"/"<<this->getQ()<<"}\n";
        }
        else
        throw 0;
    }catch(int x){
        cout<<"\nCan't Assign a 0 to Denominator.\n";
        this->~Rational_No();
    }
}

bool Rational_No:: isValid(){
    return(this->q != 0);
}

void Rational_No::setP(int p){
    this->p = p<0 ? -p : p;
    this->is_negative = p < 0; 
    this->calValue(); 
}

int Rational_No::getQ() const {
    return this->q;
}

int Rational_No::getP() const {
    return this->is_negative ? (-1 * this->p) : this->p;
}


void Rational_No::setQ(int q){
    try{
        if(q != 0){
            this->q = q < 0 ? -q : q;
            this->calValue();
            // this->is_negative = (q < 0) ? !this->is_negative : this->is_negative;
        }
        else 
            throw 0;
    }catch(int e){
        cout<<"Denominator can't be set to 0."<< nl;
    }
}

double rn::getValue() const{
    return this->value;
}

void rn:: calValue(){
    this->value = ((double)this->getP()) / (this->getQ());
}

bool Rational_No:: isNegative(){
    return this->is_negative;
}

void rn::simplyfy(){
    int gcf = this->_getGCF();
    this->p = (this->p/gcf);
    this->q = (this->q/gcf);
}

void Print(rn r1){
    cout<<r1.getP()<<nl<<"---"<<nl<<r1.getQ()<<nl<<"Value : "<<r1.getValue()<<nl;
}

int rn::_getGCF(){
    int a = this->p;
    int b = this->q;
    int res = 1;
    if(a == 0 || b == 0) return a+b;
    if(b > a){
        int temp = a;
        a = b;
        b = temp; 
    }
    while(res != 0 && a != 1 && b != 1){
        cout<<a<<" "<<b<<" "<<res<<nl;
        res = a % b;
        if(res != 0){
            a = b;
            b = res;
        }else{
            return b;
        }
    }
    return 1;
}

Rational_No Rational_No:: operator+ (const Rational_No& r1){
    int q(this->q * r1.getQ());
    int p1 = this->getP() * r1.getQ();
    int p2 = this->getQ() * r1.getP();
    Rational_No r2((p1 + p2) , q);
    r2.simplyfy();
    return r2;
}

Rational_No Rational_No:: operator- (const Rational_No& r1){
    int q(this->q * r1.getQ());
    int p1 = this->getP() * r1.getQ();
    int p2 = this->getQ() * r1.getP();
    Rational_No r2((p1 - p2) , q);
    r2.simplyfy();
    return r2;
}

Rational_No Rational_No:: operator* (const Rational_No& r1){
    int q = (this->q * r1.getQ());
    int p = this->getP() * r1.getP();
    Rational_No r2(p , q);
    r2.simplyfy();
    return r2;
}

Rational_No Rational_No:: operator/ (const Rational_No& r1){
    int p = this->getP() * r1.getQ();
    int q = (this->q * r1.getP());
    Rational_No r2(p , q);
    r2.simplyfy();
    return r2;
}

bool rn::operator!=(const rn& r1){
    return (this->getP() != r1.getP()) || (this->getQ() != r1.getQ());
}

bool rn::operator==(const rn& r1){
    return (this->getP() == r1.getP()) && (this->getQ() == r1.getQ());
}

void rn::operator++(){
    *this = *this + rn();
}

void rn::operator++(int){
    *this = *this + rn();
}

void rn::operator--(){
    *this = *this - rn();
}

void rn::operator--(int){
    *this = *this + rn();
}

ostream& operator<< (ostream& out , const rn& r1){
    out<<r1.getP()<<nl<<"---"<<nl<<r1.getQ()<<nl<<"Value : "<<r1.getValue()<<nl;
    return out;
}

istream & operator>> (istream &in , rn &r1){
    cout<<"Enter Numerator : \n";    
    in >> r1.p;
    cout<<"Enter Denominator : \n";
    in >> r1.q;
      
    return in;
}




int main(){
    // Check Line 3
    rn  r1(1,2) , r2(1,2);
    cin >> r1;
    cin >> r2;
    rn r3 = r1 + r2;
    cout<<r3;
    r3 = r1 - r2;
    cout<<r3;
    r3 = r1 * r2;
    cout<<r3;
    r3 = r1 / r2;
    cout<<r3;
    --r3;
    cout<<r3;

    return 0;
}



