// Yêu cầu:
// 1. đọc file
// 2. ghi file

// 3. đếm số lượng
// số nguyên có trong file songuyen.inp

// 4. ghi số nhỏ thứ 2 tìm được
// không tìm thấy thì ghi -1

// 5. ghi các số chính phương tìm được
// hai số cách nhau ít nhất 1 dấu cách

// bài này thì tôi sử dụng biến con trỏ
// bạn có thể dùng mảng
// hoặc bạn có thể dùng vector

#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

// hàm kiểm tra số chính phương
// số chính phương là số có căn bậc 2 ra một số nguyên
bool KiemTra_SCP(int thamSo){
    bool ketQua;

    int kiemTra = sqrt(thamSo);

    if (pow(kiemTra, 2) == thamSo)
    {
        ketQua = true;
    }
    else{
        ketQua = false;
    }

    return ketQua;
}

int main(){
    // tạo đối tượng để đọc file
    ifstream file_in;
    file_in.open("songuyen.inp", ios::in);

    // tạo con trỏ để lưu dữ liệu
    // lưu cái dữ liệu đọc được ấy
    int *pointer;

    // xin cấp phát vùng nhớ cho con trỏ
    pointer = new int[50];

    // tạo index cho cái pointer
    int index = 0;

    // biến item để hứng từng cái dữ liệu đọc được
    int item = 0;

    // biến đếm
    // để đếm số lượng dữ liệu đọc được
    int dem = 0;

    if (file_in.fail() == true)
    {
        cout << "Mo file songuyen.inp THAT BAI\n\n";
    }
    else if (file_in.fail() == false)
    {
        cout << "Mo file songuyen.inp THANH CONG\n\n";

        while (file_in.eof() == false)
        {
            // nếu đọc đến cuối file
            // thì cho break
            if (file_in.eof() == true)
            {
                break;
            }
            
            file_in >> item;

            *(pointer + index) = item;
            index = index + 1;

            dem = dem + 1;
        }
        
        // xóa dữ liệu của index
        index = 0;

        file_in.close();
    }

    // tạo đối tượng để mở file 
    ofstream file_out;
    file_out.open("songuyen.out", ios::out);

    if (file_out.fail() == true)
    {
        cout << "Mo file songuyen.out THAT BAI\n\n";
    }
    else if (file_out.fail() == false)
    {
        cout << "Mo file songuyen.out THANH CONG\n\n";

        // cái đầu tiên ghi vào
        // là số lượng dữ liệu đọc được
        file_out << dem << "\n";

        int min = *(pointer + 0);

        // bây giờ thì tìm số nhỏ nhất
        for (int i = 0; i < dem; i++)
        {
            if (min > *(pointer + i))
            {
                min = *(pointer + i);
            }            
        }
        
        // tìm cái số nhỏ thứ 2
        int min_2 = *(pointer + 0);

        // đếm giá trị nhỏ thứ 2
        int dem2 = 0;

        for (int i = 0; i < dem; i++)
        {
            if (min != *(pointer + i))
            {
                if (min_2 > *(pointer + i))
                {
                    min_2 = *(pointer + i);
                    dem2 = dem2 + 1;
                }
            }
        }
        
        if (dem2 == 0)
        {
            file_out << -1;
        }
        else if (dem2 != 0)
        {
            file_out << min_2 << "\n";
        }
        
        // làm công việc
        // số chẵn thì nhân 2
        // số lẻ thì nhân 3
        for (int i = 0; i < dem; i++)
        {
            if (*(pointer + i) % 2 == 0)
            {
                *(pointer + i) = *(pointer + i) * 2;
            }
            else if (*(pointer + i) % 2 != 0)
            {
                *(pointer + i) = *(pointer + i) * 3;
            }        
        }

        // bây giờ thì tìm số chính phương
        for (int i = 0; i < dem; i++)
        {
            if (KiemTra_SCP(*(pointer + i)) == true)
            {
                file_out << *(pointer + i) << " ";
            }           
        }

        file_out.close();
    }
    
    // thu hồi vùng nhớ của con trỏ
    delete[] pointer;

    return 0;
}