package programmers;

import java.util.Map;
import java.util.HashMap;
import java.util.Set;
import java.util.HashSet;
import java.util.List;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Iterator;

public class 베스트앨범 {

    static class Song {
        private int index;
        private int cnt;

        public Song(int index, int cnt) {
            this.index = index;
            this.cnt = cnt;
        }

        public int getIndex() {
            return index;
        }
        public int getCnt() {
            return cnt;
        }
    }

    public int[] solution(String[] genres, int[] plays) {
        int[] answer;

        Set<String> genreSet = new HashSet<>();
        Map<String, List<Song>> genreMap = new HashMap<>();

        for (int i = 0; i < genres.length; i++) {
            genreSet.add(genres[i]);
        }

        for (int i = 0; i < genres.length; i++) {

            String genreName = genres[i];

            if(!genreMap.containsKey(genreName)) {
                genreMap.put(genreName, new ArrayList<>());
            }
            genreMap.get(genreName).add(new Song(i, plays[i]));

        }

        // 빼서 정렬
        List<Integer> scoreCntList = new ArrayList<>();
        Map<Integer, List<Song>> scoreCntMap = new HashMap<>();
        Iterator<String> iter = genreSet.iterator();

        while(iter.hasNext()) {
            String genreName = iter.next();

            int cnt = genreMap.get(genreName).stream().mapToInt(Song::getCnt).sum();
            scoreCntList.add(cnt);
            scoreCntMap.put(cnt, genreMap.get(genreName));
        }

        Collections.sort(scoreCntList, (a, b) -> {
            return Integer.compare(b, a);
        });

        List<Integer> ans = new ArrayList<>();

        for (int i = 0; i < scoreCntList.size(); i++) {
            int cnt = scoreCntList.get(i);
            List<Song> songList = scoreCntMap.get(cnt);

            Collections.sort(songList, (a, b) -> {
                return Integer.compare(b.getCnt(), a.getCnt());
            });

            if (songList.size() == 1) {
                ans.add(songList.get(0).getIndex());
                continue;
            }

            if (songList.get(0).getCnt() == songList.get(1).getCnt()) {
                if (songList.get(0).getIndex() < songList.get(1).getIndex()) {
                    ans.add(songList.get(0).getIndex());
                    ans.add(songList.get(1).getIndex());
                } else {
                    ans.add(songList.get(0).getIndex());
                    ans.add(songList.get(1).getIndex());
                }
                continue;
            }

            ans.add(songList.get(0).getIndex());
            ans.add(songList.get(1).getIndex());
        }

        answer = ans.stream().mapToInt(Integer::intValue).toArray();
        return answer;
    }

}
