// Mô tả:

// cấu trúc file input
// chỉ gồm các chữ số và dấu cách

// Ở CUỐI FILE BẮT BUỘC KHÔNG CÓ DẤU CÁCH
// nếu có thì chương trình bị đếm sai cho mà xem

// cuối file nó phải trông như này "58 12" là đúng

// còn cuối file nó mà trông như này "58 12 " là sai

// cấu trúc file output
// dòng 1: đếm số lượng của các số khác nhau
// dòng 2: ghi ra dãy số chẵn đã được sắp xếp
// dòng 3: ghi ra dãy số lẻ đã được sắp xếp

#include <iostream>
#include <fstream>
#define SIZE 100
using namespace std;

// hàm xóa phần tử ở vị trí index
void Ham_XoaPhanTu(int arr[SIZE], int &n, int index){
    for (int i = index; i < n; i++)
    {
        arr[i] = arr[i + 1];
    }
    
    n = n - 1;
}

// hàm sắp xếp
// theo chiều tăng dần
void Ham_SapXep_TangDan(int arr[SIZE], int n){
    int temp = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] > arr[j])
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int main(){
    // tạo mảng để hứng dữ liệu
    int arr[SIZE];

    // tạo biến đếm
    // để đếm số đọc được
    int dem = 0;

    // tạo đối tượng đọc file
    ifstream file_in;
    file_in.open("songuyen.inp", ios::in);

    if (file_in.fail() == true)
    {
        cout << "Mo file songuyen.inp that bai\n\n";
    }
    else if (file_in.fail() == false)
    {
        cout << "Mo file songuyen.inp thanh cong\n\n";

        // tạo biến item để hứng dữ liệu
        int item = 0;

        // tạo biến index
        int index = 0;

        while (file_in.eof() == false)
        {
            if (file_in.eof() == true)
            {
                break;
            }
            
            file_in >> item;
            
            arr[index] = item;

            index ++;
            dem ++;
        }

        file_in.close();
    }

    // tạo đối tượng ghi file
    ofstream file_out;
    file_out.open("songuyen.out", ios::out);

    if (file_out.fail() == true)
    {
        cout << "Mo file songuyen.out that bai\n\n";
    }
    else if (file_out.fail() == false)
    {
        cout << "Mo file songuyen.out thanh cong\n\n";

        // gọi hàm sắp xếp tăng dần
        Ham_SapXep_TangDan(arr, dem);

        // xóa phần tử trùng nhau
        int index = 0;

        for (; index < dem;)
        {
            if (arr[index] == arr[index + 1])
            {
                // gọi hàm xóa phần tử
                Ham_XoaPhanTu(arr, dem, index);
            }
            else
            {
                index ++;
            }            
        }
        
        // ghi ra số lượng
        // của các số khác nhau
        file_out << dem << "\n";

        // ghi ra số chẵn
        for (int i = 0; i < dem; i++)
        {
            if (arr[i] % 2 == 0)
            {
                file_out << arr[i] << " ";
            }            
        }
        
        file_out << "\n";

        // ghi ra số lẻ
        for (int i = 0; i < dem; i++)
        {
            if (arr[i] % 2 != 0)
            {
                file_out << arr[i] << " ";
            }            
        }

        file_out.close();
    }

    return 0;
}