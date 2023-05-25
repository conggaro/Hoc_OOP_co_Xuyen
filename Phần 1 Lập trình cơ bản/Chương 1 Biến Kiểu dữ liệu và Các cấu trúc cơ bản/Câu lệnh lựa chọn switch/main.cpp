// Yêu cầu:
// 1. Nhập vào 1 số
// 2. Sử dụng câu lệnh lựa chọn switch để hiển thị số đó

#include <iostream>
using namespace std;

int main(){
	int x;
	
	cout << "Nhap vao 1 so: ";
	cin >> x;

	switch(x){
		case 0:
			cout << "Day la so 0." << endl;
			break;
		case 1:
			cout << "Day la so 1." << endl;
			break;
		case 2:
			cout << "Day la so 2." << endl;
			break;
		case 3:
			cout << "Day la so 3." << endl;
			break;
		case 4:
			cout << "Day la so 4." << endl;
			break;
		case 5:
			cout << "Day la so 5." << endl;
			break;
		case 6:
			cout << "Day la so 6." << endl;
			break;
		case 7:
			cout << "Day la so 7." << endl;
			break;
		case 8:
			cout << "Day la so 8." << endl;
			break;
		case 9:
			cout << "Day la so 9." << endl;
			break;
		default:
			cout << "khong nam trong [0; 9]." << endl; // không nằm trong [0; 9]
	}
	return 0;
}