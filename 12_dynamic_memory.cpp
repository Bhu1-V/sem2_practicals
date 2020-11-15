#include <iostream>
using namespace std;

class object{
    public:
    object(){
        cout<<"Object Instance Created\n\n";
    };
    ~object(){
        cout<<"Object Instance Destroyed\n\n";
    }
};

void create_an_object(){
    object* instance_pointer = new object();
    cout<<">> Created but never Destroyed \n\n";
}

void create_and_destroy_object(){
    object* instance_pointer = new object();
    cout<<">> Using Object Instance.\n\n";
    delete instance_pointer;
}

int main(){
    
    create_an_object();
    cout<<">> Let's Do It Properly.\n\n";
    create_and_destroy_object();

    return 0;
}