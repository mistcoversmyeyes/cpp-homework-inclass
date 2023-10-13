#include<iostream>
using namespace std;

int  findMax(int length ,int number[]) {
	int max = 0;
	for (int i=0;i<length;i++) {
			if(number[i] >max) {
				max=number[i];
			}
		
	};
	return max ;
}

int main() {
	int lengthOfNumbers;
	int max=0;
	cout<< "你要输入几个数:" << endl;
	cin >> lengthOfNumbers;
	int *numbers=new int [lengthOfNumbers];
	for(int i=0;i<lengthOfNumbers;i++){
		cin>>numbers[i];
	}
	
	max=findMax(lengthOfNumbers,numbers);
	cout<<"这些数中的最大值是"<< max <<endl;//调用FindMax函数的返回值作为输出
	}
	