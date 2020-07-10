#include <iostream>

using namespace std;
int factorial(int n);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin >> N;
    cout << factorial(N);
    return 0;
}
int factorial(int n)
{
    if(n == 1 || n == 0) return 1;
    return n * factorial(n - 1);
}