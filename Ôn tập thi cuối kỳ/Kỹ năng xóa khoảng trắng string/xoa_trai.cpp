// Yêu cầu:
// 1. xóa khoảng trắng thừa ở bên trái

#include <iostream>
#include <string>
using namespace std;

// hàm xóa khoảng trắng thừa ở bên trái
void Xoa_KhoangTrang_BenTrai(string &str){
    int i = 0;
    
    for (; i < str.length();)
    {
        if (str[0] == ' ')
        {
            str.erase(0, 1);
        }
        else if (str[0] != ' ')
        {
            break;
        }        
    }    
}

int main(){
    // fake nhập một chuỗi
    string str = "     Nguyen    Van    A    ";

    // in ra chuỗi ban đầu
    cout << "Ban dau: \n\"" << str << "\"";

    // gọi hàm xóa khoảng trắng
    // bị thừa bên trái
    Xoa_KhoangTrang_BenTrai(str);

    // in ra chuỗi sau khi xóa
    cout << "Sau khi xoa: \n\"" << str << "\"";

    return 0;
}