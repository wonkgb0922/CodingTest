import java.util.*;
import java.io.*;

class Main
{
	public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        int cnt = 0, cur = 0;
        int n = Integer.parseInt(br.readLine());
        ArrayList<Meeting> l = new ArrayList<>();
        for(int i = 0; i < n; i++) {
        	st = new StringTokenizer(br.readLine());
        	l.add(new Meeting(Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken())));
        }
        Collections.sort(l);
        for(Meeting m : l) {
        	if(cur <= m.s) {
        		cnt++;
        		cur = m.e;
        	}
        }
        System.out.println(cnt);
       
    }
}
class Meeting implements Comparable<Meeting> {
	int s;
	int e;
	Meeting(int s, int e) {
		this.s = s;
		this.e = e;
	}
	@Override
	public int compareTo(Meeting o) {
		int ret = Integer.compare(this.e, o.e);
		return (ret == 0) ? Integer.compare(this.s, o.s) : ret;
	}
}
