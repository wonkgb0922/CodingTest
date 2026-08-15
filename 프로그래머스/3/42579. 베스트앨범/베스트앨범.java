import java.util.*;
import java.util.Map.*;

class Solution {
    public int[] solution(String[] genres, int[] plays) {
        int[] answer = {};
        Map<String, Integer> sum = new HashMap<>();
        Map<String, PriorityQueue<Node>> map = new HashMap<>();
        int n = plays.length;
        for(int i = 0; i < n; i++) {
            sum.put(genres[i], sum.getOrDefault(genres[i], 0) + plays[i]);
            
            map.putIfAbsent(genres[i], new PriorityQueue<>());
            map.get(genres[i]).offer(new Node(i, plays[i]));
        }
        
        PriorityQueue<Genre> pq = new PriorityQueue<>();
        for(Entry<String, Integer> entry : sum.entrySet()) {
            System.out.println(entry.getValue() + " " + entry.getKey());
            pq.offer(new Genre(entry.getValue(), entry.getKey()));
        }
        List<Integer> res = new ArrayList<>();
        while(!pq.isEmpty()) {
            String name = pq.poll().name;
            PriorityQueue<Node> nodepq = map.get(name);
            res.add(map.get(name).poll().idx);
            if(!nodepq.isEmpty()) res.add(map.get(name).poll().idx);
        }
        answer = new int[res.size()];
        for(int i = 0; i < res.size(); i++)
            answer[i] = res.get(i);
        return answer;
    }
}

class Genre implements Comparable<Genre> {
    public Genre(int sum, String name) {
        this.sum = sum;
        this.name = name;
    }
    public int sum;
    public String name; 
    
    @Override
    public int compareTo(Genre genre) {
        if(this.sum == genre.sum)
            return this.name.compareTo(genre.name);
        return Integer.compare(genre.sum, this.sum);
    }
}

class Node implements Comparable<Node> {
    public Node(int idx, int play) {
        this.idx = idx;
        this.play = play;
    }
    public int idx;
    public int play;
    
    @Override
    public int compareTo(Node node) {
        if(this.play == node.play)
            return Integer.compare(this.idx, node.idx);
        return Integer.compare(node.play, this.play);
    }
    
}