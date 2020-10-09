#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int MONTH[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int SECOND[13] = {0, };

void init(){
    int month_per_second = 86400; // 1 Day == 86,400 Second
    SECOND[0] = 0;
    for(int i = 1; i <= 12; i++){
        SECOND[i] = SECOND[i-1] + (month_per_second * MONTH[i]);
    }
}

pair<int, int> change(string str){

    string temp = "";
    int second = 0;
    int amount_time = 0;
    bool first_blank = false;
    bool second_blank = false;
    int dot_index = 0;

    for(int i = 0; i < str.length(); i++){

        if(str[i] == '/'){
            int mth = stoi(temp);
            second += SECOND[mth-1];
            temp = "";
            continue;
        }
        if(str[i] == ' ' && !first_blank){
            int day = stoi(temp);
            second += day * 86400; // 1 Day == 86,400 Second
            temp = "";
            first_blank = true;
            continue;
        }
        if(str[i] == ':'){
            if(dot_index == 0){
                int hour = stoi(temp);
                second += hour * 3600; // 1 Hour == 3,600 Second
                temp = "";
                dot_index++;
            }else if(dot_index == 1){
                int minute = stoi(temp);
                second += minute * 60; // 1 Minute == 60 Second
                temp = "";
                dot_index++;
            }
            continue;
        }

        if(str[i] == ' ' && !second_blank){
            int sec = stoi(temp);
            second += sec;
            temp = "";
            second_blank = true;
            continue;
        }

        temp += str[i];
    }

    amount_time = stoi(temp);

    pair<int, int> ret = {second, amount_time};

    return ret;
}

int solution(int n, vector<string> customers)
{
    int answer = 0;

    init();

    vector<pair<int, int>> cus;

    for(int i = 0; i < customers.size(); i++){
        pair<int, int> ret = change(customers[i]);
        cus.push_back({ret.first, ret.second});
    }    

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    vector<int> kiosk(n, 0);

    for(int i = 0; i < n; i++){
        pq.push({0, i});
    }

    for(int i = 0; i < cus.size(); i++){

        int time = cus[i].first;
        int amount = cus[i].second;

        int kiosk_num = pq.top().second;
        pq.pop();
        kiosk[kiosk_num]++;

        pq.push({time + (amount*60), kiosk_num}); 

    }

    answer = *max_element(kiosk.begin(), kiosk.end());

    return answer;
}