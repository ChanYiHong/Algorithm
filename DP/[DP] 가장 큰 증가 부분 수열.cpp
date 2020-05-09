#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    int arr[1001];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    int D[1001];
    for(int i = 0; i < n; i++){
        D[i] = arr[i];
    }
    for(int i = 1; i < n; i++){
        int maximum = 0;
        for(int j = 0; j < i; j++){
            if(arr[j] < arr[i]){
                maximum = max(maximum, D[i] + D[j]);
            }
        }
        D[i] = max(D[i], maximum);
    }

    // for(int i = 0; i < n; i++){
    //     cout << D[i] << ' ';    
    // }

    int answer = 0;
    for(int i = 0; i < n; i++){
        if(answer < D[i]) answer = D[i];
    }

    cout << answer;

    return 0;
}