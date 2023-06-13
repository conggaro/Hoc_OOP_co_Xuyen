// Mô tả:
// một lớp học có n sinh viên

// mỗi sinh viên có 2 thông tin
// gồm:
// tên
// điểm tổng kết

// Yêu cầu:
// 1. nhập số nguyên n
// 2. nhập thông tin cho n sinh viên

// 3. kiểm tra và lưu những sinh viên có tên "Hoang"
// điểm tổng kết thì phải >= 8.0
// lưu vào file sinhvien.txt

// mỗi dòng thì ghi họ tên, điểm tổng kết

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

struct SinhVien{
    string ten;
    float diemTongKet;
};

// hàm nhập thông tin
void NhapThongTin(vector<SinhVien> &v_sv, int do_dai){
    cout << "\n-------------------- NHAP THONG TIN --------------------\n";

    SinhVien item;

    for (int i = 0; i < do_dai; i++)
    {
        cout << "\nSinh vien index = " << i << "\n";
        
        cout << "Nhap ten: ";
        getline(cin, item.ten, '\n');

        cout << "Nhap diem tong ket: ";
        cin >> item.diemTongKet;
        cin.ignore();

        v_sv.push_back(item);
    }
    cout << "\n";
}

// hàm lấy ra tên từ chuỗi họ và tên
string Lay_Ten(string thamSo){
    // việc 1:
    // tìm cái dấu cách đầu tiên
    // tìm từ phải sang trái
    int vi_tri = thamSo.rfind(' ', thamSo.length() - 1);
    string ten = thamSo.substr(vi_tri + 1, thamSo.length() - 1 - vi_tri);

    return ten;
}

int main(){
    // nhập vào n
    cout << "Nhap vao so nguyen n: ";
    int n;
    cin >> n;
    cin.ignore();

    // tạo vector sinh viên
    vector<SinhVien> v(0);

    // gọi hàm nhập thông tin
    NhapThongTin(v, n);

    // tạo đối tượng để ghi file
    ofstream file_out;
    file_out.open("sinhvien.txt", ios::out);

    if (file_out.fail() == true)
    {
        cout << "Mo file THAT BAI\n";
    }
    else if (file_out.fail() == false)
    {
        cout << "Mo file THANH CONG\n\n";

        for (int i = 0; i < v.size(); i++)
        {
            // lấy tên
            string data_ten = Lay_Ten(v[i].ten);

            if (data_ten == "Hoang")
            {
                if (v[i].diemTongKet >= 8.0)
                {
                    file_out << v[i].ten << "," << v[i].diemTongKet << "\n";
                }                
            }            
        }

        file_out.close();
    }

    return 0;
}