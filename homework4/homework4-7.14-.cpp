#include <iostream>
#include <vector>
#include <array>
using namespace std;
int get_int_ord(int order);
void print_vector(std::vector<int> nums);


int main(void){
    bool does_num_exist[10][10];//初始化一个显示每个数字是否存在的二维数组
    //初始化这个二维数组;
    for(int i = 0;i < 9;i++){
        for(int j = 0;j <9;j++){
            does_num_exist[i][j] = false;
        }
    }
    //初始化输入的数字的数量
    int number_of_nums = 20;
    //初始化一个初始大小为1全部初始化为0 的容器
    vector<int> nums(0,0);
    //int nums[number_of_nums - 1];

    for(int i = 0;i < number_of_nums;++i){
        int temp_num = get_int_ord(i + 1);
        if(does_num_exist[((temp_num/10)%10)][temp_num%10] == false){
        does_num_exist[((temp_num/10)%10)][temp_num%10] = true;
        nums.push_back(temp_num);
        }
    }
    print_vector(nums);
}


int get_int_ord(int order){
    int input = 0;
    do{
    cout<<"请输入第"<<order<<"个数字"<<endl;
    cin>>input;
    }while(input < 10 ||input >= 100);
    return input;
}


//这个函数用来打印容器中的所有的元素
void print_vector(std::vector<int> nums){
    for(int num : nums){
        cout<<num<<' ';
    }
}