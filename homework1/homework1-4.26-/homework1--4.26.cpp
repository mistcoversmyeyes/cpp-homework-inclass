#include <iostream>
using namespace std;

int power_of_ten(int exponent) {
    int result = 1;
    for (int i = 0; i < exponent; ++i) {
        result *= 10;
    }
    return result;
}

bool judge_palindrome(int number, int length) {
    int half_length = length / 2;
    for (int i = 0; i < half_length; i++) {
        int opposite_of_i = length - i -1;
        int a = (number / power_of_ten(i)) % 10;
        int b = (number / power_of_ten(opposite_of_i)) % 10;
        if (a != b) {
            return false;
        }
    }
    return true;
}

int main() {
    int number;
    int length;
    cout << "Please enter the number you want to judge whether it is palindrome: ";
    cin >> number;
    cout << "Enter the length of the number: ";
    cin >> length;
    bool judgement = judge_palindrome(number, length);
    if (judgement) {
        cout << "是回文数" << endl;
    } else {
        cout << "不是回文数" << endl;
    }
    return 0;}