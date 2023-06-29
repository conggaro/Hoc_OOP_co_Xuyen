#include <iostream>
#include <corecrt_math_defines.h>
#include <cmath>
using namespace std;

class Circle{
    private:
        int x;
        int y;
        int r;
        
    public:
        float dien_tich;

    public:
        // hàm khởi tạo không tham số
        Circle(){
            x = 0;
            y = 0;
            r = 0;
        }

        // hàm khởi tạo có tham số
        Circle(int data1, int data2, int data3){
            x = data1;
            y = data2;
            r = data3;
        }

        // hàm hủy
        ~Circle(){
            cout << "Huy doi tuong\n";
        }

        // hàm nhập dữ liệu từ bàn phím
        void NhapDuLieu(){
            cout << "Nhap x: ";
            cin >> x;

            cout << "Nhap y: ";
            cin >> y;

            cout << "Nhap ban kinh: ";
            cin >> r;
        }

        // hàm hiển thị
        void HienThi(){
            cout << "(" << x << ", " << y << ")\t\tr = " << r << "\n";
        }

        // Phương thức tính chu vi
        float Tinh_ChuVi(){
            float chu_vi = 0;

            chu_vi = 2 * M_PI * r;            

            return chu_vi;
        }

        // Phương thức tính diện tích
        float Tinh_DienTich(){
            dien_tich = M_PI * pow(r, 2);

            return dien_tich;
        }
};