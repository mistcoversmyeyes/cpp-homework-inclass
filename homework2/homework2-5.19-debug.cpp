#include<iostream>
using namespace std;
//计算整数的i次方(底数可以是负数、0！！！)checked
double power_of(int base,int exponent ){
    int result=1;
    for(int i=0 ; i < exponent; i++){
        result*=base;
    }
    return result;
}


//获得无穷级数的第i项
double get_i_term(int i){
    double value_of_term_i=4/((power_of(-1,i))*(2*i+1));
    return value_of_term_i;
}
int main(){
    cout<<get_i_term(1)<<endl;
}