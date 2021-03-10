package Greedy;

public class ProgrammersMostBigSquare {

    public int solution(int [][]board)
    {
        int answer = 0;
        int rowLen = board.length;
        int colLen = board[0].length;

        int[][] map = new int[rowLen + 1][colLen + 1];

        for(int i = 0; i < rowLen; i++) {
            for(int j = 0; j < colLen; j++) {
                map[i + 1][j + 1] = board[i][j];
            }
        }

        for(int i = 1; i <= rowLen; i++){
            for(int j = 1; j <= colLen; j++){
                if(map[i][j] != 0) {
                    map[i][j] = Math.min(Math.min(map[i-1][j], map[i][j-1]), map[i-1][j-1]) + 1;
                    answer = Math.max(answer, map[i][j]);
                }
            }
        }

        return answer * answer;
    }


}
