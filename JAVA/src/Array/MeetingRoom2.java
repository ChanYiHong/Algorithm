package Array;

import java.util.*;

class Inter {
    int start;
    int end;

    public Inter(int start, int end) {
        this.start = start;
        this.end = end;
    }
}

public class MeetingRoom2 {

    public static void main(String[] args) {

        List<Inter> input = new ArrayList<>();
        input.add(new Inter(0, 30));
        input.add(new Inter(4, 9));
        input.add(new Inter(10, 16));
        input.add(new Inter(5, 15));

        System.out.println(solve(input));

    }

    private static int solve(List<Inter> input) {

        if(input.size() == 0 || input == null) return 0;

        // 1. start 값으로 오름차순 소팅.
        Collections.sort(input, (a, b) -> a.start - b.start);

        // 2. PriorityQueue 생성. end중에 작은 게 튀어나오도록.
        Queue<Inter> pq = new PriorityQueue<>((a, b) -> a.end - b.end);

        pq.offer(input.get(0));

        // 3. for 문

        for(int i = 1; i < input.size(); i++) {

            // pq에서 가장 작은 end값 보다 현재 start값이 크거나 같으면, 방 1개로 두개가 커버가 가능해짐.
            if(pq.peek().end <= input.get(i).start) {
                // pq에서 가장 작은 방을 제거 후 현재 값으로 pq에 넣음..
                pq.poll();
            }

            pq.offer(input.get(i));

        }

        return pq.size();

    }

}
