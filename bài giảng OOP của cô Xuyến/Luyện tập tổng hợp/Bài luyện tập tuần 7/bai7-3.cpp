// Mô tả
// một người dân mua n cây xanh

// cây xanh index có chiều cao là arr[index] 
// (0 <= index <= n)

// người ta muốn trồng cây theo chiều cao
// chiều không giảm (tức là chiều tăng dần)

// FILE INPUT
// dòng 1 là số n
// dòng 2 là chiều cao của từng cây

// FILE OUTPUT
// dòng 1       --> ghi chỉ số của các cây
// dòng 2       --> ghi chiều cao tương ứng

#include <iostream>
#include <fstream>
#define SIZE 100
using namespace std;

// tạo kiểu bản ghi cái cây
struct CaiCay
{
    int stt;
    float chieu_cao;
};

int main(){
    // tạo mảng lưu dữ liệu
    CaiCay arr[SIZE];

    // tạo n
    int n = 0;

    // tạo đối tượng đọc file
    ifstream file_in;
    file_in.open("TREE.INP", ios::in);

    if (file_in.fail() == true)
    {
        cout << "Mo file TREE.INP THAT BAI\n\n";
    }
    else if (file_in.fail() == false)
    {
        cout << "Mo file TREE.INP THANH CONG\n\n";

        // ghi vào biến n
        file_in >> n;

        for (int i = 0; i < n; i++)
        {
            arr[i].stt = i + 1;
            file_in >> arr[i].chieu_cao;
        }      

        file_in.close();
    }

    // tạo đối tượng ghi file
    ofstream file_out;
    file_out.open("TREE.OUT", ios::out);

    if (file_out.fail() == true)
    {
        cout << "Mo file TREE.OUT THAT BAI\n\n";
    }
    else if (file_out.fail() == false)
    {
        cout << "Mo file TREE.OUT THANH CONG\n\n";

        // tạo temp
        CaiCay temp;

        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (arr[i].chieu_cao > arr[j].chieu_cao)
                {
                    temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;
                }
            }                        
        }
        
        for (int i = 0; i < n; i++)
        {
            file_out << arr[i].stt << " ";
        }
        file_out << "\n";

        for (int i = 0; i < n; i++)
        {
            file_out << arr[i].chieu_cao << " ";
        }

        file_out.close();
    }

    return 0;
}