// Yêu cầu:
// 1. tính diện tích hình tròn
// 2. tính diện tích tam giác
// 3. tính diện tích hình chữ nhật
// 4. sử dụng kỹ thuật nạp chồng hàm

// 5. số đo cạnh được nhập từ bàn phím

#include <iostream>
#include <cmath>
#include <corecrt_math_defines.h>
using namespace std;

// hàm tính diện tích hình tròn
// s_hình_tròn = (bán_kính)^2 * 3.14
void TinhDienTich(float &s, float r){
    s = pow(r, 2) * M_PI;
}

// hàm tính diện tích hình tam giác
// s_hình_tam_giác = sqrt(p*(p-a)*(p-b)*(p-c))
void TinhDienTich(float &s, float c_a, float c_b, float c_c){
    int tong = c_a + c_b + c_c;
    float p = (float)tong / 2;
    s = sqrt(p*(p-c_a)*(p-c_b)*(p-c_c));
}

// hàm tính diện tích hình chữ nhật
void TinhDienTich(float &s, float c_dai, float c_rong){
    s = c_dai * c_rong;
}

int main(){
    cout << "nhap ban kinh hinh tron: ";
    float ban_kinh;
    cin >> ban_kinh;

    cout << "nhap 3 canh tam giac: \n";
    float a, b, c;
    cin >> a >> b >> c;

    cout << "nhap chieu dai hinh chu nhat: ";
    float chieu_dai;
    cin >> chieu_dai;

    cout << "nhap chieu rong hinh chu nhat: ";
    float chieu_rong;
    cin >> chieu_rong;

    float dien_tich;

    TinhDienTich(dien_tich, ban_kinh);
    cout << "\ndien tich hinh tron la: " << dien_tich;
    cout << "\n\n";

    TinhDienTich(dien_tich, a, b, c);
    cout << "dien tich hinh tam giac la: " << dien_tich;
    cout << "\n\n";

    TinhDienTich(dien_tich, chieu_dai, chieu_rong);
    cout << "dien tich hinh chu nhat la: " << dien_tich;
    cout << "\n\n";

    return 0;
}