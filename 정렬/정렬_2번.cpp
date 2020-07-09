#include <iostream>
#include <vector>

using namespace std;

void mergeSort(vector<int>& v, int s, int e);
void merge(vector<int>& v, int s, int e, int m);
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    cin >> N;
    vector<int> vec;
    for(int i = 0; i < N; i++){
        int number;
        cin >> number;
        vec.push_back(number);
    }
    mergeSort(vec, 0, vec.size()-1);

    for(int i = 0; i < vec.size(); i++){
        cout << vec[i] << '\n';
    }

    return 0;
}
void mergeSort(vector<int>& v, int s, int e)
{
    if(e>s){
        int m = (s+e)/2;

        // Divide
        mergeSort(v, s, m);
        mergeSort(v, m+1, e);

        // Conquer
        merge(v, s, e, m);
    }
}
void merge(vector<int>& v, int s, int e, int m)
{
    vector<int> ret;
    int i = s, j = m + 1, copy = 0;

    // 두개의 배열 비교 후 합침.
    while(i <= m && j <= e){
        if(v[i] < v[j]) ret.push_back(v[i++]);
        else if(v[i] > v[j]) ret.push_back(v[j++]);
    }

    while(i <= m) ret.push_back(v[i++]);
    while(j <= e) ret.push_back(v[j++]);

    // 원래 배열에 복사
    for(int k = s; k <= e; k++){
        v[k] = ret[copy++];
    }
}