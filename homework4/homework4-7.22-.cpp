#include <iostream>

const int raws = 8;

const int columns = 8;

const int direct = 8;

const int board[raws][columns] = {};

struct moving_styles{
    int horizontal;
    int vertical;
};

//声明用于存储的数组
moving_styles styles[direct];

//初始化一个二位bool组，用于记录相应的位置骑士是否来过
bool if_have_be_here[raws][columns];//全部被初始化为false;

//初始化一个表格用于计算并储存棋盘上每个位置的可达性；
int accessable_map[raws][columns];

//
void set_moving_styles(){
    //初始化styles
    styles[0].horizontal = 2;
    styles[0].vertical = -1;
    styles[1].horizontal = 1;
    styles[1].vertical = 2;
    styles[2].horizontal = -1;
    styles[2].vertical = 2;
    styles[3].horizontal = -2;
    styles[3].vertical = 1;
    styles[4].horizontal = -2;
    styles[4].vertical = -1;
    styles[5].horizontal = -1;
    styles[5].vertical = -2;
    styles[6].horizontal = 1;
    styles[6].vertical = -2;
    styles[7].horizontal = 2;
    styles[7].vertical = -1;
}

//函数接受行和列还有函数棋子走法的输入，返回一个整数（可达性）；
int get_how_many_ways(int raw,int column,moving_styles styles){
    int ways = 0;
    for(int i = 0;i < 8;i++){
        int temp_raw = 0;
        int temp_column = 0;
        temp_raw = raw +  styles.horizontal;
        temp_column = column + styles.vertical;
        if(temp_raw >=0 || temp_raw<=7 || temp_column >=0 || temp_column<=7){
            ways++;
        }
    }
    return ways;
}

//获取可达性的表；
int caculate_accessable(moving_styles styles){
    //遍历每一行，每一列；
    for(int i = 0;i < raws;i++){
        for(int j = 0;j < columns;j++){
            accessable_map[i][j] = get_how_many_ways(i,j,styles);
        }
    }
}

//移动骑士
void move_knight(int &current_raw,int &current_column){
    //遍历向八个方向移动后的位置的可达性，并进行比较，选择目的地可达性最低的方向移动
    int accessable[direct] = {};
    
    //获取不同方向的目的地的可达性
    for(int i = 0;i < direct;i++){
        accessable[i] = accessable_map[(current_raw - 1) + styles[i].horizontal][(current_column - 1) + styles[i].vertical];
    }

    //获取目的地可达性最小的方向
    int temp_min = 10;
    int temp_direct = 0; 
    for(int i = 0;i <direct;i++){
        if(accessable[i] < temp_min){
            temp_min = accessable[i];
            temp_direct = i;
        }
    }//获取方向完成

    current_raw += styles[temp_direct].horizontal;
    current_raw += styles[temp_direct].vertical;
} 

int main(){
    set_moving_styles();

}


