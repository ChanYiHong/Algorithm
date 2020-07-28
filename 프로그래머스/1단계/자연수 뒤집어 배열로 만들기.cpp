#include <string>
#include <vector>

using namespace std;

vector<int> solution(long long n) {
    vector<int> answer;
    for(long long i = n; i > 0; i /= 10){
        answer.push_back(i%10);
    }
    return answer;
}