#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
int n;
vector<vector<int> > v;
int dp[101][101];
bool rangeCheck(int x, int y)
{
    return x>=0 && x<n && y>=0 && y<n;
}
int oneLegGame(int x, int y)
{
    // Basecase
    if(!rangeCheck(x, y)) return 0;
    if(x == n-1 && y == n-1) return 1;

    int& ref = dp[x][y];
    if(ref != -1) return ref;

    ref = oneLegGame(x + v[x][y], y) || oneLegGame(x, y + v[x][y]);
    return ref;
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
       cin >> n;
       v.resize(n, vector<int>(n));
       v.resize(n, vector<int>(n));
       for(int i = 0; i < n; i++){
           for(int j = 0; j < n; j++){
               cin >> v[i][j];
           }
       }
       memset(dp, -1, sizeof(dp));
       if(oneLegGame(0,0) == 1) cout << "YES" << '\n';
       else cout << "NO" << '\n';
    }

    return 0;
}