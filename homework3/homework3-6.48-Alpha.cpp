#include <iostream>
#include <random>
#include <ctime>

using namespace std;

// 封装掷骰子的函数
unsigned int rollDice() {
    static default_random_engine engine(static_cast<unsigned int>(time(0)));
    static uniform_int_distribution<unsigned int> diceRoll(1, 6);

    unsigned int roll1 = diceRoll(engine); // 第一个骰子
    unsigned int roll2 = diceRoll(engine); // 第二个骰子
    unsigned int sum = roll1 + roll2; // 两个骰子点数之和

    cout << "掷出了: " << roll1 << " + " << roll2 << " = " << sum << endl;

    return sum;
}

int main() {
    int bankBalance = 1000; // 银行账户余额初始化为1000元
    int wager; // 赌注

    cout << "当前银行账户余额为: " << bankBalance << " 元。" << endl;

    // 用户可以继续赌博直到余额为零
    while (bankBalance > 0) {
        cout << "请输入你的赌注: ";
        cin >> wager;

        // 检查赌注是否超过余额
        if (wager > bankBalance) {
            cout << "赌注不能超过你的银行账户余额。" << endl;
            continue;
        }

        // 执行掷骰子的函数，并获取两个骰子点数之和
        unsigned int diceSum = rollDice();

        // 根据骰子点数之和来判断输赢
        if (diceSum == 7 || diceSum == 11) {
            bankBalance += wager;
            cout << "你赢了！" << endl;
        } else if (diceSum == 2 || diceSum == 3 || diceSum == 12) {
            bankBalance -= wager;
            cout << "你输了！" << endl;
        } else {
            cout << "没有赢也没有输，再来一次！" << endl;
            continue;
        }

        cout << "当前银行账户余额为: " << bankBalance << " 元。" << endl;

        // 检查用户是否破产
        if (bankBalance <= 0) {
            cout << "你破产了！游戏结束。" << endl;
            break;
        }

        // 询问用户是否继续
        char choice;
        cout << "你想继续赌博吗（y/n）？";
        cin >> choice;
        if (choice != 'y'||'Y') {
            cout << "你选择了结束游戏。" << endl;
            break;
        }
    }

    return 0;
}
