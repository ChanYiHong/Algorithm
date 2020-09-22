#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int M, N;
    cin >> M >> N;
    // 지워지면 true;
    bool check[1000001];
    check[1] = true;
    for(int i = 2; i <= 1000000; i++){
        if(check[i] == false){
            for(int j = i + i; j <= 1000000; j+=i){
                check[j] = true;
            }
        }
    }
    for(int i = M; i <= N; i++){
        if(!check[i]) cout << i << '\n';
    }
    
    return 0;
}