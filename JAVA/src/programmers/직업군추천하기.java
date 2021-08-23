package programmers;

import java.util.Map;
import java.util.HashMap;

public class 직업군추천하기 {

    static Map<String, Integer> scoreMap;

    public String solution(String[] table, String[] languages, int[] preference) {
        String answer = "";
        int totalScore = 0;

        for (String t : table) {

            scoreMap = new HashMap<>();

            String[] column = t.split(" ");

            String job = column[0];
            scoreMap.put(column[1], 5);
            scoreMap.put(column[2], 4);
            scoreMap.put(column[3], 3);
            scoreMap.put(column[4], 2);
            scoreMap.put(column[5], 1);

            int curScore = 0;

            for (int i = 0; i < languages.length; i++) {
                int score = scoreMap.getOrDefault(languages[i], 0);
                curScore += score * preference[i];
            }

            if (totalScore == curScore) {
                if (answer.compareTo(job) > 0) {
                    answer = job;
                }
            } else if (totalScore < curScore) {
                totalScore = curScore;
                answer = job;
            }
        }
        return answer;
    }

}
