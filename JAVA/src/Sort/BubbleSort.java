package Sort;

public class BubbleSort {

    public static void main(String[] args) {
        int[] a = {2, 7, 5, 4};

        for (int i = 0; i < a.length; i++) {
            for (int j = 1; j < a.length - i; j++) {
                System.out.println((j - 1) + " 랑 " + j + " 비교..");
                if (a[j] > a[j - 1]) {
                    int temp = a[j];
                    a[j] = a[j - 1];
                    a[j - 1] = temp;
                }
            }
        }

        for (int i : a) {
            System.out.println(i);
        }

    }

}
