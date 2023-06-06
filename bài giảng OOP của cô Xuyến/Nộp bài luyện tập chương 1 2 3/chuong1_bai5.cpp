// Yêu cầu:
// giải phương trình bậc 2
// ax^2 + bx + c = 0

// delta = b^2 - 4ac

// delta > 0 thì có 2 nghiệm phân biệt
// x1 = (-b + sqrt(delta)) / (2*a)
// x2 = (-b - sqrt(delta)) / (2*a)

// delta = 0 thì có 1 nghiệm
// x = -b / (2*a)

// delta < 0 thì vô nghiệm

#include <iostream>
#include <cmath>
using namespace std;

int main(){
    cout << "nhap a, b, c (a khac 0): " << endl;
    float a, b, c;
    cin >> a >> b >> c;

    while (a == 0)
    {
        cout << "nhap lai a, b, c (a khac 0): " << endl;
        cin >> a >> b >> c;
    }
    
    cout << "\nphuong trinh bac 2 la: ";
    cout << a <<"x^2 + " << b << "x + " << c <<" = 0\n";
    cout << endl;

    float delta = pow(b, 2) - 4*a*c;

    if(delta > 0){
        cout << "phuong trinh co 2 nghiem x1, x2." << endl;
        float x1 = (-b + sqrt(delta)) / (2*a);
        float x2 = (-b - sqrt(delta)) / (2*a);
        cout << "x1 = " << x1 << endl;
        cout << "x2 = " << x2 << endl;
    }else if(delta == 0){
        cout << "phuong trinh co 1 nghiem x." << endl;
        float x = -b / (2*a);
        cout << "x = " << x << endl;
    }else if(delta < 0){
        cout << "phuong trinh vo nghiem" << endl;
    }
    cout << endl;

    return 0;
}