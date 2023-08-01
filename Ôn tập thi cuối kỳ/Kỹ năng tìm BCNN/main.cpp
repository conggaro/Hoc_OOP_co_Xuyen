// Yêu cầu:
// 1. nhập a
// 2. nhập b
// 3. tìm BCNN(a, b)

#include <iostream>
using namespace std;

// hàm tìm bội chung nhỏ nhất
int Ham_Tim_BCNN(int thamSo1, int thamSo2){
    int BCNN = 0;

    if (thamSo1 == 0 || thamSo2 == 0)
    {
        return BCNN;
    }
    
    // tạo index bắt đầu
    int index_start = max(thamSo1, thamSo2);

    // tạo index kết thúc
    int index_end = thamSo1 * thamSo2;

    for (int i = index_start; i <= index_end; i++)
    {
        bool kiemTra1 = i % thamSo1 == 0 ? true : false;
        bool kiemTra2 = i % thamSo2 == 0 ? true : false;

        if (kiemTra1 && kiemTra2)
        {
            BCNN = i;
            break;
        }
    }

    return BCNN;
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

    // in ra BCNN(a, b)
    cout << "\nBCNN(" << a << ", " << b << ") = ";
    cout << Ham_Tim_BCNN(a, b) << "\n\n";

    return 0;
}