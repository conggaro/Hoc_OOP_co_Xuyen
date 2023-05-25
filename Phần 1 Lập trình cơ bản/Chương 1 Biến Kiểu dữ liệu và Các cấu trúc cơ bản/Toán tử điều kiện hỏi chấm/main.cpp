// Yêu cầu:
// 1. cho 3 biến x, y, z có kiểu int
// 2. muốn đặt z = max(x, y)

#include <iostream>
using namespace std;

int main(){
	int x, y, z;
	x = 10;
	y = 99;
	
	z = x > y ? x : y;

	cout << "z = " << z << endl;
	return 0;
}