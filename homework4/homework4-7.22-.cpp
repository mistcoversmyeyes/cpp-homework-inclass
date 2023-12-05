#include <iostream>
#include <random>
#include <ctime>

using namespace std;

const int raws = 8;

const int columns = 8;

const int direct = 8;

const int board[raws][columns] = {};



//初始化一个二维bool组，用于记录相应的位置骑士是否来过
bool knight_has_visited[raws][columns] = {};

//初始化移动方式结构体，用于储存不同方式在水平和竖直方向的移动步数；
struct moving_styles{
    int horizontal;
    int vertical;
};

//声明用于存储的数组
moving_styles styles[direct];

//弃用
//bool if_have_be_here[raws][columns];//全部被初始化为false;
//

//初始化一个表格用于计算并储存棋盘上每个位置的可达性；
int accessable_map[raws][columns];

void set_moving_styles(){
    //初始化styles
    styles[0].horizontal = 2;
    styles[0].vertical = 1;

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


//movez_knight 的下属函数，用于检测每次时向各个方向移动会不会移出棋盘外面   
//会移动到外面返回true  不会则返回false
bool check_if_out_of_keyboard(int next_raw,int next_column){
    if(next_raw > 8 || next_column > 8 || next_raw < 1 || next_column < 1){
        return true;
    }
    return false;
}

//move_knight 的下属函数，用于检测每次移动时各个方向是否会移动到原来走过的地方；
bool check_if__hvbehere(int next_raw,int next_column){
    //查询到达表,如果到达表显示到达过,那么返回true
    if(knight_has_visited[next_raw][next_column] == true){
        return true;
    }
    return false;
}

//calculate_accessable 的下属函数   函数接受行和列还有函数棋子走法的输入，返回一个整数（可达性）；
int get_how_many_ways(int raw,int column,moving_styles styles[direct]){
    int ways = 0;

    for(int i = 0;i < direct;i++){
        int next_raw = 0;
        int next_column = 0;
        next_raw = raw + styles[i].horizontal;
        next_column = column + styles[i].vertical;
        if(!check_if_out_of_keyboard(next_raw,next_column) && !knight_has_visited[next_raw][next_column]){
            ways++;
        }
    }
    return ways;
}

//获取真随机数的函数
int get_real_random(int min,int max){
//初始化随机数引擎
    
    // 创建随机数引擎并初始化种子
    std::default_random_engine engine(static_cast<unsigned int>(time(nullptr)));
    
    // 创建均匀分布对象··
    std::uniform_int_distribution<int> distribution(min, max);

    return distribution(engine);
}

//获取可达性的表；
void calculate_accessable(moving_styles styles[direct]){
    //遍历每一行，每一列；
    for(int i = 0;i < raws;i++){
        for(int j = 0;j < columns;j++){
            accessable_map[i][j] = get_how_many_ways(i,j,styles);
        }
    }
}



//移动骑士
void move_knight(int current_raw,int current_column,int pace){
    //递归中止条件；
    if(pace == 64){
        return;
    }
    
    

    //将当前骑士所在的位置记为已经访问
    knight_has_visited[current_raw][current_column] = true;

    calculate_accessable(styles);

    //遍历向八个方向移动后的位置的可达性，并进行比较，选择目的地可达性最低的方向移动
    int accessable[direct] = {};

    cout<<"从("<<current_raw<<","<<current_column<<")移动到";

    //获取不同方向的目的地的可达性
    for(int i = 0;i < direct;i++){
        //增加对移动后坐标是否超出棋盘的判断；
        if(check_if_out_of_keyboard(current_raw  + styles[i].horizontal,current_column  + styles[i].vertical)){
            accessable[i] = 10;//"10"表示不可达;
        }
        //增加对移动后坐标是否为先前已经走过的坐标的判断;
        else if(check_if__hvbehere(current_raw  + styles[i].horizontal,current_column  + styles[i].vertical)){
            accessable[i] = 10;//"10"表示不可达;
        }
        else{
            accessable[i] = accessable_map[(current_raw - 1) + styles[i].horizontal][(current_column - 1) + styles[i].vertical];
        }
    }//(current_raw - 1) + styles[i].horizontal 对这个下标的访问可能出现了段错误；

    //获取目的地可达性最小的方向
    int temp_min = 9;
    int temp_directs[8] = {}; 
    int num_of_direct = 0;//记录方向的数量
    for(int i = 0;i <direct;i++){
        if(accessable[i] < temp_min){
            temp_min = accessable[i];
            temp_directs[num_of_direct] = i;
            num_of_direct++;
        }
    }//获取dirextion's'完成

    //如果没有一个方向可以走，就是说temp_min == 9 那么就从头再来一次move_knight()直到走完全程
    if(temp_min == 9){
        cout<<"\n完蛋了,走到死胡同了,让我们再来一次呗"<<endl;
        move_knight(4,4,0);
    }
    //随机选择一名幸运方向；
    int random_direct = get_real_random(0,num_of_direct - 1);
    current_raw += styles[temp_directs[random_direct]].horizontal;
    current_column += styles[temp_directs[random_direct]].vertical;

    //步数计数器自增一次
    pace++;
    
    //打印完后面的部分；
    cout<<pace<<"("<<current_raw<<","<<current_column<<")"<<endl;

    move_knight(current_raw,current_column,pace);
} 



int main(){
    int current_raw = 4;
    int current_column = 4;

    //初始化移动方式；
    set_moving_styles();


    int pace = 0;

    //
    move_knight(current_raw,current_column,pace);
    
}


