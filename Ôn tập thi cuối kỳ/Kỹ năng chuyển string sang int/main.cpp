// Yêu cầu:
// 1. chuyển "12345" thành 12345

#include <iostream>
#include <string>
using namespace std;

// hàm chuyển kiểu string sang kiểu int
int to_int(string str){
    int ketQua = 0;

    // tạo biến item
    // để xử lý từng cái str[i]
    int item = 0;

    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == '0')
        {
            item = 0;
        }
        else if (str[i] == '1')
        {
            item = 1;
        }
        else if (str[i] == '2')
        {
            item = 2;
        }
        else if (str[i] == '3')
        {
            item = 3;
        }
        else if (str[i] == '4')
        {
            item = 4;
        }
        else if (str[i] == '5')
        {
            item = 5;
        }
        else if (str[i] == '6')
        {
            item = 6;
        }
        else if (str[i] == '7')
        {
            item = 7;
        }
        else if (str[i] == '8')
        {
            item = 8;
        }
        else if (str[i] == '9')
        {
            item = 9;
        }
        else if (str[i] == '.')
        {
            break;
        }

        ketQua = ketQua * 10 + item;
    }

    return ketQua;
}

int main(){
    string str1 = "0";
    string str2 = "12345";
    string str3 = "5.5";

    cout << to_int(str1)<< "\n";
    cout << to_int(str2)<< "\n";
    cout << to_int(str3)<< "\n\n";

    cout << to_int(str1) + 1 << "\n";
    cout << to_int(str2) + 1 << "\n";
    cout << to_int(str3) + 1 << "\n\n";

    return 0;
}