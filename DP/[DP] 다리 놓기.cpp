#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--)
    {
        int n, m;
        cin >> n >> m;
        // 강 서쪽 사이트개수 -> 강 동쪽 사이트개수 일때 경우의 수
        int D[31][31];
        for(int i = 0; i < 31; i++){
            memset(D[i], 0, sizeof(int)*31);
        }
        for(int i = 1; i <= m; i++){
            // 강 서쪽 사이트가 1개일 때 미리 초기화 (시작조건)
            D[1][i] = i;
        }

        //Bottom Up
        //D[i][j] = D[i-1][j-1] + D[i-1][j-2] + ... + D[i-1][i-1]
        //예시. D[3][5] = D[2][4] + D[2][3] + D[2][2]
        for(int i = 2; i <= n; i++){
            for(int j = i; j <= m; j++){
                for(int k = j-1; k >= i-1; k--){
                    D[i][j] += D[i-1][k];
                }
            }
        }
        cout << D[n][m] << '\n';
    }


    return 0;
}