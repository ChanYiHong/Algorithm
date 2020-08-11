#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool descending(const pair<int, int>& a, const pair<int, int>& b){
    return a > b;
}

vector<int> custom_sort(const vector<int>& v, int n){
    
    vector<pair<int, int>> digit;
    
    for(int i = 0; i < v.size(); i++){
        int num = v[i];
        if(num < 10){
            int temp = num*1000 + num*100 + num*10 + num;
            digit.push_back({temp, num});
        }
        else if(num >= 10 && num < 100){
            int temp = num * 100 + num;
            digit.push_back({temp, num});
        }
        else if(num >= 100 && num < 1000){
            int temp = num * 10 + num / 100;
            digit.push_back({temp, num});
        }
        else{
            digit.push_back({num, num});
        }
    }
    
    
    sort(digit.begin(), digit.end(), descending);
    
    vector<int> ret;
    for(int i = 0; i < digit.size(); i++){
        ret.push_back(digit[i].second);
    }
    
    return ret;
    
}

string solution(vector<int> numbers) {
    string answer = "";
    
    vector<pair<int, int>> first_digit;
    
    for(int num : numbers){
        if(num < 10){
            first_digit.push_back({num, num});
        }
        else if(num>=10 && num<100){
            first_digit.push_back({num/10, num});
        }
        else if(num>=100 && num<1000){
            first_digit.push_back({num/100, num});
        }
        else{
            first_digit.push_back({num/1000, num});
        }
    }
    
    vector<vector<int>> each_number(10, vector<int>());
    for(int i = 0; i < first_digit.size(); i++){
        int x = first_digit[i].first;
        int num = first_digit[i].second;
        each_number[x].push_back(num);
    }
    
    for(int i = 0; i < each_number.size(); i++){
        if(each_number[i].size() == 0) continue;
        if(i == 0) continue;
        each_number[i] = custom_sort(each_number[i], i);
    }
    
    for(int i = each_number.size()-1; i >= 0; i--){
        if(each_number[i].size() == 0) continue;
        for(int j = 0; j < each_number[i].size(); j++){
            string str = to_string(each_number[i][j]);
            answer += str;
        }
    }
    
    bool if_all_zero = true;
    for(int i = 0; i < numbers.size(); i++){
        if(numbers[i] != 0){if_all_zero = false; break;}
    }
    if(if_all_zero){
        answer = "0";
    }
    
    return answer;
}

// 지리는 코드 추가..
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

bool compare(const string &a, const string &b)
{
    if (b + a < a + b)
        return true;
    return false;
}

string solution(vector<int> numbers) {
    string answer = "";

    vector<string> strings;

    for (int i : numbers)
        strings.push_back(to_string(i));

    sort(strings.begin(), strings.end(), compare);

    for (auto iter = strings.begin(); iter < strings.end(); ++iter)
        answer += *iter;

    if (answer[0] == '0')
        answer = "0";

    return answer;
}