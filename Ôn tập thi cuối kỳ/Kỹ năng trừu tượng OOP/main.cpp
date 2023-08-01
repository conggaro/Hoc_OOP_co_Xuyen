// Yêu cầu:
// 1. sử dụng tính trừu tượng

// cụ thể:
// phương thức ảo thuần túy TinhDienTich()
// phương thức ảo thuần túy TinhChuVi()

#include <iostream>
#include <corecrt_math_defines.h>
#include <cmath>
using namespace std;

// tạo lớp hình học
// lớp hình học sẽ tự động trở thành abstract class
class HinhHoc{
    public:
        virtual double TinhDienTich() = 0;
        virtual double TinhChuVi() = 0;
};

class HinhChuNhat : public HinhHoc{
    private:
        double chieu_dai;
        double chieu_rong;

    public:
        // hàm khởi tạo có tham số
        HinhChuNhat(double data1, double data2){
            chieu_dai = data1;
            chieu_rong = data2;
        }

        double TinhChuVi(){
            return (chieu_dai + chieu_rong) * 2;
        }

        double TinhDienTich(){
            return chieu_dai * chieu_rong;
        }
};

class HinhTamGiac : public HinhHoc{
    private:
        double canh_a;
        double canh_b;
        double canh_c;

    public:
        // hàm khởi tạo không tham số
        HinhTamGiac(double data1, double data2, double data3){
            canh_a = data1;
            canh_b = data2;
            canh_c = data3;
        }

        double TinhChuVi(){
            return canh_a + canh_b + canh_c;
        }

        double TinhDienTich(){
            // tính nửa chu vi
            float p = (canh_a + canh_b + canh_c) / 2;

            return sqrt(p*(p - canh_a)*(p - canh_b)*(p - canh_c));
        }
};

class HinhTron : public HinhHoc{
    private:
        double ban_kinh;
        double so_pi = M_PI;

    public:
        // hàm khởi tạo không tham số
        HinhTron(double data1){
            ban_kinh = data1;
        }

        double TinhChuVi(){
            return 2 * so_pi * ban_kinh;
        }

        double TinhDienTich(){
            return so_pi * ban_kinh * ban_kinh;
        }
};

int main(){
    // lớp ConNguoi là lớp trừu tượng
    // không thể tạo đối tượng bằng lớp ConNguoi
    // nếu cố tình tạo đối tượng thì sẽ bị báo lỗi code

    // tạo đối tượng
    HinhChuNhat dt_hcn = HinhChuNhat(2.5, 4);
    HinhTamGiac dt_htg = HinhTamGiac(3, 4, 5);
    HinhTron dt_ht = HinhTron(10);

    // gọi phương thức tính chu vi
    cout << "Tinh chu vi:\n";
    cout << "Chu vi hcn: " << dt_hcn.TinhChuVi() << "\n";
    cout << "Chu vi htg: " << dt_htg.TinhChuVi() << "\n";
    cout << "Chu vi ht: " << dt_ht.TinhChuVi() << "\n";

    // gọi phương thức tính diện tích
    cout << "\nTinh dien tich:\n";
    cout << "Dien tich hcn: " << dt_hcn.TinhDienTich() << "\n";
    cout << "Dien tich htg: " << dt_htg.TinhDienTich() << "\n";
    cout << "Dien tich ht: " << dt_ht.TinhDienTich() << "\n";

    cout << "\n";

    return 0;
}