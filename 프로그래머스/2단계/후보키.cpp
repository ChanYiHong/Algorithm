// #include <string>
// #include <vector>
// #include <map>
// #include <iostream>

// using namespace std;

// int solution(vector<vector<string> > relation) {
//     int answer = 0;
    
//     vector<int> result;
    
//     for(int i = 0; i < relation[0].size(); i++){
//         map<string, int> m;
//         for(int j = 0; j < relation.size(); j++){
//             m[relation[j][i]]++;
//         }
        
//         map<string, int>::iterator iter;
//         vector<int> index;
//         vector<string> same;
//         bool isAllOne = true;
//         for(iter = m.begin(); iter != m.end(); iter++){
//             cout << "[ " << iter->first << " , " << iter->second << " ]" << '\n';
//             if(iter->second != 1){
//                 if(isAllOne) {
//                     isAllOne = false;
//                 }
//                 same.push_back(iter->first);
//             }
//         }
        
//         if(isAllOne){
//             answer++;
//             cout << "여깅!"<<'\n';
//             continue;
//         }
        
//         for(int y = 0; y < same.size(); y++){
//             for(int j = 0; j < relation.size(); j++){
//                 if(same[y].compare(relation[j][i]) == 0){
//                     index.push_back(j);
//                 }
//             }
//         }
        
//         cout << '\n';
//         cout << "********************" << '\n';
//         vector<int> database_index = index;
//         for(int h = i+1; h < relation.size(); h++){
        
//             int k = h;
//             index = database_index;
            
//             while(k < relation[0].size()){

//                 map<string, int> temp_m;
//                 for(int j = 0; j < index.size(); j++){
//                     int nx = index[j];
//                     temp_m[relation[nx][k]]++;
//                 }

//                 isAllOne = true;
//                 vector<string> temp_vector;
//                 map<string, int>::iterator iter2;

//                 for(iter2 = temp_m.begin(); iter2 != temp_m.end(); iter2++){
//                     cout << "[ " << iter2->first << " , " << iter2->second << " ]" << '\n';
//                     if(iter2->second != 1){

//                         if(isAllOne) isAllOne = false;
//                         temp_vector.push_back(iter2->first);
//                     }
//                 }

//                 same = temp_vector; 

//                 if(isAllOne){
//                     answer++;
//                     cout << "여기요!"<<'\n';
//                     break;
//                 }

//                 index.clear();

//                 for(int y = 0; y < same.size(); y++){
//                     for(int j = 0; j < relation.size(); j++){
//                         if(same[y].compare(relation[j][i]) == 0){
//                             index.push_back(j);
//                         }
//                     }
//                 }


//                 k++;

//                 cout << "******************" << '\n';
//                 cout << "******************" << '\n';
//             }
//         }
//     }
    
//     return answer;
// }

// int main()
// {

//     vector<vector<string> > kk(5);

//     kk[0].push_back("b"); 
//     kk[0].push_back("2");
//     kk[0].push_back("a"); 
//     kk[0].push_back("a");
//     kk[0].push_back("b"); 

//     kk[1].push_back("b"); 
//     kk[1].push_back("2");
//     kk[1].push_back("7"); 
//     kk[1].push_back("1");
//     kk[1].push_back("b");

//     kk[2].push_back("1"); 
//     kk[2].push_back("0");
//     kk[2].push_back("a"); 
//     kk[2].push_back("a");
//     kk[2].push_back("8");

//     kk[3].push_back("7"); 
//     kk[3].push_back("5");
//     kk[3].push_back("a"); 
//     kk[3].push_back("a");
//     kk[3].push_back("9");

//     kk[4].push_back("3"); 
//     kk[4].push_back("0");
//     kk[4].push_back("a"); 
//     kk[4].push_back("f");
//     kk[4].push_back("9");



//     // kk[0].push_back("100"); 
//     // kk[0].push_back("ryan");
//     // kk[0].push_back("music");
//     // kk[0].push_back("2");

//     // kk[1].push_back("200"); 
//     // kk[1].push_back("apeach");
//     // kk[1].push_back("math");
//     // kk[1].push_back("2");

//     // kk[2].push_back("300"); 
//     // kk[2].push_back("tube");
//     // kk[2].push_back("computer");
//     // kk[2].push_back("3");

//     // kk[3].push_back("400"); 
//     // kk[3].push_back("con");
//     // kk[3].push_back("computer");
//     // kk[3].push_back("4");

//     // kk[4].push_back("500"); 
//     // kk[4].push_back("muzi");
//     // kk[4].push_back("music");
//     // kk[4].push_back("3");

//     // kk[5].push_back("600"); 
//     // kk[5].push_back("apeach");
//     // kk[5].push_back("music");
//     // kk[5].push_back("2");
    
    
//     // {"100","ryan","music","2"});
//     // kk[1].push_back({"200","apeach","math","2"});
//     // kk[2].push_back({"300","tube","computer","3"});
//     // kk[3].push_back({"400","con","computer","4"});
//     // kk[4].push_back({"500","muzi","music","3"});
//     // kk[5].push_back({"600","apeach","music","2"});

//     int ret = solution(kk);

//     cout << "정답 : " << ret <<'\n';
    
//     return 0;
// }
#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>

using namespace std;

bool custom(const vector<int>& a, const vector<int>& b){
    return a.size() < b.size();
}

