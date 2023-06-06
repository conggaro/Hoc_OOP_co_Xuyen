// Yêu cầu:
// 1. nhập vào số nguyên dương n
// 2. nhập vào số nguyên dương x
// 3. viết chương trình tính tổng sau đây

// s1 = 1/(1*2) + 1/(2*3) + ... + 1/(n*(n+1))

// s2 = 1 + 1/(1+2) + 1/(1+2+3) + ... + 1/(1+2+3+...+n)

// s3 = x^2 + x^4 + ... + x^(2*n)

// s4 = x + x^3 + x^5 + ... + x^(2*n + 1)

// s5 = s1 + (2 * s2) + (3 * s3) + (4 * s4)

#include <iostream>
#include <cmath>
using namespace std;

// hàm tính tổng s1
// input: n
// output: s1 (kiểu float)
float TinhTong_s1(int thamSo){
    float s1 = 0;

    float item = 0;

    for (int i = 1; i <= thamSo; i++)
    {
        item = (float)1/(i * (i + 1));
        s1 = s1 + item;
    }

    return s1;
}

// hàm tính tổng s2
// input: n
// output: s2 (kiểu float)
float TinhTong_s2(int thamSo){
    float s2 = 0;

    float item = 0;

    int mauSo = 0;

    for (int i = 1; i <= thamSo; i++)
    {
        mauSo = mauSo + i;
        item = (float)1/mauSo;
        s2 = s2 + item;
    }

    return s2;
}

// hàm tính tổng s3
// input: n, x
// output: s3 (kiểu int)
int TinhTong_s3(int thamSo, int x_){
    int s3 = 0;

    for (int i = 1; i <= thamSo; i++)
    {
        s3 = s3 + pow(x_, 2*i);
    }

    return s3;
}

// hàm tính tổng s4
// input: n, x
// output: s4 (kiểu int)
int TinhTong_s4(int thamSo, int x_){
    int s4 = 0;

    for (int i = 0; i <= thamSo; i++)
    {
        s4 = s4 + pow(x_, 2*i + 1);
    }

    return s4;
}

// hàm tính tổng s5
// input: n, x
// output: s5 (kiểu float)
float TinhTong_s5(int thamSo, int x_){
    float s5 = 0;

    float bien1 = (float)TinhTong_s1(thamSo);
    float bien2 = (float)TinhTong_s2(thamSo);
    float bien3 = (float)TinhTong_s3(thamSo, x_);
    float bien4 = (float)TinhTong_s4(thamSo, x_);

    s5 = bien1 + 2*bien2 + 3*bien3 + 4*bien4;

    return s5;
}

int main(){
    cout << "nhap vao so nguyen duong n: ";
    int n;
    cin >> n;

    cout << "nhap vao so nguyen duong x: ";
    int x;
    cin >> x;

    cout << "\ntong s1 la: " << TinhTong_s1(n) << "\n";
    cout << "\ntong s2 la: " << TinhTong_s2(n) << "\n";
    cout << "\ntong s3 la: " << TinhTong_s3(n, x) << "\n";
    cout << "\ntong s4 la: " << TinhTong_s4(n, x) << "\n";
    cout << "\ntong s5 la: " << TinhTong_s5(n, x) << "\n\n";

    return 0;
}