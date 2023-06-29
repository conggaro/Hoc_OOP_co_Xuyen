// Yêu cầu:
// 1. tạo lớp DIEM
// 2. phân quyền truy/xuất cho các thành phần

// 3. thử nghiệm việc gọi các thành phần của lớp
// để kiểm chứng mức độ che giấu thông tin

#include <iostream>
using namespace std;

class DIEM{
    public:
        int id;                 // đối tượng có thể truy/xuất

    protected:
        string ten;             // đối tượng không thể truy/xuất

    private:
        bool gioi_tinh;         // đối tượng không thể truy/xuất
};

int main(){
    // tạo đối tượng
    DIEM dt;

    dt.id = 1;          // không bị báo lỗi

    // dt.ten;          --> sẽ bị báo lỗi

    // dt.gioi_tinh;    --> sẽ bị báo lỗi

    return 0;
}