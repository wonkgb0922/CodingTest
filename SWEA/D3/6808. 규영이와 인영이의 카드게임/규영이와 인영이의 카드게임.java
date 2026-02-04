import java.io.*;
import java.util.*;

public class Solution {
	static final int n = 9;
	static int dp[] = new int[10];
	
	static boolean visited[];
	static boolean selected[];
	
	static List<Integer> a;
	static List<Integer> validB;
	static List<Integer> b;
	static int capacity;
	
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        StringBuilder sb = new StringBuilder();
        int T = Integer.parseInt(br.readLine());
        int in, win;
        for(int t = 1; t <= T; t++) {
        	capacity = 0;
        	win = 0;
        	a = new ArrayList<Integer>();
        	st = new StringTokenizer(br.readLine());
        	validB = new ArrayList<Integer>();
        	visited = new boolean[n * 2 + 1];
        	selected = new boolean[n];
        	b = new ArrayList<Integer>();
        	for(int i = 0; i < n; i++) {
        		in = Integer.parseInt(st.nextToken());
        		visited[in] = true;
        		a.add(in);
        		capacity += in;
        	}
        	Collections.sort(a, Collections.reverseOrder());
        	for(int i = n * 2; i > 0; i--) {
        		if(!visited[i]) {
        			validB.add(i);
        			b.add(i);
        			capacity += i;
        		}
        	}
        	win += countWin(-1, 0, 0);
        	sb.append("#").append(t).append(" ").append(win).append(" ").append(getFact(n) - win).append("\n");
        }
        System.out.println(sb);
        br.close();
    }
    
    static int getFact(int num) {
    	if(num <= 2) return 1 + num / 2;
    	
    	if(dp[num] > 0)
    		return dp[num];
    	
    	return num * getFact(num - 1);
    }

    static int countWin(int idx, int aScore, int bScore) {
    	if (idx >= 0) {
        	int amount = a.get(idx) + b.get(idx);
        	if (a.get(idx) > b.get(idx))
        		aScore += amount;
        	else
        		bScore += amount;
        	
        	if(aScore > capacity / 2)
        		return getFact(n - idx - 1);
        	if(bScore > capacity / 2)
        		return 0;
    	}
    	int ret = 0;
    	for(int i = 0; i < n; i++) {
    		if(!selected[i]) {
    			selected[i] = true;
    			b.set(idx + 1, validB.get(i));
    			ret += countWin(idx + 1, aScore, bScore);
    			selected[i] = false;
    		}
    	}
    	return ret;
    }
}