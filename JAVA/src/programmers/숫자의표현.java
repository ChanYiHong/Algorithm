package programmers;

public class 숫자의표현 {

    static int ANS = 0;
    static int N;

    public void successive(int cur, int plus) {

        if (cur == N) {
            ANS++;
            return;
        }

        if (cur > N) {
            return;
        }

        successive(cur + plus, plus + 1);

    }

    public int solution(int n) {
        N = n;

        for (int i = 1; i <= n; i++) {
            successive(i, i + 1);
        }

        int answer = ANS;
        return answer;
    }

}
