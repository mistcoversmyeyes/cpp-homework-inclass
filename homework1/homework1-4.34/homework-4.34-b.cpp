#include<iostream>
using  namespace std;
float power_of(int base,int exponent ){
    int result=1;
    for(int i=0 ; i < exponent; i++){
        result*=base;
    }
    return result;
}

float factorial_of(int n){
    int factorial=1;
    if(n==0){
        return 1;
    }
    else{
        for (int i=1;i<=n;i++){
        factorial *=i;
        }
    return factorial;
    }
}



float calculate_e(int terms,int x){
    float result=0;
    for (int i=0 ;i <=terms;i++){
        result +=((power_of(x,i))/factorial_of(i));
    }
    return result;
}
 
 int main(){

    int x =0;
    int step=0;
    float result=0;
    cout<<"下面计算e的值 "<<endl;
    cout<<"请输入你要迭代的次数："<<endl;
    cin>>step;
    result=calculate_e(step,1);
    cout<<"e的n次方的近似值是: "<<result<<endl;
}


