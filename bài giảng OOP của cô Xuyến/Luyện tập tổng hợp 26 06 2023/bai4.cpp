// Tác giả: Nguyễn Chí Công

// Yêu cầu:
// 1. tạo lớp THIETBI
// 2. nhập n
// 3. nhập n thiết bị
// 4. nhập m
// 5. nhập m thiết bị

// 6. in ra máy tính
// có giá bán >= (10^5)

// 7. in ra điện thoại
// có giá bán <= (10^4)

// 8. đếm siêu máy tính

// 9. đếm điện thoại siêu nhẹ

#include <iostream>
#include <string>
#include <cmath>
#define SIZE 100
using namespace std;

// tạo lớp THIETBI
class THIETBI{
    private:
        string ten_thiet_bi;
        int nam_san_xuat;
        double gia_ban;

    public:
        // hàm tạo không tham số
        THIETBI(){
            ten_thiet_bi = "";
            nam_san_xuat = 0;
            gia_ban = 0;
        }

        // hàm tạo 3 tham số
        THIETBI(string data1, int data2, double data3){
            ten_thiet_bi = data1;
            nam_san_xuat = data2;
            gia_ban = data3;
        }

        // hàm nhập thông tin
        void NhapDuLieu(){
            cout << "Nhap ten thiet bi: ";
            getline(cin, ten_thiet_bi, '\n');

            cout << "Nhap nam san xuat: ";
            cin >> nam_san_xuat;

            cout << "Nhap gia ban: ";
            cin >> gia_ban;
            cin.ignore();
        }

        // hàm hiển thị thông tin
        void HienThi(){
            cout << "Thong tin thiet bi:\n";
            cout << "Ten thiet bi: " << ten_thiet_bi << "\n";
            cout << "Nam san xuat: " << nam_san_xuat << "\n";
            cout << "Gia ban: " << gia_ban << "\n";
        }

        // kiểm tra siêu thiết bị
        // sẽ có siêu máy tính
        // hoặc có siêu điện thoại
        virtual bool KiemTra_SieuThietBi() = 0;

        // hàm get_GiaBan
        double get_GiaBan(){
            return gia_ban;
        }
};

// tạo lớp MAYTINH
// kế thừa lớp THIETBI
class MAYTINH : public THIETBI{
    private:
        string hang_san_xuat;
        double toc_do;
        long do_lon_o_chung;

    public:
        // hàm tạo không tham số
        MAYTINH() : THIETBI(){
            hang_san_xuat = "";
            toc_do = 0;
            do_lon_o_chung = 0;
        }

        // hàm tạo 6 tham số
        MAYTINH(string data1, int data2, double data3, string data4, double data5, long data6) : THIETBI(data1, data2, data3){
            hang_san_xuat = data4;
            toc_do = data5;
            do_lon_o_chung = data6;
        }

        // hàm nhập thông tin
        void NhapDuLieu(){
            THIETBI::NhapDuLieu();

            cout << "Nhap hang san xuat: ";
            getline(cin, hang_san_xuat, '\n');

            cout << "Nhap toc do: ";
            cin >> toc_do;

            cout << "Nhap do lon o cung: ";
            cin >> do_lon_o_chung;
            cin.ignore();
        }

        // hàm hiển thị
        void HienThi(){
            THIETBI::HienThi();

            cout << "Hang san xuat: " << hang_san_xuat << "\n";
            cout << "Toc do: " << toc_do << "\n";
            cout << "Do lon o cung: " << do_lon_o_chung << "\n";
        }

        // triển khai
        // cái hàm ảo thuần túy
        // của lớp trừu trượng THIETBI
        bool KiemTra_SieuThietBi(){
            bool ketQua;

            if (toc_do >= pow(10, 6))
            {
                ketQua = true;
            }
            else
            {
                ketQua = false;
            }

            return ketQua;
        }
};

// tạo lớp DIENTHOAI
// kế thừa lớp THIETBI
class DIENTHOAI : public THIETBI{
    private:
        string hang_san_xuat;
        string he_dieu_hanh;
        double kich_thuoc_man_hinh;
        double can_nang;

    public:
        // hàm tạo không tham số
        DIENTHOAI() : THIETBI(){
            hang_san_xuat = "";
            he_dieu_hanh = "";
            kich_thuoc_man_hinh = 0;
            can_nang = 0;
        }

