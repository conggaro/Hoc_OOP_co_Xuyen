// Yêu cầu:
// 1. tạo lớp Student

// 2. tạo thuộc tính
// mã sv                (string)
// họ và tên            (string)
// điểm TB              (double)

// 3. tạo phương thức
// nhập dữ liệu từ bàn phím
// hiển thị dữ liệu ra màn hình

// 4. trong hàm main thì tạo 2 đối tượng Student
// nhập dữ liệu

// 5. in ra dữ liệu giảm dần
// theo điểm TB
// điểm TB thì lấy 1 chữ số ở phần thập phân

#include <iostream>
#include "Student.cpp"
using namespace std;

int main(){
    // tạo mảng
    Student arr[2];

    // gọi phương thức nhập dữ liệu
    for (int i = 0; i < 2; i++)
    {
        arr[i].NhapDuLieu();
    }

    // sắp xếp theo chiều giảm dần
    Student temp;
    for (int i = 0; i < 2; i++)
    {
        for (int j = i + 1; j < 2; j++)
        {
            if (arr[i].get_diemTB() < arr[j].get_diemTB())
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }            
        }        
    }    
    
    // gọi phương thức hiển thị
    for (int i = 0; i < 2; i++)
    {
        arr[i].HienThi();
    }
    
    return 0;
}