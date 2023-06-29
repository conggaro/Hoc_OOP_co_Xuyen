#include <iostream>
using namespace std;

// tạo lớp DIEM
class DIEM{
    public:
        int x;
        int y;

    public:
        // hàm khởi tạo có tham số
        DIEM(int data1, int data2){
            x = data1;
            y = data2;
        }

        void HienThi(){
            cout << "(" << x << ", " << y << ")\n";
        }

    private:
        // hàm bạn friend
        friend bool compare(DIEM dt1, DIEM dt2);
};

bool compare(DIEM dt1, DIEM dt2){
    bool ketQua;

    if (dt1.x == dt2.x && dt1.y == dt2.y)
    {
        ketQua = true;
    }
    else
    {
        ketQua = false;
    }    

    return ketQua;
}

int main(){
    // tạo đối tượng
    DIEM P(2, 3);
    DIEM Q(2, 3);

    // gọi hàm bạn
    if (compare(P, Q) == true)
    {
        cout << "Hai diem trung nhau\n\n";
    }
    else
    {
        cout << "Hai diem khac nhau\n\n";
    }

    return 0;
}