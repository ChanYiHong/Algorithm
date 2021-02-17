package Array;

public class MathMax {

    public static void main(String[] args) {
        int[] arr = {8,2,6,5,1,7,5};
        System.out.println(solve(arr));
    }

    private static int solve(int[] arr) {

        if(arr.length == 0) return 0;

        int max = 0;
        // 지금까지 가장 작은 값.
        int soFarMin = arr[0];

        // 쭉 가다가 자기보다 작은 값 나오면 바꿔치기 한다.
        // 어짜피 max 값 비교를 하기 떄문에 나중에 저점 찾고 거기서 그다음에 고점에서의 차이를 보는 느낌
        for(int i = 0; i < arr.length; i++) {
            if(soFarMin > arr[i]) {
                soFarMin = arr[i];
            } else{
                max = Math.max(max, arr[i] - soFarMin);
            }
        }

        return max;
    }
}
