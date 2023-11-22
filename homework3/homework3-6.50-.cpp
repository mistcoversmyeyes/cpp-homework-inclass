#include <iostream>
int tripleByValue(int i){
    i *= 3;
    return i;
}

void tripleByReference(int &i){
    i *= 3;
}

int main(){
    int count = 0;
    std::cout<<"请输入你要操作的数";
    std::cin>>count;
    std::cout<<"按值传递的结果: "<<tripleByValue(count)<<std::endl;
    tripleByReference(count);
    std::cout<<"按引用传递的结果: "<<count<<std::endl;
}
