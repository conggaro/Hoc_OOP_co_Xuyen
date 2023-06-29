// Yêu cầu:
// 1. tạo lớp Circle

// 2. tạo thuộc tính
// x        --> kiểu int
// y        --> kiểu int
// z        --> kiểu int

// 3. tạo phương thức
// nhập dữ liệu từ bàn phím
// hiển thị dữ liệu

// 4. tạo phương thức tính chu vi

// 5. tạo phương thức tính diện tích

// kết quả thì lấy 2 chữ số phần thập phân

// 6. khai báo 3 đối tượng Circle

// 7. nhập dữ liệu

// 8. in ra thông tin theo thứ tự tăng dần theo diện tích

#include <iostream>
#include "Circle.cpp"
#include <iomanip>
using namespace std;

int main(){
    // tạo mảng
    Circle arr[3];

    // nhập dữ liệu
    for (int i = 0; i < 3; i++)
    {
        arr[i].NhapDuLieu();
        arr[i].Tinh_DienTich();
    }
    
    // sắp xếp
    for (int i = 0; i < 3; i++)
    {
        for (int j = i + 1; j < 3; j++)
        {
            Circle temp;

            if (arr[i].dien_tich > arr[j].dien_tich)
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }            
        }                
    }

    // in ra màn hình
    for (int i = 0; i < 3; i++)
    {
        arr[i].HienThi();
    }    

    return 0;
}