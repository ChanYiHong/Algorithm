#include <iostream>

using namespace std;

bool prime(int n)
{
    if(n < 2) return false;
    for(int i = 2; i * i <= n; i++){
        if(n % i == 0) return false;
    }
    return true;
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int M, N;
    cin >> M >> N;
    int min, first = 1, sum = 0;
    for(int i = M; i <= N; i++){
        if(prime(i) == true && first == 1){
            min = i;
            sum += i;
            first = 0;
        }
        else if(prime(i) == true) sum += i;
    }
    if(first == 1) cout << -1;
    else{
        cout << sum << '\n';
        cout << min << '\n';
    }
    return 0;
}