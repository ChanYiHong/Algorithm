#include <iostream>
#include <queue>
#include <utility>
#include <algorithm>
#include <stack>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int T;
    cin >> T;
    for(int k = 0; k < T; k++){
        int N, M;
        cin >> N >> M;
        // pair의 first == 우선순위
        // pair의 second == M(궁금한 문서)이면 1 아니면 0
        queue<pair<int, int> > q;
        // 우선순위를 arr에 따로저장. sort를 하기 위함
        int arr[N];
        for(int i = 0; i < N; i++){
            int num;
            cin >> num;
            arr[i] = num;
            if(i == M) q.push(make_pair(num, 1));
            else q.push(make_pair(num, 0));
        }

        sort(arr, arr+N);
        // stack에 오름차순 sort된 arr를 push
        // 젤 높은 수가 stack의 top에 오게 됨.
        stack<int> s;
        for(int i = 0; i < N; i++){
            s.push(arr[i]);
        }
        int answer;
        int count = 1;
        while(1)
        {
            // stack top과 queue의 front(정확히는 pair의 첫 번째 first)비교
            // 다르면 우선순위가 젤 높지 않다는 거니까 queue 맨 뒤로 뺌
            if(s.top() != q.front().first){
                pair<int, int> temp = q.front();
                q.push(temp);
                q.pop();
            }
            // stack top 과 queue의 front.first와 같다면
            else if(s.top() == q.front().first){
                // front.second가 1, 즉 내가 찾는 문서면 순서 저장후 break
                if(q.front().second == 1){
                    answer = count;
                    break;
                }
                // 내가 찾는 문서가 아니면, stack, queue 둘다 pop
                else{
                    q.pop();
                    s.pop();
                    count++;
                }
            }
        }
        cout << answer <<'\n';
    }
    return 0;
}