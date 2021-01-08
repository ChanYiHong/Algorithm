package DFSBFS;

import java.util.*;

public class BOJ10026 {

    static int n;
    static char[][] area;
    static int[] dx = {1, -1, 0, 0};
    static int[] dy = {0, 0, 1, -1};

    static boolean isInRange(int x, int y){
        return x >= 0 && x < n && y >=0 && y < n;
    }

    static void bfs(int t, int s, boolean[][] check, boolean isColorBlindness){

        check[t][s] = true;
        Deque<int[]> q = new ArrayDeque<>();
        q.add(new int[]{t, s});
        char color = area[t][s];

        while(!q.isEmpty()){
            int[] item = q.pop();
            int x = item[0];
            int y = item[1];

            for(int c = 0; c < 4; c++){
                int nx = x + dx[c];
                int ny = y + dy[c];

                if(isInRange(nx, ny) && !check[nx][ny]){
                    if(isColorBlindness){
                        if(color == area[nx][ny] || color == 'R' && area[nx][ny] == 'G'
                                || color == 'G' && area[nx][ny] == 'R'){
                            check[nx][ny] = true;
                            q.add(new int[]{nx, ny});
                        }
                    }
                    else{
                        if(color == area[nx][ny]){
                            check[nx][ny] = true;
                            q.add(new int[]{nx, ny});
                        }
                    }
                }
            }
        }

    }

    static int bfsLoop(boolean isColorBlindness){

        boolean[][] check = new boolean[n][n];
        int ret = 0;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(!check[i][j]){
                    bfs(i, j, check, isColorBlindness);
                    ret++;
                }
            }
        }

        return ret;

    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        area = new char[n][n];
        for(int i = 0; i < n; i++){
            String input = sc.next();
            for(int j = 0; j < n; j++){
                area[i][j] = input.charAt(j);
            }
        }
        int notColorBlindness = bfsLoop(false);
        int colorBlindness = bfsLoop(true);

        System.out.print(notColorBlindness + " " + colorBlindness);

    }
}

// Arrays.fill 메소드를 이용해서 배열 초기화가 가능. (c++ 의 memset과 같은 느낌)
// Ex) visit[i][j] 가 있는 상태에서
// for(int[] v: visited) {
//   Arrays.fill(v, 0);
// {
// 이렇게 2차원 배열도 1중 for문으로 초기화 가능. // 여기선 0으로 초기화
