// Yêu cầu:

// 1. tạo kiểu bản ghi
// để biểu diễn các vector
// trong hệ tọa độ trực chuẩn 2 chiều

// 2. viết hàm tính độ dài của vector

// 3. viết hàm tính tổng, hiệu của hai vector

#include <iostream>
#include <cmath>
using namespace std;

// dùng để tạo biểu diễn mẫu vector
struct Bieu_Dien_Vector
{
    int bieu_dien_x;
    int bieu_dien_y;
};

// hàm tính độ dài vector
double TinhDoDai_Vector(Bieu_Dien_Vector thamSo){
    double ketQua;

    double tong = pow(thamSo.bieu_dien_x, 2) + pow(thamSo.bieu_dien_y, 2);

    ketQua = sqrt(tong);

    return ketQua;
}

// hàm cộng hai vector
Bieu_Dien_Vector Ham_Cong_2_Vector(Bieu_Dien_Vector thamSo1, Bieu_Dien_Vector thamSo2){
    Bieu_Dien_Vector  khoi_tao;

    khoi_tao.bieu_dien_x = thamSo1.bieu_dien_x + thamSo2.bieu_dien_x;
    khoi_tao.bieu_dien_y = thamSo1.bieu_dien_y + thamSo2.bieu_dien_y;

    return khoi_tao;
}

// hàm trừ hai vector
Bieu_Dien_Vector Ham_Tru_2_Vector(Bieu_Dien_Vector thamSo1, Bieu_Dien_Vector thamSo2){
    Bieu_Dien_Vector  khoi_tao;

    khoi_tao.bieu_dien_x = thamSo1.bieu_dien_x - thamSo2.bieu_dien_x;
    khoi_tao.bieu_dien_y = thamSo1.bieu_dien_y - thamSo2.bieu_dien_y;

    return khoi_tao;
}

int main(){
    // tạo 1 cái vector, nó gọi là biểu diễn mẫu
    // vector là 1 đoạn thẳng có hướng
    // cho (2, 3) thì cái số 2 và 3 cũng chỉ là để biểu diễn hướng
    Bieu_Dien_Vector vector_AB;
    vector_AB.bieu_dien_x = 3;
    vector_AB.bieu_dien_y = 4;

    // tạo vector đơn vị i
    Bieu_Dien_Vector i;
    i.bieu_dien_x = 1;
    i.bieu_dien_y = 0;

    // tạo vector đơn vị j
    Bieu_Dien_Vector j;
    i.bieu_dien_x = 0;
    i.bieu_dien_y = 1;

    cout << "Do dai vector AB la: " << TinhDoDai_Vector(vector_AB) << endl;

    // tạo biểu diễn vector OM
    Bieu_Dien_Vector OM;
    OM.bieu_dien_x = 4;
    OM.bieu_dien_y = 4;

    // tạo biểu diễn vector ON
    Bieu_Dien_Vector ON;
    ON.bieu_dien_x = 3;
    ON.bieu_dien_y = 5;

    // gọi OP là biểu diễn vector khi cộng OM và ON
    Bieu_Dien_Vector OP;
    OP = Ham_Cong_2_Vector(OM, ON);

    cout << "Tong cua 2 vector OM va ON la: OP(" << OP.bieu_dien_x;
    cout << ", " << OP.bieu_dien_y << ")." << endl;

    // gọi OQ là biểu diễn vector khi cộng OM và ON
    Bieu_Dien_Vector OQ;
    OQ = Ham_Tru_2_Vector(OM, ON);

    cout << "Hieu cua 2 vector OM va ON la: OQ(" << OQ.bieu_dien_x;
    cout << ", " << OQ.bieu_dien_y << ")." << endl;

    return 0;
}