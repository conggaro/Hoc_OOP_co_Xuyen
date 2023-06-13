// Mô tả
// một cửa hàng có n sách

// sách thì có thông tin:
// tên sách
// năm xuất bản
// số lượng
// giá bán

// Yêu cầu:
// 1. đọc file
// 2. ghi file

// FILE INPUT
// dòng 1       --> ghi số lượng sách

// cứ 2 dòng tiếp theo là thông tin của 1 sách
// tên sách
// năm xuất bản, số lượng, giá bán

// FILE OUTPUT
// dòng 1       --> số lượng sách có doanh thu >= 1000
// các dòng tiếp theo là tên sách

#include <iostream>
#include <fstream>
#include <string>
#define SIZE 20
using namespace std;

// tạo kiểu dữ liệu bản ghi
struct Sach
{
    string ten;
    int nam_XuatBan;
    int so_luong;
    int gia_ban;
};

int main(){
    // tạo mảng
    Sach arr[SIZE];

    // tạo n
    int n = 0;

    // tạo đối tượng đọc file
    ifstream file_in;
    file_in.open("BOOK.INP", ios::in);

    if (file_in.fail() == true)
    {
        cout << "Mo file BOOK.INP THAT BAI\n\n";
    }
    else if (file_in.fail() == false)
    {
        cout << "Mo file BOOK.INP THANH CONG\n\n";

        // ghi vào n
        file_in >> n;
        file_in.ignore();

        for (int i = 0; i < n; i++)
        {
            getline(file_in, arr[i].ten);
            file_in >> arr[i].nam_XuatBan;
            file_in >> arr[i].so_luong;
            file_in >> arr[i].gia_ban;
            file_in.ignore();
        }

        file_in.close();
    }
    
    // tạo đối tượng ghi file
    ofstream file_out;
    file_out.open("BOOK.OUT", ios::out);

    if (file_out.fail() == true)
    {
        cout << "Mo file BOOK.OUT THAT BAI\n\n";
    }
    else if (file_out.fail() == false)
    {
        cout << "Mo file BOOK.OUT THANH CONG\n\n";

        // tạo biến đếm
        int dem = 0;

        for (int i = 0; i < n; i++)
        {
            if (arr[i].so_luong * arr[i].gia_ban >= 1000)
            {
                dem = dem + 1;
            }            
        }
        
        file_out << dem << "\n";

        for (int i = 0; i < n; i++)
        {
            if (arr[i].so_luong * arr[i].gia_ban >= 1000)
            {
                file_out << arr[i].ten << "\n";
            }
        }

        file_out.close();
    }

    return 0;
}