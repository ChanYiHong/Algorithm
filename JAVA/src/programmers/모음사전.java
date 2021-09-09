package programmers;

public class 모음사전 {

    static char[] alpha = {'A', 'E', 'I', 'O', 'U'};
    static int cnt = 0;
    static boolean findAns = false;

    public void dfs(StringBuilder cur, String word) {

        if (cur.toString().equals(word)) {
            findAns = true;
            return;
        }

        if (cur.length() == 5) {
            return;
        }

        for (int i = 0; i < 5; i++) {
            cnt++;
            cur.append(alpha[i]);
            dfs(cur, word);
            if (findAns == true) {
                return;
            }
            cur.delete(cur.length() - 1, cur.length());
        }

    }

    public int solution(String word) {
        int answer = 0;

        StringBuilder sb = new StringBuilder();

        dfs(sb, word);

        return answer = cnt;
    }

}
