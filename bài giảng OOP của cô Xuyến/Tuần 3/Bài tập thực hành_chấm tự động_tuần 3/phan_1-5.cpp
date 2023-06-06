// Yêu cầu:
// 1. nhập từ bàn phím số nguyên n
// 2. nhập dãy số a[0] đến a[n-1]
// 3. nhập dãy số b[0] đến b[n-1]
// 4. tính dãy số tổng (a + b)

#include <iostream>
#define SIZE 1000
using namespace std;

int main(){
    int n;
    cin >> n;

    int a[SIZE];
    int b[SIZE];

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }

    int c[SIZE];
    for (int i = 0; i < n; i++)
    {
        c[i] = a[i] + b[i];
        cout << c[i] << " ";
    }

    return 0;
}