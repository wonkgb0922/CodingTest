import java.io.*;
import java.util.StringTokenizer;

public class Main {
	static int dir[][] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int m = Integer.parseInt(st.nextToken());
        int n = Integer.parseInt(st.nextToken());
        int k = Integer.parseInt(br.readLine());
        int val = 1, d = 0, i = 0, j = 0;
        
        int ary[][] = new int[n][m];
        if(k > n * m)
        	System.out.println(0);
        else {
        	while(val <= n * m) {
            	ary[i][j] = val++;
            	if(ary[i][j] == k)
            		break;
            	int ii = i + dir[d][0];
            	int jj = j + dir[d][1];
            	if(ii >= 0 && ii < n && jj >= 0 && jj < m) {
            		if(ary[ii][jj] > 0)
                		d = (d + 1) % 4;
            	}
            	else
            		d = (d + 1) % 4;
            	i += dir[d][0];
            	j += dir[d][1];
            }
            i++;
            j++;
            System.out.println(j + " " + i);
        }
        br.close();
    }
}
