// Yêu cầu:
// 1. tạo lớp VECTOR

// 2. thuộc tính
// n là số lượng phần tử của vector
// *v chứa các giá trị thành phần của vector

// 3. phương thức
// hàm tạo
// hàm tạo sao chép
// hàm nhập dữ liệu
// hàm tìm phần tử max của vector
// hàm hiển thị vector

#include <iostream>
using namespace std;

class VECTOR{
    public:
        int n;              // n là số lượng phần tử của vector
        float *v;           // v sẽ được cấp phát vùng nhớ ở các dòng code bên dưới

    public:
        // hàm khởi tạo không tham số
        VECTOR(){
            n = 0;
            v = NULL;
        }

        // hàm khởi tạo có 1 tham số
        VECTOR(int data){
            n = data;
            for (int i = 0; i < n; i++)
            {
                *(v + i) = 0;
            }            
        }

        // hàm khởi tạo có 2 tham số
        VECTOR(int data1, float *v_data2){
            n = data1;

            // cấp phát vùng nhớ cho v
            v = new float[n];

            for (int i = 0; i < n; i++)
            {
                *(v + i) = *(v_data2 + i);
            }            
        }

        // hàm hủy
        ~VECTOR(){
            cout << "Huy doi tuong\n";
        }

        // hàm sao chép
        VECTOR(VECTOR &dt){
            n = dt.n;

            // cấp phát vùng nhớ
            v = new float[n];

            for (int i = 0; i < n; i++)
            {
                *(v + i) = *(dt.v + i);
            }            
        }

        // hàm nhập dữ liệu
        void NhapDuLieu(int data1, float *v_data2){
            n = data1;

            // cấp phát vùng nhớ
            v = new float[n];

            for (int i = 0; i < n; i++)
            {
                *(v + i) = *(v_data2 + i);
            }            
        }

        // hàm tìm giá trị max của vector
        float Tim_Max(){
            float max = *(v + 0);

            for (int i = 0; i < n; i++)
            {
                if (max < *(v + i))
                {
                    max = *(v + i);
                }                
            }            

            return max;
        }

        // hàm hiển thị
        void HienThi(){
            for (int i = 0; i < n; i++)
            {
                cout << "vector[" << i << "] = " << *(v + i) << "\n";
            }            
        }
};

int main(){
    int n = 10;

    // tạo biến con trỏ pointer
    // để chút nữa ném pointer vào trong dt1
    float *pointer;
    pointer = new float[n];

    for (int i = 0; i < n; i++)
    {
        *(pointer + i) = i * 2;
    }

    // tạo đối tượng dt1
    VECTOR dt1 = VECTOR(n, pointer);
    cout << "Doi tuong dt1:\n";
    dt1.HienThi();

    // tạo đối tượng dt2
    VECTOR dt2;
    dt2 = VECTOR(dt1);
    cout << "\nDoi tuong dt2:\n";
    dt2.HienThi();

    // gọi phương thức tìm max
    cout << "\nmax = " << dt2.Tim_Max() << "\n";

    return 0;
}