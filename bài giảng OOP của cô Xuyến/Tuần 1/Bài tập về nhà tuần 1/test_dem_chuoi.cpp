// Yêu cầu:
// 1. Fake 1 cái chuỗi
// 2. Đếm độ dài cái chuỗi đó

#include <iostream>
using namespace std;

int main(){
    string str = "abc";

    // for(int i = 0; i <= 5; i++){
    //     if(typeid(str[i]) == typeid(char)){
    //         cout << str[i] << i << endl;
    //     }
    // }

    int dem = 0;
    int i = 0;
    while((int)str[i] > 0)
    {
        dem = dem + 1;
        i = i + 1;
    }
    cout << dem << endl;

    return 0;
}