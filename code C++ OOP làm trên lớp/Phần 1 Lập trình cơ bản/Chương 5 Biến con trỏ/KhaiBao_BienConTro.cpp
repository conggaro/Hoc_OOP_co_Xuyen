// Yêu cầu:
// 1. khai báo biến con trỏ

// cú pháp:
// thêm ký tự "*" vào trước tên biến

// có thể khai báo kiểu con trỏ cho mọi loại dữ liệu

// khởi tạo biến con trỏ
// thì gán về 0 hoặc NULL

#include <iostream>
using namespace std;

struct ConNguoi
{
    int id;
    string ten;
};

int main(){
    // con trỏ kiểu nguyên
    int *pointer1 = 0;

    // con trỏ kiểu số thực
    double *pointer2 = 0;

    // con trỏ kiểu chuỗi
    string *pointer3 = NULL;

    // con trỏ kiểu short
    short *pointer4 = 0;

    // con trỏ kiểu long
    long *pointer5 = NULL;

    // con trỏ kiểu char
    char *pointer6 = 0;

    // con trỏ kiểu bool
    bool *pointer7 = 0;

    // con trỏ kiểu void
    void *pointer8 = 0;

    // con trỏ kiểu float
    float *pointer9 = 0;

    // con trỏ kiểu bản ghi struct
    ConNguoi *pointer10 = 0;

    return 0;
}