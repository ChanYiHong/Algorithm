#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    int arr[1001][1001];
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> arr[i][j];
        }
    }
    int D[1001][1001];
    D[1][1] = arr[1][1];

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            int maximum = 0;
            maximum = max(D[i][j-1], D[i-1][j]);
            maximum = max(maximum, D[i-1][j-1]);
            D[i][j] = maximum + arr[i][j];
        }
    }

    cout << D[n][m];
    return 0;
}