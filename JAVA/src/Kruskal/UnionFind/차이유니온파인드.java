package Kruskal.UnionFind;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class 차이유니온파인드 {

    public static void main(String[] args) throws IOException {

//        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
//        StringTokenizer st = new StringTokenizer(bf.readLine());

        int n = 100;

        int[] parent = new int[n + 1];
        for (int i = 1; i < n + 1; i++) {
            parent[i] = i;
        }

        int[] arr1 = {
                30
                ,49
                ,33
                ,79
                ,61
                ,13
                ,73
                ,1
                ,23
                ,14
                ,22
                ,1
                ,38
                ,82
                ,80
                ,75
                ,45
                ,64
                ,3
                ,19
                ,67
                ,68
                ,40
                ,10
                ,53
                ,37
                ,2
                ,47
                ,75
                ,49
                ,83
                ,63
                ,43
                ,8
                ,70
                ,37
                ,44
                ,41
                ,3
                ,34
                ,36
                ,23
                ,75
                ,13
                ,29
                ,53
                ,11
                ,60
                ,55
                ,22
                ,4
                ,48
                ,44
                ,21
                ,82
                ,69
                ,18
                ,77
                ,64
                ,19
                ,36
                ,61
                ,77
                ,65
                ,69
                ,4
                ,21
                ,78
                ,59
                ,43
                ,32
                ,30
                ,84
                ,70
                ,77
                ,17
                ,28
                ,21
                ,60
                ,67
                ,5
                ,44
                ,12, 57};
        int[] arr2 = {62
                ,19
                ,5
                ,83
                ,56
                ,78
                ,18
                ,35
                ,72
                ,33
                ,21
                ,8
                ,54
                ,6
                ,57
                ,46
                ,40
                ,10
                ,61
                ,51
                ,42
                ,51
                ,12
                ,47
                ,52
                ,67
                ,26
                ,23
                ,17
                ,52
                ,3
                ,81
                ,8
                ,68
                ,41
                ,52
                ,83
                ,48
                ,31
                ,62
                ,44
                ,38
                ,1
                ,71
                ,56
                ,33
                ,8
                ,37
                ,24
                ,26
                ,57
                ,20
                ,22
                ,14
                ,51
                ,40
                ,47
                ,20
                ,23
                ,27
                ,20
                ,13
                ,32
                ,78
                ,82
                ,51
                ,77
                ,65
                ,52
                ,5
                ,15
                ,69
                ,69
                ,7
                ,58
                ,20
                ,12
                ,28
                ,31
                ,76
                ,82
                ,64
                ,4
                ,29};
        String[] order = {"Friend", "Total", "Friend"
                ,"Total"
                ,"Friend"
                ,"Total"
                ,"Friend"
                ,"Total"
                ,"Friend"
                ,"Total"
                ,"Friend"
                ,"Total"
                ,"Friend"
                ,"Total"
                ,"Friend"
                ,"Total"
                ,"Friend"
                ,"Total"
                ,"Friend"
                ,"Total"
                ,"Friend"
                ,"Total"
                ,"Friend"
                ,"Total"
                ,"Friend"
                ,"Total"
                ,"Friend"
                ,"Total"
                ,"Friend"
                ,"Total"
                ,"Friend"
                ,"Total"
                ,"Friend"
                ,"Total"
                ,"Friend"
                ,"Total"
                ,"Friend"
                ,"Total"
                ,"Friend"
                ,"Total"
                ,"Friend"
                ,"Total"
                ,"Friend"
                ,"Total"
                ,"Friend"
                ,"Total"
                ,"Friend"
                ,"Total"
                ,"Friend"
                ,"Total"
                ,"Friend"
                ,"Total"
                ,"Friend"
                ,"Total"
                ,"Friend"
                ,"Total"
                ,"Friend"
                ,"Total"
                ,"Friend"
                ,"Total"
                ,"Friend"
                ,"Total"
                ,"Friend"
                ,"Total"
                ,"Friend"
                ,"Total"
                ,"Friend"
                ,"Total"
                ,"Friend"
                ,"Total"
                ,"Friend"
                ,"Total"
                ,"Friend"
                ,"Total"
                ,"Friend"
                ,"Total"
                ,"Friend"
                ,"Total"
                ,"Friend"
                ,"Total"
                ,"Friend"
                ,"Total"
                ,"Friend"
                ,"Total"};



        for (int i = 0; i < order.length; i++) {
            if (order[i].equals("Friend")) {
                union(arr1[i], arr2[i], parent);
                System.out.println("합치기 연산 : " + arr1[i] + ", " + arr2[i]);
            }
            if (order[i].equals("Total")) {
                parentSet(parent);
                int totalA = findGroupTotal(arr1[i], parent);
                int totalB = findGroupTotal(arr2[i], parent);
                System.out.println("total : " + arr1[i] + ", " + arr2[i] + " " + (totalA + totalB));
            }
        }

    }

    private static void parentSet(int[] parent) {
        for (int i = 1; i < parent.length; i++) {
            parent[i] = findParent(i, parent);
        }
    }

    private static int findGroupTotal(int x, int[] parent) {
        int myParent = findParent(x, parent);
        int ret = 0;

        for (int i = 1; i < parent.length; i++) {
            if (parent[i] == myParent) ret++;
        }
        return ret;
    }

    public static void union(int x, int y, int[] parent) {
        int a = findParent(x, parent);
        int b = findParent(y, parent);

        if (a != b) {
            if (a > b) {
                parent[a] = b;
            } else {
                parent[b] = a;
            }
        }
    }

    public static int findParent(int x, int[] parent) {
        if (parent[x] != x) {
            return parent[x] = findParent(parent[x], parent);
        }
        return parent[x];
    }

}

