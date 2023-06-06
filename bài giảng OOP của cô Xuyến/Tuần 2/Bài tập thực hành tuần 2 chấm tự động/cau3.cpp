// Yêu cầu:
// 1. Nhập vào 1 số
// 2. Kiểm tra nó có đối xứng không
// 3. In ra true hoặc false

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

// hàm kiểm tra số đối xứng
bool KiemTra_SDX(int thamSo){
    bool khoi_tao = false;
    string str = "";
    string item = "";
    int clone = thamSo; // lưu vào để dùng

    while (thamSo != 0)
    {
        item = to_string(thamSo % 10);
        str = str + item;
        thamSo = thamSo / 10; // bớt đi 1 số ở đuôi
    }
    
    int soDaoNguoc = stoi(str); // đây là số đảo ngược

    if(clone - soDaoNguoc == 0){
        khoi_tao = true;
    }else{
        khoi_tao = false;
    }

    return khoi_tao;
}

int main(){
    int n;
    cin >> n;

    cout << boolalpha << KiemTra_SDX(n) << endl;    
    return 0;
}