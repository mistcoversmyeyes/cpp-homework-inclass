#include <iostream>

using namespace std;




int main(){
    float salary =0 ;
    int identity = 0;
    do{
        cout<<"请输入你的员工代码：";
        cin >>identity;
    }while(identity > 4);

    
    switch (identity) 
    {
    case  1:
        /* code */
        cout<<"你的工资固定，你不需要计算工资"<<endl;
        break;
    case  2:{
        float sal_per_hour =0;
        int hour =0 ;
        cout<<"请输入你的小时工资："<<endl;
        cin >>sal_per_hour;
        cout<<"请输入你的工作时间："<<endl;
        cin >>hour;


        if(hour <= 40){
            salary =(hour*sal_per_hour);
        }
        else{
            salary = (40*sal_per_hour + (hour-40)*(1.5*sal_per_hour));
        }
        cout <<"你的工资是："<<salary<<endl;
        break;
    }
    case 3:{

        float sale_money = 0;
        cout<<"请输入你的销售总额："<<endl;
        cin >>sale_money;
        salary = (0.057*sale_money + 250);
        cout <<"你的工资是："<<salary<<endl;
        break;
    }
    case 4:{
        float per_salary;
        int number = 0;
        cout <<"你所负责的产品每件记工资多少钱："<<endl;
        cin >>per_salary;
        cout<<"你卖出了多少产品：";
        cin >>number;
        salary  = number*per_salary;
        cout <<"你的工资是："<<salary<<endl;
        break;
    }
    default:
        cout<<"你所输入的代码有误，请检查你的工资代码 "<<endl;
        break;
    }
    
}
