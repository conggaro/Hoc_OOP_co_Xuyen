// Yêu cầu:
// 1. chuyển string sang int

#include <iostream>
#include <string>
using namespace std;

int to_int(string thamSo){
    int ketQua = 0;

    int item = 0;

    for (int i = 0; i < thamSo.length(); i++)
    {
        if (thamSo[i] == '0')
        {
            item = 0;
        }
        else if (thamSo[i] == '1')
        {
            item = 1;
        }
        else if (thamSo[i] == '2')
        {
            item = 2;
        }
        else if (thamSo[i] == '3')
        {
            item = 3;
        }
        else if (thamSo[i] == '4')
        {
            item = 4;
        }
        else if (thamSo[i] == '5')
        {
            item = 5;
        }
        else if (thamSo[i] == '6')
        {
            item = 6;
        }
        else if (thamSo[i] == '7')
        {
            item = 7;
        }
        else if (thamSo[i] == '8')
        {
            item = 8;
        }
        else if (thamSo[i] == '9')
        {
            item = 9;
        }
        else if (thamSo[i] == '.')
        {
            break;
        }

        ketQua = ketQua * 10 + item;
    }
    
    return ketQua;
}

int main(){
    // fake nhập vào 1 chuỗi
    string data1 = "25";
    string data2 = "5.5";

    cout << to_int(data1) + 10<< "\n\n";
    cout << to_int(data2) + 3<< "\n\n";

    return 0;
}