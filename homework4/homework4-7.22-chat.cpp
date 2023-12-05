#include <iostream>
#include <array>
#include <algorithm>
using namespace std;

constexpr int N = 8; // 棋盘大小为8x8
array<array<int, N>, N> accessibility; // 存储每个位置的可达性

// 骑士的移动方向，共有8个可能的方向
const int dx[N] = {2, 1, -1, -2, -2, -1, 1, 2};
const int dy[N] = {1, 2, 2, 1, -1, -2, -2, -1};

// 检查当前坐标是否在棋盘内
bool isInside(int x, int y) {
    return (x >= 0 && x < N && y >= 0 && y < N);
}

// 预计算每个位置的初始可达性
void calculateAccessibility() {
    for (int x = 0; x < N; ++x) {
        for (int y = 0; y < N; ++y) {
            int count = 0;
            for (int i = 0; i < N; ++i) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (isInside(nx, ny)) count++;
            }
            accessibility[x][y] = count;
        }
    }
}

// 获取下一步的最优位置
pair<int, int> nextMove(array<array<int, N>, N>& board, int x, int y) {
    int min_deg_idx = -1, c, min_deg = (N+1), nx, ny;

    // 尝试所有可能的移动
    for (int i = 0; i < N; ++i) {
        nx = x + dx[i];
        ny = y + dy[i];
        c = accessibility[nx][ny];
        if ((isInside(nx, ny)) && (c < min_deg) && (board[nx][ny] == -1)) {
            min_deg_idx = i;
            min_deg = c;
        }
    }

    // 如果没有找到可移动的位置，返回(-1, -1)
    if (min_deg_idx == -1) return {-1, -1};

    // 移动到下一个位置
    nx = x + dx[min_deg_idx];
    ny = y + dy[min_deg_idx];

    // 减少可达性
    accessibility[nx][ny]--;
    board[nx][ny] = board[x][y] + 1;

    return {nx, ny};
}

// 骑士巡游的主函数
bool knightTour() {
    array<array<int, N>, N> board = {0};
    for (auto& row : board) row.fill(-1);

    // 骑士初始位置
    int sx = 0, sy = 0;

    board[sx][sy] = 1; // 开始位置标记为1
    calculateAccessibility(); // 计算初始可达性

    pair<int, int> next_move;
    for (int i = 0; i < N*N-1; ++i) {
        next_move = nextMove(board, sx, sy);
        if (next_move.first == -1) return false; // 如果没有下一步可走，返回失败
        sx = next_move.first;
        sy = next_move.second;
    }

    // 打印路径
    for (const auto& row : board) {
        for (int sq : row) {
            cout << sq << "\t";
        }
        cout << endl;
    }
    return true; // 巡游成功
}

int main() {
    if (!knightTour()) {
        cout << "解决方案不存在\n";
    }
    return 0;
}
