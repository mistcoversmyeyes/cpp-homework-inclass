#include <iostream>

// 函数用于检查两个表达式的等价性
bool check_equivalence(int x, int y) {
    bool original_expression =!(a == b)||!(g != 5);
    bool new_expression = !(a == b) && (g != 5);
    return original_expression == new_expression;
}

int main() {
    // 测试所有可能的x和y值组合（假设范围为0到9）
    for(int x = 0; x < 10; ++x) {
        for(int y = 0; y < 10; ++y) {
            if(!check_equivalence(x, y)) {
                std::cout << "Not equivalent for x = " << x << ", y = " << y << std::endl;
                return 1;  // 如果找到不等价的情况，结束程序
            }
        }
    }
    std::cout << "The expressions are logically equivalent for all tested values of x and y." << std::endl;
    return 0;
}
