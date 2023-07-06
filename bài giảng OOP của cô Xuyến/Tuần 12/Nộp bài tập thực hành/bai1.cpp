// Mô tả:
// Cấu trúc file input
// Dòng đầu ghi số N
// N dòng tiếp theo, mỗi dòng ghi một xâu kí tự

// Cấu trúc file output
// ghi số từ đếm được

// Yêu cầu:
// 1. đọc file
// 2. đếm từ
// 3. ghi file

// Định nghĩa từ:
// được bắt đầu bằng chữ cái
// và không chứa dấu cách

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// hàm đếm từ
int Ham_DemTu(string str){
    int dem = 0;

    bool kt = str[0] != ' ' ? true : false;
    bool kt0 = str[0] != '0' ? true : false;
    bool kt1 = str[0] != '1' ? true : false;
    bool kt2 = str[0] != '2' ? true : false;
    bool kt3 = str[0] != '3' ? true : false;
    bool kt4 = str[0] != '4' ? true : false;
    bool kt5 = str[0] != '5' ? true : false;
    bool kt6 = str[0] != '6' ? true : false;
    bool kt7 = str[0] != '7' ? true : false;
    bool kt8 = str[0] != '8' ? true : false;
    bool kt9 = str[0] != '9' ? true : false;

    if (kt && kt0 && kt1 && kt2 && kt3 && kt4 && kt5 && kt6 && kt7 && kt8 && kt9)
    {
        dem = 1;
    }

    // giải thuật để đếm từ (algorithms)
    // nếu str[i] == ' ' và str[i + 1] != ' '
    // thì đấy là 1 từ
    
    // trong bài này
    // thì cái ký tự đầu tiên của 1 từ
    // nó sẽ không được chứa số 0,1,2,...,9
    for (int i = 0; i <= str.length() - 2; i++)
    {
        if (str[i] == ' ' && str[i + 1] != ' ')
        {
            bool kiemTra1 = 'a' <= str[i + 1] && str[i + 1] <= 'z' ? true : false;
            bool kiemTra2 = 'A' <= str[i + 1] && str[i + 1] <= 'Z' ? true : false;

            if (kiemTra1 == true || kiemTra2 == true)
            {
                dem ++;
            }
        }
    }

    return dem;
}

int main(){
    // tạo biến khoi_tao
    // để hứng dữ liệu
    string khoi_tao = "";

    // tạo n
    int n = 0;

    // tạo đối tượng đọc file
    ifstream file_in;
    file_in.open("demtu.inp", ios::in);

    if (file_in.fail() == true)
    {
        cout << "Mo file demtu.inp that bai\n\n";
    }
    else if (file_in.fail() == false)
    {
        cout << "Mo file demtu.inp thanh cong\n\n";

        // ghi dữ liệu vào n
        file_in >> n;
        file_in.ignore();

        // ghi dữ liệu vào khoi_tao
        string item = "";
        
        for (int i = 0; i < n; i++)
        {
            getline(file_in, item, '\n');

            khoi_tao = khoi_tao + item + " ";
        }

        file_in.close();
    }

    // tạo đối tượng ghi file
    ofstream file_out;
    file_out.open("demtu.out", ios::out);

    if (file_out.fail() == true)
    {
        cout << "Mo file demtu.out that bai\n\n";
    }
    else if (file_in.fail() == false)
    {
        cout << "Mo file demtu.out thanh cong\n\n";

        // gọi hàm đếm từ
        int dem = 0;
        dem = Ham_DemTu(khoi_tao);

        // ghi dữ liệu ra file
        file_out << dem;

        file_out.close();
    }
    
    return 0;
}