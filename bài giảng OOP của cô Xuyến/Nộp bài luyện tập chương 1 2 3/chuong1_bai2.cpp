// Yêu cầu:
// 1. nhập vào 1 số nguyên a
// 2. nhập vào 1 số nguyên b
// 3. nhập vào 1 số nguyên c

// tìm số lớn nhất

#include <iostream>
using namespace std;

int main(){
    cout << "nhap vao 3 so a, b, c: " << endl;
    int a, b, c;
    cin >> a >> b >> c;

    int max = a;

    if (max < b)
    {
        max = b;
    }
    
    if(max < c){
        max = c;
    }
    
    cout << "so lon nhat la: " << max << endl;

    return 0;
}