#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    // n번째 방이 k번 라운드 일때..
    bool D[101][101];
    memset(D, true, sizeof(D));

    for(int i = 2; i <= 100; i++){
        for(int j = 1; j <= 100; j++){
            D[j][i] = D[j][i-1];
            if(j % i == 0){
                if(D[j][i] == true){
                    D[j][i] = false;
                }
                else{
                    D[j][i] = true;
                }
            }
        }
    }

    for(int i = 1; i < 10; i++){
        for(int j = 1; j < 10; j++){
            cout << D[i][j] << ' ';
        }
        cout << '\n';
    }

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int answer = 0;
        for(int i = 1; i <= n; i++){
            if(D[i][n] == true) answer++;
        }
        cout << answer << '\n';
     
    }
    return 0;
}