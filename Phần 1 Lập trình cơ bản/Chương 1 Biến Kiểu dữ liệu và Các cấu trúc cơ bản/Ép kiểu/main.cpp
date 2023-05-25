// Yêu cầu:
// 1. Nhập vào 2 số nguyên a, b
// 2. Nếu b == 0 thì bắt nhập lại
// 3. Hiển thị ketQua = a / b
// nhưng c phải là kiểu dữ liệu float

#include <iostream>
using namespace std;

int main(){
	int a, b;
	
	cout << "Nhap vao 1 so a: ";
	cin >> a;

	cout << "Nhap vao 1 so b: ";
	cin >> b;
	
	while(b == 0){
		cout << "Nhap vao 1 so b (b khac 0): ";
		cin >> b;
	}	
	
	float ketQua = (float)a / (float)b; // ép kiểu

	cout << "Ket qua la: " << ketQua << endl;
	return 0;
}