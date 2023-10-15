#include<iostream>
using namespace std;

// 计算 num 的 pow 次方
int power_of_number(int num, int pow) {
    int result = 1;
    for (int i = 0; i < pow; i++) {
        result *= num;
    }
    return result;
}

// 计算 n 的阶乘
int calculate_fac_n(int n) {
    int factorial = 1;
    for (int i = 1; i <= n; i++) {
        factorial *= i;
    }
    return factorial;
}

// 使用泰勒级数计算 e 的 x 次方的近似值
float calculate_e(int step, int x) {
    float result = 1;  // 初始化为 1，因为泰勒级数的第一个项是 1
    float num = 1;  // 存储 num 的 i 次方
    float den = 1;  // 存储 i 的阶乘
    for (int i = 1; i <= step; i++) {
        num *= x;
        den *= i;
        result += (num / den);
    }
    return result;
}

int main() {
    int x = 0;
    int step = 0;
    cout << "请输入你要计算e的几次方: " << endl;
    cin >> x;
    cout << "请输入你要迭代的次数：" << endl;
    cin >> step;
    // 检查输入是否有效
    if (step < 0 || x < 0) {
        cout << "错误：幂和迭代次数必须为非负数。" << endl;
        return 1;
    }
    float result = calculate_e(step, x);
    cout << "e的" << x << "次方的近似值是: " << result << endl;
    return 0;
}
