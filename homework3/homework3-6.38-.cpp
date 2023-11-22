#include <iostream>
#include <stack>
using namespace std;
//固定死圆盘上限；
int const MAX = 24;//可能overflow;
//初始化不依赖输入的三个杆子
class peg{
    public:
    int num_of_disks;//圆盘的数量
    stack<int> disks;//创建盘子栈；
    void add_disks(int disks_size){
        num_of_disks++;
        disks.push(disks_size);//先不执行大小检查，直接压进去；
    }
    private:
    ;
};
//预声明下面用到的函数；
void move_disks();
void haino();

void move_disks(int start,int destination,peg pegs[]){
    int disk_want_to_move = pegs[start].disks.top();
    pegs[start].disks.pop();
    pegs[destination].disks.push(disk_want_to_move);
}


void haino(int unhainoed_disks_number,peg pegs[]){
    //确定递归中止条件；
    if (unhainoed_disks_number == 1){
        for(int i = 0;i < 2;i++){
            if(pegs[i].num_of_disks == 1){
                move_disks(i,2,pegs);
            }
        }
    }
    //进行递归；
    return haino(unhainoed_disks_number - 1,pegs);
}

//checked(temperare);
void print_the_expressions_of_onepeg(peg pegs){
    int size_of_each_disk[pegs.num_of_disks];
    for (int i = 0;i < pegs.num_of_disks;++i){
        size_of_each_disk[i] = pegs.disks.top();
        for (int j = 0;j < size_of_each_disk[i];j++){
            cout<<"#";
        }
        //打印一次清空一次栈顶；
        pegs.disks.pop();
        cout<<endl;
    }
}

void print_the_expressions_of_allpegs(peg pegs[]){
    cout<<"pegs1:";
    print_the_expressions_of_onepeg(pegs[0]);
    cout<<"pegs2:";
    print_the_expressions_of_onepeg(pegs[1]);
    cout<<"pegs3:";
    print_the_expressions_of_onepeg(pegs[2]);
}

int main(void){
    //对汉诺塔的初始状态进行准备；
    int total_num_of_disks = 0;
        //初始化描述每个peg(棍子)状态的peg组；
    peg pegs[2];
        //初始化pegs
    pegs[0].num_of_disks = total_num_of_disks;
    pegs[1].num_of_disks = 0;
    pegs[2].num_of_disks = 0;
    std::cout<<"你想要玩几个盘子的汉诺塔：";
    cin>>total_num_of_disks;
        //给第一个peg压入所有的圆盘（disks）;
    for (int i = 0;i < total_num_of_disks;++i){
        pegs[0].disks.push(total_num_of_disks - i);
    }
    //准备完成；
    print_the_expressions_of_allpegs(pegs);
    //使用hano进行归档；
    haino(total_num_of_disks,pegs);
    print_the_expressions_of_allpegs(pegs);

    
}