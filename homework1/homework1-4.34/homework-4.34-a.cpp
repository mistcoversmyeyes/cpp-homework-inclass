#include<iostream>
using  namespace std;

int main(){
    int n=0;
    int factorial=1;
    cout<<"请输入一个数字n："<<endl;
    cin>>n;
    for (int i=0;i<n;i++){
        factorial *=i+1;
    }
    cout<<"n的阶乘是"<<factorial<<endl;

    return 0;
}