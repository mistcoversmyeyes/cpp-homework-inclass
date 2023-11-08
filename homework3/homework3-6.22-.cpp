#include <iostream>
using namespace std;
void print_square(int side,char c){
    for(int i = 0;i < side;i++){
        for (int j = 0; j < side; j++){
            cout<<c;
        }
        cout<<endl;
    }
}
int main(void){
    int side = 0;
    char character ;
    do {
        cout<<"你要打印的图案是什么（请在右边输入）：";
        cin>>character;
        cout<<"你要打印边长多大的"<<character<<"方阵呢？\n请输入：";
        cin>>side;
    }while(side < 1||side > 1000000);
    print_square(side,character);
    return 0;
}