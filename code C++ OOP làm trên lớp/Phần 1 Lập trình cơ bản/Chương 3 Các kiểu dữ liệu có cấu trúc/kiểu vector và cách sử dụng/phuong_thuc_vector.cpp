#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<int> v1;
    vector<string> v2(5);
    v2 = {"A", "B", "C", "D", "E"};

    // .empty() để kiểm tra rỗng
    string ketQua = v1.empty() == true ? "v1 bi rong." : "v1 co phan tu";
    cout << ketQua << endl;

    // .size() để trả về độ dài vector
    cout << "vector v2 co do dai la: " << v2.size() << endl;

    // .at(i) để trả về phần tử thứ "i" của vector
    cout << "phan tu i = 2 cua v2 la: ";
    cout << v2.at(2) << endl;

    // .push_back() để thêm phần tử cho vector
    cout << "vector v2 ban dau la: ";
    for(int i = 0; i < v2.size(); i++){
        cout << v2[i] << "  ";
    }
    cout << endl;

    v2.push_back("F");
    cout << "vector v2 sau khi them phan tu la: ";
    for(int i = 0; i < v2.size(); i++){
        cout << v2[i] << "  ";
    }
    cout << endl;

    // .pop_back() để loại bỏ phần tử ở cuối vector
    vector<int> v3(4);
    v3 = {1, 2, 3, 4};
    v3.pop_back();
    cout << "vector v3 sau khi xoa phan tu la: ";
    for(int i = 0; i < v3.size(); i++){
        cout << v3[i] << "  ";
    }
    cout << endl;

    // .resize(n) để thay đổi kích thước vector
    vector<float> v4(5);
    cout << "kich thuoc cua v4 ban dau la: " << v4.size() << endl;
    v4.resize(40);
    cout << "kich thuoc cua v4 sau khi thay doi la: " << v4.size() << endl;

    return 0;
}