#include <iostream>
#include <algorithm>
#include <cmath>
int n;
int arr[2187][2187];
int negative = 0;
int zero = 0;
int one = 0;

using namespace std;

void conquer(int x, int y, int size)
{
    if(size == 1){
        if(arr[x][y] == -1) negative++;
        else if(arr[x][y] == 0) zero++;
        else if(arr[x][y] == 1) one++;
        return;
    }
    int color = arr[x][y];
    bool unification = true;
    // i의 범위를 i < size 가 아니라 start_x + size로 해야하는 실수 했었음
    for(int i = x; i < x + size; i++){
        for(int j = y; j < y + size; j++){
            if(color != arr[i][j]){
                unification = false;
                break;
            }
        }
        if(!unification) break;
    }
    if(!unification){
        conquer(x, y, size/3);
        conquer(x, y + size/3, size/3);
        conquer(x, y + ((size/3) *2), size/3);
        conquer(x + size/3, y, size/3);
        conquer(x + size/3, y + size/3, size/3);
        conquer(x + size/3, y + ((size/3) *2), size/3);
        conquer(x + ((size/3) *2), y, size/3);
        conquer(x + ((size/3) *2), y + size/3, size/3);
        conquer(x + ((size/3) *2), y + ((size/3) *2), size/3);
    }
    else{
        if(arr[x][y] == -1) negative++;
        else if(arr[x][y] == 0) zero++;
        else if(arr[x][y] == 1) one++;
    }
    return;
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
    
    conquer(0, 0, n);
    cout << negative << '\n';
    cout << zero << '\n';
    cout << one;

    return 0;
}