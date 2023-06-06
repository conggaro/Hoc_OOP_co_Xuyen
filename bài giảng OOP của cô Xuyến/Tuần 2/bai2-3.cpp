// Yêu cầu:
// sử dụng nguyên lý nạp chồng để giải quyết các yêu cầu sau:

// 1. hàm trả về giá trị tuyệt đối của 1 số nguyên, 1 số thực
// 2. hàm trả về giá trị lớn nhất của 3 số nguyên, 3 số thực
// 3. hàm trả về giá trị nhỏ nhất của 3 số nguyên, 3 số thực
// 4. hàm tính trung bình cộng của 3 số nguyên, 3 số thực

#include <iostream>
#include <string>
using namespace std;

// hàm trả về giá trị tuyệt đối của 1 số nguyên
void GiaTriTuyetDoi(int thamSo){
    // số 0 là số nguyên
    // nhưng số 0 không phải số nguyên âm
    // số 0 cũng không phải số nguyên dương

    if(thamSo >= 0){
        cout << "Gia tri tuyet doi cua " << thamSo << " la: " << thamSo;
        cout << endl;
    }else{
        int gia_tri = thamSo*(-1);
        cout << "Gia tri tuyet doi cua " << thamSo << " la: " << gia_tri;
        cout << endl;
    }
}

// hàm trả về giá trị tuyệt đối của 1 số thực
void GiaTriTuyetDoi(double thamSo){
     if(thamSo >= 0){
        cout << "Gia tri tuyet doi cua " << thamSo << " la: " << thamSo;
        cout << endl;
    }else{
        double gia_tri = thamSo*(-1);
        cout << "Gia tri tuyet doi cua " << thamSo << " la: " << gia_tri;
        cout << endl;
    }
}

// hàm trả về giá trị lớn nhất của 3 số nguyên
void Tim_Max(int so_1, int so_2, int so_3){
    int max = 0;
    int arr[3] = {so_1, so_2, so_3};
    int length = sizeof(arr) / sizeof(int);
    int temp = 0;

    for(int i = 0; i < length; i++){
        for(int j = i + 1; j < length; j++){
            if(arr[i] < arr[j]){
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    
    max = arr[0];

    cout << "Max(" << so_1 << ", " << so_2 << ", " << so_3 << ") = " << max;
    cout << endl;
}

// hàm trả về giá trị lớn nhất của 3 số thực
void Tim_Max(double so_1, double so_2, double so_3){
    double max = 0;
    double arr[3] = {so_1, so_2, so_3};
    int length = sizeof(arr) / sizeof(double);
    double temp = 0;

    for(int i = 0; i < length; i++){
        for(int j = i + 1; j < length; j++){
            if(arr[i] < arr[j]){
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    
    max = arr[0];

    cout << "Max(" << so_1 << ", " << so_2 << ", " << so_3 << ") = " << max;
    cout << endl;
}

// hàm trả về giá trị nhỏ nhất của 3 số nguyên
void Tim_Min(int so_1, int so_2, int so_3){
    int min = 0;
    int arr[3] = {so_1, so_2, so_3};
    int length = sizeof(arr) / sizeof(int);
    int temp = 0;

    for(int i = 0; i < length; i++){
        for(int j = i + 1; j < length; j++){
            if(arr[i] < arr[j]){
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    
    min = arr[length - 1];

    cout << "Min(" << so_1 << ", " << so_2 << ", " << so_3 << ") = " << min;
    cout << endl;
}

// hàm trả về giá trị nhỏ nhất của 3 số thực
void Tim_Min(double so_1, double so_2, double so_3){
    double min = 0;
    double arr[3] = {so_1, so_2, so_3};
    int length = sizeof(arr) / sizeof(double);
    double temp = 0;

    for(int i = 0; i < length; i++){
        for(int j = i + 1; j < length; j++){
            if(arr[i] < arr[j]){
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    
    min = arr[length - 1];

    cout << "Min(" << so_1 << ", " << so_2 << ", " << so_3 << ") = " << min;
    cout << endl;
}

// hàm tính trung bình cộng của 3 số nguyên
void TinhTrungBinhCong(int so_1, int so_2, int so_3){
    double TBC = (double)(so_1 + so_2 + so_3) / 3;
    
    cout << "TBC(" << so_1 << ", " << so_2 << ", " << so_3 << ") = " << TBC;
    cout << endl;
}

// hàm tính trung bình cộng của 3 số thực
void TinhTrungBinhCong(double so_1, double so_2, double so_3){
    double TBC = (so_1 + so_2 + so_3) / 3;
    
    cout << "TBC(" << so_1 << ", " << so_2 << ", " << so_3 << ") = " << TBC;
    cout << endl;
}

int main(){
    cout << "Nhap vao 1 so nguyen: ";
    int n;
    cin >> n;

    cout << "Nhap vao 1 so thuc: ";
    double m;
    cin >> m;

    GiaTriTuyetDoi(n);
    GiaTriTuyetDoi(m);

    cout << "\nNhap vao 3 so nguyen:" << endl;
    int a, b, c;
    cin >> a >> b >> c;

    cout << "Nhap vao 3 so thuc:" << endl;
    double x, y, z;
    cin >> x >> y >> z;

    cout << endl;
    Tim_Max(a, b, c);
    Tim_Max(x, y, z);

    cout << endl;
    Tim_Min(a, b, c);
    Tim_Min(x, y, z);

    cout << endl;
    TinhTrungBinhCong(a, b, c);
    TinhTrungBinhCong(x, y, z);
    return 0;
}