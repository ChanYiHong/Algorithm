package Sort;

public class InsertionSort2 {

    public static void main(String[] args) {

        int[] arr = {11 ,5,5, 8, 4, 3, 6, 1};

        for (int i = 1; i < arr.length; i++) {
            int temp = arr[i];
            int j = i - 1;
            while ((j >= 0) && arr[j] > temp) {
                arr[j + 1] = arr[j];
                j--;
            }
            arr[j + 1] = temp;

        }

        for (int i : arr) {
            System.out.println(i);
        }

    }
}


