package Sort;

public class CompareTo {

    public static void main(String[] args) {
        String version1 = "8.5.2.4", version2 = "8.5.3";
        System.out.println(solve(version1, version2));
    }

    public static int compareToTest(Integer a, Integer b) {
        return a.compareTo(b);
        // a 가 크면 1
        // a 가 작으면 -1
        // 같으면 0
    }

    private static int solve(String v1, String v2) {

        //1. String Class의 split method를 통해서 .을 기준으로 String 배열로 리턴받음.
        String[] split1 = v1.split(".");
        String[] split2 = v2.split(".");

        //2.
        int length = Math.max(split1.length, split2.length);
        for (int i = 0; i < length; i++) {

            Integer v1Int = i < split1.length ? Integer.parseInt(split1[i]) : 0;
            Integer v2Int = i < split2.length ? Integer.parseInt(split2[i]) : 0;

            int comp = v1Int.compareTo(v2Int);
            if (comp != 0) {
                return comp;
            }
        }

        return 0;
    }
}
