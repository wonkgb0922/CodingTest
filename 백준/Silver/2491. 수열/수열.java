import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        int n = Integer.parseInt(br.readLine());
        int in, prev;
        int res=1, less=1, greater=1;
        StringTokenizer st = new StringTokenizer(br.readLine());

    	prev = Integer.parseInt(st.nextToken());
        for(int i = 1; i < n; i++) {
        	in = Integer.parseInt(st.nextToken());
        	if(prev < in) {
        		less = 1;
        		greater++;
        	}
        	else if(prev > in)  {
        		less++;
        		greater = 1;
        	}
        	else {
        		less++;
        		greater++;
        	}
        	res = Math.max(res, Math.max(less, greater));
        	prev = in;
        }
        System.out.println(res);
        br.close();
    }
}

