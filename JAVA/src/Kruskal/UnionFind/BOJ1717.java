package Kruskal.UnionFind;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class BOJ1717 {

    static int[] parent;

    public static void isSameParent(int a, int b) {

        int x = find(a);
        int y = find(b);

        if(x == y) {
            System.out.println("YES");
        }else {
            System.out.println("NO");
        }
    }

    public static void union(int a, int b) {
        int x = find(a);
        int y = find(b);

        if(x != y) {
            if(x > y) {
                parent[x] = y;
            }else {
                parent[y] = x;
            }
        }
    }

    public static int find(int n) {
        if(parent[n] == n) {
            return n;
        }
        else {
            return parent[n] = find(parent[n]);
        }
    }

    public static void main(String[] args) throws IOException {

        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(bf.readLine());

        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());

        parent = new int[n + 1];

        for(int i = 0; i < parent.length; i++) {
            parent[i] = i;
        }

        for(int i = 0; i < m; i++) {
            st = new StringTokenizer(bf.readLine());

            int order = Integer.parseInt(st.nextToken());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());

            if(order == 1) {
                isSameParent(a, b);
            }else {
                union(a, b);
            }
        }
    }

}
