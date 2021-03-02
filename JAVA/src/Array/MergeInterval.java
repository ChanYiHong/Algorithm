package Array;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;

class Interval {
    int start;
    int end;

    public Interval(int start, int end) {
        this.start = start;
        this.end = end;
    }
}

public class MergeInterval {

    public static void main(String[] args) {

        List<Interval> input = new ArrayList<>();
        input.add(new Interval(1, 3));
        input.add(new Interval(2, 6));
        input.add(new Interval(8, 10));
        input.add(new Interval(15, 18));

        List<Interval> result = solve(input);
        for (Interval interval : result) {
            System.out.println(interval.start + "---" + interval.end);
        }

    }

    private static List<Interval> solve(List<Interval> input) {

        if(input.size() == 0) return null;

        List<Interval> ret = new ArrayList<>();

        Collections.sort(input, (a, b) -> {
            if(a.start == b.start) return a.end - b.end;
            else return a.start - b.start;
        });

        int beforeStart = input.get(0).start;
        int beforeEnd = input.get(0).end;

        for(int i = 1; i < input.size(); i++) {
            int currentStart = input.get(i).start;
            int currentEnd = input.get(i).end;

            if(currentStart <= beforeEnd) {
                beforeEnd = Math.max(currentEnd, beforeEnd);
            }
            else {
                ret.add(new Interval(beforeStart, beforeEnd));
                beforeStart = currentStart;
                beforeEnd = currentEnd;
            }
        }

        ret.add(new Interval(beforeStart, beforeEnd));

        return ret;
    }
}

