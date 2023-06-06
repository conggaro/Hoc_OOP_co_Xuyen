// Yêu cầu:
// 1. nhập 1 chuỗi bất kỳ từ bàn phím
// 2. đếm số lượng từ trong chuỗi

// 3. viết chức năng "Capitalize Each Word" trong MS Word

// VD: "hA NOI" --> "Ha Noi"

#include <iostream>
#include <string>
#include <vector>
using namespace std;

// hàm đếm số lượng từ trong chuỗi
// input: chuỗi (string)
// output: dem (kiểu int)
int HamDemSoLuongTu(string thamSo){
    int dem = 0;

    // từ hợp lệ --> bắt đầu bằng chữ hoa, hoặc chữ thường
    char kyTu;
    int soThapPhan;

    for (int i = 0; i < thamSo.length(); i++)
    {
        kyTu = thamSo[i];
        soThapPhan = (int)kyTu;

        bool kiemTra1 = soThapPhan >= 65 && soThapPhan <= 90 ? true : false;
        bool kiemTra2 = soThapPhan >= 97 && soThapPhan <= 122 ? true : false;

        if (kiemTra1 == true || kiemTra2 == true)
        {
            dem ++;
        }        
    }    

    return dem;
}

// hàm thực hiện chức năng Capitalize Each Word
// input: chuỗi (string)
// output: chuỗi đã được xử lý
string Ham_Capitalize_Each_Word(string thamSo){
    string ketQua;

    string khoi_tao1 = "";

    char kyTu;
    int soTP; // số thập phân

    for (int i = 0; i < thamSo.length(); i++)
    {
        kyTu = thamSo[i];
        soTP = (int)kyTu;

        if (65 <= kyTu && kyTu <= 90)
        {
            soTP = soTP + 32;
            kyTu = (char)soTP;
            thamSo[i] = kyTu;
        }
    }
    
    for (int i = 0; i < thamSo.size(); i++)
    {
        for (int j = i + 1; j < thamSo.size(); j++)
        {
            if (thamSo[i] == ' ')
            {
                kyTu = thamSo[j];
                soTP = (int)kyTu;
                if (soTP >= 97 && soTP <= 122)
                {
                    soTP = soTP - 32;
                    kyTu = (char)soTP;
                    thamSo[j] = kyTu;
                }
            }
            break;
        }
        
    }

    kyTu = thamSo[0];
    soTP = (int)kyTu;
    soTP = soTP - 32;
    kyTu = (char)soTP;
    thamSo[0] = kyTu;

    return thamSo;
}

int main(){
    cout << "Nhap vao 1 chuoi bat ky: ";
    string str;
    getline(cin, str, '\n');

    int dem = HamDemSoLuongTu(str);
    cout << "\nso luong tu trong chuoi la: ";
    cout << dem << "\n\n";

    // chuỗi đề bài “hA noi MUA vang Nhung CON mUA”
    string de_bai = "hA noi MUA vang Nhung CON mUA";

    cout << "chuoi ban dau la:\n";
    cout << "=> hA noi MUA vang Nhung CON mUA";

    cout << "\n\nchuoi sau khi duoc Capitalize Each Word la:\n";
    cout << "=> " << Ham_Capitalize_Each_Word(de_bai) << endl;
    cout << "\n";

    return 0;
}