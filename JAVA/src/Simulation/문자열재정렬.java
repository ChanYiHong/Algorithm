package Simulation;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.StringTokenizer;

public class 문자열재정렬 {

    public static void main(String[] args) throws IOException {
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(bf.readLine());

        String input = st.nextToken();

        List<Character> charList = new ArrayList<>();
        List<Integer> intList = new ArrayList<>();

        for (int i = 0; i < input.length(); i++) {
            char cur = input.charAt(i);
            if (cur >= 65 && cur <= 90) {
                charList.add(cur);
            } else {
                intList.add(cur - '0');
            }
        }

        Collections.sort(charList);

        for (Character c : charList) {
            System.out.print(c);
        }
        int sum = intList.stream().mapToInt(Integer::intValue).sum();
        System.out.print(sum);

    }
}
