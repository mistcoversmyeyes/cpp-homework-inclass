#include<iostream>
using namespace std;

int Maximun(int length,int number[]) {
	int SizeOfNumbers=length ;
	for (int i=0;i<SizeOfNumbers;i++) {
		int max = 0;
			if(number[i] < max) {
				max=number[i];
			}
		
		return max;
	}
}

int main() {
	int length ;
	cout << "你要输入几个数:" << endl;
	cin >> length;
	int numbers[length];
		
