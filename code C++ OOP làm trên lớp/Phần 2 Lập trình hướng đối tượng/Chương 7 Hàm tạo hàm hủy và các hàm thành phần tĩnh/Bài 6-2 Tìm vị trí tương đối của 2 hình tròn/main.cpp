// Yêu cầu:
// 1. bổ sung thuộc tính TÂM_HÌNH_TRÒN vào lớp HÌNH_TRÒN
// đã xây dựng trong bài 6-1

// tức là tạo ra 1 lớp "Diem"
// rồi dùng lớp "Diem" như 1 thuộc tính trong lớp "HinhTron"

// 2. viết hàm bạn vitrituongdoi(HinhTron dt1, HinhTron dt2)
// để xét vị trí tương đối giữa 2 hình tròn
// giao nhau
// hoặc không giao nhau

#include <iostream>
#include "HinhTron.cpp"
using namespace std;

int main(){
    // tạo đối tượng
    HinhTron dt1 = HinhTron(1, "Mau trang");

    HinhTron dt2;
    dt2.set_BanKinh(1);
    dt2.set_MauSac("Mau den");

    // gọi phương thức hiển thị
    dt1.HienThi();
    dt2.HienThi();

    // thiết lập tọa độ cho tâm hình tròn
    dt1.set_TamHinhTron(0, 0);
    dt2.set_TamHinhTron(2, 0);

    vitrituongdoi(dt1, dt2);

    return 0;
}