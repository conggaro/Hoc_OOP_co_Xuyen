// Yêu cầu:
// 1. nhập 1 chuỗi bất kỳ từ bàn phím
// 2. chuẩn hóa chuỗi đó

// VD: "   HA noi     mua vANg nhung    con muA "
// --> "Ha noi mua vang nhung con mua"

#include <iostream>
#include <string>
using namespace std;

// hàm chuẩn hóa chuỗi
// input:
// 1. chuỗi (chuỗi bị nhiều vấn đề)

// output:
// 1. chuỗi đã được chuẩn hóa
string HamChuanHoaChuoi(string thamSo){
    string khoi_tao;

    // việc 1: 
    // xóa hết những cái khoảng trắng bị trùng nhau
    // kết quả thu được là chuỗi cách nhau bởi 1 khoảng trắng thôi
    // Gợi ý: sử dụng hàm xóa phần tử trong chuỗi .erase()

    int index = 0;

    while(index < thamSo.length()){
        if(thamSo[index] == thamSo[index + 1]){
            if(thamSo[index] == ' '){
                thamSo.erase(index, 1);
            }
        }
        else if(thamSo[index] != thamSo[index + 1]){
            index = index + 1;
        }
    }

    // việc 2:
    // chuyển tất cả chữ hoa thành chữ thường
    char kyTu;
    int soTP; // số thập phân
    for (int i = 0; i < thamSo.length(); i++)
    {
        kyTu = thamSo[i];
        soTP = (int)kyTu;
        if (soTP >= 65 && soTP <= 90)
        {
            soTP = soTP + 32;
            kyTu = (char)soTP;
            thamSo[i] = kyTu;
        }        
    }
    
    // việc 3:
    // xóa khoảng trắng ở đầu
    if(thamSo[0] == ' '){
        thamSo.erase(0, 1);
    }

    // việc 4:
    // xóa khoảng trắng ở cuối
    if(thamSo[thamSo.length() - 1] == ' '){
        thamSo.erase(thamSo.length() - 1, 1);
    }

    // việc 5:
    // viết hoa chữ đầu tiên
    kyTu = thamSo[0];
    soTP = (int)kyTu;
    soTP = soTP - 32;
    kyTu = (char)soTP;
    thamSo[0] = kyTu;

    return thamSo;
}

int main(){
    // cout << "nhap vao 1 chuoi bat ky: \n";
    string str;
    // getline(cin, str, '\n');

    // fake nhập chuỗi
    str = "   HA noi     mua vANg nhung    con muA ";

    // hiển thị chuỗi ban đầu
    cout << "chuoi ban dau la:\n";
    cout << "\"" << str << "\"";

    cout << "\n\n";

    // hiển thị chuỗi đã được chuẩn hóa
    cout << "chuoi da duoc chuan hoa la:\n";
    cout << "\"" << HamChuanHoaChuoi(str) << "\"" << endl;

    cout << "\n\n";

    return 0;
}