import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int k = Integer.parseInt(st.nextToken());
        Pair[] p = new Pair[6];
        boolean visited[] = new boolean[4];
        int d, v, idx = 0, i, stt = 0;
        
        for(i = 0 ; i < 6 ; i++) {
        	st = new StringTokenizer(br.readLine());
        	d = Integer.parseInt(st.nextToken()) - 1;
        	v = Integer.parseInt(st.nextToken());
        	p[idx++] = new Pair(d, v);
        	if(visited[d])
        		stt = i;
        	visited[d] = !visited[d];
        }
        for(i = (stt + 1) % 6; i < 6; i = (i + 1) % 6) {
        	if(visited[p[i].first]) break;
        }
        int area = p[i].second;
        i = (i + 1) % 6;
        area *= p[i].second;
        i = (i + 2) % 6;
        int v1 = p[i].second;
        i = (i + 1) % 6;
        int v2 = p[i].second;	
        
        area -= v1 * v2;        
        area *= k;
        System.out.println(area);
        br.close();
    }
}
class Pair {
	int first;
	int second;
	Pair(int first, int second) {
		this.first = first;
		this.second = second;
	}
}