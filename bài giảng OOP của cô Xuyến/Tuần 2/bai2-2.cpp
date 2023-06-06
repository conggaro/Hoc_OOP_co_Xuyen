// Yêu cầu:
// 1. nhập vào số nguyên dương M nhỏ hơn 2 tỷ 
// (nên chọn int vì int cỡ 2,1 tỷ)

// 2. M có bao nhiêu chữ số
// 3. M có phải số chính phương không?
// 4. M có phải số nguyên tố không?
// 5. M có phải số đối xứng không?

#include <iostream>
#include <cmath>
#include <string>
using namespace std;

// hàm đếm chữ số của M
int Dem_Chu_So(int thamSo){
    int dem = 0;
    int clone = thamSo; // tạo 1 cái clone vì tý nữa sẽ cắt số thật

    while (clone != 0)
    {
        dem = dem + 1;
        clone = clone / 10;
    }
    
    return dem;
}

// hàm kiểm tra số chính phương
bool KiemTra_SCP(int thamSo){
    bool khoi_tao = false;

    int kiemTra = sqrt(thamSo);

    if(pow(kiemTra, 2) == thamSo){
        khoi_tao = true;
    }else{
        khoi_tao = false;
    }

    return khoi_tao;
}

// hàm kiểm tra số nguyên tố
bool KiemTra_SNT(int thamSo){
    bool khoi_tao = false;
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

// hàm kiểm tra số đối xứng
bool KiemTra_SDX(int thamSo){
    bool khoi_tao = false;
    int clone = thamSo;
    string str = "";
    string item = "";

    while (clone != 0)
    {
        item = to_string(clone % 10);
        str = str + item;
        clone = clone / 10;
    }
    
    int soDaoNguoc = stoi(str);

    if (thamSo - soDaoNguoc == 0)
    {
        khoi_tao = true;
    }else{
        khoi_tao = false;
    }
    

    return khoi_tao;
}

int main(){
    cout << "Nhap vao so nguyen duong M nho hon 2 ty: ";
    int M;
    cin >> M;

    while (M <= 0 || M >= 2000000000)
    {
        cout << "Hay nhap lai: ";
        cin >> M;
    }
    
    // M có bao nhiêu chữ số
    cout << "M co " << Dem_Chu_So(M) << " chu so." << endl;

    // M có phải số chính phương không
    if(KiemTra_SCP(M) == true){
        cout << "M la so chinh phuong." << endl;
    }else{
        cout << "M khong phai so chinh phuong." << endl;
    }

    // M có phải số nguyên tố không
    if(KiemTra_SNT(M) == true){
        cout << "M la so nguyen to." << endl;
    }else{
        cout << "M khong phai so nguyen to." << endl;
    }

    // M có phải số đối xứng
    if(KiemTra_SDX(M) == true){
        cout << "M la so doi xung." << endl;
    }else{
        cout << "M khong phai so doi xung." << endl;
    }

    return 0;
}