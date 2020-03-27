#include <iostream>

using namespace std;
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int D[1001];
    int n;
    cin >> n;
    int arr[n+1];
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
    }
    for(int i = 1; i <= n; i++){
        D[i] = 1;
        int temp = 1;
        for(int j = 1; j < i; j++){
            if(arr[i] > arr[j] && temp < D[i] + D[j]){
                temp = D[i] + D[j];
            }
        }
        D[i] = temp;
    }
    int max = 0;
    for(int i = 1; i <= n; i++){
        if(D[i] > max) max = D[i];
    }
    cout << max;

    return 0;
}
