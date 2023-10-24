#include <iostream>

// 函数用于检查两个表达式的等价性
bool check_equivalence(int a, int b, int g) {
    bool original_expression = !(a == b) || !(g != 5);
    bool new_expression = !((a == b) && (g != 5));  // 根据德摩根定律，这是等价的表达式
    return original_expression == new_expression;
}

int main() {
    // 测试所有可能的a，b和g值组合（假设范围为0到9）
    for(int a = 0; a < 10; ++a) {
        for(int b = 0; b < 10; ++b) {
            for(int g = 0; g < 10; ++g) {
                if(!check_equivalence(a, b, g)) {
                    std::cout << "Not equivalent for a = " << a << ", b = " << b << ", g = " << g << std::endl;
                    return 1;  // 如果找到不等价的情况，结束程序
                }
            }
        }
    }
    std::cout << "The expressions are logically equivalent for all tested values of a, b, and g." << std::endl;
    return 0;
}
