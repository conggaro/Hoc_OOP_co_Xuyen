// Yêu cầu:
// 1. tạo mảng
// 2. sửa giá trị bên trong bằng random()
// 3. in ra màn hình

#include <iostream>
using namespace std;

int main(){
    int arr[10];

    // hàm khởi tạo bộ sinh số ngẫu nhiên
    srand(time(NULL));

    for(int i = 0; i < 10; i++){
        arr[i] = rand() % 10;
        cout << arr[i] << endl;
    }

    return 0;
}