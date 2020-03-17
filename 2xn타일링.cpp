#include <iostream>

using namespace std;

/*n이 홀수 : 반드시 세로 1나옴
n이 짝수 : all 세로, all 가로 가능

2칸에 하나씩 짝은 문제로 갈 수 있음
내 생각엔..
n 4면

D[n] = 2xn을 채우는 방법의 수
문제 나눌때 
D[n] = D[n - 2] + 2;
D[n] = D[n - 1] + 1;*/
int D[1001];
int df(int n)
{
    if(n == 1) return 1;
    if(n == 2) return 2;
    if(D[n] > 0) return D[n];
    D[n] = (df(n - 2) + df(n - 1))%10007;
    return D[n];
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    int result = df(n);
    cout << result << '\n';

    return 0;
}