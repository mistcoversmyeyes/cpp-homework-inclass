#include <iostream>

using namespace std;
//check所有的!((i>4)||(j<=6))==(!(i>4)&&!(j<=6))
int main(){
    //不妨取x , j 均为小于100的整数
    for (int i=0 ; i <=100;++i ){
        for(int j = 0; j<=100; ++j){
            if (!((i>4)||(j<=6))==(!(i>4)&&!(j<=6)))
            std::cout<<"!((i>4)||(j<=6))等价"<<endl;
            return 0;
        }
    }
     std::cout<<"!((i>4)||(j<=6))等价不等价"<<endl;
    return 1;
}