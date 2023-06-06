// Yêu cầu:
// 1. nhập số n từ bàn phím
// 2. nhập các phần tử a[0] đến a[n-1]
// 3. tính tổng các SỐ NGUYÊN TỐ có trong dãy

#include <iostream>
#define SIZE 1000
using namespace std;

// hàm kiểm tra số nguyên tố
// số 1 không phải số nguyên tố
bool KiemTra_SNT(int thamSo){
    bool khoi_tao;

    int dem = 0;

    for(int i = 1; i <= thamSo; i++){
        if(thamSo % i == 0){
            dem = dem + 1;
        }
    }

    if(dem == 2){
        khoi_tao = true;
    }else{
        khoi_tao = false;
    }

    return khoi_tao;
}

int main(){
    int n;
    cin >> n;

    int arr[SIZE];

    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    int khoi_tao = 0;

    for(int i = 0; i < n; i++){
        if(KiemTra_SNT(arr[i]) == true){
            khoi_tao = khoi_tao + arr[i];
        }        
    }

    cout << khoi_tao << endl;

    return 0;
}