// Yêu cầu:
// 1. tạo lớp DIEM

// 2. tạo hàm thành phần
// nhập dữ liệu điểm
// tính khoảng cách từ gốc tọa độ đến điểm
// di chuyển điểm một khoảng dx, dy
// hiển thị điểm

#include <iostream>
#include <cmath>
using namespace std;

// tạo lớp DIEM
class DIEM{
    private:
        int x;
        int y;

    public:
        // hàm khởi tạo không tham số
        DIEM(){
            x = 0;
            y = 0;
        }

        // hàm khởi tạo có tham số
        DIEM(int data1, int data2){
            x = data1;
            y = data2;
        }

        // hàm hủy
        ~DIEM(){
            cout << "Huy doi tuong\n";
        }

        // hàm nhập dữ liệu điểm
        void NhapDuLieu(int data1, int data2){
            x = data1;
            y = data2;
        }

        // hàm tính khoảng cách từ gốc tọa độ đến điểm
        float Tinh_KhoangCach_Tu_GocToaDo_Den_Diem(){
            float khoangCach = 0;

            float gia_tri_1 = pow(x - 0, 2);
            float gia_tri_2 = pow(y - 0, 2);

            khoangCach = sqrt(gia_tri_1 + gia_tri_2);

            return khoangCach;
        }

        // hàm di chuyển điểm một khoảng dx, dy
        void Di_Chuyen(int data1, int data2){
            x = x + data1;
            y = y + data2;
        }

        // hàm hiển thị
        void HienThi(){
            cout << "(" << x << ", " << y << ")\n";
        }
};

int main(){
    // tạo đối tượng
    DIEM dt1;

    // gọi phương thức nhập dữ liệu
    dt1.NhapDuLieu(2, 2);

    // hiển thị điểm vừa nhập
    cout << "Diem vua nhap:\n";
    dt1.HienThi();

    // gọi phương thức tính khoảng cách từ điểm đếm gốc tọa độ
    cout << "\nKhoang cach tu diem den goc toa do:\n";
    float x = dt1.Tinh_KhoangCach_Tu_GocToaDo_Den_Diem();
    cout << x << "\n";

    // gọi phương thức di chuyển điểm 1 khoảng dx, dy
    cout << "\nSau khi di chuyen:\n";
    dt1.Di_Chuyen(10, 30);
    dt1.HienThi();
    cout << "\n";

    return 0;
}