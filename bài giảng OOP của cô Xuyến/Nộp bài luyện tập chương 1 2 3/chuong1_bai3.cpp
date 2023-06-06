// Yêu cầu:
// 1. nhập vào 3 cạnh của 1 tam giác
// 2. tính chu vi tam giác

#include <iostream>
using namespace std;

// hàm kiểm tra tam giác
bool KiemTra(int canh_a, int canh_b, int canh_c){
    bool ketQua;

    bool kiemTra1 = (canh_a + canh_b) > canh_c ? true : false;
    bool kiemTra2 = (canh_a + canh_c) > canh_b ? true : false;
    bool kiemTra3 = (canh_b + canh_c) > canh_a ? true : false;

    if (kiemTra1 && kiemTra2 && kiemTra3)
    {
        ketQua = true;
    }else{
        ketQua = false;
    }

    return ketQua;
}

int main(){
    cout << "nhap vao 3 canh cua 1 tam giac: " << endl;
    int a, b, c;
    cin >> a >> b >> c;

    while (a <= 0 || b <=0 || c <=0)
    {
        cout << "nhap lai 3 canh cua 1 tam giac: " << endl;
        cin >> a >> b >> c;
    }
    
    if(KiemTra(a, b, c) == true){
        cout << "Chu vi tam giac la: " << a + b+ c << endl;
    }else{
        cout << "a, b, c khong phai 3 canh cua 1 tam giac." << endl;
    }

    return 0;
}