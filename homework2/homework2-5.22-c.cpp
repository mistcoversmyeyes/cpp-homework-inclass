#include <iostream>

using namespace std;
//check所有的!((×<=8)&&(y>4))==!(×<=8)||! (y>4)
int main(){
    //不妨取x , y 均为小于100的整数
    for (int x=0 ; x <=100;++x ){
        for(int y = 0; y<=100; ++y){
            if (!((x<=8)&&(y>4))==!(x<=8)||! (y>4))
            std::cout<<"!((x<=8)&&(y>4))==!(y<=8)||! (y>4)等价"<<endl;
            return 0;
        }
    }
     std::cout<<"!((x<=8)&&(y>4))==!(y<=8)||! (y>4)不等价"<<endl;
    return 1;
}