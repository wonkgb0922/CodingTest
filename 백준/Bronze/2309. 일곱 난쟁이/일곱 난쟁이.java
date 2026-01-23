import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        int[] ary = new int[9];
        int sum = 0;
        for(int i = 0; i < 9; i++) {
        	ary[i] = Integer.parseInt(br.readLine());
        	sum += ary[i];
        }
        Arrays.sort(ary);
        int ii=-1, jj=-1;
        for(int i = 0; i < 8; i++) {
        	for(int j = i + 1; j < 9; j++) {
        		if(sum-ary[i] - ary[j] == 100) {
        			ii = i;
        			jj = j;
        			break;
        		}
        	}
        	if(ii >= 0) break;
        }
        for(int i = 0; i < 9; i++) {
        	if(i == ii || i == jj) continue;
        	sb.append(ary[i]).append("\n");
        }
        System.out.println(sb);
    }
}