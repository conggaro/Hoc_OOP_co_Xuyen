#include <iostream>
using namespace std;

int main(){
	cout << boolalpha; // yêu cầu in giá trị logic kiểu true/false thay vì 1/0
	int i = 3;

	bool b = (i < 1) && (++i == 4); // bỏ qua phép so sánh ++i == 4
	
	cout << b << endl;
	cout << i << endl; // in ra 3, vì lệnh ++i ở trên không được thực hiện
	
	return 0;
}