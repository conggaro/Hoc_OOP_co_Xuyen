// Yêu cầu:
// 1. chuẩn hóa chuỗi

// chuỗi ban đầu:
// "    HA   noi    mua vANg     nhung con   muA    "

// kết quả mong đợi:
// "Ha Noi Mua Vang Nhung Con Mua"

#include <iostream>
#include <string>
using namespace std;

// hàm xóa khoảng trắng ở đầu
void Ham_Xoa_Dau(string &str){
    int i = 0;

    for (; i < str.length();)
    {
        if (str[0] == ' ')
        {
            str.erase(0, 1);
        }
        else
        {
            break;
        }
    }    
}

// hàm xóa khoảng trắng ở đuôi
void Ham_Xoa_Duoi(string &str){
    for (int i = str.length() - 1; i >= 0;)
    {
        if (str[i] == ' ')
        {
            str.erase(i, 1);

            i --;
        }
        else
        {
            break;
        }
    }    
}

// hàm xóa khoảng trắng ở giữa
void Ham_Xoa_Giua(string &str){
    int i = 0;
    
    for (; i < str.length();)
    {
        if (str[i] == ' ' && str[i + 1] == ' ')
        {
            str.erase(i, 1);
        }
        else
        {
            i ++;
        }
    }    
}

// hàm chuyển tất cả ký tự thành chữ thường
void Ham_Chuyen_ChuThuong(string &str){
    for (int i = 0; i < str.length(); i++)
    {
        if ('A' <= str[i] && str[i] <= 'Z')
        {
            str[i] = str[i] + 32;
        }
    }
}

// hàm viết hoa chữ đầu tiên của mỗi từ
void Ham_VietHoa_ChuDauTien(string &str){
    if ('a' <= str[0] && str[0] <= 'z')
    {
        str[0] = str[0] - 32;
    }

    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == ' ' && str[i + 1] != ' ')
        {
            if ('a' <= str[i + 1] && str[i + 1] <= 'z')
            {
                str[i + 1] = str[i + 1] - 32;
            }
        }
    }
}

int main(){
    // fake nhập 1 chuỗi
    string str = "    HA   noi    mua vANg     nhung con   muA    ";

    // in ra chuỗi ban đầu
    cout << "Ban dau:\n\"" << str << "\"\n";

    // gọi hàm xóa khoảng trắng ở đầu
    Ham_Xoa_Dau(str);

    // gọi hàm xóa khoảng trắng ở đuôi
    Ham_Xoa_Duoi(str);

    // gọi hàm xóa khoảng trắng ở giữa
    Ham_Xoa_Giua(str);

    // gọi hàm chuyển tất cả ký tự thành chữ thường
    Ham_Chuyen_ChuThuong(str);

    // gọi hàm viết hoa chữ đầu tiên của mỗi từ
    Ham_VietHoa_ChuDauTien(str);

    // in ra chuỗi sau khi chuẩn hóa
    cout << "\nSau khi chuan hoa:\n\"" << str << "\"\n\n";

    return 0;
}