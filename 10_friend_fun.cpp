#include <iostream>
using namespace std;

class object{
    private:
    
    int private_member;
    
    public:
    object(){
        this->private_member = 0;
    }
    friend void accessPrivateMember(object& a,int add);
};

void accessPrivateMember(object& instance , int add){
    instance.private_member += add;
    cout<<"Private Member = "<< instance.private_member<<endl;
}

int main(){
    object instance;
    accessPrivateMember(instance,20);
    return 0;
}