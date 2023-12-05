#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

#define N 8

int board[N][N]; // 初始化棋盘

// 检查当前位置是否安全
bool isSafe(int row, int col) {
    for (int i = 0; i < col; i++) // 检查行
        if (board[row][i])
            return false;
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) // 检查左上对角线
        if (board[i][j])
            return false;
    for (int i = row, j = col; j >= 0 && i < N; i++, j--) // 检查左下对角线
        if (board[i][j])
            return false;
    return true;
}

// 主要的解决函数，使用回溯法
bool solveNQUtil(int col) {
    if (col >= N) // 如果所有皇后都被放置好
        return true;
    for (int i = 0; i < N; i++) { // 尝试所有行
        if (isSafe(i, col)) {
            board[i][col] = 1; // 放置皇后
            if (solveNQUtil(col + 1)) // 递归放置其余的皇后
                return true;
            board[i][col] = 0; // 回溯，移除皇后
        }
    }
    return false; // 如果没有解决方案，则回溯
}

// 打印棋盘的函数
void printSolution() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            cout << " " << board[i][j] << " ";
        cout << endl;
    }
}

// 解决八皇后问题的函数
bool solveNQ() {
    memset(board, 0, sizeof(board)); // 初始化棋盘为 0
    if (solveNQUtil(0) == false) { // 从第一列开始放置皇后
        cout << "Solution does not exist";
        return false;
    }
    printSolution(); // 打印解决方案
    return true;
}

int main() {
    solveNQ(); // 解决八皇后问题
    return 0;
}
