package StackQueue;

import java.util.*;

public class 캐시 {

    class Solution {
        public int solution(int cacheSize, String[] cities) {
            int answer = 0;

            // Queue 사용..
            Queue<String> cache = new LinkedList<>();

            for(int i = 0; i < cities.length; i++) {

                String city = cities[i].toLowerCase();

                // hit
                if(cache.contains(city)) {
                    answer++;

                    // {2, 1, 3, 4} 순서에서 3이 오면, {1, 3, 4, 3} 이 아니라 {2, 1, 4, 3}이 되어야 함!
                    cache.remove(city);
                    cache.offer(city);

                } else {
                    answer += 5;
                    if(cacheSize == 0) continue;

                    if(cache.size() == cacheSize) {
                        cache.poll();
                    }
                    cache.offer(city);
                }

            }

            return answer;
        }
    }

}
