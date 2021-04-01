package DFSBFS;

import java.util.LinkedList;
import java.util.Queue;

public class 게임맵최단거리 {

    int[] dx = {1, -1, 0, 0};
    int[] dy = {0, 0, 1, -1};

    public int bfs(int[][] maps) {

        int[][] check = new int[maps.length][maps[0].length];

        Queue<int[]> queue = new LinkedList<>();
        queue.offer(new int[]{0, 0});
        check[0][0] = 1;

        while (!queue.isEmpty()) {
            int[] front = queue.poll();
            int x = front[0];
            int y = front[1];
            int cur = check[x][y];

            if (x == maps.length - 1 && y == maps[0].length - 1) {
                return cur;
            }

            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if (nx >= 0 && nx < maps.length && ny >= 0 && ny < maps[0].length) {

                    if (maps[nx][ny] == 1 && check[nx][ny] == 0) {
                        check[nx][ny] = cur + 1;
                        queue.offer(new int[]{nx, ny});
                    }
                }
            }
        }
        return -1;
    }

    public int solution(int[][] maps) {
        int answer = 0;

        answer = bfs(maps);

        return answer;


    }
}
