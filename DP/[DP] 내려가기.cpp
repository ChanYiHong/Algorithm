#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n; cin >> n;
    int arr[n][3];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 3; j++){
            cin >> arr[i][j];
        }
    }
    long long DMax[2][3];
    long long DMin[2][3];

    DMax[0][0] = DMin[0][0] = arr[0][0];
    DMax[0][1] = DMin[0][1] = arr[0][1];
    DMax[0][2] = DMin[0][2] = arr[0][2];

    for(int i = 1; i < n; i++){
        for(int j = 0; j < 3; j++){
            DMax[i % 2][j] = 0;
            DMin[i % 2][j] = 999999;
            for(int k = j-1; k <= j+1; k++){
                if(k >= 0 && k <= 2){
                    DMax[i % 2][j] = max(DMax[i % 2][j], DMax[(i-1) % 2][k] + arr[i][j]);
                    DMin[i % 2][j] = min(DMin[i % 2][j], DMin[(i-1) % 2][k] + arr[i][j]);
                }
            }
        }
    }

    sort(DMax[(n-1)%2], DMax[(n-1)%2] + 3);
    sort(DMin[(n-1)%2], DMin[(n-1)%2] + 3);
    cout << DMax[(n-1)%2][2] << ' ' << DMin[(n-1)%2][0];

    return 0;
}