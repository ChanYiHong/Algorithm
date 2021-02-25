package Sort;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

class Interval{
    int start, end;

    public Interval(int start, int end) {
        this.start = start;
        this.end = end;
    }
}

public class Comparator {

    public static void main(String[] args) {
        Interval in1 = new Interval(1, 3);
        Interval in2 = new Interval(2, 6);
        Interval in3 = new Interval(8, 10);
        Interval in4 = new Interval(15, 18);

        List<Interval> intervals = new ArrayList<>();
        intervals.add(in1);
        intervals.add(in2);
        intervals.add(in3);
        intervals.add(in4);

        List<Interval> list = merge(intervals);
        for (Interval interval : list) {
            System.out.println(interval.start + " - " + interval.end);
        }
    }

    private static List<Interval> merge(List<Interval> intervals) {

        if(intervals.isEmpty()) return intervals;

        // 1. 일단 start를 기준으로 소팅. Collection List기 때문에 Collections.sort()     ( Array였으면 Arrays.sort())
        Collections.sort(intervals, (a, b) -> a.start - b.start); // 오름 차순

        List<Interval> result = new ArrayList<>();

        // 2. 맨 앞에꺼 가져옴.
        Interval before = intervals.get(0);

        // 3. before의 end 가 다음꺼 start보다 크면 겹치는 것.
        for(int i = 1; i < intervals.size(); i++) {
            Interval after = intervals.get(i);
            if(before.end >= after.start) {
                // 겹칠 때 end 가 더 큰거로 합쳐줌. (다음 것도 겹칠 수 있어서 end만 늘려놓은 상태)
                before.end = Math.max(before.end, after.end);
            }else {
                // 안 겹치면 그대로 before 답에 추가. 현재 after를 새로운 before로.
                result.add(before);
                before = after;
            }
        }

        // 다 돌고 나서 지금 before가 답에 없으면 추가!
        if(!result.contains(before)) result.add(before);

        return result;
    }
}
