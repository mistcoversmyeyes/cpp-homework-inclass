#include<iostream>
using namespace std;

//初始化每月的天数
int const days_of_month = 2;

//初始化货物的数量;
int const types_of_goods = 5;

//初始化员工人数
const int num_of_salers = 4;

class saler{
    public:
    //用于从用户处获得这个obj的Saler成员

    //void get_saler(){
    //    cout<<"请输入销售员的编号: ";
    //    cin>>index_of_saler;
    //}
    
    //用于从用户处获得这个obj的goods_index成员

    //用于从用户处获得这个obj的sales_amount_each_day成员

    void get_each_day_sales_amount_of(int index_of_goods){
        cout<<"请按顺序输入编号为"<<index_of_goods + 1<<"的商品的每日销售额"<<endl;
        for(int i = 0;i < days_of_month;i++){
            cout<<"这位售货员"<<"第"<<i + 1<<"天商品"<<index_of_goods + 1<<"的销售额为: ";
            cin>>sales_amount_each_day[index_of_goods][i];
        }
    }

    //用于访问成员sales_amout_each_day
    int show_sales_amount_each_day(int index,int day){
        return sales_amount_each_day[index][day];
    }

    //用于访问成员sales_amount
    
    int shows_total_sales_amount_of(int index_num){
        for (int i = 0;i < days_of_month;i++){
            sales_amount_total[index_num] += sales_amount_each_day[index_num][i];
        }
        return sales_amount_total[index_num];
    }

    private:
    int sales_amount_each_day[types_of_goods][days_of_month];
    int sales_amount_total[types_of_goods];
};

//定义函数
void print_sales(int sales[num_of_salers][types_of_goods]){
    //cout<<"        ";
    //for(int i = 0;i < types_of_goods;i++){
    //    cout<<
    //}
    for(int i = 0;i < num_of_salers;i++){
        cout<<"销售员"<<i + 1<<" ";
        for(int j = 0;j < types_of_goods;j++){
            cout<<sales[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main(){
    
    saler saler[num_of_salers] = {};
    
    //初始化一个数组用于储存销售额；
    int sales[num_of_salers][types_of_goods];

    //从用户处获取每位员工的所有纸条信息；
    for(int i = 0;i < num_of_salers;i++){
        //告诉用户现在要输入有关第几位售货员的纸条
        cout<<"请在下面按照提示输入第"<<i + 1<<"位售货员的纸条"<<endl;

        //从用户处一次获取该售货员每种商品每天的销售额信息
        for(int goods_index = 0;goods_index < types_of_goods;goods_index++){
            saler[i].get_each_day_sales_amount_of(goods_index);
        }

        //获取完一位售货员销售信息后用函数打印出这位售货员每种商品该月销售额;
        for(int goods_index = 0;goods_index < types_of_goods;goods_index++){
            saler[i].shows_total_sales_amount_of(goods_index);
        }
    }
    //将所得的销售额传入储存销售额的数组里面;
    for(int i = 0;i < num_of_salers;i++){
        for(int j = 0;j < types_of_goods;j++){
            sales[i][j] = saler[i].shows_total_sales_amount_of(j);
        }
    }
    
    //调用函数答应出统计后的表格的内容；
    print_sales(sales);
}