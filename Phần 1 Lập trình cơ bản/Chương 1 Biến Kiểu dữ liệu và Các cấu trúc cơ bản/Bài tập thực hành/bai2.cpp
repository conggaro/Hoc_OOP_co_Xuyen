// Yêu cầu:
// 1. Nhập vào số phút gọi điện thoại của 1 "ĐẠI GIA"
// 2. Tính tiền điện thoại

#include <iostream>
using namespace std;

int main(){
    cout << "Nhap vao so phut goi dien thoai: ";
    int soPhut;
    cin >> soPhut;

    while (soPhut <= 0)
    {
        cout << "Moi nhap lai so phut: ";
        cin >> soPhut;
    }
    

    // Công thức tính tiền
    // Phí thuê bao bắt buộc 150000đ
    // Tức là mở máy alo 1 cái là mất 150k
    // 1. 600đ cho mỗi phút gọi của 50p đầu tiên
    // 2. 400đ cho mỗi phút gọi của 150 phút tiếp theo
    // 3. 200đ cho mỗi phút gọi của các phút tiếp theo

    int Tien;
    int tien1 = 600; // 600đ mỗi phút
    int tien2 = 400; // 400đ mỗi phút
    int tien3 = 200; // 200đ mỗi phút

    if(soPhut <= 50){
        Tien = 150000 + tien1 * soPhut;
        cout << "Ban bi tru " << Tien << "d vao tai khoan goc." << endl;
    }else if(soPhut > 50 && soPhut <= 200){
        Tien = 150000 + tien1*50 + tien2*(soPhut-50);
        cout << "Ban bi tru " << Tien << "d vao tai khoan goc." << endl;
    }else if (soPhut > 200){
        Tien = 150000 + tien1*50 + tien2*(200-50) + tien3*(soPhut-200);
        cout << "Ban bi tru " << Tien << "d vao tai khoan goc." << endl;
    }

    return 0;
}