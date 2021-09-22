package Greedy;

import java.util.PriorityQueue;
import java.util.Collections;
import java.util.Arrays;
import java.util.List;
import java.util.ArrayList;

public class 무지의먹방라이브 {


    class Solution {

        class Food implements Comparable<Food>{

            int time;
            int index;

            public Food (int time, int index) {
                this.time = time;
                this.index = index;
            }

            @Override
            public int compareTo(Food o) {
                return Integer.compare(this.time, o.time);
            }

        }

        public int solution(int[] food_times, long k) {

            long sum = 0;
            PriorityQueue<Food> pq = new PriorityQueue<>();

            for (int i = 0; i < food_times.length; i++) {
                pq.offer(new Food(food_times[i], i + 1));
                sum += food_times[i];
            }

            if (sum <= k) {
                return -1;
            }

            long remainFood = food_times.length;
            sum = 0;
            long previous = 0;

            while (sum + ((pq.peek().time - previous) * remainFood) <= k) {

                Food food = pq.poll();
                sum += ((food.time - previous) * remainFood);
                remainFood--;
                previous = food.time;
            }

            List<Food> remainFoodList = new ArrayList<>();
            while (!pq.isEmpty()) {
                remainFoodList.add(pq.poll());
            }

            Collections.sort(remainFoodList, (a, b) -> {
                return a.index - b.index;
            });

            return remainFoodList.get((int)((k - sum) % remainFood)).index;

        }
    }

}
