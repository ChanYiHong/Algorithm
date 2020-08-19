#include <iostream>
#include <vector>

using namespace std;

vector<string> str;
vector<bool> check;
vector<char> answer;

void dfs(int n, int index){

    
    
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--){

        int n;
        cin >> n;
        for(int i =0;i < n; i++){
            string input;
            cin >> input;
            str.push_back(input);
        }

        check.resize(26, false);

        
        check.clear();
        str.clear();
        answer.clear();
    }

    return 0;
}