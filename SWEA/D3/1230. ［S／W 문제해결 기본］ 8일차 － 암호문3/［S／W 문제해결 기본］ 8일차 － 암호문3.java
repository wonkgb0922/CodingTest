import java.util.*;
import java.io.*;

class Solution
{
	public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        StringTokenizer st;
        int T = 10;
        int n, m, x, y, k;
        String command;

        LinkedList<Integer> l = new LinkedList<Integer>();
        LinkedList<Integer> l2 = new LinkedList<Integer>();
        
        for(int t = 1; t <= T; t++) {
        	l.clear();
        	n = Integer.parseInt(br.readLine());
        	st = new StringTokenizer(br.readLine());
        	for(int i = 0; i < n; i++)
        		l.addLast(Integer.parseInt(st.nextToken()));
        	m = Integer.parseInt(br.readLine());
        	st = new StringTokenizer(br.readLine());
        	while(m-- > 0) {
        		command = st.nextToken();
            	if(command.charAt(0) == 'I') {
                	x = Integer.parseInt(st.nextToken());
                	y = Integer.parseInt(st.nextToken());
            		while(y-- > 0)
            			l2.add(Integer.parseInt(st.nextToken()));
            		l.addAll(x, l2);
            		l2.clear();
            	}
            	else if(command.charAt(0) == 'D') {
                	x = Integer.parseInt(st.nextToken()) - 1;
            		ListIterator<Integer> it = l.listIterator(x);
            		y = Integer.parseInt(st.nextToken());
            		while(y-- > 0 && it.hasNext()) {
                		it.next();
            			it.remove();
            		}
            	}
            	else if(command.charAt(0) == 'A') {
            		y = Integer.parseInt(st.nextToken());
            		while(y-- > 0) {
            			l.addLast(Integer.parseInt(st.nextToken()));
            		}
            	}
        	}
        	sb.append("#").append(t).append(" ");
        	k = 0;
        	for(int it : l) {
        		sb.append(it).append(" ");
        		if(k++ >= 9) break;        		
        	}
        	
        	sb.append("\n");
        }
        System.out.println(sb);
    }
}