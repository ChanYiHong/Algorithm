#include <string>
#include <vector>

using namespace std;

string solution(vector<string> seoul) {
    string answer = "";
    int location = 0;
    for(string str : seoul){
        if(str == "Kim") break;
        location++;
    }
    string loc = to_string(location);
    answer = "김서방은 " + loc + "에 있다";
    return answer;
}