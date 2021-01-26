package DoItJavaAlgorithm.Chapter2;

public class ReverseArray {

    static void swap(int[] a, int indexA, int indexB){
        int temp = a[indexA];
        a[indexA] = a[indexB];
        a[indexB] = temp;
    }

    static void reverse(int[] a){
        for(int i = 0; i < a.length / 2; i++) {
            swap(a, i, a.length - 1 - i);
        }
    }

    public static void main(String[] args) {
        int[] arr = new int[]{1,2,3,4,5};
        reverse(arr);
        for (int i : arr) {
            System.out.println(i);
        }
    }

}
