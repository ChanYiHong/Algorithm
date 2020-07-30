#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(string s) {
    int answer = 1001;
    if(s.length() == 1) return 1;
    // 문자열 길이의 반만큼 짜르는거 시도
    for(int cut = 1; cut <= s.length() / 2; cut++){
        string compression = "";
        string last = s.substr(0, cut);
        int cnt = 1;
        for(int i = cut; i < s.length(); i+=cut){
            string current = s.substr(i, cut);
            
            // 같다면 cnt ++
            if(last.compare(current) == 0){
                cnt++;
            }
            // 다르다면.. cnt 개수에 따라 적절히 compression에 저장
            else{
                if(cnt == 1){
                    compression += last;
                    last = current;
                    cnt = 1;
                }
                else{
                    char num = cnt + '0';
                    compression += num;
                    compression += last;
                    last = current;
                    cnt = 1;
                }
            }
        }
        if(cnt != 1){
            char num = cnt + '0';
            compression += num;
            compression += last;
        }
        else{
            compression += last;
        }
        
        if(answer > compression.length()) answer = compression.length();
        //cout << compression << "  " << answer << '\n';
    }
    
    return answer;
}

int main()
{
    

    cout << "메인 실험 :  " << solution("a") << '\n';
    return 0;
}