#include<iostream>
using namespace std;
int main(){
    //初始化直角边与斜边
    int a = 0 ;
    int b = 0 ;
    int c = 0 ;
    //遍历a,b,c的所有组合，从内到外分别控制遍历a,b,c.
    for (int i = 1;i <= 500;++i){
        a = i;
        for (int i = 1;i <= 500;++i){
            b = i;
            for (int i = 1;i < 500;++i){
                c = i;
                if  (a*a+b*b==c*c){
                    cout<<"side1: "<<a<<"\nside2: "<<b<<"\nhypotenuse: "<<c<<"\n"<<endl;
                }
            }
        }

    }
}