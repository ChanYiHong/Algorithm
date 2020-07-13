#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;
    int num[N];
    for(int i = 0; i < N; i++){
        cin >> num[i];
    }
    int max = -1;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(i == j) continue;
            for(int k=0;k<N;k++){
                if(j == k || i == k) continue;
                int sum = num[i] + num[j] + num[k];
                if(sum >= max && sum <= M) max = sum;
            }
        }
    }

    cout << max;

    return 0;
}