// Yêu cầu
// 1. Nhập vào 3 cạnh của 1 tam giác.
// 2. Kiểm tra 3 cạnh có phải của 1 tam giác không.

#include <iostream>
#include <cmath>
using namespace std;

int main(){
	cout << "Nhap vao 3 canh cua tam giac: " << endl;
	double a, b, c;
	cin >> a >> b >> c;

	// kiểm tra 3 cạnh có phải của 1 tam giác không
	if(a>0 && b>0 && c>0 && (a+b>c) && (b+c>a) && (a+c>b)){
		cout << "Day la 3 canh cua 1 tam giac." << endl;
		double p = (a+b+c) / 2;
		double s = sqrt(p*(p-a)*(p-b)*(p-c));
		cout << "Dien tich la: " << s << endl;
	}else{
		cout << "Day khong phai la 3 canh cua 1 tam giac." << endl;
	}

	// cout << a << "\t" << b << "\t" << c << endl;

	return 0;
}