#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
int n;
int dp[101][101];
int arr[101][101];

int findMaximum(int x, int y)
{
//     if(stair == 0) return arr[0][0];
//     if(dp[x][stair] != -1) return dp[x][stair];
    
//     if(x-1 < 0) dp[x][stair] = findMaximum(stair-1, x) + arr[x][stair];
//     else if(x > stair - 1) dp[x][stair] = findMaximum(stair-1, x-1) + arr[x][stair];
//     else dp[x][stair] = max(findMaximum(stair-1, x-1), findMaximum(stair-1, x)) + arr[x][stair];

//     return dp[x][stair];

    if(y == n - 1) return arr[x][y];
    if(dp[x][y] != -1) return dp[x][y];

    dp[x][y] = max(findMaximum(x, y+1), findMaximum(x+1, y+1)) + arr[x][y];
    return dp[x][y]; 
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
        cin >> n;
        memset(dp, -1, sizeof(dp));
        for(int j = 0; j < n; j++){
            for(int i = 0; i <= j; i++){
                cin >> arr[i][j];
            }
        }
        cout << findMaximum(0, 0) << '\n';
    }
    return 0;
}