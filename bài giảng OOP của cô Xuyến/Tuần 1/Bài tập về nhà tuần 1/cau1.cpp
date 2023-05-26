// Yêu cầu:
// viết chương trình hiển thị bảng cửu chương

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

// |x       | --> có 8 ô trống
// tạo ra hàm chiếm 8 ô trống
string O_Trong_8(string str){
    string khoi_tao = "";
    
    int dem = 0;
    int index = 0;
    while((int)str[index] > 0)
    {
        dem = dem + 1;
        index = index + 1;
    }

    khoi_tao = khoi_tao + str;
    for(int i = 1; i <= 8 - dem; i++){
        khoi_tao = khoi_tao + " ";
    }

    return khoi_tao; 
}

string O_Trong_8(int thamSo){
    string str = to_string(thamSo);
    string khoi_tao = "";

    int dem = 0;
    int index = 0;
    while((int)str[index] > 0)
    {
        dem = dem + 1;
        index = index + 1;
    }

    khoi_tao = khoi_tao + str;
    for(int i = 1; i <= 8 - dem; i++){
        khoi_tao = khoi_tao + " ";
    }

    return khoi_tao;    
}

int main(){
    cout << O_Trong_8("x");
    for(int i = 1; i <= 10; i++){
        cout << O_Trong_8(i);
    }
    cout << endl;

    for(int i = 1; i <= 10; i++){
        cout << O_Trong_8(i);
        for(int j = 1; j <= 10; j++){
            if(j < 10){
                cout << O_Trong_8(i*j);
            }else if(j == 10){
                cout << i*j;
            }
        }
        cout << endl;
    }
    return 0;
}