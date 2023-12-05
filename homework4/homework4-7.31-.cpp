#include <iostream>
#include <string>

using namespace std;

void stringReverse(string str,int start_index){
    cout<<str[str.length() - 1 -start_index];
    //递归的终止条件;
    if(start_index == str.length() - 1){
        return;
    }
    stringReverse(str, ++start_index);
}

int main(void){
    string str = "";
    cout<<"请输入你需要逆序打印的数字: ";
    cin>>str;
    stringReverse(str,0);
}