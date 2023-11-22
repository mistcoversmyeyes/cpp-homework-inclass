#include <iostream>
template <class T>
T sum(T a,T b){
    return a + b;
}
int main(){
    float a = 0;
    float b = 0;
    std::cout<<"a是多少: ";
    std::cin>>a;
    std::cout<<"b是多少: ";
    std::cin>>b;
    float summary = 0;
    summary = sum(a,b);
    std::cout<<"sum是: "<<summary<<std::endl;
}