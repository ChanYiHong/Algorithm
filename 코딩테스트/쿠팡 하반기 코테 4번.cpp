#include <string>
#include <vector>
#include <map>

using namespace std;
vector<vector<string>> R;
vector<vector<int>> graph;
map<string, int> m;
int N;

void init(){

    // Make Map
    int index = 1;
    for(int i = 0; i < R.size(); i++){
        for(int j = 0; j < 2; j++){
            if(m[R[i][j]] == 0){
                m[R[i][j]] = index;
                index++;
            }
        }
    }

    // Make Graph
    N = index;  // number of nodes
    graph.resize(N, vector<int>());
    int start, end;
    for(int i = 0; i < R.size(); i++){
        start = m[R[i][0]];
        end = m[R[i][1]];

        graph[start].push_back(end);
    }
}

int DFS(int cur, int target, vector<bool> check){

    if(cur == target) return 1;

    int ret = 0;

    for(int i = 0; i < graph[cur].size(); i++){
        int next = graph[cur][i];

        if(!check[next]){
            check[next] = true;
            ret += DFS(next, target, check);
            check[next] = false;
        }
    }

    return ret;
}

int solution(string depar, string hub, string dest  , vector<vector<string>> roads) {
    int answer = -1;
    R = roads;
    init();

    int start = m[depar];
    int stopper = m[hub];
    int destination = m[dest];

    vector<bool> check(N, false);
    int route1 = DFS(start, stopper, check);
    int route2 = DFS(stopper, destination, check);

    answer = (route1 * route2)%10007;

    return answer;
}