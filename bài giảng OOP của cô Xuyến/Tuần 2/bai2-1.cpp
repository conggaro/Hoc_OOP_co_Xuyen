// Yêu cầu:
// 1. nhập vào số int n, double x
// 2. tính toán
// 3. in kết quả ra màn hình

#include <iostream>
#include <cmath>
using namespace std;

// hàm tính tổng s1
double Tinh_Tong_s1(int _n, double _x){
    double khoi_tao = 0;

    for(int i = 1; i <= _n; i++){
        khoi_tao = khoi_tao + pow(_x, i) / i / (i + 1);
    }

    return khoi_tao;
}

// hàm tính giai thừa
int TinhGiaiThua(int thamSo){
    int khoi_tao = 0;

    if(thamSo <= 1){
        khoi_tao = 1;
    }else{
        khoi_tao = thamSo * TinhGiaiThua(thamSo - 1);
    }

    return khoi_tao;
}

// hàm tính tổng s2
double Tinh_Tong_s2(int _n){
    double khoi_tao = 1;

    for(int i = 1; i <= _n; i++){
        khoi_tao = khoi_tao + (double)1 / TinhGiaiThua(i);
    }

    return khoi_tao;
}

// hàm tính tổng s3
int Tinh_Tong_s3(int _n, double _x){
    int khoi_tao = 0;

    for(int i = 0; i <= _n; i++){
        int soMu = 2 * i + 1;
        khoi_tao = khoi_tao + pow(_x, soMu);
    }

    return khoi_tao;
}

// hàm tính tổng s4
double Tinh_Tong_s4(int _n, double _x){
    double khoi_tao = 0;

    khoi_tao = khoi_tao + Tinh_Tong_s1(_n, _x) + 2*Tinh_Tong_s2(_n) + 
                (double)3*Tinh_Tong_s3(_n, _x);

    return khoi_tao;
}

int main(){
    cout << "Nhap vao so nguyen duong n: ";
    int n;
    cin >> n;

    cout << "Nhap vao so thuc x: ";
    double x;
    cin >> x;

    cout << "Tong s1 la: " << Tinh_Tong_s1(n, x) << endl;
    cout << "Tong s2 la: " << Tinh_Tong_s2(n) << endl;
    cout << "Tong s3 la: " << Tinh_Tong_s3(n, x) << endl;
    cout << "Tong s4 la: " << Tinh_Tong_s4(n, x) << endl;
    return 0;
}