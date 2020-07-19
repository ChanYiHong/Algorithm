#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = n-1;
    vector<int> numbers(n+1, 1);
    numbers[0] = 0; numbers[1] = 0;
    for(int i = 2; i < numbers.size(); i++){
        if(numbers[i] == 1){
            for(int j = i+i; j < numbers.size(); j+=i){
                if(numbers[j] == 1){
                    numbers[j] = 0;
                    answer--;
                }
            }
        }
    }
    return answer;
}