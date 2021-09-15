package Simulation;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class 게임개발 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());

        st = new StringTokenizer(br.readLine());

        int x = Integer.parseInt(st.nextToken());
        int y = Integer.parseInt(st.nextToken());
        int direction = Integer.parseInt(st.nextToken());

        int[][] board = new int[N][M];

        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < M; j++) {
                board[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        boolean[][] check = new boolean[N][M];
        check[x][y] = true;

        int[][] move = new int[][]{{0, -1}, {-1, 0}, {0, 1}, {1, 0}};
        int[][] moveBack = new int[][]{{1, 0}, {0, -1}, {-1, 0}, {0, 1}};

        int rotationCnt = 0;
        int ans = 1;

        while (true) {

            if (direction < 0) {
                direction = 3;
            }

            // 4 방향 다 봤는데 이미 다 가본 칸이면..
            if (rotationCnt > 3) {
                int nextX = x + moveBack[direction][0];
                int nextY = y + moveBack[direction][1];

                if (isInRange(N, M, nextX, nextY) && board[nextX][nextY] == 0) {
                    x = nextX;
                    y = nextY;
                    check[x][y] = true;
                    rotationCnt = 0;
                    continue;
                } else {
                    break;
                }
            }

            int nextX = x + move[direction][0];
            int nextY = y + move[direction][1];

            if (isInRange(N, M, nextX, nextY) && !check[nextX][nextY] && board[nextX][nextY] == 0) {
                x = nextX;
                y = nextY;
                check[x][y] = true;
                rotationCnt = 0;
                ans++;
            }
            else {
                rotationCnt++;
            }

            direction--;
        }

        System.out.println(ans);
    }

    private static boolean isInRange(int N, int M, int x, int y) {
        return x >= 0 && x < N && y >= 0 && y < M;
    }

}
