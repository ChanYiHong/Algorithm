package Kruskal.UnionFind;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class 여행계획 {

    public static void main(String[] args) throws IOException {

        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(bf.readLine());

        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());

        int[][] arr = new int[n][n];

        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(bf.readLine());
            for (int j = 0; j < n; j++) {
                arr[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        st = new StringTokenizer(bf.readLine());

        int[] travel = new int[m];
        for (int i = 0; i < m; i++) {
            travel[i] = Integer.parseInt(st.nextToken()) - 1;
        }

        int[] parent = new int[n];
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (!isSameParent(i, j, parent)) {
                    union(i, j, parent);
                }
            }
        }

        boolean answer = true;
        for (int i = 0; i < m - 1; i++) {
            if (!isSameParent(i, i + 1, parent)) {
                answer = false;
                break;
            }
        }

        if (answer) {
            System.out.println("YES");
        } else {
            System.out.println("NO");
        }
    }

    private static boolean isSameParent(int x, int y, int[] parent) {
        int a = findParent(x, parent);
        int b = findParent(y, parent);
        return a == b;
    }

    private static void union(int x, int y, int[] parent) {
        int a = findParent(x, parent);
        int b = findParent(y, parent);

        if (a != b) {
            if (a > b) {
                parent[a] = b;
            } else {
                parent[b] = a;
            }
        }
    }

    private static int findParent(int x, int[] parent) {
        if (x != parent[x]) {
            return parent[x] = findParent(parent[x], parent);
        }
        return parent[x];
    }

}
