package Sort;

import java.util.PriorityQueue;

public class PriorityQueueTest {

    public static void main(String[] args) {
        int[] sticks = {1, 8, 2, 5};

        System.out.println(pqSticks(sticks));
    }

    private static int pqSticks(int[] sticks) {

        PriorityQueue<Integer> pq = new PriorityQueue<>(); // Default : Min Heap

        for(int i : sticks) {
            pq.offer(i);  // pq에 저장. 알아서 젤 작은게 위로!
        }

        int sum = 0;
        while(pq.size() > 1) {
            int twoSum = pq.poll() + pq.poll(); // 맨 위에꺼 빼는듯.
            System.out.println(twoSum);
            sum += twoSum;
            pq.offer(twoSum);
        }

        return sum;

    }

}
