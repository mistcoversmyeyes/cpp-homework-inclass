#include <iostream>
#include <cmath>
using namespace std;
typedef struct triangle {
    double side1;
    double side2;
};

int main(){
    int n = 3;
    triangle triangle[n];
    triangle[0].side1 = 3;
    triangle[0].side2 = 4;
    triangle[1].side1 = 5;
    triangle[1].side2 = 12;
    triangle[2].side1 = 8;
    triangle[2].side2 = 15;
    int hypotenuse[n];
    for(int i = 0;i < n;i++){
        hypotenuse[i] = sqrt(pow(triangle[i].side1,2) + pow(triangle[i].side2,2));
        cout<<"hypotenuse "<<i+1<<" is: "<<hypotenuse[i]<<endl;
    }
    return 0;

}