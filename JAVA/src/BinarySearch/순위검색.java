package BinarySearch;

import java.util.Map;
import java.util.HashMap;
import java.util.List;
import java.util.ArrayList;
import java.util.Collections;

public class 순위검색 {

    static Map<String, List<Integer>> cases;
    static List<Integer> scoreList;

    public void makeCases(String combination, int depth, String[] infos) {

        // 탈출 조건. depth가 4 (모든 경우 끝까지 다 봤을 때 map에 추가)
        if (depth == 4) {

            if(!cases.containsKey(combination)) {
                scoreList = new ArrayList<>();
                scoreList.add(Integer.parseInt(infos[4]));
                cases.put(combination, scoreList);
            }
            else {
                cases.get(combination).add(Integer.parseInt(infos[4]));
            }

            return;

        }

        // 포함 하는 경우
        makeCases(combination + infos[depth], depth + 1, infos);
        // 포함 안하는 경우
        makeCases(combination + "-", depth + 1, infos);

    }

    // 이분탐색
    public int search(String query, int score) {

        if (!cases.containsKey(query)) return 0;

        List<Integer> list = cases.get(query);
        int left = 0;
        int right = list.size() - 1;

        while(left <= right) {

            int mid = (left + right) / 2;

            if (list.get(mid) < score) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }

        }

        return list.size() - left;

    }

    public int[] solution(String[] info, String[] query) {
        int[] answer = new int[query.length];
        cases = new HashMap<>();

        // 조합 만들기
        for (int i = 0; i < info.length; i++) {
            makeCases("", 0, info[i].split(" "));
        }

        // 정렬 (map에 저장된 각 점수들을 오름차순 정렬)
        List<String> keySets = new ArrayList<>(cases.keySet());
        for (String key : keySets) {
            List<Integer> list = cases.get(key);
            Collections.sort(list);
        }

        // sorting한 점수를 가지고 이분 탐색사용해서 특정 조건에 특정 점수 이상인 사람을 찾음
        for (int i = 0; i < query.length; i++) {
            query[i] = query[i].replaceAll(" and ", "");
            String[] strs = query[i].split(" ");
            answer[i] = search(strs[0], Integer.parseInt(strs[1]));
        }

        return answer;
    }

}
