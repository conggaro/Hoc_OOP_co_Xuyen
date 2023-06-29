// cách khác để không phải dùng hàm bạn

#include <iostream>
using namespace std;

class A{
    private:
        int x;

    public:
        // hàm khởi tạo có tham số
        A(int data){
            x = data;
        }

        // hàm lấy x
        int get_x(){
            return x;
        }
};

class B{
    private:
        int y;

    public:
        // hàm khởi tạo có tham số
        B(int data){
            y = data;
        }

        // hàm lấy y
        int get_y(){
            return y;
        }
};

// hàm tính tổng
int Tinh_Tong(A dt1, B dt2){
    int tong = dt1.get_x() + dt2.get_y();

    return tong;
}

int main(){
    // tạo đối tượng
    A dt1 = A(1);
    B dt2 = B(2);

    // gọi hàm tính tổng
    int tong = Tinh_Tong(dt1, dt2);
    cout << "Ket qua: " << tong << "\n\n";

    return 0;
}