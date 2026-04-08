import java.io.*;
import java.util.*;
import java.util.Map.Entry;

public class Solution {
	static int n, m;
	static ArrayList<Node> student, stairs;
	static ArrayList<Integer> stairsVal, s1, s2;
	static int ans;

	public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        StringBuilder sb = new StringBuilder();
        
        int T = Integer.parseInt(br.readLine());
        int in;
        for(int tc = 1; tc <= T; tc++) {
        	n = Integer.parseInt(br.readLine());
        	m = 0;
        	student = new ArrayList<>();
        	stairs = new ArrayList<>();
        	stairsVal = new ArrayList<>();
        	s1 = new ArrayList<>();
        	s2 = new ArrayList<>();
        	ans = Integer.MAX_VALUE;
        	for(int i = 0; i < n; i++) {
        		st = new StringTokenizer(br.readLine());
        		for(int j = 0; j < n; j++) {
        			in = Integer.parseInt(st.nextToken());
        			if(in >= 1) {
        				if(in == 1) {
        					student.add(new Node(i, j));
        					m++;
        				}
        				else {
        					stairs.add(new Node(i, j));
        					stairsVal.add(in);
        				}
        			}
        		}
        	}
        	dfs(0);
        	sb.append("#").append(tc).append(" ").append(ans).append("\n");
        }
        System.out.print(sb);
    }
	
	static void dfs(int idx) {
	    if (idx == m) {
	        int time1 = simulate(new ArrayList<>(s1), stairsVal.get(0));
	        int time2 = simulate(new ArrayList<>(s2), stairsVal.get(1));
	        
	        ans = Math.min(ans, Math.max(time1, time2));
	        return;
	    }

	    s1.add(calcDistance(idx, 0));
	    dfs(idx + 1);
	    s1.remove(s1.size() - 1); 
	    s2.add(calcDistance(idx, 1));
	    dfs(idx + 1);
	    s2.remove(s2.size() - 1);
	}
	
	static int calcDistance(int studentIdx, int stairIdx) {
		Node stu = student.get(studentIdx);
		Node sta = stairs.get(stairIdx);
		return Math.abs(stu.i - sta.i) + Math.abs(stu.j - sta.j);
	}
	
	static int simulate(ArrayList<Integer> arrivals, int stairLength) {
	    if (arrivals.isEmpty()) return 0;
	    
	    Collections.sort(arrivals);
	    int[] endTimes = new int[arrivals.size()];
	    
	    for (int i = 0; i < arrivals.size(); i++) {
	        int arrivalTime = arrivals.get(i);
	        
	        if (i < 3) {
	           endTimes[i] = arrivalTime + 1 + stairLength;
	        }
	        else {
	        	int prevFinishTime = endTimes[i - 3];
	            
	        	if (arrivalTime + 1 < prevFinishTime) {
	                endTimes[i] = prevFinishTime + stairLength;
	            } else {
	                endTimes[i] = arrivalTime + 1 + stairLength;
	            }
	        }
	    }
	    
	    return endTimes[arrivals.size() - 1];
	}
}

class Node {
	int i;
	int j;
	public Node(int i, int j) {
		this.i = i;
		this.j = j;
	}
}

