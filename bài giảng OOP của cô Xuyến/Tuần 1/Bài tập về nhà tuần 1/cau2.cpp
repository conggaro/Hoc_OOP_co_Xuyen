// Yêu cầu:
// 1. Nhập vào 1 số từ bàn phím
// 2. Vẽ ngôi sao

	
// * 1
// *** 3
// ***** 5
// ******* 7
// ********* 9
// *******
// *****
// ***
// *

#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n; // 5

    string khoi_tao = "";

    for(int i = 0; i <= n - 1; i++){
        for(int j = 1; j <= (i*2 + 1); j++){
            khoi_tao = khoi_tao + "*";
        }
        cout << khoi_tao << endl;
        khoi_tao = "";
    }

    for(int i = n - 2; i >= 0; i--){
        for(int j = (i*2 + 1); j >= 1; j--){
            khoi_tao = khoi_tao + "*";
        }
        cout << khoi_tao << endl;
        khoi_tao = "";
    }
    return 0;
}