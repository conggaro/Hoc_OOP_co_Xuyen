// Yêu cầu:
// 1. nhập một chuỗi bất kỳ từ bàn phím
// 2. viết hàm mã hóa chuỗi

// quy tắc mã hóa:
// 2 --> "ABC"
// 3 --> "DEF"
// 4 --> "GHI"
// 5 --> "JKL"
// 6 --> "MNO"
// 7 --> "PQRS"
// 8 --> "TUV"
// 9 --> "WXYZ"

// VD chuỗi: "CNTT - DHSPHN" --> "2688 - 347746"

#include <iostream>
using namespace std;

// hàm mã hóa ký tự
// trả ra ký tự '2', '3',..., '9'
char HamMaHoa(char thamSo){
    char ketQuaMaHoa;
    
    char kyTu;
    int soThapPhan;
    
    kyTu = thamSo;
    soThapPhan = (int)kyTu;

    // code tiền xử lý
    // vùng "ABC"
    bool kiemTra_ABC = soThapPhan >= 65 && soThapPhan <= 67 ? true : false;

    // vùng "DEF"
    bool kiemTra_DEF = soThapPhan >= 68 && soThapPhan <= 70 ? true : false;

    // vùng "GHI"
    bool kiemTra_GHI = soThapPhan >= 71 && soThapPhan <= 73 ? true : false;

    // vùng "JKL"
    bool kiemTra_JKL = soThapPhan >= 74 && soThapPhan <= 76 ? true : false;

    // vùng "MNO"
    bool kiemTra_MNO = soThapPhan >= 77 && soThapPhan <= 79 ? true : false;

    // vùng "PQRS"
    bool kiemTra_PQRS = soThapPhan >= 80 && soThapPhan <= 83 ? true : false;

    // vùng "TUV"
    bool kiemTra_TUV = soThapPhan >= 84 && soThapPhan <= 86 ? true : false;

        // vùng "WXYZ"
        bool kiemTra_WXYZ = soThapPhan >= 87 && soThapPhan <= 90 ? true : false;

        if (kiemTra_ABC)
        {
            ketQuaMaHoa = '2';

        }else if (kiemTra_DEF)
        {
            ketQuaMaHoa = '3';

        }else if (kiemTra_GHI)
        {
            ketQuaMaHoa = '4';

        }else if (kiemTra_JKL)
        {
            ketQuaMaHoa = '5';

        }else if (kiemTra_MNO)
        {
            ketQuaMaHoa = '6';
            
        }else if (kiemTra_PQRS)
        {
            ketQuaMaHoa = '7';
            
        }else if (kiemTra_TUV)
        {
            ketQuaMaHoa = '8';
            
        }else if (kiemTra_WXYZ)
        {
            ketQuaMaHoa = '9';
            
        }
        
    return ketQuaMaHoa;
}

// hàm mã hóa cả một chuỗi luôn
// đưa vào 1 chuỗi string
// trả ra 1 chuỗi string đã được mã hóa
string HamMaHoa_String_To_23456789(string thamSo){
    string khoi_tao;

    char kyTu;
    int soThapPhan;

    for (int i = 0; i < thamSo.length(); i++)
    {
        kyTu = thamSo[i];
        soThapPhan = (int)kyTu;

        // đây là điều kiện tiền xử lý "ABC...XYZ"
        // nó là cái khoảng [65, 90]
        bool kiemTra1 = soThapPhan >= 65 ? true : false;
        bool kiemTra2 = soThapPhan <= 90 ? true : false;

        if (kiemTra1 && kiemTra2)
        {
            khoi_tao.push_back(HamMaHoa(thamSo[i]));
        }else if (kiemTra1 == false || kiemTra2 == false)
        {
            khoi_tao.push_back(thamSo[i]);
        }
    }    

    return khoi_tao;
}

int main(){
    // cho chuỗi: "CNTT - DHSPHN"
    string str = "CNTT - DHSPHN"; 

    // hứng kết quả
    string data = HamMaHoa_String_To_23456789(str);

    cout << "\nchuoi sau khi ma hoa la: ";
    for (int i = 0; i < data.length(); i++)
    {
        cout << data[i];
    }
    cout << endl;

    return 0;
}