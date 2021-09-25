package Simulation;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class 럭키스트레이트 {

    public static void main(String[] args) throws IOException {
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(bf.readLine());

        int n = Integer.parseInt(st.nextToken());

        String str = Integer.toString(n);

        int left = 0;
        int right = 0;

        for (int i = 0; i < str.length() / 2; i++) {
            char c = str.charAt(i);
            left += c - '0';
        }
        for (int i = str.length() / 2; i < str.length(); i++) {
            char c = str.charAt(i);
            right += c - '0';
        }

        if (left == right) System.out.println("LUCKY");
        else System.out.println("READY");
    }
}
