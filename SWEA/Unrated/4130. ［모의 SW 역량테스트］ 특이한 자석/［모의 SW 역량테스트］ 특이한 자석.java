import java.util.*;
import java.io.*;

class Solution
{
	static int gear[] = new int[4];
	static boolean visited[] = new boolean[4];;
	static void rotateGear(int idx, boolean isClockwise) {
		visited[idx] = true;
		
		if(idx > 0) {
			if(!visited[idx - 1]) {
				if(((gear[idx - 1] >> 2) & 1) != ((gear[idx] >> 6) & 1))
					rotateGear(idx - 1, !isClockwise);
			}
		}
		if(idx < 3) {
			if(!visited[idx + 1]) {
				if(((gear[idx + 1] >> 6) & 1) != ((gear[idx] >> 2) & 1))
					rotateGear(idx + 1, !isClockwise);
			}
		}
		if(isClockwise)
			gear[idx] = ((gear[idx] << 1) | ((gear[idx] >> 7) & 1));
		else
			gear[idx] = ((gear[idx] >> 1) | ((gear[idx] & 1) << 7));
		visited[idx] = false;
	}
	
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        StringBuilder sb = new StringBuilder();
        int T = Integer.parseInt(br.readLine());
        int k, res;
        for(int t = 1; t <= T; t++) {
        	res = 0;
        	k = Integer.parseInt(br.readLine());
        	for(int i = 0; i < 4; i++)
        		gear[i] = 0;
        	
        	for(int i = 0; i < 4; i++) {
        		st = new StringTokenizer(br.readLine());
        		for(int j = 0; j < 8; j++) {
        			if(Integer.parseInt(st.nextToken()) == 1)
        				gear[i] |= 1 << j;
        		}
        	}
        	while(k-- > 0) {
        		st = new StringTokenizer(br.readLine());
        		int i = Integer.parseInt(st.nextToken());
        		boolean isClockwise = (Integer.parseInt(st.nextToken()) > 0) ? true : false;
        		rotateGear(i - 1, isClockwise);
        	}
        	for(int i = 0; i < 4; i++)
        		res += (gear[i] & 1) * (1 << i);
        	sb.append("#").append(t).append(" ").append(res).append("\n");
        }
        System.out.println(sb);       
    }
}