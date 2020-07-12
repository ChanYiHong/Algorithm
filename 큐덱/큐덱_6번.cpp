#include <iostream>
#include <deque>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int N, M;
    cin >> N >> M;
    int location[M];
    for(int i = 0; i < M; i++){
        int num;
        cin >> num;
        location[i] = num;
    }
    deque<int> deq;
    for(int i = 1; i <= N; i++){
        deq.push_back(i);
    }
    
    int count = 0;
    int answer = 0;
    deque<int>::iterator iter;
    while(count != M){
        if(deq.front() == location[count]){
            deq.pop_front();
            count++;
        }
        else{
            int c = 1;
            for(iter = deq.begin(); iter != deq.end(); iter++){
                if(*iter == location[count]) break;
                c++;
            }
            if(c <= deq.size()/2 + 1){
                int temp = deq.front();
                deq.push_back(temp);
                deq.pop_front();
                answer++;
            }
            else{
                int temp = deq.back();
                deq.push_front(temp);
                deq.pop_back();
                answer++;
            }
        }
    }
    cout << answer;
    return 0;
}

