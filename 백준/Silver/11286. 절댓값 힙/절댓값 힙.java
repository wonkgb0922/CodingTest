import java.io.*;
import java.util.*;
 
public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        int n = Integer.parseInt(br.readLine());
        int in;
        
        PriorityQueue<Integer> q = new PriorityQueue<>((o1, o2) -> {
        	int ret = Integer.compare(Math.abs(o1), Math.abs(o2));
        	return (ret == 0) ? Integer.compare(o1, o2) : ret;
        });
        
        for(int i = 0; i < n; i++) {
        	in = Integer.parseInt(br.readLine());
        	if(in == 0) {
        		if(!q.isEmpty())
            		sb.append(q.poll());
        		else
        			sb.append(0);
        		sb.append("\n");
        	}
        	else
        		q.add(in);
        }
        System.out.println(sb);
    }
}