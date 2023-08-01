// Yêu cầu:
// 1. xóa khoảng trắng thừa ở giữa

#include <iostream>
#include <string>
using namespace std;

// hàm xóa khoảng trắng thừa ở giữa
void Xoa_KhoangTrang_Giua(string &str){
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

int main(){
    // fake nhập một chuỗi
    string str = "Nguyen    Van    A";

    // in ra chuỗi ban đầu
    cout << "Ban dau: \n\"" << str << "\"";

    // gọi hàm xóa khoảng trắng
    // bị thừa bên giữa
    Xoa_KhoangTrang_Giua(str);

    // in ra chuỗi sau khi xóa
    cout << "Sau khi xoa: \n\"" << str << "\"";

    return 0;
}