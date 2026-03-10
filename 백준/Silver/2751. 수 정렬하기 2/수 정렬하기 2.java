import java.io.*;
import java.util.*;
 
public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        int n = Integer.parseInt(br.readLine());
        PriorityQueue<Integer> pq = new PriorityQueue<>();
        for(int i = 0; i < n; i++)
        	pq.offer(Integer.parseInt(br.readLine()));
        while(!pq.isEmpty())
        	sb.append(pq.poll()).append("\n");
        
        System.out.println(sb);
    }
}