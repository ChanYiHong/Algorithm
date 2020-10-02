#include <string>
#include <vector>
#include <algorithm>
#define INF 987654321

using namespace std;

vector<string> WORDS;
int N;
string GOAL;

bool just_one_char_dif(string a, string b){
    
    int ret = 0;
    for(int i = 0; i < a.length(); i++){
        if(a[i] != b[i]) ret++;
    }
    
    if(ret == 1) return true;
    else return false;
}

int DFS(string cur, int cnt, vector<bool> check){
    
    if(cur == GOAL) return cnt;
    
    int ret = INF;
    
    for(int i = 0; i < N; i++){
        if(check[i]) continue;
        
        if(just_one_char_dif(cur, WORDS[i])){
            check[i] = true;
            ret = min(ret, DFS(WORDS[i], cnt+1, check));
            check[i] = false;
        }
    }
    
    return ret;
}

int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    
    WORDS = words;
    N = words.size();
    GOAL = target;
    
    vector<bool> check(N, false);
    
    answer = DFS(begin, 0, check);
    
    return answer == INF ? 0 : answer;
}