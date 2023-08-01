// Yêu cầu:
// 1. làm tròn số 1.234567
// lấy 3 chữ số sau dấu phẩy

#include <iostream>
#include <iomanip>
using namespace std;

int main(){
    // cho số 1.234567
    float x = 1.234567;

    // lấy 3 chữ số sau dấu phẩy
    cout << fixed << setprecision(3);
    cout << "x = " << x << "\n\n";

    return 0;
}