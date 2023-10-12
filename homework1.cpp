#include<iostream>
using namespace std;

int  findMax(int length ,int number[]) {
	for (int i=0;i<length;i++) {
		int max = 0;
			if(number[i] >max) {
				max=number[i];
			}
		
	}
}

int main() {
	int lengthOfNumbers;
	int max=0;
	cout<< "你要输入几个数:" << endl;
	cin >> lengthOfNumbers;
	int *numbers=new  [lengthOfNumbers];
	for(int i=0;i<lengthOfNumbers;i++){
		cin>>numbers[i];
	}
	
	max=findMax(lengthOfNumbers,numbers);
	cout<<"这些数中的最大值是"<< max <<endl;//调用FindMax函数的返回值作为输出
	}
	