// Yêu cầu:
// 1. xóa khoảng trắng thừa ở bên phải

#include <iostream>
#include <string>
using namespace std;

// hàm xóa khoảng trắng thừa ở bên phải
void Xoa_KhoangTrang_BenPhai(string &str){
    int i = str.length() - 1;
    
    for (; i >= 0;)
    {
        if (str[i] == ' ')
        {
            str.erase(i, 1);

            i --;
        }
        else if (str[i] != ' ')
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
    // bị thừa bên phải
    Xoa_KhoangTrang_BenPhai(str);

    // in ra chuỗi sau khi xóa
    cout << "Sau khi xoa: \n\"" << str << "\"";

    return 0;
}