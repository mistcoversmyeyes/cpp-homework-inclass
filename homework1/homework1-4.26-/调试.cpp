#include<iostream>
using namespace std;
int power_of_number(int num,int pow){
    int outcome=1;
    for(int i=0;i<pow;i++){
        outcome=outcome*num;
    }
    return outcome;
}


    
    
int main(){
    int number=0;
    int length=0;
    cin>>number;
    cin>>length;
    int half_length=length/2;//获取对称中心
    cout<<half_length;
}