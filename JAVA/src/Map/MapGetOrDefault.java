package Map;

import java.util.HashMap;
import java.util.Map;

public class MapGetOrDefault {

    public static void main(String[] args) {
        String str = "inflearninlove";
        System.out.println(solve(str));
    }

    private static int solve(String str) {

        if(str == null || str.length() == 0) return -1;

        Map<Character, Integer> map = new HashMap<>();
        int index = 0;

        for(char c : str.toCharArray()) {
            // c가 존재하면 c의 value를 가져와서 + 1, c가 존재하지 않으면 0을 가져와서 + 1
            map.put(c, map.getOrDefault(c, 0) + 1);
        }

        for(char c : str.toCharArray()) {
            System.out.println(map.get(c));
            if(map.get(c) == 1){
                return index;
            }
            index++;
        }

        return -1;
    }
}
