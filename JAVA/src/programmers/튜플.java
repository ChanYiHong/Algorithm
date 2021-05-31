package programmers;

import java.util.*;

public class 튜플 {

    class Data {

        public List<Integer> list;
        public int size;

        public Data(List list, int size) {
            this.list = list;
            this.size = size;
        }

        public List getList() {
            return list;
        }

        public int getSize() {
            return size;
        }

    }

    class Solution {
        public int[] solution(String s) {
            int[] answer = {};

            String[] strs = s.split("}");

            List<Data> datas = new ArrayList<>();

            // 집합을 숫자로 list에 저장, 사이즈도. 사이즈로 정렬할 예정.

            for(int i = 0; i < strs.length; i++) {

                List<Integer> list = new ArrayList<>();
                String tempNumString = "";

                for(int j = 2; j < strs[i].length(); j++) {
                    if(Character.isDigit(strs[i].charAt(j))){
                        tempNumString += strs[i].charAt(j);
                    }else if(strs[i].charAt(j) == ',') {
                        int tempNum = Integer.parseInt(tempNumString);
                        list.add(tempNum);
                        tempNumString = "";
                    }
                }

                int tempNum = Integer.parseInt(tempNumString);
                list.add(tempNum);

                Data data = new Data(list, list.size());

                datas.add(data);

            }

            // datas.sort((a, b) -> {
            //     return a.getSize() - b.getSize();
            // });

            // size 오름차순 정렬.
            Collections.sort(datas, (a, b) -> {
                return a.getSize() - b.getSize();
            });

            // 최초의 것인지 확인하기 위한 map.
            Map<Integer, Integer> checkMap = new HashMap<>();
            answer = new int[datas.size()];
            int answerIndex = 0;

            for(int i = 0; i < datas.size(); i++) {

                List<Integer> list = datas.get(i).getList();

                for(int j = 0; j < list.size(); j++) {
                    int curNum = list.get(j);

                    if(checkMap.get(curNum) == null) {
                        answer[answerIndex] = curNum;
                        answerIndex++;
                        checkMap.put(curNum, 1);
                    }
                }
            }

            return answer;
        }
    }

}
