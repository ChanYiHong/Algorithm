#include <iostream>
#include <deque>
#include <string>
#include <vector>
#include <cstdlib>
#include <cstring>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int T;
    cin >> T;
    for(int i = 0; i < T; i++){
        deque<int>::iterator iter;
        deque<int>::reverse_iterator riter;
        string fun;
        cin >> fun;
        int N;
        cin >> N;
        deque<int> deq;

        char str[400004];
        cin >> str;
        // 입력 [1,2,3,4]을 토큰화해서 [,]을 제외시켜줌
        char* tok = strtok(str, "[,]");
        vector<string> v;
        while(tok!=NULL){
            v.push_back(tok);
            tok = strtok(NULL, "[,]");
        }
        // 제외시킨 char를 int로
        for(int j = 0; j < v.size(); j++){
            int str_num = atoi(v[j].c_str());
            deq.push_back(str_num);
        }
        // 1이면 정방향, -1이면 역방향. 실제로 안바꾸고 앞뒤로. 덱의 활용
        int way = 1;
        int state = 1;
        for(int j = 0; j < fun.length(); j++){
            if(fun[j] == 'R') way *= -1;
            else if(fun[j] == 'D'){
                if(way == 1 && deq.size()>0) deq.pop_front();
                else if(way == -1 && deq.size()>0) deq.pop_back();
                else state = 0;
            }
        }
        if(state == 0) cout << "error" << '\n';
        else if(state == 1){
            cout << '[';
            if(way == 1){
                for(iter = deq.begin(); iter != deq.end(); iter++){
                    if(iter + 1 != deq.end()) cout << *iter << ',';
                    else cout << *iter;
                }
            }
            // 역방향은 reverse_iterator 활용
            else if(way == -1){
                for(riter = deq.rbegin(); riter != deq.rend(); ++riter){
                    if(riter + 1 != deq.rend()) cout << *riter << ',';
                    else cout << *riter;
                }
            }
            cout << ']' << '\n';
        }
    }

    return 0;
}