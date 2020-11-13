#include <iostream>
using namespace std;

template <class t,int rows,int columns>
class matrix{
    t mat_arr[rows*columns];
    int row;
    int column;
    int size;

    int _getindex(int& r,int& c){
        return r*this->column + c;
    }
    
    void _setValue(int index,t value){
        *(mat_arr + index) = value;
    }

    t _getValue(int index) const {
        return *(mat_arr + index);
    }

    public:
    
    matrix operator+(const matrix& m1){
        matrix m2;
        if(this->row == m1.row && this->column == m1.column){
            for(int i = 0; i<this->size;i++ ){
                m2._setValue(i,(this->_getValue(i)) + (m1._getValue(i)));
            }
            return m2;
        }else{
            return 0;
        }
    }

    matrix operator-(const matrix& m1){
        matrix m2;
        if(this->row == m1.row && this->column == m1.column){
            for(int i = 0; i<this->size;i++ ){
                m2._setValue(i,this->_getValue(i) - m1._getValue(i));
            }
            return m2;
        }else{
            return 0;
        }
    }

    matrix(t x = 0){
        this->row = rows;
        this->column = columns;
        this->size = rows * columns;
        // this->mat_arr = new t [size];
        for(int i = 0;i < this->size;i++){
            *(this->mat_arr + i) = x;
        }
        cout<<"\n Made a Matrix of "<<this->row<<" Rows "<<this->column<<" Columns of value "<<x<<"\n";
    }
    
    matrix(const matrix& m2){
        this->row = m2.row;
        this->column = m2.column;
        this->size = m2.row * m2.column;
        // this->mat_arr = new t [size];
        for(int i = 0;i < this->size;i++){
            *(this->mat_arr + i) = *(m2.mat_arr + i);
        }
        cout<<"\n Made a Matrix of "<<this->row<<" Rows "<<this->column<<" Columns of value m2 values "<<"\n";
    }

    // ~matrix(){
    //     delete mat_arr;
    // }
    
    void print(){
        for(int i = 0; i < this->row ; i++){
            for(int j = 0; j< this->column ; j++){
                cout<<this->_getValue(this->_getindex(i,j))<<"\t";
            }
            cout<<"\n";
        }
    }
};

int main(){
    cout<<"Running";
    matrix <int,2,8> m1(-1);
    matrix <int,2,8>m2(m1);
    (m1 + m2).print();
    return 0;
}