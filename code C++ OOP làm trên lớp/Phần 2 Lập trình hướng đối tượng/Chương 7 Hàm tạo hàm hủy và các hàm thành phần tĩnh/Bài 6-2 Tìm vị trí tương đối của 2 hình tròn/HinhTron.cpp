#include <iostream>
#include <cmath>
#include <corecrt_math_defines.h>
#include <iomanip>
using namespace std;

// tạo lớp Diem
class Diem{
    public:
        int x;
        int y;
};

// tạo lớp HinhTron
class HinhTron{
    private:
        double ban_kinh;
        string mau_sac;
        Diem dt_diem;               // đối tượng điểm

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

        // hàm set_TamHinhTron
        void set_TamHinhTron(int data1, int data2){
            dt_diem.x = data1;
            dt_diem.y = data2;
        }

        // hàm bạn vitrituongdoi()
        friend void vitrituongdoi(HinhTron a, HinhTron b);
};

void vitrituongdoi(HinhTron a, HinhTron b){
    // tính (x2 - x1)^2
    float x2_x1 = b.dt_diem.x - a.dt_diem.x;
    float data1 = pow(x2_x1, 2);

    // tính (y2 - 11)^2
    float y2_y1 = b.dt_diem.y - a.dt_diem.y;
    float data2 = pow(y2_y1, 2);

    // gọi A là tâm của hình tròn 1
    // gọi B là tâm của hình tròn 2
    // AB là khoảng cách giữa 2 tâm
    float AB = sqrt(data1 + data2);

    if (a.ban_kinh + b.ban_kinh < AB)
    {
        // ngoài nhau
        cout << "Khong giao nhau\n\n";
    }
    else if (AB == 0 && a.ban_kinh == b.ban_kinh)
    {
        // trùng nhau, giao nhau tại mọi điểm luôn
        cout << "Giao nhau\n\n";
    }
    else if (a.ban_kinh + b.ban_kinh == AB || abs(a.ban_kinh - b.ban_kinh) == AB)
    {
        // r1 + r2 == AB
        // thì cái loại này gọi là tiếp xúc ngoài

        // giá trị tuyệt đối của (r1 - r2) bằng AB
        // thì cái loại này gọi là tiếp xúc trong
        // cái loại này giao nhau tại 1 điểm
        cout << "Giao nhau\n\n";
    }
    else if (AB + min(a.ban_kinh, b.ban_kinh) < max(a.ban_kinh, b.ban_kinh))
    {
        // cái loại này là trong nhau
        // tức là không giao nhau
        cout << "Khong giao nhau\n\n";
    }
    else
    {
        // còn lại là giao nhau tại 2 điểm
        cout << "Giao nhau\n\n";
    }
}