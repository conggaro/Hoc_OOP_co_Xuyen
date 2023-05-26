// Yêu cầu:
// 1. Nhập cân nặng và chiều cao
// 2. Tính BMI và đưa ra kết luận.

// cân nặng --> ki-lô-gram
// chiều cao --> mét

#include <iostream>
#include <cmath>
using namespace std;

int main(){
    cout << "Nhap vao chieu cao va can nang: " << endl;
    double weight, height;
    cin >> weight >> height;

    // công thức BMI = w/(h*h)
    double BMI = weight / pow(height, 2);

    // hiển thị BMI
    cout << "BMI cua ban la: " << BMI << endl;

    // hiển thị sức khỏe
    if(BMI < 18.5){
        cout << "You are thinness." << endl;
    }else if(18.5 <= BMI && BMI < 25){
        cout << "You are normal." << endl;
    }else if(25 <= BMI && BMI < 30){
        cout << "You are overweight." << endl;
    }else if(30 <= BMI && BMI < 35){
        cout << "You are obese 1." << endl;
    }else if(35 <= BMI && BMI < 40){
        cout << "You are obese 2." << endl;
    }else if(40 <= BMI){
        cout << "You are obese 3." << endl;
    }
}