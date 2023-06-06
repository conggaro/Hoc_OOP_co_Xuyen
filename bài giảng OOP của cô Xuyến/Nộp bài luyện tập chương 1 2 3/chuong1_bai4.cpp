// Yêu cầu:
// 1. nhập vào điểm toán
// 2. nhập vào điểm lý
// 3. nhập vào điểm hóa

// 4. tính điểm trung bình

// 5.   diem_TB >= 8 (giỏi)
//      diem_TB >=7 && diem_TB < 8 (khá)
//      diem_TB >=5 && diem_TB < 7 (trung bình)
//      diem_TB < 5 (yếu)

#include <iostream>
#include <iomanip>
using namespace std;

int main(){
    cout << "nhap diem toan, ly, hoa: " << endl;
    int toan, ly, hoa;
    cin >> toan >> ly >> hoa;

    int tong = toan + ly + hoa;

    float diem_TB = (float)tong / 3;

    cout << fixed << setprecision(1);
    if(diem_TB >= 8){
        cout << diem_TB <<" => loai gioi";
    }else if(diem_TB >=7 && diem_TB < 8){
        cout << diem_TB <<" => loai kha";
    }else if(diem_TB >=5 && diem_TB < 7){
        cout << diem_TB <<" => loai trung binh";
    }else if(diem_TB < 5){
        cout << diem_TB <<" => loai yeu";
    }

    cout << endl;

    return 0;
}