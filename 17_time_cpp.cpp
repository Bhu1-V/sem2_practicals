#include <iostream>
using namespace std;

#define hours th
#define minutes tm
#define seconds ts

class time{
    private:
    unsigned int hours;
    unsigned int minutes;
    unsigned int seconds;
    void _refactor_time(){
        while(this->ts > 59){
            unsigned int additional_minutes = this->ts / 60;
            this->ts = this->ts % 60;
            this->tm += additional_minutes;
        }
        while(this->tm > 59){
            unsigned int additional_hours = this->tm / 60;
            this->tm = this->tm % 60;
            this->th += additional_hours;
        }
        while(this->th > 23){
            this->th = this->th % 24;
        }

        cout<<"\n\n"<<this->th<<" "<<this->tm<<" "<<this->ts<<"\n\n\n";
    }

    public:
    time(int h=0,int m=0,int s=0){
        this->th = h;
        this->tm = m;
        this->ts = s;
        _refactor_time();
    }


    time operator+ (const time& t){
        int h = this->th + t.th;
        int m = this->tm + t.tm;
        int s = this->ts + t.ts;
        time t1 = time(h,m,s);
        return t1;
    }

    void operator++(int){
        this->ts++;
        this->_refactor_time();
    }
    void operator++(){
        this->ts++;
        this->_refactor_time();
    }

};

int main(){
    time t(24,65,120);
    t++;
    t++;
    return 0;
}