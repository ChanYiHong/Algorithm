package PermutationCombination;

import java.util.*;

public class 후보키 {

    class Solution {

        private List<String> combi;
        private List<List<String>> candidateKeys; // List가 List에 포함이 되는지 알기 위한 containsAll을 쓰기위해 이중 List로 선언했다. Column 번호를 pattern으로 지정(예시 : 01, 013) 해서 후보키를 만들고, 이것이 최소성을 가지는 지는 현재 Column pattern을 String List로 만들어서.. (예 : 013을 List<String> 안에 "0", "1", "3" 으로) 현재 candidateKeys에 "0", "1" 이라는 List가 있다면 이는 더 최소인 후보키가 이미 존재한다는 뜻이므로 (0 1 3(현재 후보키) 안에 0 1 (이미 있는 후보키)이 포함됨) candidateKey에 포함안시킴.
        private int colLen;
        private int rowLen;

        public void makeCombiString(List<Integer> list) {
            StringBuilder sb = new StringBuilder();

            for(int n : list) {
                sb.append(Integer.toString(n));
            }
            combi.add(sb.toString());
        }

        public void combination(int[] colIndex, List<Integer> list, boolean[] visited, int start, int r) {

            if(r == list.size()) {
                makeCombiString(list);
                return;
            }

            for(int i = start; i < colIndex.length; i++) {
                if(!visited[i]) {
                    visited[i] = true;
                    list.add(colIndex[i]);
                    combination(colIndex, list, visited, i + 1, r);
                    list.remove(list.size() - 1);
                    visited[i] = false;
                }
            }

        }

        public void makeTuple(String[][] relation, String pattern) {

            String[] colStr = pattern.split("");
            List<Integer> colList = new ArrayList<>();
            for(String col : colStr) {
                colList.add(Integer.parseInt(col));
            }

            Set<String> tuple = new HashSet<>();

            for(int i = 0; i < relation.length; i++) {
                StringBuilder sb = new StringBuilder();
                for(int j = 0; j < colLen; j++) {
                    if(colList.contains(j)) {
                        sb.append(relation[i][j] + " ");
                    }
                }
                tuple.add(sb.toString());
            }

            if(tuple.size() == rowLen) {
                checkMinimality(pattern);
            }

        }

        public void checkMinimality(String pattern) {

            List<String> patternList = Arrays.asList(pattern.split(""));

            for(int i = 0; i < candidateKeys.size(); i++) {
                if(patternList.containsAll(candidateKeys.get(i))) {
                    return;
                }
            }

            candidateKeys.add(patternList);

        }

        public int solution(String[][] relation) {
            int answer = 0;
            colLen = relation[0].length;
            rowLen = relation.length;
            combi = new ArrayList<>();
            candidateKeys = new ArrayList<>();
            int[] colIndex = new int[colLen];

            for(int i = 0; i < colLen; i++) {
                colIndex[i] = i;
            }

            for(int i = 1; i <= colLen; i++) {
                combination(colIndex, new ArrayList<>() ,new boolean[colLen], 0, i);
            }

            for(String str : combi) {
                makeTuple(relation, str);
            }

            return answer = candidateKeys.size();
        }
    }

}
