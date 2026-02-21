import java.util.*;
import java.io.*;
 
class Solution
{
	static int n;
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        StringTokenizer st;
        int T = Integer.parseInt(br.readLine());
        PriorityQueue<Integer> min = new PriorityQueue<>();
        PriorityQueue<Integer> max = new PriorityQueue<>(Collections.reverseOrder());
        int x, res;
        for(int t = 1; t <= T; t++) {
        	st = new StringTokenizer(br.readLine());
        	n = Integer.parseInt(st.nextToken());
        	x = Integer.parseInt(st.nextToken());
        	res = 0;
        	min.clear();
        	max.clear();
        	min.offer(x);
        	max.offer(x);
        	for(int i = 0; i < n; i++) {
        		st = new StringTokenizer(br.readLine());
        		for(int j = 0; j < 2; j++) {
            		x = Integer.parseInt(st.nextToken());
            		if(max.peek() < x) min.offer(x);
            		else max.offer(x);
        		}
        		while(min.size() != max.size()) {
        			if(min.size() < max.size()) {
        				max.poll();
        				min.offer(max.peek());
        			}
        			else {
        				min.poll();
        				max.offer(min.peek());
        			}
        		}
        		res += min.peek() % 20171109;
                res %= 20171109;
        	}
        	sb.append(String.format("#%d %d\n", t, res));
        }
        System.out.println(sb);
    }
}