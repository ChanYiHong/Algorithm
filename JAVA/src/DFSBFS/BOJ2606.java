package DFSBFS;

import java.util.*;

public class BOJ2606 {

    static int n, k;
    static ArrayList<Integer> [] graph;
    static boolean[] check;
    static int answer = 0;

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        n = sc.nextInt();
        k = sc.nextInt();

        graph = new ArrayList[n+1];
        for(int i = 0; i < n+1; i++){
            graph[i] = new ArrayList<Integer>();
        }

        for(int i = 0; i < k; i++) {
            int a = sc.nextInt();
            int b = sc.nextInt();
            graph[a].add(b);
            graph[b].add(a);
        }
        bfs();
        System.out.println(answer);
    }

    public static void bfs() {
        Queue<Integer> queue = new LinkedList<Integer>();
        check = new boolean[n+1];
        queue.add(1);
        check[1] = true;

        while(!queue.isEmpty()){
            int x = queue.peek();
            queue.remove();
            for(int i = 0; i < graph[x].size(); i++){
                int nx = graph[x].get(i);
                if(!check[nx]){
                    check[nx] = true;
                    answer++;
                    queue.add(nx);
                }
            }
        }
    }
}
