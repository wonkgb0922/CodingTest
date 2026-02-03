import java.io.*;

public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        
        int n, i, h;
        String[] deck;
        while(true) {
        	n = Integer.parseInt(br.readLine());
        	if(n == 0) break;
        	deck = new String[n];
        	for(i = 0; i < n; i++) {
        		deck[i] = br.readLine();
        	}
        	i = 0;
        	h = n / 2 + n % 2;
        	for(; i + h < n; i++) {
        		sb.append(deck[i]).append("\n").append(deck[i + h]).append("\n");
        	}
        	if(n % 2 == 1)
        		sb.append(deck[i]).append("\n");
        }
        System.out.println(sb);
        br.close();
    }
}
