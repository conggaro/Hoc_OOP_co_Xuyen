// Yêu cầu:
// 1. chuyển int sang string

// nhưng mà code của tôi 
// chỉ chuyển int dương sang string thôi

#include <iostream>
using namespace std;

// hàm chuyển kiểu int sang kiểu string
string to_string(int thamSo){
    string ketQua = "";

    // tạo biến item để xử lý từng số
    string item = "";

    // tạo biến số dư
    // để hứng dữ liệu
    int so_du = 0;

    // tạo biến khởi tạo
    // để ghép dữ liệu
    string khoi_tao = "";

    // tạo biến đếm độ dài của chuỗi khởi tạo
    int dem = 0;

    if (thamSo == 0)
    {
        ketQua = "0";
        return ketQua;
    }    

    while (thamSo != 0)
    {
        so_du = thamSo % 10;
        thamSo = thamSo / 10;

        if (so_du == 0)
        {
            item = "0";
        }
        else if (so_du == 1)
        {
            item = "1";
        }
        else if (so_du == 2)
        {
            item = "2";
        }
        else if (so_du == 3)
        {
            item = "3";
        }
        else if (so_du == 4)
        {
            item = "4";
        }
        else if (so_du == 5)
        {
            item = "5";
        }
        else if (so_du == 6)
        {
            item = "6";
        }
        else if (so_du == 7)
        {
            item = "7";
        }
        else if (so_du == 8)
        {
            item = "8";
        }
        else if (so_du == 9)
        {
            item = "9";
        }

        khoi_tao = khoi_tao + item;

        dem ++;
    }
    
    // đảo ngược chuỗi
    for (int i = dem - 1; i >= 0; i--)
    {
        ketQua = ketQua + khoi_tao[i];
    }

    return ketQua;
}

int main(){
    // cho các số x, y, z
    int x = 0;
    int y = 12345;
    // int z = -1;

    cout << to_string(x) << "\n";
    cout << to_string(y) << "\n\n";

    cout << to_string(x) + "1" << "\n";
    cout << to_string(y) + "AB" << "\n\n";

    return 0;
}