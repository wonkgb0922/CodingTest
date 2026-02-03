import java.io.*;

public class Solution {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        
        int T = Integer.parseInt(br.readLine());
        int n, i, h;
        String[] deck;
        for(int t = 1; t <= T; t++) {
        	n = Integer.parseInt(br.readLine());
        	deck = br.readLine().split(" ");
        	i = 0;
        	h = n / 2 + n % 2;
        	sb.append("#").append(t).append(" ");
        	for(; i + h < n; i++) {
        		sb.append(deck[i]).append(" ").append(deck[i + h]).append(" ");
        	}
        	if(n % 2 == 1)
        		sb.append(deck[i]).append(" ");
        	sb.append("\n");
        }
        System.out.println(sb);
        br.close();
    }
}
