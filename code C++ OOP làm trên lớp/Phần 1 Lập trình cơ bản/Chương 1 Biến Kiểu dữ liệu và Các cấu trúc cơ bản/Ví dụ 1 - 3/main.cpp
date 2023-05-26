// Yêu cầu:
// 1. Nhập vào 3 số nguyên --> là ngày, tháng, năm.
// 2. Cho công thức.
// 3. Hãy cho biết ngày/tháng/năm đó là thứ mấy

// Với 0 --> Saturday
// Với 1 --> Sunday
// Với 2 --> Monday
// Với 3 --> Tuesday
// Với 4 --> Wednesday
// Với 5 --> Thursday
// Với 6 --> Friday

// DOW --> là "days of the week"

#include <iostream>
using namespace std;

int main(){
	int day, month, year;
	
	cout << "Nhap vao ngay, thang, nam: " << endl;
	cin >> day >> month >> year;

	if(month < 3){
		month = month + 12;
		year = year - 1;
	}

	int c = year / 100;
	int k = year % 100;

	int DOW = (day + 26*(month+1)/10 + k + k/4 + c/4 + c*5) % 7;

	switch(DOW){
		case 0:
			cout << "Saturday" << endl;
			break;
		case 1:
			cout << "Sunday" << endl;
			break;
		case 2:
			cout << "Monday" << endl;
			break;
		case 3:
			cout << "Tuesday" << endl;
			break;
		case 4:
			cout << "Wednesday" << endl;
			break;
		case 5:
			cout << "Thursday" << endl;
			break;
		case 6:
			cout << "Friday" << endl;
			break;
	}
	return 0;
}