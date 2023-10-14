#include <iostream>

int main() {
    // 声明变量
    float base, height, area;

    // 获取用户输入
    std::cout << "请输入直角三角形的底边长度：";
    std::cin >> base;
    std::cout << "请输入直角三角形的高：";
    std::cin >> height;

    // 计算面积
    area = 0.5 * base * height;

    // 打印面积
    std::cout << "直角三角形的面积是：" << area << std::endl;

    return 0;
}
