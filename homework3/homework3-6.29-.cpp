#include<iostream>
bool judge_if_prime(int x) {
	for (int i = 2;i < ((int)(x / 2) +1);i++) {
		if (x % i == 0) {
			return false;
		}
	}
	return true;
 }


int main(void) {
	int tempt_prime = 0;
	std::cout << "请输入你要判断的数：";
	std::cin >> tempt_prime;
	if (judge_if_prime(tempt_prime)) {
		std::cout << tempt_prime << "是质数" << std::endl;
		return 0;
	}
    else{
        std::cout << tempt_prime << "不是质数" << std::endl;
        return 1;
    }
}