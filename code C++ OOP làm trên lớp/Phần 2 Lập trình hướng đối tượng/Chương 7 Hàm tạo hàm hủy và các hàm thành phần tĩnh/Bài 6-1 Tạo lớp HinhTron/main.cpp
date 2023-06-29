// Yêu cầu:
// 1. tạo lớp HinhTron

// 2. tạo thuộc tính
// bán kính (double)
// màu sắc (string)

// 3. tạo các phương thức
// hàm tạo
// hàm hủy
// hàm thiết lập bán kính
// hàm thiết lập màu sắc
// hàm lấy bán kính
// hàm lấy màu sắc
// hàm hiển thị thông tin của hình tròn
// hàm tính diện tích hình tròn

#include <iostream>
#include <cmath>
#include <corecrt_math_defines.h>
#include <iomanip>
using namespace std;

// tạo lớp HinhTron
class HinhTron{
    private:
        double ban_kinh;
        string mau_sac;

    public:
        // hàm khởi tạo không tham số
        HinhTron(){
            ban_kinh = 0;
            mau_sac = "NO COLOR";
        }

        // hàm khởi tạo có tham số
        HinhTron(double data1, string data2){
            ban_kinh = data1;
            mau_sac = data2;
        }

        // hàm hủy
        ~HinhTron(){
            cout << "Huy doi tuong\n";
        }

        // hàm thiết lập bán kính
        void set_BanKinh(double data){
            ban_kinh = data;
        }

        // hàm thiết lập màu sắc
        void set_MauSac(string data){
            mau_sac = data;
        }

        // hàm lấy bán kính
        double get_BanKinh(){
            return ban_kinh;
        }

        // hàm lấy màu sắc
        string get_MauSac(){
            return mau_sac;
        }

        // hàm hiển thị
        void HienThi(){
            cout << "Thong tin hinh tron:\n";
            cout << "Ban kinh: " << ban_kinh << "\n";
            cout << "Mau sac: " << mau_sac << "\n";
            
            cout << fixed << setprecision(3);       // lấy 3 chữ số phần thập phân
            cout << "Dien tich = " << Tinh_DienTich() << "\n\n";
        }

        // hàm tính diện tích
        double Tinh_DienTich(){
            double dien_tich = M_PI * pow(ban_kinh, 2);
            
            return dien_tich;
        }
};

int main(){
    // tạo đối tượng
    HinhTron dt1 = HinhTron(2, "Mau trang");

    HinhTron dt2;
    dt2.set_BanKinh(10);
    dt2.set_MauSac("Mau den");

    // gọi phương thức hiển thị
    dt1.HienThi();
    dt2.HienThi();

    return 0;
}