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

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            D[i][j] = D[i-1][j] + D[i][j-1] - D[i-1][j-1] + arr[i][j];  
        }
    }

    int T;
    cin >> T;
    while(T--){
        int i, j, x, y;
        cin >> i >> j >> x >> y;
        cout << D[x][y] - D[x][j-1] - D[i-1][y] + D[i-1][j-1] <<'\n';
    }

    return 0;
}