import java.util.Stack;

class Solution {
    public int solution(int[][] board, int[] moves) {
        int answer = 0;
        int len = moves.length;
        int height = board.length;

        Stack<Integer> basket = new Stack<>();

        for(int i = 0; i < len; i++){
            int position = moves[i]-1;
            int item = 0;
            for(int j = 0; j < height; j++){
                if(board[j][position] == 0) continue;
                else{
                    item = board[j][position];
                    board[j][position] = 0;
                    break;
                }
            }
            if(item == 0) continue;
            if(basket.empty()){
                basket.push(item);
                continue;
            }
            if(basket.peek() == item){
                answer = answer + 2;
                basket.pop();
            } else{
                basket.push(item);
            }
        }

        return answer;
    }
}