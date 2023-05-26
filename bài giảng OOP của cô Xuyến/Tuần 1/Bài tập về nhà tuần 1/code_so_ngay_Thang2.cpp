#include <iostream>
using namespace std;

int main()
{
    int year;
    cout << "Nhap nam: ";
    cin >> year;

    if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
        cout << "Nam nhuan" << endl; // 29 ngày
    else
        cout << "Khong phai nam nhuan" << endl; // 28 ngày

    int month = 2;
    int day;
    switch (month)
    {
    case 2:
        if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
            day = 29;
        else
            day = 28;
        break;
    }
    cout << "Thang " << month << " nam " << year << " co " << day << " ngay." << endl;
}
