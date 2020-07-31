#include <string>
#include <vector>

using namespace std;

string solution(string phone_number) {
    string answer = "";
    string last_four_number = phone_number.substr(phone_number.length() - 4);
    string star = "****************";
    answer = star.substr(0, phone_number.length() - 4);
    answer += last_four_number;
    return answer;
}