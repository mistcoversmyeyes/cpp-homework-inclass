#include <iostream>
#include <strings.h>
#include <string.h>
#include <string>
using namespace std;
//下面一行的内容弃用
//#define MAX 10;//编译器会在编译时自动将所有为MAX的东西替换为10(这会被编译器认为是一个整数)
int const MAX = 10;
int get_sales();
int get_bonus(int sales);
int get_salary(int getbonus(int salse));


bool checked_if_legal(string argv);
int salary_calcu(string sales);//将参数中的销售额数字字符转化为数字,并且计算薪资;



int main(int argc,char *argv[]){
    //检查参数的输入是否合法
    if(argc == 1){
        cout<<"输入的参数太少";
        return 1;
    }
    for(int i = 1;i <argc;++i){
        if(!checked_if_legal(argv[i])){
            cout<<"请检查工资输入是否正确"<<endl;
            return 2;
        }
    }
    int num_of_levels = 8;
    //初始化一个整数数组储存每个工资区间的任务
    int salary_level[num_of_levels];
    //初始化一个工资组储存每个被输入员工的工资；
    int salary[argc - 1];
    //计算每位员工的实际工资
    for (int i = 1;i <argc;++i){
        salary[i - 1] = salary_calcu(argv[i]);
        
        for(int j = 0;(salary[i - 1] >= j*100 + 200)||(salary[i - 1] < j*100 + 300)||j < num_of_levels;j++){
            salary_level[j] += 1;//相应的收入等级人数增加一；
        }//遍历完所有的收入等级后循环结束
    }//遍历完所有的输入人员的销售额度后，循环结束
    //遍历一遍每个收入等级，并将每个收入等级的人数打印出来；
    for(int i = 0;i < num_of_levels;++i){
        cout<<"获得第"<<i + 1<<"等级薪水的人数是："<<salary_level[i]<<endl;
    }
    return 0;//表示程序正常执行；
}



bool checked_if_legal(string argv){
    for(int j = 0;j < MAX;++j){
        if(argv[j] > '0' && argv[j] < '9' ){
            return false;
        }
    }
    return true;
}
int salary_calcu(string sales){
    //使用标准库<string>内的函数将一串数字字符转化为一个数字整形
    int i_sales = std::stoi(sales);
    return (200 + i_sales*0.09);
}