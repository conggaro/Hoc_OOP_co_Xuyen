// Yêu cầu:
// 1. nhập a
// 2. nhập b
// 3. tìm UCLN(a, b)

#include <iostream>
using namespace std;

// hàm tìm ước chung lớn nhất
int Ham_Tim_UCLN(int thamSo1, int thamSo2){
    int UCLN = 0;

    if (thamSo1 == 0 || thamSo2 == 0)
    {
        UCLN = 1;
        return UCLN;
    }
    
    while (thamSo1 != thamSo2)
    {
        if (thamSo1 > thamSo2)
        {
            thamSo1 = thamSo1 - thamSo2;
        }
        
        if (thamSo2 > thamSo1)
        {
            thamSo2 = thamSo2 - thamSo1;
        }
    }
    
    UCLN = thamSo1;

    return UCLN;
}

int main(){
    // nhập a
    cout << "Nhap a: ";
    int a = 0;
    cin >> a;

    // nhập b
    cout << "Nhap b: ";
    int b = 0;
    cin >> b;

    cout << "\nUCLN(" << a << ", " << b << ") = ";
    cout << Ham_Tim_UCLN(a, b) << "\n\n";

    return 0;
}