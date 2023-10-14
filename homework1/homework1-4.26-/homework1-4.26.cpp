#include<iostream>
using namespace std;
int power_of_number(int num,int pow){
    int result=1;
    for(int i=0 ; i < pow; i++){
        result=result*num;
    }
    return result;
}

bool judge_palindrome(int number,int length){
    int half_length=length/2;//获取对称中心（正确）
    for(int i=0;i<half_length;i++){
        int oposite_of_i=length-(i+1);//找出和第i位对称的位
        int a=(number/power_of_number(10,i))%10;//获取第i+1位数值
        int b=number%(number/power_of_number(10,oposite_of_i))%10;//获取第i+1位对称位的数值
        if(a!=b)//判断两个数值是否相等
            return false;
        }
    return true;
}

int main(){
    int number=0;
    int judgement=0;
    int length=0;
    cout<<"please print the number you want to judge wheter it is palindrome :"<<endl;
    cin>>number;
    cout<<"数字的长度是："<<endl;
    cin>>length;
    judgement=judge_palindrome(number,length);
    
    if(judgement)
        cout<<"是回文数"<<endl;
    else
        cout<<"不是回文数"<<endl;
    



}