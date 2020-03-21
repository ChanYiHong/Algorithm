#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n;
    cin >> n;
    int stair[301];
    long long D[301];
    for(int i = 1; i <= n; i++){
        cin >> stair[i];
    }
    //초기값 설정
    D[0] = 0;
    stair[0] = 0;
    D[1] = stair[1];
    D[2] = stair[1] + stair[2];
    for(int i = 2; i <= n; i++){
        D[i] = 0;
        D[i] += max(D[i-2], D[i-3]+stair[i-1]) + stair[i];
    }
           
    cout << D[n];
    return 0;
}
