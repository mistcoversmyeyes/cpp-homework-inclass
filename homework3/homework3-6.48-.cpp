#include <iostream>
#include <iomanip>
#include <random>  // 包含 C++11 随机数生成功能
#include <ctime>

using namespace std;
//初始化赌徒银行的钱数;
int bankBalance = 1000;//全局变量使得后面的所有更改均会改变银行的钱数，且不需要传参
int dice_roll();
bool if_win(int guess_dice);
bool if_want_to_continue();
void single_game(int &bankBalance);

int main(){
    //调用函数开始第一局
    single_game(bankBalance);
    //询问是否开启下一局;
    if(!if_want_to_continue()){
        cout<<"你结束时还剩下: "<<bankBalance<<'$'<<endl;
        return 0;
    }
    else{
        single_game(bankBalance);
    }
}


int dice_roll() {
    // 使用默认的随机数生成引擎，生成从 1 到 6 的均匀分布的伪随机整数
    default_random_engine engine(static_cast<unsigned int>(time(0)));
    uniform_int_distribution<unsigned int> randomInt(1, 6);
    return randomInt(engine);//函数返回一个骰子的点数
} // 结束 main


bool if_win(int guess_dice){
    //如果猜测的点数和掷出的点数一样,就win
    if (guess_dice == dice_roll()){
        return true;
    }
    //默认不一样,返回false失败;
    return false;
}
bool if_want_to_continue(){
    char chose = ' ';
    cout<<"你目前的余额是: "<<bankBalance<<endl;
    cout<<"你想继续下一局吗?(y/n)"<<endl;
    cin>>chose;
    if(chose == 'Y' || chose == 'y'){
        return true; 
    }
    if(chose == 'N' || chose == 'n'){
        return false;
    }
    return false;
}

//创建一个每局局内状况的函数,专注于一局,
//它将接受当前的银行余额,但是没有返回值;
//注意,这个函数需要在开始游戏之前检查银行余额是否大于0;
void single_game(int &bankBalance){
    //检查余额是否大于零
    if(bankBalance < 0){
        cout<<"你寄了"<<endl;
        return;
    }
    //初始化每局的赌注变量;
    int lay = 0;
    //初始化每局赌徒猜测的点数;
    int guess_dice = 0;
    //从用户获取一个小于1000的整数;
    do{
        cout<<"请输入你的赌注: ";
        cin>>lay;
    }while(lay > bankBalance);
    //获取这局用户猜测的点数;

    //do{
    //    cout<<"请输入你猜测的点数: ";
    //    cin>>guess_dice;
    //}while(guess_dice > 6||guess_dice < 1);
    
    //利用函数判断赌徒是否猜对了点数;
        //if    true
        //  bankBalance + lay
        //if    false 
        //  bankBalance - lay
    if(if_win(guess_dice)){
        bankBalance += lay;
        cout<<"你赢了这一局,并且你现在的银行金额为: "<<bankBalance<<endl;
    }
    else{
        bankBalance -= lay;
        cout<<"你输了这一局,并且你现在的银行金额为: "<<bankBalance<<endl;
    }
}
