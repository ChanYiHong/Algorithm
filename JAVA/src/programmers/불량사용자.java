package programmers;

import java.util.*;

/** Set 사용법들.. HashSet TreeSet LinkedHashSet 차이
 *  그리고 DFS로 완탐 하는 법..
 *  어짜피 모두 확인해서 1:1 비교 하는 법 등.. 배울게 많았다.**/

public class 불량사용자 {

    class Solution {

        Set<Set<String>> caseSet;

        public void makeCase(String[] user_id, String[] banned_id, Set<String> curSet) {

            // 탈출 조건.
            if(curSet.size() == banned_id.length) {
                if(isBanned(banned_id, curSet)) {
                    caseSet.add(new HashSet<>(curSet));
                }
                return;
            }

            // 반복.
            for(int i = 0; i < user_id.length; i++) {
                if(!curSet.contains(user_id[i])){
                    curSet.add(user_id[i]);
                    makeCase(user_id, banned_id, curSet);
                    curSet.remove(user_id[i]);
                }
            }

        }

        public boolean isBanned(String[] banned_id, Set<String> curSet) {

            int i = 0;

            // LinkedHashSet : 저장된 순서대로 저장.
            for(String s : curSet) {
                if(!isMatch(s, banned_id[i++])) {
                    return false;
                }
            }

            return true;

        }

        public boolean isMatch(String a, String b) {

            if(a.length() != b.length()) {
                return false;
            }

            for(int i = 0; i < a.length(); i++) {
                if(b.charAt(i) == '*'){
                    continue;
                }
                if(a.charAt(i) != b.charAt(i)) {
                    return false;
                }
            }

            return true;

        }

        public int solution(String[] user_id, String[] banned_id) {
            int answer = 0;

            caseSet = new HashSet<>();
            makeCase(user_id, banned_id, new LinkedHashSet<>());

            return caseSet.size();
        }
    }

}
