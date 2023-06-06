// Yêu cầu:
// 1. nhập số học sinh M (số học sinh trong khoảng 10 đến 30)
// 2. nhập số môn học N

// 3. nhập vào điểm các môn học của học sinh thứ nhất
// 4. nhập vào điểm các môn học của học sinh thứ M

// 5. in ra số lượng (giỏi khá trung_bình yếu)

#include <iostream>
#define SIZE 1000
using namespace std;

int main(){
    int M;
    cin >> M;

    int N;
    cin >> N;

    int arr[SIZE][SIZE];

    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> arr[i][j];
        } 
    }
    
    int tong = 0;
    float TBC = 0;

    // đếm học sinh giỏi
    int dem1 = 0;

    // đếm học sinh khá
    int dem2 = 0;

    // đếm học sinh trung bình
    int dem3 = 0;

    // đếm học sinh yếu
    int dem4 = 0;

    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            tong = tong + arr[i][j];
        } 
        
        TBC = tong / N;
        
        if (TBC >= 8.0)
        {
            dem1 ++;
        }else if(TBC >= 6.0 && TBC < 8.0){
            dem2 ++;
        }else if(TBC >= 5.0 && TBC < 6.0){
            dem3 ++;
        }else if(TBC < 5.0){
            dem4 ++;
        }

        tong = 0;
        TBC = 0;
    }

    cout << dem1 << " " << dem2 << " " << dem3 << " " << dem4;

    return 0;
}