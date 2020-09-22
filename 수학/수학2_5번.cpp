#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    bool check[10001];
    check[1] = true;
    for(int i = 2; i < 10000; i++){
        if(check[i] == false){
            for(int j = i + i; j < 10000; j+=i){
                check[j] = true;
            }
        }
    }
    int T;
    cin >> T;
    for(int i = 0; i < T; i++){
        int n;
        cin >> n;
        int a, b;
        int answer_a, answer_b;
        int differ = n;
        for(int j = 2; j <= n; j++){
            if(check[j] == false){
                for(int k = j; k <= n-j; k++){
                    if(j + k == n){
                        a = j;
                        b = k;
                        break;
                    }
                }
            }
            if(differ > b - a){
                differ = b - a;
                answer_a = a;
                answer_b = b;
            }
        }
        cout << answer_a << ' ' << answer_b << '\n';
    }
    return 0;
}