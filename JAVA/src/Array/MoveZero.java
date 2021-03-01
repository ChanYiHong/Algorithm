package Array;

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;

public class MoveZero {

    public static void main(String[] args) {
        int[] arr = {0, 3, 2, 0, 7, 5};
        System.out.println(solve(arr));
    }

    private static List<Integer> solve(int[] arr) {

        List<Integer> list = new ArrayList<>();
        int zeroNum = 0;

        for(int num : arr) {
            if(num == 0) zeroNum++;
            else list.add(num);
        }

        while(zeroNum > 0) {
            list.add(0);
            zeroNum--;
        }

        return list;

    }
}
