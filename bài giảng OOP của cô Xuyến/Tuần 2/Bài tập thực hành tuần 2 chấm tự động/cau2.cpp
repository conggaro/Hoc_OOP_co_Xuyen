// Yêu cầu:
// 1. Nhập vào 1 số
// 2. Kiểm tra số nguyên tố
// 3. In ra true hoặc false

// số nguyên tố là cái loại chỉ chia hết cho nó hoặc cho 1
// thuật toán (nếu đếm = 2 thì là số nguyên tố)

#include <iostream>
#include <iomanip>
using namespace std;

// hàm kiểm tra số nguyên tố
bool KiemTra_SNT(int thamSo){
    bool khoi_tao = false;
    int dem = 0;

    for(int i = 1; i <= thamSo; i++){
        if(thamSo % i == 0){
            dem = dem + 1;
        }
    }

    khoi_tao = dem == 2 ? true : false;

    return khoi_tao;
}

int main(){
    int n;
    cin >> n;

    cout << boolalpha << KiemTra_SNT(n) << endl;
    return 0;
}