#include <iostream>
using namespace std;

void hanoi(int the_num_of_disks,int start_peg,int end_peg,int temperary_peg){
    //确定中止条件
    if(the_num_of_disks == 1){
        cout<<start_peg<<"->"<<end_peg<<endl;
        return;
    }
    //先将
    hanoi(the_num_of_disks - 1,start_peg,temperary_peg,end_peg);

    cout<<start_peg<<"->"<<end_peg<<endl;

    hanoi(the_num_of_disks - 1,temperary_peg,end_peg,start_peg);
}
int main(){
    int num_of_disks = 0;
    cout<<"请输入你想获取几个盘子的回复路线: ";
    cin>>num_of_disks;
    hanoi(num_of_disks,1,3,2);
}
