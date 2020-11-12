#include <iostream>
using namespace std;

class object{
    
    public:
    object(){
        cout<<"Object Instance Has been Created.\n";
    }
    void DoWork(){
        cout<<"Object is Running.....\n";
    }
    ~object(){
        cout<<"Object Instance Has Been Destroyed\n";
    }

};

int main(){
    object instance;
    instance.DoWork();
    return 0;
}
