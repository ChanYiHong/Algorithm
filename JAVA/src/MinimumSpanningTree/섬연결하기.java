package MinimumSpanningTree;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class 섬연결하기 {

    int[] parent = new int[101];
    List<Point> points = new ArrayList<>();

    class Point{
        int x;
        int y;
        int cost;

        public Point(int x, int y, int cost) {
            this.x = x;
            this.y = y;
            this.cost = cost;
        }
    }

    public int findParent(int x) {
        if(parent[x] == x) {
            return x;
        }
        else {
            return parent[x] = findParent(parent[x]);
        }
    }

    public void union(int x, int y) {
        x = findParent(x);
        y = findParent(y);

        if(x != y) {
            if(x < y) {
                parent[y] = x;
            }
            else {
                parent[x] = y;
            }
        }
    }

    public boolean isSameParent(int x, int y) {
        x = findParent(x);
        y = findParent(y);

        return x == y;
    }

    public int solution(int n, int[][] costs) {
        int answer = 0;

        for(int i = 0; i < costs.length; i++) {
            points.add(new Point(costs[i][0], costs[i][1], costs[i][2]));
        }

        for(int i = 0; i < n; i++) {
            parent[i] = i;
        }

        Collections.sort(points, (a, b) -> {
            if(a.cost > b.cost) {
                return 1;
            }
            else if (a.cost == b.cost) {
                return 0;
            }
            else {
                return -1;
            }
        });


        for(int i = 0; i < points.size(); i++) {

            Point p = points.get(i);

            if(!isSameParent(p.x, p.y)) {
                union(p.x, p.y);
                answer += p.cost;
            }
        }

        return answer;
    }


}