int solution(vector<vector<string> > relation) {
    int answer = 0;
    
    vector<vector<int> > result;
    
    for(int i = 0; i < relation[0].size(); i++){
        map<string, int> m;
        vector<string> same;
        for(int j = 0; j < relation.size(); j++){
            m[relation[j][i]]++;
            same.push_back(relation[j][i]);
        }
        
        map<string, int>::iterator iter;
        //vector<int> index;
        
        bool isAllOne = true;
        for(iter = m.begin(); iter != m.end(); iter++){
            cout << "[ " << iter->first << " , " << iter->second << " ]" << '\n';
            if(iter->second != 1){
                if(isAllOne) {
                    isAllOne = false;
                    break;
                }
                //same.push_back(iter->first);
            }
        }
        
        if(isAllOne){
            answer++;
            cout << "여깅!"<<'\n';
            vector<int> res;
            res.push_back(i);
            result.push_back(res);
            continue;
        }
        
        // for(int y = 0; y < same.size(); y++){
        //     for(int j = 0; j < relation.size(); j++){
        //         if(same[y].compare(relation[j][i]) == 0){
        //             index.push_back(j);
        //         }
        //     }
        // }
        
        cout << '\n';
        cout << "********************" << '\n';
        //vector<int> database_index = index;
        vector<string> database_same = same;
        for(int h = i+1; h < relation.size(); h++){
        
            vector<int> res;
            res.push_back(i);
            
            int k = h;
            //index = database_index;
            same = database_same;
            
            while(k < relation[0].size()){

                res.push_back(k);
                map<string, int> temp_m;
                for(int j = 0; j < relation.size(); j++){
                    
                    same[j] += relation[j][k];
                }
                
                for(int j = 0; j < same.size(); j++){
                    cout << same[j] << '\n';
                }
                
                for(int j = 0; j < same.size(); j++){
                    //int nx = index[j];
                    temp_m[same[j]]++;
                }

                isAllOne = true;
                //vector<string> temp_vector;
                map<string, int>::iterator iter2;

                for(iter2 = temp_m.begin(); iter2 != temp_m.end(); iter2++){
                    cout << "[ " << iter2->first << " , " << iter2->second << " ]" << '\n';
                    if(iter2->second != 1){

                        if(isAllOne) isAllOne = false;
                        break;
                        //temp_vector.push_back(iter2->first);
                        
                    }
                }

                //same = temp_vector; 

                if(isAllOne){
                    answer++;
                    cout << "여기요!"<<'\n';
                    result.push_back(res);
                    break;
                }

                //index.clear();

//                 for(int y = 0; y < same.size(); y++){
//                     for(int j = 0; j < relation.size(); j++){
//                         if(same[y].compare(relation[j][i]) == 0){
//                             index.push_back(j);
//                         }
//                     }
//                 }


                k++;

                cout << "******************" << '\n';
                cout << "******************" << '\n';
            }
        }
    }
    
    sort(result.begin(), result.end(), custom);

    for(int i = 0; i < result.size(); i++){
        cout << "[ ";
        for(int j = 0; j < result[i].size(); j++){
            cout << result[i][j] << ' ';
        }
        cout << "]" << '\n';
    }

    
    return answer;
}
int main()
{

    vector<vector<string> > kk(5);

    kk[0].push_back("b"); 
    kk[0].push_back("2");
    kk[0].push_back("a"); 
    kk[0].push_back("a");
    kk[0].push_back("b"); 

    kk[1].push_back("b"); 
    kk[1].push_back("2");
    kk[1].push_back("7"); 
    kk[1].push_back("1");
    kk[1].push_back("b");

    kk[2].push_back("1"); 
    kk[2].push_back("0");
    kk[2].push_back("a"); 
    kk[2].push_back("a");
    kk[2].push_back("8");

    kk[3].push_back("7"); 
    kk[3].push_back("5");
    kk[3].push_back("a"); 
    kk[3].push_back("a");
    kk[3].push_back("9");

    kk[4].push_back("3"); 
    kk[4].push_back("0");
    kk[4].push_back("a"); 
    kk[4].push_back("f");
    kk[4].push_back("9");



    // kk[0].push_back("100"); 
    // kk[0].push_back("ryan");
    // kk[0].push_back("music");
    // kk[0].push_back("2");

    // kk[1].push_back("200"); 
    // kk[1].push_back("apeach");
    // kk[1].push_back("math");
    // kk[1].push_back("2");

    // kk[2].push_back("300"); 
    // kk[2].push_back("tube");
    // kk[2].push_back("computer");
    // kk[2].push_back("3");

    // kk[3].push_back("400"); 
    // kk[3].push_back("con");
    // kk[3].push_back("computer");
    // kk[3].push_back("4");

    // kk[4].push_back("500"); 
    // kk[4].push_back("muzi");
    // kk[4].push_back("music");
    // kk[4].push_back("3");

    // kk[5].push_back("600"); 
    // kk[5].push_back("apeach");
    // kk[5].push_back("music");
    // kk[5].push_back("2");
    
    
    // {"100","ryan","music","2"});
    // kk[1].push_back({"200","apeach","math","2"});
    // kk[2].push_back({"300","tube","computer","3"});
    // kk[3].push_back({"400","con","computer","4"});
    // kk[4].push_back({"500","muzi","music","3"});
    // kk[5].push_back({"600","apeach","music","2"});

    int ret = solution(kk);

    cout << "정답 : " << ret <<'\n';
    
    return 0;
}