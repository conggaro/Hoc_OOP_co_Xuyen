#include <iostream>
using namespace std;

class Fraction{
    private:
        int a;          // tử số
        int b;          // mẫu số

    public:
        float data;     // dùng để so sánh 2 phân số

    public:
        // hàm khởi tạo không tham số
        Fraction(){
            a = 0;
            b = 1;
        }

        // hàm nhập dữ liệu
        void NhapDuLieu(){
            cout << "Nhap tu so: ";
            cin >> a;

            cout << "Nhap mau so: ";
            cin >> b;

            while (b == 0)
            {
                cout << "Nhap lai mau so: ";
                cin >> b;
            }
        }

        // hàm hiển thị
        void HienThi(){
            cout << a << "/" << b << "\n\n";
        }

        // hàm rút gọn phân số
        void Rut_Gon_PhanSo(){
            int UCLN = Tim_UCLN();

            a = a / UCLN;
            b = b / UCLN;
        }

        // hàm tìm ước chung lớn nhất
        int Tim_UCLN(){
            int UCLN = 1;

            // tạo index bắt đầu
            int index_bat_dau = max(a, b);

            // tạo index kết thúc
            int index_ket_thuc = 1;

            for (int i = index_bat_dau; i >= index_ket_thuc; i--)
            {
                if (a % i == 0 && b % i == 0)
                {
                    UCLN = i;
                    break;
                }                
            }            

            return UCLN;
        }

        // tạo hàm bạn friend để so sánh phân số
        // dùng int
        // return 1     --> dt1 > dt2
        // return 0     --> dt1 == dt2
        // return -1    --> dt1 < dt2
        friend int SoSanh_2_PhanSo(Fraction dt1, Fraction dt2);
};

int SoSanh_2_PhanSo(Fraction dt1, Fraction dt2){
    int ketQua = 404;

    dt1.data = (float)dt1.a / dt1.b;

    dt2.data = (float)dt2.a / dt2.b;

    if (dt1.data > dt2.data)
    {
        ketQua = 1;
    }
    else if (dt1.data == dt2.data)
    {
        ketQua = 0;
    }
    else if (dt1.data < dt2.data)
    {
        ketQua = -1;
    }    

    return ketQua;
}