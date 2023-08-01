// Yêu cầu:
// 1. đếm từ

// trường hợp 2:
// không chứa dấu cách
// ký tự đầu tiên của từ khác số
// ký tự đầu tiên của từ phải là chữ (a...z hoặc A...Z)

#include <iostream>
#include <string>
using namespace std;

int main(){
    // fake nhập vào 1 chuỗi
    string str = "abc124 56hk79   6868 abcde gh780  abc345kmda   hksh";

    // tạo biến đếm
    int dem = 0;

    if (str[0] != ' ' && !('0' <= str[0] && str[0] <= '9'))
    {
        dem = 1;
    }

    // thuật toán đếm từ 
    // nếu str[i] == ' ' && str[i + 1] != ' '
    // 'a' <= str[i + 1] && str[i + 1] <= 'z'
    // 'A' <= str[i + 1] && str[i + 1] <= 'Z'
    // thì dem = dem + 1

    // duyệt chuỗi string chỉ đến
    // str.length() - 2 thôi

    for (int i = 0; i <= str.length() - 2; i++)
    {
        if (str[i] == ' ' && str[i + 1] != ' ')
        {
            bool kiemTra1 = 'a' <= str[i + 1] && str[i + 1] <= 'z' ? true : false;
            bool kiemTra2 = 'A' <= str[i + 1] && str[i + 1] <= 'Z' ? true : false;

            if (kiemTra1 || kiemTra2)
            {
                dem ++;
            }            
        }        
    }

    // in ra biến dem
    cout << "dem = " << dem << "\n\n";          // in ra 5

    return 0;
}