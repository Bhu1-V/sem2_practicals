#include <iostream>
using namespace std;

template<typename t>
void swp(t& a,t& b){
    cout<<"\n\nBefore SWAP "<<a<<" "<<b<<"\n\n";
    t temp;
    temp = a;
    a = b;
    b = temp;
    cout<<"After SWAP "<<a<<" "<<b<<"\n";
}

int main(){
    int ia = 1 , ib = 2;
    float fa = 1.25 , fb = 5.444;
    bool ba = true , bb = false;

    swp(ia,ib);
    swp(fa,fb);
    swp(ba,bb);
    return 0;
}