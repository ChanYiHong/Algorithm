#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    bool check[1000001];
    check[1] = true;
    for(int i = 2; i < 1000000; i++){
        if(check[i] == false){
            for(int j = i + i; j < 1000000; j += i){
                check[j] = true;
            }
        }
    }
    while(1){
        int n;
        cin >> n;
        if(n == 0) break;
        int cnt = 0;
        for(int i = n+1; i <= 2*n; i++){
            if(!check[i]) cnt++;
        }
        cout << cnt << '\n';
    }
    return 0;
}