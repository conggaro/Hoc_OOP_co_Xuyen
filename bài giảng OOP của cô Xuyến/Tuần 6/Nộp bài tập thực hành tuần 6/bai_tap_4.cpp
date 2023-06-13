// Yêu cầu:
// 1. nhập vào số nguyên n

// 2. nhập thông tin cho n sinh viên
// mỗi sinh viên có các thông tin
// tên
// quê quán
// điểm toán
// điểm văn
// điểm tiếng anh

// 3. in ra danh sách sinh viên vừa nhập

// 4. nhập quê quán
// in ra tên sinh viên và quê quán

// 5. in ra danh sách sinh viên
// có điểm trung bình lớn hơn hoặc bằng 8.5

// 6. in ra đánh giá năng lực học

#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct SinhVien{
    string ten;
    string queQuan;
    float diemToan;
    float diemVan;
    float diemTiengAnh;
};

// hàm nhập dữ liệu
void NhapDuLieu(vector<SinhVien> &v, int do_dai){
    cout << "\n----------------- NHAP DU LIEU -----------------\n";
    
    SinhVien item;
    
    for (int i = 0; i < do_dai; i++)
    {
        cout << "\nSinh vien index = " << i << "\n";
        cout << "Nhap ten: \t\t\t";
        getline(cin, item.ten, '\n');

        cout << "Nhap que quan: \t\t\t";
        getline(cin, item.queQuan, '\n');

        cout << "Nhap diem toan: \t\t";
        cin >> item.diemToan;

        cout << "Nhap diem van: \t\t\t";
        cin >> item.diemVan;

        cout << "Nhap diem tieng anh: \t\t";
        cin >> item.diemTiengAnh;

        cin.ignore();

        v.push_back(item);
    }
}

// hàm hiển thị dữ liệu
void HienThi(vector<SinhVien> v){
    cout << "\n----------------- HIEN THI DU LIEU -----------------\n";

    for (int i = 0; i < v.size(); i++)
    {
        cout << "\nSinh vien index = " << i << "\n";
        cout << "Ten: \t\t\t\t" << v[i].ten << "\n";
        cout << "Que quan: \t\t\t" << v[i].queQuan << "\n";
        cout << "Diem toan: \t\t\t" << v[i].diemToan << "\n";
        cout << "Diem van: \t\t\t" << v[i].diemVan << "\n";
        cout << "Diem tieng anh: \t\t" << v[i].diemTiengAnh << "\n";
    }
    cout << "\n";
}

// hàm nhập quê quán
// hiển thị sinh viên ở quê quán đó
void Nhap_QueQuan_HienThi_QueQuan(vector<SinhVien> v){
    cout << "\n----------------- HIEN THI QUE QUAN -----------------\n";
    cout << "\nNhap que quan: ";
    string str = "";
    getline(cin, str, '\n');

    int dem = 0;

    cout << "\n";
    for (int i = 0; i < v.size(); i++)
    {
        if (str == v[i].queQuan)
        {
            cout << v[i].ten << ", " << v[i].queQuan << "\n";
            dem = dem + 1;
        }                
    }    

    if (dem == 0)
    {
        cout << "Khong ton tai." << "\n";
    }
    cout << "\n";
}

// hàm xếp loại sinh viên
void Xep_Loai_SinhVien(vector<SinhVien> v){
    vector<float> diemTB(0);

    float item_diem = 0;

    for (int i = 0; i < v.size(); i++)
    {
        item_diem = (v[i].diemToan + v[i].diemVan + v[i].diemTiengAnh) / 3;
        diemTB.push_back(item_diem);
    }
    
    cout << "\n----------------- XEP LOAI SINH VIEN -----------------\n\n";
    for (int i = 0; i < v.size(); i++)
    {
        if (diemTB[i] >= 8.5)
        {
            cout << v[i].ten << ", xep loai Gioi\n";
        }
        else if (diemTB[i] >= 7 && diemTB[i] < 8.5)
        {
            cout << v[i].ten << ", xep loai Kha\n";
        }
        else if (diemTB[i] >= 5 && diemTB[i] < 7)
        {
            cout << v[i].ten << ", xep loai Trung Binh\n";
        }
        else if (diemTB[i] < 5)
        {
            cout << v[i].ten << ", xep loai Yeu\n";
        }
    }

    cout << "\n";
}

int main(){
    cout << "Nhap vao so nguyen n: ";
    int n;
    cin >> n;
    cin.ignore();

    // tạo vector v_SinhVien
    vector<SinhVien> v_SinhVien(0);

    // gọi hàm nhập dữ liệu
    NhapDuLieu(v_SinhVien, n);

    // gọi hàm hiển thị
    HienThi(v_SinhVien);

    // gọi hàm nhập quê quán
    // in ra quê quán vừa nhập
    Nhap_QueQuan_HienThi_QueQuan(v_SinhVien);

    // gọi hàm xếp loại sinh viên
    Xep_Loai_SinhVien(v_SinhVien);

    return 0;
}