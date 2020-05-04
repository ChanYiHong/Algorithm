#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    int D[10001] = {0, };
    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    D[0] = 1;
    for(int i = 0; i < n; i++){
        for(int j = arr[i]; j <= k; j++){
            D[j] += D[j-arr[i]];
        }
    }

    cout << D[k];

    return 0;
}