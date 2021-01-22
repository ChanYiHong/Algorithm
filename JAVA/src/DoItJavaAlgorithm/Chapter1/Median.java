package DoItJavaAlgorithm.Chapter1;

public class Median {

    public static int median(int a, int b, int c) {
        if(a >= b) {
            if(b >= c) return b;
            else {
                if(c >= a) return a;
                else return c;
            }
        }else if(a > c) return a;
        else if(b > c) return c;
        else return b;
    }

    /**
     *
     *  a b c
     *  b >= c
     *  a > c
     *  a > b
     *
     * **/

    public static int sum(int n) {
        return (n*(n+1))/2;
    }

    public static int sumBetween(int n, int m){
        if(n > m) {
            return (n*(n+1))/2 - ((m-1)*m)/2;
        } else if(m > n) {
            return (m*(m+1))/2 - ((n-1)*n)/2;
        } else {
            return n;
        }
    }

    public static void main(String[] args) {
        System.out.println(median(1,2,3));
        System.out.println(median(2,2,3));
        System.out.println(median(2,2,2));
        System.out.println(median(4,3,2));
        System.out.println(median(5, -3,2));

        System.out.println(sum(10));

        System.out.println(sumBetween(3, 5));
        System.out.println(sumBetween(6,4));
    }

}
