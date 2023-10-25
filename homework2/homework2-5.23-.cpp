#include<iostream>
using namespace std;

int main() {
    int n = 5;  // 这里的 n 是宝石的一半的行数
    // 打印上半部分
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < n - i; ++j) {
            cout << " ";
        }
        for (int t = 0; t < 2 * i - 1; ++t) {
            cout << "*";
        }
        cout << "\n";
    }
    // 打印下半部分
    for (int i = n - 1; i >= 1; --i) {
        for (int j = 0; j < n - i; ++j) {
            cout << " ";
        }
        for (int t = 0; t < 2 * i - 1; ++t) {
            cout << "*";
        }
        cout << "\n";
    }

    return 0;
}
