package DFSBFS;

import java.util.List;
import java.util.ArrayList;
import java.util.Queue;
import java.util.LinkedList;

public class 거리두기확인하기 {

    class Person {
        int x;
        int y;
        public Person (int x, int y) {
            this.x = x;
            this.y = y;
        }
    }

    static List<Person> persons;
    static int[] dx = new int[]{1, -1, 0, 0};
    static int[] dy = new int[]{0, 0, 1, -1};

    public void findPerson(String[] places) {

        for (int i = 0; i < places.length; i++) {
            for (int j = 0; j < places[i].length(); j++) {
                if (places[i].charAt(j) == 'P') {
                    persons.add(new Person(i, j));
                }
            }
        }
    }

    public boolean bfs(Person person, String[] places) {

        boolean ret = true;

        Queue<int[]> queue = new LinkedList<>();
        int[][] check = new int[5][5];
        queue.offer(new int[]{person.x, person.y});
        check[person.x][person.y] = 1; // 0으로 하면 다시 제자리로 돌아와버리니까 1로 해야됨...

        while(!queue.isEmpty()) {

            int[] cur = queue.poll();
            int x = cur[0];
            int y = cur[1];

            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if (nx >= 0 && nx < 5 && ny >= 0 && ny < 5 && check[nx][ny] == 0) {
                    if (places[nx].charAt(ny) == 'X') {
                        continue;
                    }
                    // 거리가 2 이하면 false.. 사람일 경우
                    if (places[nx].charAt(ny) == 'P') {
                        if (check[x][y] + 1 <= 3) {
                            return false;
                        } else {
                            check[nx][ny] = check[x][y] + 1;
                            queue.offer(new int[]{nx, ny});
                        }
                    }
                    if (places[nx].charAt(ny) == 'O') {
                        check[nx][ny] = check[x][y] + 1;
                        queue.offer(new int[]{nx, ny});
                    }
                }
            }
        }

        return ret;

    }

    public int[] solution(String[][] places) {
        int[] answer = new int[places.length];

        for (int i = 0; i < places.length; i++) {
            persons = new ArrayList<>();
            findPerson(places[i]);

            if (persons.size() == 0) {
                answer[i] = 1;
                continue;
            }

            boolean isOk = true;

            for (int j = 0; j < persons.size(); j++) {
                if (!bfs(persons.get(j), places[i])) {
                    isOk = false;
                    break;
                }
            }

            answer[i] = isOk ? 1 : 0;

        }

        return answer;
    }
}
