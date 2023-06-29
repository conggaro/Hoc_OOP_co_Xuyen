// ví dụ
// hàm bạn của nhiều lớp

#include <iostream>
using namespace std;

class B;

class A{
    private:
        int x;

    public:
        // hàm khởi tạo có tham số
        A(int data){
            x = data;
        }

        friend int Tinh_Tong(A dt1, B dt2);
};

class B{
    private:
        int y;

    public:
        // hàm khởi tạo có tham số
        B(int data){
            y = data;
        }

        friend int Tinh_Tong(A dt1, B dt2);
};

int Tinh_Tong(A dt1, B dt2){
    int tong = dt1.x + dt2.y;

    return tong;
}

int main(){
    // tạo đối tượng
    A dt1 = A(1);
    B dt2 = B(99);

    // gọi hàm tính tổng
    int tong = Tinh_Tong(dt1, dt2);
    cout << "Ket qua: " << tong << "\n\n";

    return 0;
}