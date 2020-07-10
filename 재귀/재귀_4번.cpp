#include <iostream>
#include <stack>
#include <vector>

using namespace std;
void Hano(int n, int from, int to, int rest);
//void Hano2(int n, int one, int two, int three);
vector<int> answer;
//vector<int> answer2;
//int state = 1;
int count_itr = 0;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    Hano(N, 1, 3, 2);
    cout << count_itr << '\n';
    /*if(state == 1){
        for(vector<int>::size_type i = 0; i < answer.size(); i++){
            cout << answer[i];
            if(i%2 == 0){
                cout << " ";
            }
            else{
                cout << '\n';
            }
        }
    }
    else{
        for(vector<int>::size_type i = 0; i < answer2.size(); i++){
            cout << answer2[i];
            if(i%2 == 0){
                cout << " ";
            }
            else{
                cout << '\n';
            }
        }
    }*/

    for(vector<int>::size_type i = 0; i < answer.size(); i++){
            cout << answer[i];
            if(i%2 == 0) cout << " ";
            else cout << '\n';
        }

    return 0;
}
void Hano(int n, int from, int to, int rest)
{
    if(n == 1)
    {   
        answer.push_back(from);
        answer.push_back(to);
        ::count_itr++;
    }
    else
    {
        Hano(n-1, from, rest, to);
        answer.push_back(from);
        answer.push_back(to);
        ::count_itr++;
        Hano(n-1, rest, to, from);
    }
}
/*
void Hano2(int n, int one, int two, int three)
{
    if(n == 1)
    {   
        answer.push_back(one);
        answer.push_back(three);
        //count++;
    }
    else
    {
        if(state == 1){
            Hano2(n-1, one, two, three);
            // Step 1 ( two < - > three )
            for(vector<int>::size_type i = 0; i < answer.size(); i++){
                if(answer[i] == 2){
                    answer2.push_back(three);
                }
                else if(answer[i] == 3){
                    answer2.push_back(two);
                }
                else{
                    answer2.push_back(one);
                }
            }
            // step 2 ( 원래것에서 1 -> 3 )
            answer2.push_back(one);
            answer2.push_back(three);

            // step 3 ( one < - > two )
            for(vector<int>::size_type i = 0; i < answer.size(); i++){
                if(answer[i] == 1){
                    answer2.push_back(two);
                }
                else if(answer[i] == 2){
                    answer2.push_back(one);
                }
                else{
                    answer2.push_back(three);
                }
            }
            answer.clear();
            state = 2;
        }
        else{
            Hano2(n-1, one, two, three);
            // Step 1 ( two < - > three )
            for(vector<int>::size_type i = 0; i < answer2.size(); i++){
                if(answer2[i] == 2){
                    answer.push_back(three);
                }
                else if(answer2[i] == 3){
                    answer.push_back(two);
                }
                else{
                    answer.push_back(one);
                }
            }
            // step 2 ( 원래것에서 1 -> 3 )
            answer.push_back(one);
            answer.push_back(three);

            // step 3 ( one < - > two )
            for(vector<int>::size_type i = 0; i < answer.size(); i++){
                if(answer2[i] == 1){
                    answer.push_back(two);
                }
                else if(answer2[i] == 2){
                    answer.push_back(one);
                }
                else{
                    answer.push_back(three);
                }
            }
            answer2.clear();
            state = 1;
        }
    }
}
*/