package programmers;

import java.util.*;

public class 단체사진찍기 {

    class Solution {

        List<List<Character>> result;

        public void makeCase(char[] friends, String[] data , boolean[] check, List<Character> list) {

            if(list.size() == friends.length) {
                if(isCondition(data, list)) {
                    result.add(new ArrayList<>(list));
                }
                return;
            }

            for(int i = 0; i < friends.length; i++) {
                if(check[i] == false) {
                    list.add(friends[i]);
                    check[i] = true;
                    makeCase(friends, data, check, list);
                    list.remove(list.size()-1);
                    check[i] = false;
                }
            }

        }

        public boolean isCondition(String[] data, List<Character> list) {

            for(int i = 0; i < data.length; i++) {

                char first = data[i].charAt(0);
                char second = data[i].charAt(2);
                char sign = data[i].charAt(3);
                int amount = Character.getNumericValue(data[i].charAt(4));

                int firstLoc = list.indexOf(first);
                int secondLoc = list.indexOf(second);
                int distance = Math.abs(firstLoc - secondLoc) - 1;

                if(sign == '>') {

                    if(distance <= amount) {
                        return false;
                    }

                }else if(sign == '<') {

                    if(distance >= amount) {
                        return false;
                    }

                }else {

                    if(distance != amount) {
                        return false;
                    }

                }

            }

            return true;

        }

        public int solution(int n, String[] data) {

            result = new ArrayList<>();

            char[] friends = {'A', 'C', 'F', 'J', 'M', 'N', 'R', 'T'};
            List<Character> list = new ArrayList<>();
            boolean[] check = new boolean[8];

            makeCase(friends, data, check, list);

            return result.size();
        }
    }

}
