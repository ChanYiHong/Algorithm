#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#define INF 987654321
using namespace std;
char str[10001];
int D[10001];

int decision(int begin, int end)
{

}
int dp(int begin)
{
    if(begin >= strlen(str)) return 0;
    int& ret = D[begin];
    if(ret != -1) return D[begin];

    ret = INF;

    ret = min(ret, dp(begin+3) + decision(begin, begin+2));
    ret = min(ret, dp(begin+4) + decision(begin, begin+3));
    ret = min(ret, dp(begin+5) + decision(begin, begin+4));

    return ret;
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int t; 
    cin >> t;
    while(t--){
        cin >> str;
        memset(D, -1, sizeof(D));
        //strlen(str)
        cout << dp(0) << '\n';
    }
    return 0;
}