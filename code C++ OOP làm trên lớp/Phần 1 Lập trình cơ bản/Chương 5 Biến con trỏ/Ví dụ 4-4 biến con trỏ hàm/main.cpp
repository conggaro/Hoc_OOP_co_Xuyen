// biến con trỏ hàm
// có thể truyền 1 hàm vào hàm khác như 1 tham số

// Ví dụ:
// int pheptoan(int x, int y, (*ham_phep_toan)(int, int));

#include <iostream>
using namespace std;

int phep_cong(int x, int y){
    return x + y;
}

int phep_tru(int x, int y){
    return x - y;
}

// khai báo hàm
// có sử dụng tham số là BIẾN CON TRỎ HÀM
int PhepToan(int bien1, int bien2,int (*bienConTroHam)(int, int)){
    int ketQua;

    ketQua = bienConTroHam(bien1, bien2);

    return ketQua;
}

int main(){
    // tạo BIẾN CON TRỎ HÀM
    // biến này trỏ đến hàm phép trừ
    int (*pointer)(int, int) = 0;

    pointer = phep_tru;

    int m = PhepToan(15, 20, &phep_cong);
    int n = PhepToan(40, 18, pointer);

    cout << "m = " << m << "\n";
    cout << "n = " << n << "\n\n";

    return 0;
}