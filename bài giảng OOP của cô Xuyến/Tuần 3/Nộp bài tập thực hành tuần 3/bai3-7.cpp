// Yêu cầu:
// 1. một của hàng có n sản phẩm

// 2. mỗi sản phẩm chứa thông tin: 
// --> mã
// --> tên
// --> năm sản xuất
// --> số lượng
// --> giá bán

// 3. nhập thông tin về n sản phẩm

#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct SanPham
{
    string ma_sanPham;
    string ten_sanPham;
    int nam_san_xuat;
    int so_luong;
    int gia;
};

// hàm nhập n sản phẩm
void NhapThongTinSanPham(vector<SanPham> &v){
    for (int i = 0; i < v.size(); i++)
    {
        cout << "\nNhap ma cua san pham \"index = "<< i <<"\" la: \t\t";
        getline(cin, v[i].ma_sanPham, '\n');
        cout << "Nhap ten cua san pham \"index = "<< i <<"\" la: \t\t";
        getline(cin, v[i].ten_sanPham, '\n');
        cout << "Nhap nam san xuat cua san pham \"index = "<< i <<"\" la: \t";
        cin >> v[i].nam_san_xuat;
        cout << "Nhap so luong cua san pham \"index = "<< i <<"\" la: \t";
        cin >> v[i].so_luong;
        cout << "Nhap gia cua san pham \"index = "<< i <<"\" la: \t\t";
        cin >> v[i].gia;
        cin.ignore();
    }
}

// hàm hiển thị n sản phẩm
void HienThi(vector<SanPham> v){
    for (int i = 0; i < v.size(); i++)
    {
        cout << "\nTHONG TIN SAN PHAM (index = " << i << ") \n";
        cout << "1. ma: \t\t\t" << v[i].ma_sanPham << endl;
        cout << "2. ten: \t\t" << v[i].ten_sanPham << endl;
        cout << "3. nam san xuat: \t" << v[i].nam_san_xuat << endl;
        cout << "4. so luong: \t\t" << v[i].so_luong << endl;
        cout << "5. gia: \t\t" << v[i].gia << endl;
    }
    
}

// hàm hiển thị tên sản phẩm được sản xuất năm 2020
void HienThi_TenSanPham_SanXuat2020(vector<SanPham> v){
    cout << "\nDANH SACH SAN PHAM SAN XUAT NAM 2020\n";
    int stt = 0;
    for (int i = 0; i < v.size(); i++)
    {
        if(v[i].nam_san_xuat == 2020){
            stt ++;
            cout << stt <<". ";
            cout << "ten: " << v[i].ten_sanPham;
            cout << ", nam san xuat: " << v[i].nam_san_xuat << endl;
        }else{
            cout << "=> Khong co san pham!" << endl;
        }
    }
    
}

// hàm tính tổng giá trị của tất cả sản phẩm đã nhập vào
// tổng_giá_trị_của_1_loại_sản_phẩm = số_lượng * giá_bán
// tổng_giá_trị = tổng_loại_1 + tổng_loại_2 + ... + tổng_loại_n
long TongGiaTri(vector<SanPham> v){
    long tong = 0;

    for (int i = 0; i < v.size(); i++)
    {
        tong = tong + v[i].so_luong * v[i].gia;
    } 

    return tong;
}

int main(){
    cout << "Nhap so luong san pham: ";
    int n;
    cin >> n;    
    cin.ignore();

    vector<SanPham> v_sp(n);

    NhapThongTinSanPham(v_sp);

    HienThi(v_sp);

    HienThi_TenSanPham_SanXuat2020(v_sp);

    cout << "\nTONG GIA TRI\n";
    cout << "=> " << TongGiaTri(v_sp) << endl;

    return 0;
}
