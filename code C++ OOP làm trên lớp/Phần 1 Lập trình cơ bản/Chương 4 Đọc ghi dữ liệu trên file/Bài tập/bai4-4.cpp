// Mô tả:
// cho file dayso.txt
// mỗi dòng chứa 1 số nguyên dương

// Yêu cầu:
// 1. đếm số lượng số chẵn
// 2. in kết quả ra màn hình

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main(){
    // tạo đối tượng đọc file
    ifstream file_in;
    file_in.open("dayso.txt", ios::in);

    if (file_in.fail() == true)
    {
        cout << "Mo file THAT BAI\n";
    }
    else if (file_in.fail() == false)
    {
        cout << "Mo file THANH CONG\n";

        int data = 0;
        vector<int> v_SoChan(0);

        while (file_in.eof() == false)
        {
            // nếu đọc đến cuối file
            // thì break
            if (file_in.eof() == true)
            {
                break;
            }
            
            file_in >> data;

            if (data % 2 == 0)
            {
                v_SoChan.push_back(data);
            }
        }

        int dem = v_SoChan.size();

        cout << "\nCo: " << dem << " so chan.\n";

        for (int i = 0; i < v_SoChan.size(); i++)
        {
            cout << v_SoChan[i] << "  ";
        }   

        file_in.close();
    }

    cout << "\n\n";

    return 0;
}