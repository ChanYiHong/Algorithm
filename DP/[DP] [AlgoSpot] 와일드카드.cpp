#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

string wildcard, fileName;

int dp[101][101];

bool match(int w, int s)
{
    int &ret = dp[w][s];
    if(ret != -1) return ret;
    int w = 0;
    int s = 0;
    while(w < wildcard.size() && s < fileName.size() 
    && (wildcard[w] == '?' || wildcard[w] == fileName[s])){
        w++;
        s++;
    }
    // 만약 끝까지 다 봄. wildcard를
    // 그럼 이 스트링 (부분스트링일수도 아닐수도) 은 *를 안만나고 끝났다는 것
    // 그럼 주어진 문자열 길이랑 똑같아야 함. 안그러면 주어진 문자열 뒤에
    // 더 있다는 거니까 문자가. 똑같다는 것이 아님
    if(w == wildcard.size()) {
        ret = (s == fileName.size());
        return ret;
    }
    
    // * 를 만나서 끝나는 경우에 몇 글자에 대응해야 할지를 본다. 이게 무슨 말이냐면..
    // substring을 계속 넣는데 예를들어 abc*def가 wildcard고
    // abcxxdef가 파일 문자열임
    // 첨에 def랑 xxdef를 넣음 당연히 매칭이 안됨
    // 그 다음에 def랑 xdef
    // 그 다음에 def랑 def! 이런식으로 매칭이 되면 다시 위에 while문을 돌거임
    if(wildcard[w] == '*'){
        for(int size = 0; s + size <= fileName.size(); size++){
            if(match(w+1, s + size)){
                ret = true;
                return ret;
            }
        }
    }
    ret = false;
    return ret;
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
        cin >> wildcard;
        int n;
        cin >> n;
        for(int i = 0; i < n; i++){
            cin >> fileName;
            bool res = match(0, 0);
            if(res) cout << fileName << '\n';
        }
    }
    return 0;
}