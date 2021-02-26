package DFSBFS;

public class BasicDFS {

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

        m = grid.length;
        n = grid[0].length;

        int cnt = 0;

        for(int i = 0; i < grid.length; i++) {
            for(int j = 0; j < grid[i].length; j++) {
                if(grid[i][j] == '1'){
                    cnt++;
                    dfs(grid, i, j);
                }
            }
        }

        return cnt;

    }

    private static void dfs(char[][] grid, int x, int y) {

        grid[x][y] = '0';

        for(int c = 0; c < 4; c++) {
            int nx = x + dx[c];
            int ny = y + dy[c];

            if(nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] == '1') {
                dfs(grid, nx, ny);
            }
        }

    }
}
