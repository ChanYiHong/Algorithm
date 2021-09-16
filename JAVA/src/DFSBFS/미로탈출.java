package DFSBFS;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class 미로탈출 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());

        int[][] graph = new int[N][M];

        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < M; j++) {
                graph[i][j] = Integer.parseInt(st.nextToken());
            }
        }
        
        int[][] check = new int[N][M];
        Queue<int[]> queue = new LinkedList<>();
        int[] dx = new int[]{1, -1, 0, 0};
        int[] dy = new int[]{0, 0, 1, -1};
        
        queue.offer(new int[]{0, 0});
        check[0][0] = 1;
        
        while(!queue.isEmpty()) {
            int[] coordinate = queue.poll();
            int x = coordinate[0];
            int y = coordinate[1];

            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if (nx >= 0 && nx < N && ny >= 0 && ny < M) {
                    if (check[nx][ny] == 0 && graph[nx][ny] == 1) {
                        check[nx][ny] = check[x][y] + 1;
                        queue.offer(new int[]{nx, ny});
                    }
                }
            }
        }

        System.out.println(check[N-1][M-1]);
        
    }
    
}
