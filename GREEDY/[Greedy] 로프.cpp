#include <iostream>
#include <algorithm>
using namespace std;

bool descending(int &a, int &b){
    return a > b;
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n;
    cin >> n;
    int rope[n];
    for(int i = 0; i < n; i++){
        cin >> rope[i];
    }
    sort(rope, rope + n, descending);

    // 모든 경우를 다 볼 필요는 없음. 최대의 중량만 생각
    // 어떤 병렬 조합이던 최소인 값 x (n + 1) 만큼이 최대 중량
    // n + 1인건 0번 인덱스부터 저장해서임
    // 최소인 값의 순서임...
    int answer = 0;
    for(int i = 0; i < n; i++){
        answer = max(answer, rope[i] * (i + 1));
    }
    cout << answer;

    return 0;
}
