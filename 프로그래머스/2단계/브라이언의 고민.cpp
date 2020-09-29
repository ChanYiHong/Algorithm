#include <string>
#include <map>
#include <iostream>
#include <vector>

using namespace std;

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
string solution(string sentence) {
    string answer = "";
    
    map<char, int> m;
    
    bool number_one = false;
    bool number_two = false;
    
    // 다음이 소문자여야 하면 true
    bool number_one_small = false;
    char special;
    
    // 첫 글자 세팅
    if(sentence[0] >= 65 && sentence[0] <= 90){
        number_one = true;
        special = sentence[1];
        m[special]++;
        number_one_small = true;
        answer += sentence[0];
    }
    else{
        number_two = true;
        special = sentence[0];
        m[special]++;
    }
    
    for(int i = 1; i < sentence.length(); i++){
        
        // 2번 규칙 (@HELLO@)
        if(number_two){
            if(sentence[i] >= 65 && sentence[i] <= 90){
                answer += sentence[i];
            }
            if(sentence[i] >= 97 && sentence[i] <= 122){
                if(special == sentence[i]){
                    number_two = false;
                    answer += " ";
                }
                // 소문자 두개가 연속 (2번 -> 2번)
                else{
                    special = sentence[i];
                    // 이미 나왔던 소문자면.. invaild
                    if(m[special] != 0){
                        return "invalid";
                    }
                    number_two = true;
                    m[special]++;
                    answer += " ";
                }
            }
        }
        
        // 1번 규칙 (H@E@L@L@O)
        else if(number_one){
            if(sentence[i] >= 65 && sentence[i] <= 90){
                if(!number_one_small){
                    answer += sentence[i];
                    number_one_small = true;
                }
                // 대문자가 연속으로 오면?
                else{
                    answer += " ";
                    answer += sentence[i];
                    special = sentence[i+1];
                    // 특수 문자가 사용되었던 것이면 invaild
                    if(m[special] != 0){
                        return "invalid";
                    }
                    else{
                        m[special]++;
                    }
                }
            }
            if(sentence[i] >= 97 && sentence[i] <= 122){
                // 1번 규칙에서 소문자가 연속으로 두개 나오면 무조건 x 
                if(!number_one_small){
                    return "invalid";
                }
                else{
                    if(special == sentence[i]){
                        number_one_small = false;
                    }
                    // 1번 -> 2번 규칙으로 넘어감
                    else{
                        number_one = false;
                        number_two = true;
                        special = sentence[i];
                        if(m[special] != 0){
                            return "invalid";
                        }
                        m[special]++;
                        answer += " ";
                    }
                }
            }
        }
        else if(!number_one && !number_two){
            if(sentence[i] >= 97 && sentence[i] <= 122){
                number_one = true;
                special = sentence[i+1];
                if(m[special] != 0){
                    return "invalid";
                }
                m[special]++;
                number_one_small = true;
                answer += sentence[i];
            }
            if(sentence[i] >= 65 && sentence[i] <= 90){
                number_two = true;
                special = sentence[i];
                if(m[special] != 0){
                    return "invalid";
                }
                m[special]++;
            }
        }
    }
    
    cout << answer;
    
    if(answer[answer.length()-1] == ' '){
        answer = answer.substr(0, answer.length()-1);
    }
    
    return answer;
}


int main() { 
    vector<string> testcase; 
    testcase.push_back("HaEaLaLaObWORLDb"); //HELLO WORLD 
    testcase.push_back("SpIpGpOpNpGJqOqA"); //SIGONG JOA 
    testcase.push_back("A"); //A 
    testcase.push_back("HELLOWORLD"); //HELLOWORLD 
    testcase.push_back("aHbEbLbLbOacWdOdRdLdDc"); //HELLO WORLD 
    testcase.push_back("HaEaLaLObWORLDb"); //HELL O WORLD 
    testcase.push_back("AAA"); //AAA 
    testcase.push_back("aHELLOWORLDa"); //HELLOWORLD 
    testcase.push_back("AAAaBaAbBBBBbCcBdBdBdBcCeBfBeGgGGjGjGRvRvRvRvRvR"); //AA ABA BBBB C BBBB C BB GG GGG RRRRRR 
    testcase.push_back("aIaAM"); //I AM 
    testcase.push_back("bAaOb"); //AO 
    testcase.push_back("AxAxAxAoBoBoB"); //invalid 
    testcase.push_back("a"); //invalid 
    testcase.push_back("Aa"); //invalid 
    testcase.push_back("aA"); //invalid 
    testcase.push_back("HaEaLaLaOWaOaRaLaD"); //invalid 
    testcase.push_back("abHELLObaWORLD"); //invalid 
    testcase.push_back("aHELLOa bWORLDb"); //invalid 
    testcase.push_back("TxTxTxbAb"); //invalid 
    testcase.push_back("bTxTxTaTxTbkABaCDk"); //invalid 
    testcase.push_back("baHELLOabWORLD"); //invalid 
    testcase.push_back("AxAxAxABcBcBcB"); //AAAA BBBB 
    testcase.push_back("A B"); //invalid 
    testcase.push_back("oBBoA"); //BB A 
    testcase.push_back("AxAxAxA"); //AAAA 
    testcase.push_back("HaEaLaLaObWORLDbSpIpGpOpNpGJqOqAdGcWcFcDdeGfWfLeoBBoAAAAxAxAxAA"); //HELLO WORLD SIGONG J O A GWFD GWL BB AAA AAAA A 
    testcase.push_back("aBcAadDeEdvAvlElmEEEEm"); //BA DE A E EEEE 
    testcase.push_back("AcAcABaBaB"); //A A AB B B 
    testcase.push_back("aGbWbFbDakGnWnLk"); //GWFD GWL 
    testcase.push_back("aCaCa"); //invalid 
    for (int i = 0; i < testcase.size(); ++i) { 
        cout << '[' << solution(testcase[i]) << ']' << '\n'; 
    } 
    return 0; 
}
