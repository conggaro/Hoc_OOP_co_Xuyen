#include <iostream>
using namespace std;

int main(){
	int x, y;
	
	x = 4;
	cout << x << endl;

	x = x + 8;
	cout << x << endl;

	x = x * 2;
	cout << x << endl;

	y = (x = x * 5) + 3;
	cout << "x = " << x << endl;
	cout << "y = " << y << endl;

	return 0;
}