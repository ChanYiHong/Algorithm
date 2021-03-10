package StackQueue;

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;

public class Programmers기능개발 {

    public int[] solution(int[] progresses, int[] speeds) {

        List<Integer> answer = new ArrayList<>();
        Queue<Integer> queue = new LinkedList<>();
        int index = 0;

        for(int i = 0; i < progresses.length; i++) {
            queue.add((100-progresses[i])%speeds[i] == 0? (100 - progresses[i]) / speeds[i]
                    : (100 - progresses[i]) / speeds[i] + 1);
        }

        int cnt = 1;
        int frontProgress = queue.poll();

        while(!queue.isEmpty()) {

            int nextProgress = queue.poll();

            if(frontProgress >= nextProgress) {
                cnt++;
            }
            else {
                frontProgress = nextProgress;
                answer.add(cnt);
                cnt = 1;
            }
        }

        answer.add(cnt);

        return answer.stream().mapToInt(i -> i).toArray();
    }

}
