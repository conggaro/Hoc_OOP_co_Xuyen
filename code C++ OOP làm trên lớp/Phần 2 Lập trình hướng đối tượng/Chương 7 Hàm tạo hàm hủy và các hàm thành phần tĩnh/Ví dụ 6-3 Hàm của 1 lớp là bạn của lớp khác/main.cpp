// ví dụ hàm của 1 lớp
// là bạn của lớp khác

#include <iostream>
using namespace std;

class A;

class B{
    private:
        int x;

    public:
        // hàm khởi tạo có tham số
        B(int data){
            x = data;
        }

        int Cong(int, A);
};

class A{
    private:
        int y;

    public:
        // hàm khởi tạo có tham số
        A(int data){
            y = data;
        }

        friend int B::Cong(int, A);
};

int B::Cong(int h, A dt){
    return h * (x + dt.y);
}

int main(){
    // tạo đối tượng
    A dt1 = A(10);
    B dt2 = B(10);

    // kết quả
    cout << "Ket qua: " << dt2.Cong(2, dt1) << "\n\n";

    return 0;
}