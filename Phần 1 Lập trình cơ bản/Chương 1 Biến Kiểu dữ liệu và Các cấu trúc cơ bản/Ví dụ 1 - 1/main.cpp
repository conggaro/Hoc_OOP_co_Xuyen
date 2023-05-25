// Yêu cầu:
// 1. nhập vào 3 số thực a, b, c là độ dài 3 cạnh của một tam giác
// 2. tính diện tích tam giác đó theo công thức Heron

#include <iostream>
#include <cmath>
using namespace std;

int main(){
	float a, b, c;
	
	// nhập cạnh a
	cout << "Nhap vao canh a: ";
	cin >> a;
	while(a <= 0){
		cout << "Nhap vao canh a (a > 0): ";
		cin >> a;
	}
	
	// nhập cạnh b
	cout << "Nhap vao canh b: ";
	cin >> b;
	while(b <= 0){
		cout << "Nhap vao canh b (b > 0): ";
		cin >> b;
	}
	
	// nhập cạnh c
	cout << "Nhap vao canh c: ";
	cin >> c;
	while(c <= 0){
		cout << "Nhap vao canh c (c > 0): ";
		cin >> c;
	}
	
	if((a+b>c) && (b+c>a) && (a+c>b)){
		float p = (a + b + c) / 2;
		float s = sqrt(p*(p-a)*(p-b)*(p-c));
		cout << "Dien tich = " << s << endl;
	}else{
		cout << "Day khong phai tam giac." << endl;
	}
	
	return 0;
}
