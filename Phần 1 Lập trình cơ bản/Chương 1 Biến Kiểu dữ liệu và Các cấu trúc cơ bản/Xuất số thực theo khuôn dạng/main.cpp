// Yêu cầu:
// cho số 12,345678
// hiển thị ra 12,35 (làm tròn đến số thập phân thứ 2)

#include <iostream>
#include <iomanip>
using namespace std;

int main(){
    double x = 12.345678;

    cout << fixed << setprecision(2);
    cout << x; // 12,35

    return 0;
}