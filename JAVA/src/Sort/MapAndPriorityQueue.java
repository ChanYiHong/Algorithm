package Sort;

import java.util.*;

public class MapAndPriorityQueue {

    public static void main(String[] args) {
        int k = 2;
        String[] words = {"i", "study", "inflearn", "i", "study", "conding"};

        List<String> result = solve(words, k);
        for (String s : result) {
            System.out.println(s);
        }
    }

    private static List<String> solve(String[] words, int k) {

        // 1. 그릇
        Map<String, Integer> map = new HashMap<>();
        PriorityQueue<String> pq = new PriorityQueue<>((a, b) -> {
            if (map.get(a) == map.get(b)) {
                return a.compareTo(b);
            } else {
                return map.get(b).compareTo(map.get(a));
            }
        });

        List<String> ret = new ArrayList<>();


        // for 문 or while 문
        for (String w : words) {
            map.put(w, map.getOrDefault(w, 0) + 1);
        }

        for (String key : map.keySet()) {
            pq.offer(key);
        }

        for (int i = 0; i < k; i++) {
            ret.add(pq.poll());
        }

        return ret;

    }

    private static List<String> solve2(String[] words, int k) {

        // 1. 그릇
        Map<String, Integer> map = new HashMap<>();
        Queue<Map.Entry<String, Integer>> pq = new PriorityQueue<>((a, b) -> {
            if (a.getValue() == b.getValue()) {
                return a.getKey().compareTo(b.getKey());
            } else {
                return a.getValue().compareTo(b.getValue());
            }
        });

        List<String> ret = new ArrayList<>();

        for(Map.Entry<String, Integer> entry : map.entrySet()) {
            pq.offer(entry);
        }

        while(k > 0) {
            ret.add(pq.poll().getKey());
            k--;
        }

        return ret;

    }

}
