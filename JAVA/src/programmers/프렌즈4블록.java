package programmers;

public class 프렌즈4블록 {

    static int[][] dx = {
            {-1, -1, 0},
            {1, 1, 0},
            {-1, -1, 0},
            {1, 1, 0}
    };
    static int[][] dy = {
            {0, 1, 1},
            {0, 1, 1},
            {0, -1, -1},
            {0, -1, -1}
    };

    static boolean isChange = false;

    public void scanningBlock(char[][] blocks, boolean[][] check) {

        for (int i = 0; i < blocks.length; i++) {
            for (int j = 0; j < blocks[0].length; j++) {
                fourWayCheck(blocks, check, i, j);
            }
        }
    }

    public void fourWayCheck(char[][] blocks, boolean[][] check, int x, int y) {

        char cur = blocks[x][y];

        if (cur == 'X') return;

        for (int c = 0; c < 4; c++) {

            if(isInRange(x + dx[c][0], y + dy[c][0], blocks)
                    && isInRange(x + dx[c][1], y + dy[c][1], blocks)
                    && isInRange(x + dx[c][2], y + dy[c][2], blocks)) {

                if((cur == blocks[x + dx[c][0]][y + dy[c][0]])
                        && (cur == blocks[x + dx[c][1]][y + dy[c][1]])
                        && (cur == blocks[x + dx[c][2]][y + dy[c][2]])) {

                    check[x][y] = true;
                    check[x + dx[c][0]][y + dy[c][0]] = true;
                    check[x + dx[c][1]][y + dy[c][1]] = true;
                    check[x + dx[c][2]][y + dy[c][2]] = true;
                    isChange = true;

                }
            }
        }
    }

    public boolean isInRange(int x, int y, char[][] blocks) {
        return x >= 0 && x < blocks.length && y >= 0 && y < blocks[0].length;
    }

    public int removeBlock(char[][] blocks, boolean[][] check) {

        int removeCnt = 0;
        // 맨 윗줄은 그냥 삭제.
        for (int i = 0; i < blocks.length; i++) {
            for (int j = 0; j < blocks[0].length; j++) {
                if (blocks[i][j] == 'X') {
                    continue;
                }
                if (i == 0 && check[i][j]) {
                    blocks[i][j] = 'X';
                    removeCnt++;
                }
                if (i != 0 && check[i][j]) {
                    for (int k = i; k > 0; k--) {
                        blocks[k][j] = blocks[k - 1][j];
                        if (k == 1) {
                            blocks[k - 1][j] = 'X';
                        }
                    }
                    removeCnt++;
                }
            }
        }

        return removeCnt;

    }

    public int solution(int m, int n, String[] board) {
        int answer = 0;

        char[][] blocks = new char[m][n];

        for (int i = 0; i < m; i++) {
            String row = board[i];
            char[] chars = row.toCharArray();

            for (int j = 0; j < chars.length; j++) {
                blocks[i][j] = chars[j];
            }

        }

        do{
            isChange = false;
            boolean[][] check = new boolean[blocks.length][blocks[0].length];
            scanningBlock(blocks, check);
            answer += removeBlock(blocks, check);

        }while(isChange);


        return answer;
    }

    public static void main(String[] args) {
        프렌즈4블록 main = new 프렌즈4블록();

        String[] strs = new String[]{"CCBDE", "AAADE", "AAABF", "CCBBF"};

        int result = main.solution(4, 5, strs);

        System.out.println(result);
    }

}