        // hàm tạo 6 tham số
        DIENTHOAI(string data1, int data2, double data3, string data4, string data5, double data6, double data7) : THIETBI(data1, data2, data3){
            hang_san_xuat = data4;
            he_dieu_hanh = data5;
            kich_thuoc_man_hinh = data6;
            can_nang = data7;
        }

        // hàm nhập thông tin
        void NhapDuLieu(){
            THIETBI::NhapDuLieu();

            cout << "Nhap hang san xuat: ";
            getline(cin, hang_san_xuat, '\n');

            cout << "Nhap he dieu hanh: ";
            getline(cin, he_dieu_hanh, '\n');

            cout << "Nhap kich thuoc man hinh: ";
            cin >> kich_thuoc_man_hinh;

            cout << "Nhap can nang: ";
            cin >> can_nang;
            cin.ignore();
        }

        // hàm hiển thị
        void HienThi(){
            THIETBI::HienThi();

            cout << "Hang san xuat: " << hang_san_xuat << "\n";
            cout << "He dieu hanh: " << he_dieu_hanh << "\n";
            cout << "Kich thuoc man hinh: " << kich_thuoc_man_hinh << "\n";
            cout << "Can nang: " << can_nang << "\n";
        }

        // triển khai
        // cái hàm ảo thuần túy
        // của lớp trừu trượng THIETBI
        bool KiemTra_SieuThietBi(){
            bool ketQua;

            if (can_nang <= 50)
            {
                ketQua = true;
            }
            else
            {
                ketQua = false;
            }

            return ketQua;
        }
};

int main(){
    // nhập n
    cout << "Nhap n: ";
    int n;
    cin >> n;

    while (n <= 0)
    {
        cout << "Nhap lai n (n > 0): ";
        cin >> n;
    }
    cin.ignore();

    // tạo mảng máy tính
    MAYTINH arr_MayTinh[SIZE];

    // nhập n máy tính
    cout << "\n-------------------- NHAP DU LIEU MAY TINH --------------------\n";
    for (int i = 0; i < n; i++)
    {
        arr_MayTinh[i].NhapDuLieu();
        cout << "\n";
    }

    // nhập m
    cout << "Nhap m: ";
    int m;
    cin >> m;

    while (m <= 0)
    {
        cout << "Nhap lai m (m > 0): ";
        cin >> m;
    }
    cin.ignore();

    // tạo mảng điện thoại
    DIENTHOAI arr_DienThoai[SIZE];

    // nhập m điện thoại
    cout << "\n-------------------- NHAP DU LIEU DIEN THOAI --------------------\n";
    for (int i = 0; i < m; i++)
    {
        arr_DienThoai[i].NhapDuLieu();
        cout << "\n";
    }

    // in ra máy tính
    // có giá bán >= (10^5)
    // lớn hơn hoặc bằng 100 nghìn
    cout << "\n----------------- IN RA MAY TINH (gia ban >= 10^5) -----------------\n";
    for (int i = 0; i < n; i++)
    {
        if (arr_MayTinh[i].get_GiaBan() >= pow(10, 5))
        {
            arr_MayTinh[i].HienThi();
            cout << "\n";
        }
    }

    // in ra điện thoại
    // có giá bán <= (10^4)
    // nhỏ hơn hoặc bằng 10 nghìn
    cout << "\n----------------- IN RA DIEN THOAI (gia ban <= 10^4) -----------------\n";
    for (int i = 0; i < m; i++)
    {
        if (arr_DienThoai[i].get_GiaBan() <= pow(10, 4))
        {
            arr_DienThoai[i].HienThi();
            cout << "\n";
        }
    }

    // đếm siêu máy tính
    int dem_sieu_MayTinh = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr_MayTinh[i].KiemTra_SieuThietBi() == true)
        {
            dem_sieu_MayTinh ++;
        }        
    }

    cout << "\nCo " << dem_sieu_MayTinh << " sieu may tinh\n";

    // đếm điện thoại siêu nhẹ
    int dem_DienThoai_sieu_nhe = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr_DienThoai[i].KiemTra_SieuThietBi() == true)
        {
            dem_DienThoai_sieu_nhe ++;
        }        
    }

    cout << "\nCo " << dem_DienThoai_sieu_nhe << " dien thoai sieu nhe\n\n";

    return 0;
}