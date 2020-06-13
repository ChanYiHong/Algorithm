#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
int n;
int arr[501];
int D[501];

void LIS(int index)
{
    if(index == n) return;
    D[index] = 1;
    for(int i = 0; i < index; i++){
        if(arr[i] < arr[index]){
            D[index] = max(D[index], D[i] + 1);
        }
    }
    LIS(index + 1);
    return;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
        cin >> n;
        for(int i= 0; i < n; i++){
            cin >> arr[i];
        }
        D[0] = 1;
        LIS(1);
        int maximum = 0;
        for(int i = 0; i < n; i++){
            if(maximum < D[i]) maximum = D[i];
        }
        cout << maximum << '\n';
    }

    return 0;
}


