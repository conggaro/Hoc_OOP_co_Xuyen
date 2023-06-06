// Yêu cầu:
// 1. nhập từ bàn phím số nguyên N (N > 0)
// 2. nhập các phần tử arr[0] đến arr[n-1]
// 3. đếm số âm
// 4. đếm số dương

#include <iostream>
#define SIZE 1000
using namespace std;

// hàm kiểm tra số dương
bool KiemTra_SoDuong_SoAm(int thamSo){
    bool khoi_tao;

    if(thamSo > 0){
        khoi_tao = true;
    }else if(thamSo < 0){
        khoi_tao = false;
    }

    return khoi_tao;
}

int main(){
    int n;
    cin >> n;

    int arr[SIZE];

    int dem_soDuong = 0;
    int dem_soAm = 0;

    for(int i = 0; i < n; i++){
        cin >> arr[i];
        if(KiemTra_SoDuong_SoAm(arr[i]) == true){
            dem_soDuong ++;
        }else{
            dem_soAm ++;
        }
    }

    cout << dem_soDuong << " " << dem_soAm << endl;

    return 0;
}