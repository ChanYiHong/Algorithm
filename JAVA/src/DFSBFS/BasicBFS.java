package DFSBFS;

import java.util.LinkedList;
import java.util.Queue;

public class BasicBFS {

    static int m, n;
    static int[] dx = {1, -1, 0, 0};
    static int[] dy = {0, 0, 1, -1};

    public static void main(String[] args) {

        char[][] grid = {
                {'1', '1', '0', '0', '1'},
                {'1', '1', '0', '0', '0'},
                {'0', '0', '0', '0', '0'},
                {'0', '0', '0', '1', '1'} };

        System.out.println(solve(grid));

    }

    private static int solve(char[][] grid) {

        if(grid == null || grid.length == 0) return 0;

        int cnt = 0;
        m = grid.length;
        n = grid[0].length;

        for(int i = 0; i < grid.length; i++) {
            for(int j = 0; j < grid[i].length; j++) {
                if(grid[i][j] == '1'){
                    cnt++;
                    bfs(grid, i, j);
                }
            }
        }

        return cnt;

    }

    private static void bfs(char[][] grid, int x, int y) {

        Queue<int[]> queue = new LinkedList<>();

        queue.offer(new int[]{x, y});

        while(!queue.isEmpty()) {
            int[] front = queue.poll();
            for(int c = 0; c < 4; c++) {
                int nx = front[0] + dx[c];
                int ny = front[1] + dy[c];
                if(nx >= 0 && nx < m && ny >= 0 && ny < n) {
                    if(grid[nx][ny] == '1') {
                        grid[nx][ny] = '0';
                        queue.offer(new int[]{nx, ny});
                    }
                }
            }
        }

    }
}
