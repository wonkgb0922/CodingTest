import java.io.*;
import java.util.*;
 
public class Main {
	static long cnt;
	static int[] ary;
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        ary = new int[n];
        int in;
        
        StringTokenizer st = new StringTokenizer(br.readLine());
        for(int i = 0; i < n; i++) {
        	in = Integer.parseInt(st.nextToken());
        	ary[i] = in;
        }
        ArrayList<Integer> ret = sort(0, n - 1);
        System.out.println(cnt);
    }
    static ArrayList<Integer> sort(int s, int e) {
    	ArrayList<Integer> ret = new ArrayList<>();
    	if(s == e) {
    		ret.add(ary[s]);
    		return ret;
    	}
    	int mid = (s + e) / 2;
    	ArrayList<Integer> a = sort(s, mid);
    	ArrayList<Integer> b = sort(mid + 1, e);
    	int l = 0, r = 0;
    	long c = 0;
    	while(l < a.size() && r < b.size()) {
    		if(a.get(l) <= b.get(r)) {
    			ret.add(a.get(l++));
    			cnt += c;
    		}
    		else if(a.get(l) > b.get(r)){
    			c++;
    			ret.add(b.get(r++));
    		}
    	}
    	while(l < a.size()) {
    		cnt += c;
			ret.add(a.get(l++));
    	}
    	while(r < b.size())
			ret.add(b.get(r++));
    	
    	return ret;
    }
}