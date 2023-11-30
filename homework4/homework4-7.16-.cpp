#include <iostream>
#include <iomanip>
#include <random>
#include <ctime>

using namespace std;

int main() {
    // 创建随机数生成器引擎，使用系统时间作为种子
    static default_random_engine engine(static_cast<unsigned int>(time(nullptr)));
    
    // 创建一个分布对象，范围从1到6
    uniform_int_distribution<int> distribution(1, 6);
    
    // 创建一个一维数组用于存放掷出点数的次数，初始化所有元素为0
    int frequency[11] = {};  // 数组索引从0到10，对应点数之和的2到12

    // 掷骰子36000次
    for (int i = 0; i < 36000; ++i) {
        int roll1 = distribution(engine);  // 第一个骰子
        int roll2 = distribution(engine);  // 第二个骰子
        int sum = roll1 + roll2;           // 计算点数之和
        frequency[sum - 2]++;             // 索引是 sum - 2，因为数组索引从0开始
    }

    // 打印出每个点数之和的频数
    for (int i = 0; i < 11; ++i) {  // 遍历frequency数组
        cout << "点数之和为" << i + 2 << "的有: " << frequency[i] << endl;
    }
}
