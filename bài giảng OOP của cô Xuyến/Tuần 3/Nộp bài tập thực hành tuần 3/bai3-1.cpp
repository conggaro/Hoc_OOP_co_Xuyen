// Yêu cầu:
// 1. nhập số nguyên N (N < 1000)
// 2. nhập dãy số thực arr[0] đến arr[N - 1]

// 3. tìm số nhỏ nhất thứ 2 trong dãy
// 4. tìm số lớn nhất thứ 2 trong dãy

// 5. nhân đôi các phần tử ở vị trí chia hết cho 3
// --> giả sử dãy được đánh số từ 1

#include <iostream>
#define SIZE 1000
using namespace std;

// hàm tìm số nhỏ thứ 2 trong dãy
float Tim_Min_Top2(float arr[], int do_dai){
    float min_top2 = arr[0];

    for (int i = 0; i < do_dai; i++)
    {
        if(min_top2 < arr[i]){
            min_top2 = arr[i];
            break;
        }
    }    
    return min_top2;
}

// hàm tìm số lớn thứ 2 trong dãy
float Tim_Max_Top2(float arr[], int do_dai){
    float max_top2 = arr[do_dai - 1];

    for (int i = do_dai - 1; i >= 0; i--)
    {
        if(max_top2 > arr[i]){
            max_top2 = arr[i];
            break;
        }
    }    
    return max_top2;
}

int main(){
    cout << "Nhap vao so thuc N: ";
    int N;
    cin >> N;

    float arr[SIZE];

    for(int i = 0; i < N; i++){
        cout << "arr[" << i << "] = ";
        cin >> arr[i];
    }

    int temp = 0;
    for (int  i = 0; i < N; i++)
    {
        for (int j = i + 1; j < N; j++)
        {
            if (arr[i] > arr[j])
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }            
        }
    }    

    cout << "So nho nhat thu 2 trong day la: " << Tim_Min_Top2(arr, N);
    cout << endl;

    cout << "So lon nhat thu 2 trong day la: " << Tim_Max_Top2(arr, N);
    cout << endl;

    // tạo mảng clone
    float arr_clone[SIZE];
    arr_clone[0] = 0;
    for(int i = 1; i < N + 1; i++){
        arr_clone[i] = arr[i - 1];
        if(i % 3 == 0){
            arr_clone[i] = arr_clone[i] * 2;
        }
    }

    cout << "\nGia su vi tri:\t\t\t\t";
    for (int i = 1; i < N + 1; i++)
    {
        cout << i << "\t";
    }
    cout << endl;
    
    cout << "\nVi tri chia het cho 3 thi x2:\t\t";
    for (int i = 1; i < N + 1; i++)
    {
        cout << arr_clone[i] << "\t";
    }
    cout << endl;

    cout << "\nDay so ban dau la:";
    for (int i = 0; i < N; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}