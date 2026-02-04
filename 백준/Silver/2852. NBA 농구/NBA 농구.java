import java.io.*;
import java.util.*;
 
public class Main {
	static List<Integer>[] map;
	static boolean visited[];
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        
        StringTokenizer st;
        int n = Integer.parseInt(br.readLine());
        int win[] = new int[2];
        int curM = 0, curS = 0, m, s, m1 = 0, s1 = 0, m2 = 0, s2 = 0;
        
        while(n-- > 0) {
        	st = new StringTokenizer(br.readLine());
        	int num = Integer.parseInt(st.nextToken()) - 1;
        	String[] time = st.nextToken().split(":");
        	m = Integer.parseInt(time[0]);
        	s = Integer.parseInt(time[1]);
        	
        	if(win[0] > win[1]) {
        		m1 += m - curM;
        		s1 += s - curS;
        	}
        	else if(win[0] < win[1]) {
        		m2 += m - curM;
        		s2 += s - curS;
        	}
        	curM = m;
        	curS = s;
        	win[num]++;
        }
        if(win[0] > win[1]) {
    		m1 += 48 - curM;
    		s1 += -curS;
    	}
    	else if(win[0] < win[1]) {
    		m2 += 48 - curM;
    		s2 += -curS;
    	}
        m1 += s1 / 60;
        s1 %= 60;
        m2 += s2 / 60;
        s2 %= 60;
        if(s1 < 0) {
        	m1 -= 1;
        	s1 += 60;
        }
        if(s2 < 0) {
        	m2 -= 1;
        	s2 += 60;
        }
        System.out.printf("%02d:%02d\n", m1, s1);
        System.out.printf("%02d:%02d", m2, s2);
    }
}