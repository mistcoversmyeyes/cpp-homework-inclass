#include <iostream>
using namespace std;

template<typename T>
T product(T a,T b){
    return a*b;
}//用于确定两个函数的乘积;


//测试
int main(){
    float number1 = 0;
    float number2 = 0;
    cout<<"请输入第一个数字"<<endl;
    cin>>number1;
    cout<<"请输入第二个数字"<<endl;
    cin>>number2;
    cout<<"两个数的乘积是: "<<product(number1,number2)<<endl;
}