#include <iostream>

using namespace std;

bool prime(int n)
{
    if(n == 1) return false;
    for(int i = 2; i*i <= n; i++){
        if(n%i==0) return false;
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int N;
    cin >> N;
    int count = 0;
    for(int i = 0; i < N; i++){
        int num;
        cin >> num;
        if(prime(num) == true) count++;
    }
    cout << count;

    return 0;
}