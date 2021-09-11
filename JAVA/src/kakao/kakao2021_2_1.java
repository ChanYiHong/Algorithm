package kakao;

import java.util.Map;
import java.util.HashMap;
import java.util.List;
import java.util.ArrayList;

public class kakao2021_2_1 {

    class Solution {
        public int[] solution(String[] id_list, String[] report, int k) {
            int[] answer = new int[id_list.length];

            Map<String, List<String>> reportMap = new HashMap<>();
            Map<String, Integer> reportedNumberMap = new HashMap<>();

            for (int i = 0; i < id_list.length; i++) {
                reportMap.put(id_list[i], new ArrayList<>());
                reportedNumberMap.put(id_list[i], 0);
            }

            for (int i = 0; i < report.length; i++) {
                String[] reports = report[i].split(" ");
                String reporter = reports[0];
                String illegalUser = reports[1];

                if (!reportMap.get(reporter).contains(illegalUser)) {
                    reportMap.get(reporter).add(illegalUser);
                    reportedNumberMap.put(illegalUser, reportedNumberMap.get(illegalUser) + 1);
                }
            }

            List<String> moreThanKReportedUserList = new ArrayList<>();

            for (String key : reportedNumberMap.keySet()) {

                Integer value = reportedNumberMap.get(key);
                if (value >= k) {
                    moreThanKReportedUserList.add(key);
                }

            }

            for (int i = 0; i < id_list.length; i++) {
                List<String> reportList = reportMap.get(id_list[i]);
                int receivedMailNumber = 0;

                for (int j = 0; j < moreThanKReportedUserList.size(); j++) {
                    if (reportList.contains(moreThanKReportedUserList.get(j))) {
                        receivedMailNumber++;
                    }
                }

                answer[i] = receivedMailNumber;
            }


            return answer;
        }
    }


}
