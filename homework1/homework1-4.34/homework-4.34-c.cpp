#include<iostream>
using  namespace std;
double power_of(int base,int exponent ){
    int result=1;
    for(int i=0 ; i < exponent; i++){
        result*=base;
    }
    return result;
}

double factorial_of(int n){
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



double calculate_e(int terms,int x){
    double result=0;
    for (int i=0 ;i <=terms;i++){
        result +=((power_of(x,i))/factorial_of(i));
    }
    return result;
}
 
int main(){

    int x = 0;
    int step = 0;
    double result = 0;
    char continueChoice;

    do {
        cout << "请输入你要计算e的几次方: " << endl;
        cin >> x;
        cout << "请输入你要迭代的次数：" << endl;
        cin >> step;

        result = calculate_e(step, x);
        cout << "e的n次方的近似值是: " << result << endl;

        cout << "您想要继续计算吗? (y/n): ";
        cin >> continueChoice;
    } while (continueChoice == 'y' || continueChoice == 'Y');

    return 0;
}



