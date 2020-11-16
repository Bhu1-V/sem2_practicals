#include <iostream>
using namespace std;

void mysteryFun(char* input){
    char output[200];
    char better_output[200];
    // Iterator of Input String.
    int i = 0;
    // Iterator for Output String.
    int oi = 0;
    // Iterator for Better Output.
    int bi = 0;
    while(input[i]){
        int count = 1;
        int j = i+1;
        while(input[j] == input[i]){
            count++;
            j++;
            if(count == 9) break;
        }
        output[oi++] = count + 48;
        better_output[bi++] = count + 48;
        output[oi++] = input[i];
        better_output[bi++] = input[i];
        better_output[bi++] = 32;
        i = j;
    }
    // Making Last character '\0' making it the end of string.
    output[oi] = 0;
    cout<<"OutPut = "<<output<<"\n";
    // Making Last character '\0' making it the end of string.
    better_output[bi] = 0;
    cout<<"\nBetter_OutPut = "<<better_output<<"\n";

}

int main(){
    char in[20];
    while(in[0] != 48){
        cout<<"Enter an Integer For Input in mysteryFun:\n";
        cin>>in;
        mysteryFun(in);
        cout<<"\n\n Enter 0 to Stop Loop\n\n";
    }
    return 0;
}