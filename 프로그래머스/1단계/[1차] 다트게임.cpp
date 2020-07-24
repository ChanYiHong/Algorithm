#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int currentPoint = 0;
int lastPoint = 0;
// 10을 쓸지 말지 판단하기 위함
bool digit = false;
// 맨 첫 번째인지 아닌지 판단
bool isStart = true;

int saveLastPoint(int answer, int index, int len, string& dart){
    // 다음 문자가 없음
    if(index + 1 == len){
        answer += currentPoint;
        return answer;
    }
    // 다음 문자가 * 나 #이라면
    if(dart[index+1] == '*' || dart[index+1] == '#'){
        return answer;
    }
    // 만약 첫 번째 문자라면..
    if(isStart) isStart = false;
    // 이전 문자 저장해둠.
    lastPoint = currentPoint;
    answer += currentPoint;
    currentPoint = 0;
    return answer;
}

int solution(string dartResult) {
    int answer = 0;
    
    for(int i = 0; i < dartResult.length(); i++){
        
        char letter = dartResult[i];
        
        if(digit){
            // 2자리 수는 10밖에 없음
            if(letter == '0'){
                currentPoint = 10;
                continue;
            }
            else digit = false;
        }
        // 숫자면.. 10 확인 위해 digit을 true로
        if(letter >= '0' && letter <= '9'){
            currentPoint += (letter - '0');
            digit = true;
            continue;
        }
        // 싱글, 더블, 트리플 확인
        // 싱글은 로직을 위해 그냥 적음.
        if(letter == 'S') {
            currentPoint = pow(currentPoint, 1);
            answer = saveLastPoint(answer, i, dartResult.length(), dartResult);
            continue;
        }
        if(letter == 'D') {
            currentPoint = pow(currentPoint, 2); 
            answer = saveLastPoint(answer, i, dartResult.length(), dartResult);
            continue;
        }
        if(letter == 'T') {
            currentPoint = pow(currentPoint, 3);
            answer = saveLastPoint(answer, i, dartResult.length(), dartResult);
            continue;
        }
        
        if(letter == '*') {
            if(isStart) {
                isStart = false;
                answer += currentPoint * 2;
            }
            else{
                answer += (currentPoint*2) + lastPoint;
            }
            lastPoint = currentPoint * 2;
            currentPoint = 0;
        }
        if(letter == '#') {
            if(isStart) isStart = false;
            answer -= currentPoint;
            lastPoint = (-1) * currentPoint;
            currentPoint = 0;
        }
    }
    
    return answer;
}