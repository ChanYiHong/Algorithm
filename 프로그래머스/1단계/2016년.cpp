#include <string>
#include <vector>

using namespace std;

int month[12] = {0 ,31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30};
string day[7] = {"THU", "FRI", "SAT", "SUN", "MON", "TUE", "WED"};

string solution(int a, int b) {
    string answer = "";
    
    int amount = 0;
    for(int i = 1; i < a; i++){
        amount += month[i];
    }
    
    amount += b;
    
    answer = day[amount % 7];
    
    return answer;
}