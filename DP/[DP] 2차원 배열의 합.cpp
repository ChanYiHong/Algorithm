#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    long long arr[301][301];

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> arr[i][j];
        }
    }
    
    long long D[301][301];
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= m; j++){
            D[i][j] = 0;
        }
    }

    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= n; j++){
            if(j == 1){
                D[j][i] = D[n][i-1] + arr[j][i];
            }
            else D[j][i] = D[j-1][i] + arr[j][i];
        }
    }

    int T;
    cin >> T;
    while(T--){
        int i, j, x, y;
        cin >> i >> j >> x >> y;
        cout << D[x][y] - D[i][j] + arr[i][j] <<'\n';
    }

    return 0;
}