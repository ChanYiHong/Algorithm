package backtracking;

public class NQueen {

    static int[] col;
    static int N;
    static int ANS = 0;

    public void backtracking(int row) {

        if (row == N) {
            ANS++;
            return;
        }

        for (int i = 0; i < N; i++) {
            col[row] = i; // row행 i열
            if (isPossible(row)) {
                backtracking(row + 1);
            }
        }
    }

    public boolean isPossible(int row) {

        for (int i = 0; i < row; i++) {

            if (col[i] == col[row]) return false;

            // 행과 열의 증가분이 같으면 대각선임.
            if (Math.abs(i - row) == Math.abs(col[i] - col[row])) return false;

        }

        return true;
    }

    public int solution(int n) {
        int answer = 0;
        N = n;

        // i는 열임.
        for (int i = 0; i < n; i++) {

            col = new int[n];
            col[0] = i;  // 0 행 i열.
            backtracking(1);

        }

        return ANS;
    }
}
