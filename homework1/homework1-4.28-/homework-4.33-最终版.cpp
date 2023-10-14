#include<iostream>
using namespace std;
int main(){
    for (int b=0 ; b<8 ;b++){
        if(b%2==0){
            for(int i=0 ; i < 8; i++){
            cout<<"*"<<" ";
            }
        }
        else{
            cout<<" ";
            for(int i=0 ; i < 8; i++){
            cout<<"*"<<" ";
            }
        }
        cout<<endl;
    }
    
}