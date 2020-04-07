#include <iostream>
#include <algorithm>
using namespace std;

int n;
int T[16];
int P[16];
int max_cost = 0;
void go(int index, int cost)
{
    if(index > n){
        if(max_cost < cost) max_cost = cost;
        return;
    }
    if(index + T[index] <= n + 1){
        cost += P[index];
        go(index + T[index], cost);
        cost -= P[index];
    }
    if(index + 1 <= n + 1){
        go(index + 1, cost);
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> n;
    for(int i = 1; i <=n; i++){
        cin >> T[i] >> P[i];
    }
    go(1, 0);
    cout << max_cost;
    return 0;
}
/*
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n,i,j,l;
    cin >> n;
    int day[16], pay[16];
    for(i =1; i <= n; i++){
        cin >> day[i] >> pay[i];
    }
    int D[16][16];
    for(i = 1; i <= n; i++){
        for(j = 1; j <= n; j++){
            D[i][j] = 0;
            if(day[i] + i == j && day[i] + i <= n){
                for(l = 1; l < i; l++){
                    if(D[l][j] > D[i][j]){
                        D[i][j] = D[l][j];
                    }
                }
                D[i][j] += pay[i];
            }
            else{
                for(l = 1; l < i; l++){
                    if(D[l][j] > D[i][j]){
                        D[i][j] = D[l][j];
                    }
                }
            }
        }
    }
    int max = 0;
    for(i = 1; i <= n; i++){
        for(j = 1; j <= n; j++){
            if(max < D[i][j]) max = D[i][j];
        }
    }
    cout << max;
    return 0;
}*/