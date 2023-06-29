#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class Student{
    private:
        string ma_sv;
        string ho_ten;
        double diemTB;

    public:
        // hàm khởi tạo không tham số
        Student(){
            ma_sv = "";
            ho_ten = "";
            diemTB = 0;
        }

        // hàm nhập dữ liệu từ bàn phím
        void NhapDuLieu(){
            cout << "Nhap ma sinh vien: ";
            getline(cin, ma_sv, '\n');

            cout << "Nhap ho va ten: ";
            getline(cin, ho_ten, '\n');

            cout << "Nhap diem trung binh: ";
            cin >> diemTB;
            cin.ignore();
            cout << "\n";
        }

        // hàm hiển thị
        void HienThi(){
            cout << fixed << setprecision(1);
            cout << ma_sv << " | " << ho_ten << " | " << Lay_PhanTP(diemTB) << "\n\n";
        }

        // hàm lấy 1 chữ số phần thập phân
        double Lay_PhanTP(double data){
            double khoi_tao = 0;

            double clone1 = data * 10;

            int clone2 = (int)clone1;

            khoi_tao = (double)clone2 / 10;

            return khoi_tao;
        }

        // hàm lấy điểm TB
        double get_diemTB(){
            return diemTB;
        }
};