// Mô tả:
// cho n sinh viên

// mỗi sinh viên có các thông tin:
// tên
// quê quán
// điểm Toán
// điểm Văn
// điểm Anh

// Yêu cầu:
// 1. đọc file
// 2. ghi file

// FILE INPUT
// dòng 1 là số lượng sinh viên

// cứ 3 dòng tiếp theo thì ghi thông tin về 1 sinh viên
// tên sinh viên
// quê quán
// điểm Toán, điểm Văn, điểm Anh

// FILE OUTPUT
// dòng đầu đếm sinh viên có điểm trung bình >= 8.5

// các dòng sau ghi
// tên, quê quán, điểm trung bình

#include <iostream>
#include <fstream>
#include <string>
#define SIZE 20
using namespace std;

// tạo kiểu dữ liệu bản ghi sinh viên
struct SinhVien
{
    string ten;
    string que_quan;
    float diemToan;
    float diemVan;
    float diemAnh;
};


int main(){
    // tạo mảng
    SinhVien arr[SIZE];

    // tạo n
    int n = 0;

    // tạo đối tượng đọc file
    ifstream file_in;
    file_in.open("SINHVIEN.INP");

    if (file_in.fail() == true)
    {
        cout << "Mo file SINHVIEN.INP THAT BAI\n\n";
    }
    else if (file_in.fail() == false)
    {
        cout << "Mo file SINHVIEN.INP THANH CONG\n\n";

        // ghi vào n
        file_in >> n;
        file_in.ignore();

        for (int i = 0; i < n; i++)
        {
            getline(file_in, arr[i].ten, '\n');
            getline(file_in, arr[i].que_quan, '\n');
            file_in >> arr[i].diemToan;
            file_in >> arr[i].diemVan;
            file_in >> arr[i].diemAnh;
            file_in.ignore();
        }

        file_in.close();
    }
    
    // tạo đối tượng ghi file
    ofstream file_out;
    file_out.open("SINHVIEN.OUT",ios::out);
    
    if (file_out.fail() == true)
    {
        cout << "Mo file SINHVIEN.OUT THAT BAI\n\n";
    }
    else if (file_out.fail() == false)
    {
        cout << "Mo file SINHVIEN.OUT THANH CONG\n\n";

        // tạo điểm trung bình
        float diemTB = 0;

        int dem = 0;

        for (int i = 0; i < n; i++)
        {
            diemTB = (arr[i].diemToan + arr[i].diemVan + arr[i].diemAnh) / 3;
            if (diemTB >= 8.5)
            {
                dem ++;
            }            
        }

        file_out << dem << "\n";

        for (int i = 0; i < n; i++)
        {
            diemTB = (arr[i].diemToan + arr[i].diemVan + arr[i].diemAnh) / 3;
            if (diemTB >= 8.5)
            {
                file_out << arr[i].ten << " " << arr[i].que_quan << " ";
                file_out << diemTB << "\n";
            }            
        }        

        file_out.close();
    }    

    return 0;
}