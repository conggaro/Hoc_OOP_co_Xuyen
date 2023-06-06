// Yêu cầu:
// 1. nhập số nguyên n
// 2. nhập n phần tử
// 3. in ra phần tử vừa nhập

// 4. tính tổng các số nguyên dương của dãy số

// 5. in ra vị trí các phần tử có giá trị nhỏ nhất

// 6. in ra màn hình các số nguyên khác nhau

#include <iostream>
#include <vector>
using namespace std;

// hàm in ra vị trí các phần tử nhỏ nhất
// chắc là có ít nhất 2 số nhỏ nhất giống nhau
void HamInRaViTri_Min(vector<int> v){
    int min = v[0];

    for (int i = 0; i < v.size(); i++)
    {
        if (min > v[i])
        {
            min = v[i];
        }        
    }
    
    int index = 0;

    cout << "\nvi tri cac phan tu nho nhat la:\n";
    for (int i = 0; i < v.size(); i++)
    {
        if(v[i] == min){
            cout << "index = " << i << "\n";
        }
    }    
}

// hàm in ra màn hình các số nguyên khác nhau
void HamInRa_SoNguyenKhacNhau(vector<int> v){
    int temp = 0;
    
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = i + 1; j < v.size(); j++)
        {
            if (v[i] > v[j])
            {
                temp = v[i];
                v[i] = v[j];
                v[j] = temp;
            }            
        }        
    }
    
    int q = 0;
    for (int i = 1; i < v.size(); i++){
        if (v[i] != v[q]){
            v[++q] = v[i];
        }
    }
    cout << "\ncac so nguyen khac nhau la:\n";
    for (int i = 0; i <= q; i++){
        cout << v[i] << " ";
    }
}

int main(){
    cout << "nhap so nguyen n (0 < n < 100): ";
    int n;
    cin >> n;

    vector<int> v1(n);

    cout << "\nnhap " << n << " phan tu:\n";
    for (int i = 0; i < v1.size(); i++)
    {
        cout << "v[" << i << "] = ";
        cin >> v1[i];
    }
    
    cout << "\ntong cac so nguyen duong cua day so: tong = ";
    int tong_nguyen_duong = 0;
    for (int i = 0; i < v1.size(); i++)
    {
        if (v1[i] > 0)
        {
            tong_nguyen_duong = tong_nguyen_duong + v1[i];
        }        
    }
    cout << tong_nguyen_duong << endl;
    
    HamInRaViTri_Min(v1);

    HamInRa_SoNguyenKhacNhau(v1);

    cout << "\n";
    return 0;
}