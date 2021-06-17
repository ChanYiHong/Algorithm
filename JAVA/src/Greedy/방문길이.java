package Greedy;

import java.util.*;

public class 방문길이 {

    class Edge {

        int startX;
        int startY;
        int endX;
        int endY;

        public Edge(int startX, int startY, int endX, int endY) {
            this.startX = startX;
            this.startY = startY;
            this.endX = endX;
            this.endY = endY;
        }

    }

    class Solution {

        private List<Edge> edges;

        public boolean isInRange(int x, int y) {
            if(x >= 0 && x < 11 && y >= 0 && y < 11) return true;
            return false;
        }

        public void addEdge(int startX, int startY, int endX, int endY) {

            Edge e1 = new Edge(startX, startY, endX, endY);
            Edge e2 = new Edge(endX, endY, startX, startY);

            for(int i = 0; i < edges.size(); i++) {
                Edge edge = edges.get(i);
                if(edge.startX == e1.startX && edge.startY == e1.startY && edge.endX == e1.endX && edge.endY == e1.endY){
                    return;
                }
            }

            edges.add(e1);
            edges.add(e2);

        }

        public int solution(String dirs) {
            int answer = 0;

            edges = new ArrayList<>();

            int x = 5;
            int y = 5;

            for(char direction : dirs.toCharArray()) {

                if(direction == 'U') {
                    if(isInRange(x, y + 1)) {
                        addEdge(x, y, x, y + 1);
                        y++;
                    }
                }

                if(direction == 'D') {
                    if(isInRange(x, y - 1)) {
                        addEdge(x, y, x, y - 1);
                        y--;
                    }
                }

                if(direction == 'L') {
                    if(isInRange(x - 1, y)) {
                        addEdge(x, y, x - 1, y);
                        x--;
                    }
                }

                if(direction == 'R') {
                    if(isInRange(x + 1, y)) {
                        addEdge(x, y, x + 1, y);
                        x++;
                    }
                }

            }

            return answer = edges.size() / 2;
        }
    }

}
