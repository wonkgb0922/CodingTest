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
        int x, y, res;
        for(int t = 1; t <= T; t++) {
        	st = new StringTokenizer(br.readLine());
        	n = Integer.parseInt(st.nextToken());
        	x = Integer.parseInt(st.nextToken());
        	res = 0;
        	min.clear();
        	max.clear();
        	min.offer(x);
        	for(int i = 0; i < n; i++) {
        		st = new StringTokenizer(br.readLine());
        		x = Integer.parseInt(st.nextToken());
        		y = Integer.parseInt(st.nextToken());
        		if(x > y) {
        			min.offer(x);
        			max.offer(y);
        		}
        		else {
        			min.offer(y);
        			max.offer(x);
        		}
        		x = min.peek();
        		y = max.peek();
        		if(x < y) {
        			min.poll();
        			max.poll();
        			min.offer(y);
        			max.offer(x);
        		}
        		
        		res += min.peek() % 20171109;
                res %= 20171109;
        	}
        	sb.append(String.format("#%d %d\n", t, res));
        }
        System.out.println(sb);
    }
}