package programmers;

import java.util.PriorityQueue;
import java.util.Comparator;
import java.util.Arrays;

public class 이중우선순위큐 {

    public int[] solution(String[] operations) {
        int[] answer = new int[2];

        PriorityQueue<Integer> minHeap = new PriorityQueue<>();
        PriorityQueue<Integer> maxHeap = new PriorityQueue<>(Comparator.reverseOrder());

        Arrays.stream(operations)
                .forEach(o -> {
                    String[] strs = o.split(" ");
                    String operation = strs[0];
                    Integer num = Integer.parseInt(strs[1]);
                    if (operation.equals("I")) {
                        minHeap.offer(num);
                        maxHeap.offer(num);
                    } else {
                        if (!minHeap.isEmpty()) {
                            if (num == 1) {
                                int maxValue = maxHeap.peek();
                                maxHeap.remove(maxValue);
                                minHeap.remove(maxValue);
                            } else {
                                int minValue = minHeap.peek();
                                maxHeap.remove(minValue);
                                minHeap.remove(minValue);
                            }
                        }
                    }
                });

        if (!minHeap.isEmpty()) {
            answer[0] = maxHeap.peek();
            answer[1] = minHeap.peek();
        } else {
            answer[0] = 0;
            answer[1] = 0;
        }

        return answer;
    }

}
