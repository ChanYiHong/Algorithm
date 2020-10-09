#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(int k, vector<int> score) {
    int answer = 0;

    vector<pair<int, pair<int, int>>> diff;
    map<int, int> m;

    for(int i = 0; i < score.size() - 1; i++){
        int score_diff = score[i] - score[i+1];
        m[score_diff]++;
        diff.push_back({score_diff, {i, i+1}});
    }

    int score_diff, rank_person1, rank_person2;
    vector<bool> check(score.size(), true);

    for(int i = 0; i < diff.size(); i++){
        score_diff = diff[i].first;
        rank_person1 = diff[i].second.first;
        rank_person2 = diff[i].second.second;

        if(m[score_diff] >= k){
            check[rank_person1] = false;
            check[rank_person2] = false;
        }
    }

    for(int i = 0; i < score.size(); i++){
        if(check[i]) answer++;
    }

    return answer;
}