package Dp;

import java.util.Arrays;

public class 거스름돈 {

    class Solution {
        public int solution(int n, int[] money) {
            int answer = 0;

            Arrays.sort(money);

            int[] dp = new int[n];

            for (int i = 0; i < n; i++) {
                if ((i+1) % money[0] == 0) {
                    dp[i] = 1;
                }
            }

            for (int i = 1; i < money.length; i++) {
                int nowMoney = money[i];
                for (int j = nowMoney - 1; j < n; j++) {
                    if (j == nowMoney - 1) {
                        dp[j] = (dp[j] + 1) % 1000000007;
                    }
                    else if (j > nowMoney - 1) {
                        dp[j] = (dp[j] + dp[j - nowMoney]) % 1000000007;
                    }
                }
            }

            return dp[n - 1];
        }
    }

}
