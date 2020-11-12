#include <iostream>
using namespace std;

class Rational_No
{
  private:
    int p;
    int q;
    bool isNegative;
  public:
    void setP(int p);
    int getP();
    void setQ(int q);
    int getQ();    
    Rational_No(int p = 1,int q = 1);
    bool isValid();
    ~Rational_No();
    Rational_No operator+(Rational_No);
};
Rational_No:: ~Rational_No(){
    cout<<"Deleted Your Rational No. {"<<this->p<<"/"<<this->q<<"}\n"; 
}

Rational_No:: Rational_No(int p = 1,int q = 1)
{
    this->isNegative = false;
    try{
        this->p = p < 0 ? -p : p;
        this->isNegative = (p<0);
        if(q != 0){
            this->q = q < 0 ? -q : q;
            this->isNegative = (q < 0) ? !this->isNegative : this->isNegative;  
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
    this->isNegative = p < 0;  
}
void Rational_No::setQ(int q){
    try
    {
        if(q!=0)this->q = q;
        else throw 0;
    }
    catch(int e)
    {
        std::cerr << "\nCan't Assign 0 to Denominator.\n" << '\n';
    }
}

int Rational_No::getQ(){
    return this->q;
}

int Rational_No::getP(){
    return this->p;
}

void Rational_No::setP(int p){
    this->p = p;
}

void Rational_No::setQ(int q){
    try{
        if(q != 0){
            this->q = q < 0 ? -q : q;
            // this->isNegative = (q < 0) ? !this->isNegative : this->isNegative;
        }
        else 
            throw 0;
    }catch(int e){
        cout<<"Denominator can't be set to 0.";
    }
}

Rational_No Rational_No:: operator+ (Rational_No r1){
    Rational_No r2 = Rational_No(1,1);
    r2.setQ(this->q * r1.getQ());
    int p1 = this->getP() * r1.getQ();
    int p2 = this->getQ() * r1.getP();
    
}



