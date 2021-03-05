package Array;

import java.util.*;

class Point {
    int x;
    int y;

    public Point(int x, int y) {
        this.x = x;
        this.y = y;
    }
}

public class KClosest {

    public static void main(String[] args) {
        List<Point> points = new ArrayList<>();
        int k = 1;
        points.add(new Point(1, 3));
        points.add(new Point(-2, 2));
        List<Point> result = solve(points, k);

        for (Point point : result) {
            System.out.println(point.x + " " + point.y);
        }
    }

    private static List<Point> solve(List<Point> points, int k) {
        Queue<Point> queue = new PriorityQueue<>(points.size(), (a, b) -> {
            return (a.x * a.x + a.y * a.y) - (b.x * b.x + b.y * b.y);
        });
        List<Point> ret = new ArrayList<>();

        for(Point p : points) {
            queue.offer(p);
        }

        int index = 0;
        while(index < k) {
            ret.add(queue.poll());
            index++;
        }

        return ret;
    }
}
