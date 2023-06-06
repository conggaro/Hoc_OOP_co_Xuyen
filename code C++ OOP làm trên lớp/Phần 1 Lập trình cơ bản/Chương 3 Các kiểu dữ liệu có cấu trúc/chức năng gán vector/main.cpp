// Yêu cầu:
// 1. vector cho phép gán
// 2. mảng không cho phép gán

// đây chính là ưu điểm của vector

#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<int> v_x(5);
    v_x = {1, 2, 3, 4, 5};

    vector<int> v_y;
    v_y = v_x;

    v_y.push_back(6);
    for(int i = 0; i < v_y.size(); i++){
        cout << v_y[i] << endl;
    }

    return 0;
}