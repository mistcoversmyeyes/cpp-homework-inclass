#include<iostream>
//计算整数的i次方(底数可以是负数、0！！！)checked
double power_of(int base,int exponent );
//获得无穷级数的第i项（check）
double get_i_term(int i);
//将前一千项加起来(calculate the summary of 1000 terms)
double addUp();

//调用主函数输出结果
int main(){
    std::cout<<"Π计算结果是："<<addUp()<<std::endl;

}


//计算整数的i次方(底数可以是负数、0！！！)checked
double power_of(int base,int exponent ){
    double result=1;
    for(int i=0 ; i < exponent; i++){
        result*=base;
    }
    return result;
}


//获得无穷级数的第i项（check）
double get_i_term(int i){
    double value_of_term_i=4/((power_of(-1,i))*(2*i+1));
    return value_of_term_i;
}

//将前一千项加起来(calculate the summary of 1000 terms)

double addUp(){
    double result =0;
    for(int j =0 ;j < 1000 ; j++){
        result += get_i_term(j);
    }
    return result;


}
