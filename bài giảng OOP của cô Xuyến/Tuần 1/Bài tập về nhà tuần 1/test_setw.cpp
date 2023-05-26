#include <iostream>
#include <iomanip>
using namespace std;

int main(){
    // cout << setw(-9); --> không thể truyền số âm
    cout << 1;
    cout << setw(9);
    cout << 98765432 << endl;

    cout << 123456789 << endl;
    return 0;
}

// cách này không dùng được vì setw() nó chỉ nhận số dương