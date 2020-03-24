#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int N, K, i, j;
    cin >> N >> K;
    long long weight[101], value[101];
    for(i = 1; i <= N; i++){
        cin >> weight[i] >> value[i];
    }
    long long D[101][100001];
    for(i = 0; i <= N; i++){
        for(j = 0; j <= K; j++){
            if(i == 0 || j == 0){
                D[i][j] = 0;
                continue;
            }
            if(weight[i] > j) D[i][j] = D[i-1][j];
            else D[i][j] = max(D[i-1][j], D[i-1][j-weight[i]]+ value[i]);
        }
    }
    cout << D[N][K];
    return 0;
}
