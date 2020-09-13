#include <string>
#include <vector>

using namespace std;

vector<int> dealer;
vector<int> player;
vector<int> C;
int index = 4;

int changeCard(int n){
    if(n > 10) n = 10;
    return n;
}

void init(){
    player.push_back(changeCard(C[0]));
    dealer.push_back(changeCard(C[1]));
    player.push_back(changeCard(C[2]));
    dealer.push_back(changeCard(C[3]));
}

bool checkIfPlayerBlackJack(){

    bool ret = false;
    if((player[0] + player[1] == 11 && player[0] == 1) || (player[0] + player[1] == 11 && player[1] == 1)) {
        ret = true;
    }
    
    return ret;
}

int checkIfDealerBlackJack(){
    
    int current = dealer[0] + dealer[1];
    while(1){
        if(current >= 17) break;
        
        current += changeCard(C[index]);
        index++;
    }
    
    return current;
}

void playerTurn(){
    
    if(dealer[1] == 1 || dealer[1] >= 7){
        
        int current = player[0] + player[1];
        while(1){
            if(current >= 17) break;
            current += changeCard(C[index]);
            player.push_back(C[index]);
            index++;
        }
        return;
    }
    
    if(dealer[1] == 4 || dealer[1] == 5 || dealer[1] == 6){
        return;
    }
    
    if(dealer[1] == 2 || dealer[1] == 3){
        while(1){
            if(current >= 17) break;
            current += changeCard(C[index]);
            player.push_back(C[index]);
            index++;
        }
        return;
    }
}

int solution(vector<int> cards) {
    int answer = -1;
    
    C = cards;
    
    init();
    
    if(checkIfPlayerBlackJack()){
        // Player win (BlackJack)
        if(checkIfDealerBlackJack() != 21){
            answer = 3;
            return answer;
        }
        // Draw
        else{
            answer = 0;
            return answer;
        }
    }
    
    playerTurn();
    
    return answer;
}