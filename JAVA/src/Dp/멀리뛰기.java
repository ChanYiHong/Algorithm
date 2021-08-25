package Dp;

public class 멀리뛰기 {

    static long[] D;

    public long dp(long x) {

        if (x == 1) return 1;
        if (x == 2) return 2;

        if (D[(int) x] != 0) {
            return D[(int) x];
        }

        return D[(int) x] = (dp(x-1) + dp(x-2)) % 1234567 ;

    }

    public long solution(int n) {
        long answer = 0;

        D = new long[n + 1];
        answer = dp(n);

        return answer;
    }
}
