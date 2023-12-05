#include <iostream>
#include <string>
using namespace std;
bool testPalindrome(string str,int left_hanside_index,int right_handside_index){
    //递归中止条件
    if(left_hanside_index >= right_handside_index ){   
        return true;
    }
    else {
        if(str[left_hanside_index] == str[right_handside_index] ){
        return testPalindrome(str,++left_hanside_index,--right_handside_index);
        }
        else{
            return false;
        }
    }
    
}

int main(void){
    string str = "";
    cout<<"请输入一个字符串: ";
    cin>>str;
    if(testPalindrome(str,0,str.length() - 1)){
        cout<<"你输入的是回文";
    }
    else{
        cout<<"你输入的不是回文";
    }
    
}