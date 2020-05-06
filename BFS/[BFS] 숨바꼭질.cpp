#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <utility>
#include <cstring>
using namespace std;
int check[100001];
void bfs(int n, int k)
{
    queue<int> q;
    q.push(n);
    //check 에 최초에 왔던 시점을 저장.
    check[n] = 0;
    while(1){
        int cur = q.front();
        q.pop();

        if(cur == k) break;

        // 최초에 왔던 점만 파악
        if(cur - 1 >= 0 && !check[cur-1]){
            check[cur-1] = check[cur] + 1;
            q.push(cur-1);
        }
        if(cur + 1 <= 100000 && !check[cur+1]){
            check[cur+1] = check[cur] + 1;
            q.push(cur+1);
        }
        if(cur * 2 <= 100000 && !check[cur*2]){
            check[2*cur] = check[cur] + 1;
            q.push(2*cur);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    bfs(n, k);
    cout << check[k];
    return 0;
}