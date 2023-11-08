#include <iostream>
using namespace std;
void print_star_square(int side){
    for(int i = 0;i < side;i++){
        for (int j = 0; j < side; j++){
            cout<<"*";
        }
        cout<<endl;
    }
}
int main(void){
    int side = 0;
    do {
        cout<<"你要打印边长多大的星型方阵呢？\n请输入：";
        cin>>side;
    }while(side < 1||side > 1000000);
    print_star_square(side);
    return 0;
}