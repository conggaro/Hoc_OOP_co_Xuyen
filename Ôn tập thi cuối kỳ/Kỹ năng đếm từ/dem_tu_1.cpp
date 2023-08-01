// Yêu cầu:
// 1. đếm từ

// trường hợp 1:
// chỉ cần từ không chứa dấu cách

#include <iostream>
#include <string>
using namespace std;

int main(){
    // fake nhập vào 1 chuỗi
    string str = "abc124 56hk79   6868 abcde gh780  abc345kmda   hksh";

    // tạo biến đếm
    int dem = 0;

    if (str[0] != ' ')
    {
        dem = 1;
    }

    // thuật toán đếm từ 
    // nếu str[i] == ' ' && str[i + 1] != ' '
    // thì dem = dem + 1

    // duyệt chuỗi string chỉ đến
    // str.length() - 2 thôi

    for (int i = 0; i <= str.length() - 2; i++)
    {
        if (str[i] == ' ' && str[i + 1] != ' ')
        {
            dem ++;
        }        
    }

    // in ra biến dem
    cout << "dem = " << dem << "\n\n";          // in ra 7

    return 0;
}