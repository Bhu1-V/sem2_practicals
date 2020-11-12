#include <iostream>
using namespace std;

class Particale{
    private:
        static int count;
        int x;
        int y;
    public:
        static int getCount (){
            return count;
        };
        Particale(double,double);
};

Particale::Particale(double x=0, double y=0){
    this->x = x;
    this->y = y;
    count++;
}
int Particale::count = 0;
int main(){
    Particale x[10];
    cout<<"No. of Partiles = "<<Particale::getCount();
    return 0;
}