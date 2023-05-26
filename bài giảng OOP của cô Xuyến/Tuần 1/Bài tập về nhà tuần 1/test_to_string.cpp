// Yêu cầu:
// sử dụng to_string() để tạo ra dãy chiếm 8 ô trống

#include <iostream>
#include <string>
using namespace std;

int main(){
    int x = 10;
    string str = to_string(x);

    // bool kiemTra = typeid(str) == typeid(string) ? true : false;
    // cout << kiemTra << endl;
    // đã kiểm tra --> đúng là chuyển được sang string

    cout << str.size() << endl;

    string khoi_tao = "";

    if(str.size() < 8){
        khoi_tao = khoi_tao + str;
        for(int i = 1; i <= 8 - str.size(); i++){
            khoi_tao = khoi_tao + " ";
        }
    }

    cout << khoi_tao.size() << endl;
    return 0;
}