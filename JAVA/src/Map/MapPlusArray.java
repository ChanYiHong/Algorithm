package Map;

import java.util.*;

public class MapPlusArray {

    public static void main(String[] args) {
        int[] nums = {1,1,2,2,2,3,5,5,5,5};
        int k = 2;
        System.out.println(topFrequent(nums, k));
    }

    private static List<Integer> topFrequent(int[] nums, int k) {

        // 1. 담을 그릇
        Map<Integer, Integer> map = new HashMap<>();
        List<Integer>[] list = new List[nums.length];
        List<Integer> result = new ArrayList<>();

        // 2. 맵 채우기
        for(int n : nums) {
            map.put(n, map.getOrDefault(n, 0) + 1);
        }

        // 3. ArrayList를 담는 배열에 key에 해당하는 value 값을 index로 잡고, 그 index위치에 ArrayList를 만듬. 그 안에다 key를 저장.
        // 예를 들어 key값인 2가 3개고, key값인 5가 3개이면
        // List[3] 에 해당하는 ArrayList에 2와 5를 집어넣는 것!
       for(int key : map.keySet()) {
            int topFrequent = map.get(key);
            if(list[topFrequent] == null) {
                list[topFrequent] = new ArrayList<>();
            }
            list[topFrequent].add(key);
        }

       // 처음에 ArrayList들을 담는 그릇을 nums의 길이로 책정함. 왜냐면 하나의 숫자가 가장 많은 크기가 그 nums 전체가 다 똑같은 숫자일 경우니까
        // 개수가 많은 애를 차례대로 결과를 저장하는 ArrayList에 저장. result 사이즈가 k보다 작아지면 끝.
        for(int lastIndex = list.length-1; lastIndex >= 0; lastIndex--) {
            if(list[lastIndex] != null) {
                for(int i = 0; i < list[lastIndex].size() && result.size() < k; i++) {
                    result.add(list[lastIndex].get(i));
                }
            }
        }
        return result;
    }
}
