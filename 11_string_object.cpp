#include <iostream>
using namespace std;

class String{
    
    char* str;
    int length;
    
    public:

    String(char* in_str){
        this->str = in_str;
        for(length = 0; *(this->str + length) != 0 ; length++);
        cout<<"\nCreated A String of Lenght "<<this->length<<endl;
    }

    void concat(const String& s2){
        int len = s2.length;
        int len2 = this->length;
        int i = 0;
        char* new_str = new char[len+len2];
        while(i<len2){
            *(new_str + i) = *(this->str + i);
            i++;
        }i = 0;
        while(i<len){
            *(new_str + len2 + i) = *(s2.str + i);
            i++;
        }
        *(new_str + len2 + i ) = 0;
        this->length += s2.length;
        delete[] this->str;
        this->str = new_str;
        cout<<"\nNew String = "<<this->str<<"\n";
    }

    bool compare(String s){
        if(this->length == s.length){
            for(int i = 0;i < this->length ; i++){
                if(*(this->str + i) != *(s.str + i)) return false;
            }
            return true;
        }else{
            return false;
        }
    }

};

int main(){
    String s1((char*)"Hello") , s2 ((char*)"Hello");
    s1.concat(s2);
    cout<<"s1 = s2 => "<<s1.compare(s2);
    return 0;
}