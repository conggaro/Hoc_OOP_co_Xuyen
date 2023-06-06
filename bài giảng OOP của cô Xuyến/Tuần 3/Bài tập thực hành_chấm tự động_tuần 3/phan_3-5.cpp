// Yêu cầu:
// 1. nhập vào số nguyên n (n > 0)
// 2. nhập vào số x
// 3. nhập vào n phần tử (phần tử thuộc Z)

// đếm chữ số trong dãy bằng x

#include <iostream>
#define SIZE 500
using namespace std;

// hàm đếm
// input: mảng, n, x
// output: đếm thành công
int Dem(int mang[SIZE], int n, int x){
    int dem = 0;

    for (int i = 0; i < n; i++)
    {
        if (x == mang[i])
        {
            dem ++;
        }        
    }

    return dem;
}

int main(){
    int n;
    cin >> n;

    int x;
    cin >> x;

    int v1[SIZE];

    for (int i = 0; i < n; i++)
    {
        cin >> v1[i];
    }
    
    cout << Dem(v1, n, x) << endl;

    return 0;
}