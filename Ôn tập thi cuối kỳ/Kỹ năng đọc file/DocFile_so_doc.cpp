// Yêu cầu:
// 1. đọc file
// 2. in ra màn hình console

#include <iostream>
#include <fstream>
#define SIZE 100
using namespace std;

int main(){
    // tạo mảng để hứng dữ liệu
    int arr[SIZE];

    // tạo biến đếm phần tử
    int dem = 0;

    // tạo đối tượng đọc file
    ifstream file_in;
    file_in.open("so_doc.inp", ios::in);

    if (file_in.fail() == true)
    {
        cout << "Mo file so_doc.inp that bai\n\n";
    }
    else if (file_in.fail() == false)
    {
        cout << "Mo file so_doc.inp thanh cong\n\n";

        // tạo biến index
        int index = 0;

        // ghi dữ liệu vào mảng
        while (file_in.eof() == false)
        {
            if (file_in.eof() == true)
            {
                break;
            }
            
            file_in >> arr[index];

            index ++;

            dem ++;
        }

        file_in.close();
    }
    
    // in ra màn hình console
    for (int i = 0; i < dem; i++)
    {
        cout << arr[i] << " ";
    }
    
    cout << "\n\n";

    return 0;
}