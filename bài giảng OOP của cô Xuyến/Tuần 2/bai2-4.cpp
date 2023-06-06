// Yêu cầu:
// 1. nhập vào 2 số nguyên dương N, M
// 2. tìm ước chung lớn nhất bằng thuật toán Euclid

// công thức
// UCLN(a, b) = b nếu a chia hết cho b
// ngược lại, UCLN(a, b) = UCLN(b, a % b)
// sử dụng đệ quy

#include <iostream>
using namespace std;

// hàm tính ước chung lớn nhất
int Tinh_UCLN(int so_N, int so_M){
    int khoi_tao = 0;

    if (so_N % so_M == 0)
    {
        khoi_tao = so_M;
    }else{
        khoi_tao = Tinh_UCLN(so_M, so_N % so_M);
    }    

    return khoi_tao;
}

int main(){
    cout << "Nhap vao 2 so nguyen duong N, M: " << endl;
    int N, M;
    cin >> N >> M;

    cout << "UCLN(" << N << ", " << M << ") = " << Tinh_UCLN(N, M);
    cout << endl;

    return 0;
}