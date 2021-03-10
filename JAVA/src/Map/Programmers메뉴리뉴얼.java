package Map;

import java.util.*;

public class Programmers메뉴리뉴얼 {

    Map<String, Integer> map = new HashMap<>();
    int max = 0;

    public void saveToMap(char[] arr, boolean[] visited, int n) {
        StringBuilder sb = new StringBuilder();
        for(int i = 0; i < n; i++) {
            if(visited[i] == true) {
                sb.append(arr[i]);
            }
        }

        char[] charArray = sb.toString().toCharArray();
        Arrays.sort(charArray);
        String key = String.valueOf(charArray);

        map.put(key, map.getOrDefault(key, 0) + 1);
        if(map.get(key) > max) {
            max = map.get(key);
        }
    }

    public void combination(char[] arr, boolean[] visited, int index, int n, int r) {
        if(r == 0) {
            saveToMap(arr, visited, n);
        }

        for(int i = index; i < n; i++) {
            visited[i] = true;
            combination(arr, visited, i + 1, n, r - 1);
            visited[i] = false;
        }
    }

    public String[] solution(String[] orders, int[] course) {

        List<String> answer = new ArrayList<>();

        for(int i = 0; i < course.length; i++) {
            for(int j = 0; j < orders.length; j++) {
                char[] charArray = orders[j].toCharArray();
                int n = charArray.length;
                int r = course[i];
                boolean[] visited = new boolean[n];

                combination(charArray, visited, 0, n, r);
            }

            for(String key : map.keySet()) {
                if(map.get(key) > 1 && map.get(key) == max) {
                    answer.add(key);
                }
            }

            max = 0;
            map.clear();
        }

        Collections.sort(answer);

        return answer.stream().toArray(String[]::new);
    }


}
