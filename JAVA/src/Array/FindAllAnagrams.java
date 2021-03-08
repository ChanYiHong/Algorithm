package Array;

import java.util.ArrayList;
import java.util.List;

public class FindAllAnagrams {

    public static void main(String[] args) {
        String txt = "BACDGABCDA";
        String pattern = "ABCD";
        List<Integer> result = findAnagrams(txt, pattern);

        for (Integer integer : result) {
            System.out.println(integer);
        }
    }

    private static List<Integer> findAnagrams(String txt, String pattern) {

        List<Integer> ret = new ArrayList<>();

        int[] patArr = new int[256];

        for(int i = 0; i < pattern.length(); i++) {
            patArr[pattern.charAt(i)]++;
        }

        for(int i = 0; i <= txt.length() - pattern.length(); i++) {
            int[] txtArr = new int[256];
            for(int j = 0; j < pattern.length(); j++) {
                txtArr[txt.charAt(i + j)]++;
            }

            if(check(patArr, txtArr)) {
                ret.add(i);
            }
        }

        return ret;

    }

    private static boolean check(int[] patArr, int[] txtArr) {
        for(int i = 0; i < patArr.length; i++) {
            if(patArr[i] != txtArr[i]){
                return false;
            }
        }
        return true;
    }


}
