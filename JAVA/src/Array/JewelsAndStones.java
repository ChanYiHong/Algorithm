package Array;

import java.util.HashSet;
import java.util.Set;

public class JewelsAndStones {

    public static void main(String[] args) {
        String stone = "aAAbbbb";
        String Jewel = "aA";

        System.out.println(solve(stone, Jewel));
    }

    private static int solve(String stone, String jewel) {
        Set<Character> set = new HashSet<>();
        int cnt = 0;

        for(Character c : jewel.toCharArray()) {
            set.add(c);
        }

        for(Character c : stone.toCharArray()) {
            if(set.contains(c)){
                cnt++;
            }
        }

        return cnt;
    }
}
