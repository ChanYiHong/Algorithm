package BinarySearch;

public class 이진탐색 {

    public static void main(String[] args) {

        int[] arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

        System.out.println(binarySearch(arr, 0, arr.length-1, 4));

    }

    private static Integer binarySearch(int[] arr, int start, int end, int findElement) {

        if (start > end) {
            return null;
        }

        int mid = (start + end) / 2;
        int midElement = arr[mid];

        if (midElement > findElement) {
            return binarySearch(arr, start, mid - 1, findElement);
        }
        else if (midElement < findElement) {
            return binarySearch(arr, mid + 1, end, findElement);
        }
        else {
            return mid;
        }

    }

}
