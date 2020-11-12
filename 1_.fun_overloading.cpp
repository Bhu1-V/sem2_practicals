#include <iostream>
using namespace std;

int add(int a , int b){
    return(a+b);
}
double add(double a,double b){
    return(a+b);
}

int main(){
    int x,y;
    double a,b;

    cout<<"-----Add Two Integers-----\n";
    cout<<"-----Enter Two Intergers--\n> ";
    cin>>x>>y;
    cout<<"-----Output:--------------\n";     
    cout<<add(x,y)<<"\n";
    cout<<"-----Enter Two Floats--\n> ";
    cin>>a>>b;
    cout<<"-----Output--------------\n";     
    cout<<add(a,b)<<"\n";
}