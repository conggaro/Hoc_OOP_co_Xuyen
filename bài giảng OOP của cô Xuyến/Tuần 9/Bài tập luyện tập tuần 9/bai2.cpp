// Yêu cầu:
// 1. tạo lớp Fraction

// 2. thuộc tính
// a
// b

// 3. phương thức
// nhập dữ liệu từ bàn phím
// hiển thị dữ liệu ra màn hình

// 4. tạo phương thức rút gọn phân số

// 5. tạo hàm bạn friend để so sánh 2 phân số

// 6. khai báo 3 đối tượng Fraction

// 7. nhập dữ liệu cho 3 đối tượng

// 8. sắp xếp đối tượng tăng dần
// in ra màn hình
// nhưng mà phải in ra cái loại đã rút gọn

#include <iostream>
#include "Fraction.cpp"
using namespace std;

int main(){
    // tạo mảng
    Fraction arr[3];

    // gọi phương thức nhập dữ liệu
    for (int i = 0; i < 3; i++)
    {
        arr[i].NhapDuLieu();
    }

    // sắp xếp tăng dần
    for (int i = 0; i < 3; i++)
    {
        for (int j = i + 1; j < 3; j++)
        {
            Fraction temp;

            if (SoSanh_2_PhanSo(arr[i], arr[j]) == 1)
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }        
    }    

    // gọi phương thức hiển thị
    for (int i = 0; i < 3; i++)
    {
        arr[i].Rut_Gon_PhanSo();
        arr[i].HienThi();
    }        

    return 0;
}