// Yêu cầu:
// 1. nhập vào 1 số
// 2. kiểm tra số chính phương

// số chính phương kiểu nó lấy căn bậc 2 thì phải ra số nguyên
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

// hàm kiểm tra số chính phương
bool KiemTra_SCP(int thamSo){
    bool khoi_tao = false;

    int kiemTra = sqrt(thamSo);

    khoi_tao = pow(kiemTra, 2) == thamSo ? true : false;
    return khoi_tao;
}

int main(){
    int n;
    cin >> n;

    cout << boolalpha << KiemTra_SCP(n) << endl;
    return 0;
}