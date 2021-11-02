package OlimPlanet;

public class Raccoon {

    public static void main(String[] args) {

        int input = 4;

        Raccoon raccoon = new Raccoon();
        System.out.println(raccoon.solve(input));

    }

    /**
     1 : 4 (2)
     2 : 6 (4)
     3 : 10 (6)
     4 : 16 (10)
     5 : 26 (16)
     6 : 42 (26)
     ...
     **/
    private static int solve(int n) {

        int adult = 2;
        int num = 2;

        for (int i = 1; i <= n; i++) {
            num += adult;
            adult = num - adult;
        }

        return num;
    }

}
