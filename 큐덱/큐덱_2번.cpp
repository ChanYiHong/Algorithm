#include <iostream>
#include <queue>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int N;
    cin >> N;
    queue<int> q;
    for(int i = 1; i <= N; i++){
        q.push(i);
    }
    while(q.size()!=1){
        q.pop();
        int temp = q.front();
        q.push(temp);
        q.pop();
    }
    cout << q.front();

    return 0;
}