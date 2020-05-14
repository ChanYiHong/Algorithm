#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    int D[n];
    for(int i = 0; i < n; i++){
        D[i] = 1;
        for(int j = 0; j < i; j++){
            if(arr[i] < arr[j]){
                D[i] = max(D[i], D[j] + 1);
            }
        }
    }
    int max = 0;
    for(int i = 0; i < n; i++){
        if(max < D[i]) max = D[i];
    }
    cout << max;

    return 0;
}