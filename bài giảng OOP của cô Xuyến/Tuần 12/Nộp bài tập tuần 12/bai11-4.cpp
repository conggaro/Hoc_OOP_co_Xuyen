// Yêu cầu:
// 1. tạo lớp Sach
// 2. nhập n (n <= 100)
// 3. nhập n phần tử

// 4. in ra những quyển sách đang bị mượn
// (trạng thái = true)

// 5. sắp xếp danh sách theo tên sách

// 6. in ra sách xuất bản trước năm 1990

#include <iostream>
#include <string>
#define SIZE 101
using namespace std;

// tạo lớp Sach
class Sach{
    private:
        string ten_sach;
        string ten_nha_xuat_ban;
        int nam_xuat_ban;
        int so_luong;
        bool trang_thai_muon;       // True là đang mượn, False là không mượn

    public:
        // hàm khởi tạo không tham số
        Sach(){
            ten_sach = "";
            ten_nha_xuat_ban = "";
            nam_xuat_ban = 0;
            so_luong = 0;
            trang_thai_muon = false;
        }

        // hàm nhập dữ liệu
        void NhapDuLieu(){
            cout << "Nhap ten sach: ";
            getline(cin, ten_sach, '\n');

            cout << "Nhap ten nha xuat ban: ";
            getline(cin, ten_nha_xuat_ban, '\n');

            cout << "Nhap nam xuat ban: ";
            cin >> nam_xuat_ban;

            cout << "Nhap so luong: ";
            cin >> so_luong;

            cout << "Nhap trang thai muon: ";
            cin >> trang_thai_muon;
            cin.ignore();
        }

        // hàm hiển thị dữ liệu
        void HienThi(){
            cout << "THONG TIN SACH:\n";
            cout << "Ten sach: " << ten_sach << "\n";
            cout << "Ten nha xuat ban: " << ten_nha_xuat_ban << "\n";
            cout << "Nam xuat ban: " << nam_xuat_ban << "\n";
            cout << "So luong: " << so_luong << "\n";
            cout << "Trang thai muon: " << trang_thai_muon << "\n";
        }

        // hàm get_TrangThai
        bool get_TrangThai(){
            return trang_thai_muon;
        }

        // hàm get_TenSach
        string get_TenSach(){
            return ten_sach;
        }

        // hàm get_NamXuatBan
        int get_NamXuatBan(){
            return nam_xuat_ban;
        }
};

int main(){
    // nhập n
    cout << "Nhap n: ";
    int n;
    cin >> n;

    while (n <= 0 || n > 100)
    {
        cout << "Nhap lai n (0 < n <= 100): ";
        cin >> n;
    }
    cin.ignore();

    // tạo mảng
    Sach arr[SIZE];

    // gọi phương thức nhập dữ liệu
    cout << "\n-------------------- NHAP DU LIEU --------------------\n";
    for (int i = 0; i < n; i++)
    {
        arr[i].NhapDuLieu();
        cout << "\n";
    }

    // in ra sách (mượn = true)
    cout << "-------------------- NHUNG SACH DANG MUON --------------------\n";
    for (int i = 0; i < n; i++)
    {
        if (arr[i].get_TrangThai() == true)
        {
            arr[i].HienThi();
            cout << "\n";
        }
    }

    // sắp xếp danh sách theo tên sách
    Sach temp;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i].get_TenSach() > arr[j].get_TenSach())
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }            
        }        
    }
    
    cout << "-------------------- SAP XEP THEO TEN SACH --------------------\n";
    for (int i = 0; i < n; i++)
    {
        arr[i].HienThi();
        cout << "\n";
    }

    // in ra sách xuất bản trước năm 1990
    // đếm xem có bao nhiêu
    // quyển sách xuất bản trước năm 1990
    int dem_sach = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i].get_NamXuatBan() < 1990)
        {
            dem_sach ++;
        }        
    }
    
    cout << "Co " << dem_sach << " quyen sach xuat ban truoc nam 1990\n\n";
    if (dem_sach > 0)
    {
        for (int i = 0; i < n; i++)
        {
            if (arr[i].get_NamXuatBan() < 1990)
            {
                arr[i].HienThi();
            }
        }        
    }
    
    return 0;
}