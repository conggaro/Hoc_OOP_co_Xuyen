// Yêu cầu:
// 1. Nhập vào bàn phím 3 số thực a, b, c
// 2. Kiểm tra xem 3 số này có phải là 3 cạnh của một tam giác không
// 3. Nếu đúng --> tính S, tính bán kính R, tính bán kính r
// 4. Nếu sai --> in ra "Day khong phai ba canh tam giac"

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

// hàm kiểm tra 3 cạnh có phải là 3 cạnh của 1 tam giác không
bool KiemTra_3_Canh(double canh_a, double canh_b, double canh_c){
    bool kiemTra1 = canh_a > 0;
    bool kiemTra2 = canh_b > 0;
    bool kiemTra3 = canh_c > 0;
    
    bool kiemTra4 = (canh_a + canh_b) > canh_c;
    bool kiemTra5 = (canh_b + canh_c) > canh_a;
    bool kiemTra6 = (canh_a + canh_c) > canh_b;

    bool tong_kiemTra1 = kiemTra1 && kiemTra2;
    bool tong_kiemTra2 = tong_kiemTra1 && kiemTra3;
    bool tong_kiemTra3 = tong_kiemTra2 && kiemTra4;
    bool tong_kiemTra4 = tong_kiemTra3 &&  kiemTra5;
    bool tong_kiemTra5 = tong_kiemTra4 && kiemTra6;

    if(tong_kiemTra5 == true){
        return true;
    }else{
        return false;
    }
}

// tính diện tích tam giác
double TinhDienTich(double canh_a, double canh_b, double canh_c){
    // nửa chu vi
    double p = (canh_a+canh_b+canh_c) / 2;

    // tính diện tích, công thức Heron
    double s = sqrt(p*(p-canh_a)*(p-canh_b)*(p-canh_c));
    return s;
}

// tính bán kính đường tròn ngoại tiếp tam giác
double Tinh_R(double canh_a, double canh_b, double canh_c){
    double R = canh_a * canh_b * canh_c / 4 / TinhDienTich(canh_a, canh_b, canh_c);

    return R;
}

// tính bán kính đường tròn nội tiếp tam giác
double Tinh_r(double canh_a, double canh_b, double canh_c){
    // nửa chu vi
    double p = (canh_a+canh_b+canh_c) / 2;
    
    double r = TinhDienTich(canh_a, canh_b, canh_c) / p;

    return r;
}

int main(){
    double a, b, c;
    cin >> a >> b >> c;

    if(KiemTra_3_Canh(a, b, c) == true){
        cout << fixed << setprecision(4);
        cout << TinhDienTich(a, b, c) << endl;
        cout << Tinh_R(a, b, c) << endl;
        cout << Tinh_r(a, b, c) << endl;
    }else{
        cout << "Day khong phai ba canh tam giac" << endl;
    }

    return 0;
}