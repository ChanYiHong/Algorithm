package DFSBFS;

public class N으로표현 {

    class Solution {

        int ANS = 9;
        int NUMBER;
        int _N;

        public void dfs(int num, int cnt) {

            // 탈출 조건.
            if(cnt > 8) return;

            if(NUMBER == num) {
                ANS = Math.min(ANS, cnt);
                return;
            }

            int tempN = _N;

            for(int i = 1; i <= 8 - cnt; i++) {
                dfs(num + tempN, cnt + i);
                dfs(num - tempN, cnt + i);
                dfs(num * tempN, cnt + i);
                dfs(num / tempN, cnt + i);

                tempN = tempN * 10 + _N;
            }
        }

        public int solution(int N, int number) {
            int answer = 0;

            _N = N;
            NUMBER = number;

            dfs(0, 0);

            if(ANS > 8) answer = -1;
            else answer = ANS;

            return answer;
        }
    }

}
