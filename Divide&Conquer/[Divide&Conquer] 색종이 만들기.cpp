#include <iostream>
#include <algorithm>
using namespace std;
int n;
int arr[128][128];
int white = 0;
int blue = 0;

void divide(int start_x, int start_y, int size)
{
    if(size == 1){
        if(arr[start_x][start_y] == 1) blue++;
        else white++;
        return;
    }
    int color = arr[start_x][start_y];
    bool unification = true;
    // i의 범위를 i < size 가 아니라 start_x + size로 해야하는 실수 했었음
    for(int i = start_x; i < start_x + size; i++){
        for(int j = start_y; j < start_y + size; j++){
            if(color != arr[i][j]){
                unification = false;
                break;
            }
        }
        if(!unification) break;
    }
    if(!unification){
        divide(start_x, start_y, size/2);
        divide(start_x, start_y + size/2, size/2);
        divide(start_x + size/2, start_y, size/2);
        divide(start_x + size/2, start_y + size/2, size/2);
    }
    else{
        if(color == 1) blue++;
        else white++;
        return;
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> arr[i][j];
        }
    }
    divide(0, 0, n);
    cout << white << '\n';
    cout << blue;
    return 0;
}

// Divide & Conquer
// 재귀 호출을 통한 부분 문제로 분할
// 그 후 결과를 합침

/*
처음에 8/2 
0,1,2,3 <4
까지 나눠서 전체 인덱스를 줌

전체 쭉 훑고 다 똑같은 색이면 

*/