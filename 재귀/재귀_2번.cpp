#include <iostream>

using namespace std;
int Fibo(int n);
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin >> N;
    cout << Fibo(N);
    return 0;
}
int Fibo(int n)
{
    if(n == 0) return 0;
    if(n == 1) return 1;
    return Fibo(n-1) + Fibo(n-2);
}