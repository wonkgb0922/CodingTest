import java.util.*;
import java.io.*;

class Solution
{
    static int price[] = new int[4];
    static int month[] = new int[12];
    static int dp[] = new int[12];
	public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        StringBuilder sb = new StringBuilder();
        int T = Integer.parseInt(br.readLine());
        int res;
        for(int t = 1; t <= T; t++) {
        	res = 0;
        	PriorityQueue<int[]> pq = new PriorityQueue<int[]>((o1, o2) -> {
        		return Integer.compare(o2[0], o1[0]);
        	});
        	st = new StringTokenizer(br.readLine());
        	for(int i = 0; i < 4; i++)
        		price[i] = Integer.parseInt(st.nextToken());
        	st = new StringTokenizer(br.readLine());
        	for(int i = 0; i < 12; i++) {
        		dp[i] = -1;
        		month[i] = Integer.parseInt(st.nextToken());
        	}
        	sb.append(String.format("#%d %d\n", t, Math.min(sol(11), price[3])));
        }
        System.out.println(sb);
    }
	static int sol(int idx) {
		if(idx == 0) return Math.min(month[0] * price[0], price[1]);
		else if(idx < 0) return 0;
		if(dp[idx] > -1) return dp[idx];
		// 자기를 1일권으로
		// 자기를 1달권으로
		// 자기를 끝 달로 포함하여 3달권으로
		int oneDay = sol(idx - 1) + (month[idx] * price[0]);
		int oneMonth = sol(idx - 1) + price[1];
		int threeMonth = 1000000000;
		if(idx >= 2) {
			threeMonth = sol(idx - 3) + price[2];
		}
		dp[idx] = Math.min(Math.min(oneDay, oneMonth), threeMonth);
		return dp[idx];
	}
}
