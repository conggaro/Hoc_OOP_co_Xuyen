// Yêu cầu:
// 1. nhập vào 1 số nguyên n
// 2. kiểm tra số đó là chẵn hay lẻ

#include <iostream>
using namespace std;

int main(){
    cout << "nhap vao 1 so nguyen n: ";
    int n;
    cin >> n;

    if (n % 2 == 0)
    {
        cout << "n la so chan." << endl;        
    }else if (n % 2 != 0){
        cout << "n la so le." << endl;
    }
    
    return 0;
}