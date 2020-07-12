#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int N, K;
    cin >> N >> K;
    queue<int> q;
    for(int i = 1; i <= N; i++){
        q.push(i);
    }
    int count = 1;
    vector<int> answer;
    while(q.size()!= 0){
        if(count == K){
            answer.push_back(q.front());
            q.pop();
            count = 1;
        }
        else{
            int temp = q.front();
            q.push(temp);
            q.pop();
            count++;
        }
    }
    vector<int>::iterator iter;
    cout << '<';
    for(iter = answer.begin(); iter != answer.end(); iter++){
        if(iter+1 != answer.end()) cout << *iter << ", ";
        else cout << *iter;
    }
    cout << '>';

    return 0;
}