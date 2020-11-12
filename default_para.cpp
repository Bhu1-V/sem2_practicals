#include <iostream>
using namespace std;

int increment_by_x(int n,int x = 1){
    return n+x;
}

int main(){
    int n,x;
    cout<<"Enter a Interger and Increment value\n";
    cin>>n>>x;
    cout<<"Output without second parameter \n> ";
    cout<<increment_by_x(n)<<endl;
    cout<<"Output with second parameter \n> ";
    cout<<increment_by_x(n,x)<<endl;
    return 0;
}