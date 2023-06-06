// Yêu cầu:
// 1. nhập vào số nguyên n
// 2. nhập n cái họ và tên
// 3. in ra màn hình tên của những người đó

#include <iostream>
#include <string>
#define SIZE 100
using namespace std;

// hàm lấy tên
string HamLayTen(string thamSo){
    string khoi_tao = "";
    string dao_nguoc = "";

    for (int i = thamSo.length() - 1; i >= 0 ; i--)
    {
        dao_nguoc = dao_nguoc + thamSo[i];
    }
    
    char kyTu;
    int soTP; // số thập phân
    string dao_nguoc2 = "";

    for (int i = 0; i < dao_nguoc.length(); i++)
    {
        kyTu = dao_nguoc[i];
        soTP = (int)kyTu;
        if (soTP == 32)
        {
            break;
        }
        dao_nguoc2 = dao_nguoc2 + dao_nguoc[i];
    }
    
    for (int i = dao_nguoc2.length() - 1; i >= 0; i--)
    {
        khoi_tao = khoi_tao + dao_nguoc2[i];
    }

    return khoi_tao;
}

int main(){
    cout << "nhap vao so nguyen n: ";
    int n;
    cin >> n;
    cin.ignore();

    string arr[SIZE];

    for (int i = 0; i < n; i++)
    {
        cout << "arr[" << i << "] = ";
        getline(cin, arr[i], '\n');
    }
    
    cout << "\nhien thi ten:\n";
    for (int i = 0; i < n; i++)
    {
        cout << HamLayTen(arr[i]) << endl;
    }

    return 0;
}