#include <iostream>
using namespace std;

class account{

    unsigned int _account_no;
    char* name;
    unsigned int balance;

    void _generateAccountNo(){  
        this->_account_no = 1;
        for(int i = 0 ; *(this->name + i) != 0 ; i++){
            this->_account_no = ( (this->_account_no) * (*(this->name + i)) % 100000);
        }
        cout<<"Genereated Account Number = "<<this->_account_no<<"\n";
    }

    public:
    account(char* n){
        this->name = n;
        _generateAccountNo();
        this->balance = 0;
    }
    ~account(){
        delete[] name;
    }

    unsigned int getBalance(){
        return this->balance;
    }

    void credit(int add){
        this->balance += add;
    }

    void debit(int sub){
        if(this->balance > sub) {
            this->balance -= sub;
        }else{
            cout<<"Insufficient Amount to Avialable Balance "<<getBalance()<<endl;
        }
    }

    void getAccountDetails(){
        cout<<"\n_____LOOTERS_BANK______\n";
        cout<<"ACC NO  : "<<this->_account_no<<"\n";
        cout<<"Name    : "<<this->name<<endl;
        cout<<"Balance : "<<this->balance << endl<<endl;        
    }

};

int main(){
    account a1((char*)"BhuvanVemula");
    a1.getAccountDetails();
    a1.credit(4684);
    a1.getAccountDetails();
    a1.debit(10000);
    a1.debit(250);
    a1.getAccountDetails();

    return 0;
}