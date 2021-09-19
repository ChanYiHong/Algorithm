package Kruskal.UnionFind;

import Dijkstra.전보;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class 팀결성 {

    public static void main(String[] args) throws IOException {

        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(bf.readLine());

        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());

        int[] parent = new int[n + 1];
        for (int i = 0; i < n + 1; i++) {
            parent[i] = i;
        }

        for (int i = 0; i < m; i++) {

            st = new StringTokenizer(bf.readLine());

            int command = Integer.parseInt(st.nextToken());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());

            if (command == 0) {
                union(a, b, parent);
            } else {
                boolean result = isSameParent(a, b, parent);
                if (result) {
                    System.out.println("YES");
                } else {
                    System.out.println("NO");
                }
            }

        }
    }

    private static int findParent(int x, int[] parent) {

        if (parent[x] != x) {
            return parent[x] = findParent(parent[x], parent);
        }
        return parent[x];
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

    private static boolean isSameParent(int x, int y, int[] parent) {

        int a = findParent(x, parent);
        int b = findParent(y, parent);

        if (a != b) return false;
        else return true;

    }

}
