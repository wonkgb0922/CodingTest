import java.io.*;
import java.util.*;

public class Solution {
    static int n;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        StringBuilder sb = new StringBuilder();

        int T = Integer.parseInt(br.readLine());
        for (int t = 1; t <= T; t++) {
            int res = 0;
            PriorityQueue<Integer> min = new PriorityQueue<>();
            PriorityQueue<Integer> max = new PriorityQueue<>(Collections.reverseOrder());
            st = new StringTokenizer(br.readLine());
            n = Integer.parseInt(st.nextToken());
            int a = Integer.parseInt(st.nextToken());
            max.offer(a);
            for(int i = 0; i < n; i++) {
                st = new StringTokenizer(br.readLine());
                a = Integer.parseInt(st.nextToken());
                if(max.peek() < a) min.offer(a);
                else max.offer(a);
                a = Integer.parseInt(st.nextToken());
                if(max.peek() < a) min.offer(a);
                else max.offer(a);

                if(max.size() > min.size() + 1)
                    min.offer(max.poll());
                else if(min.size() > max.size())
                    max.offer(min.poll());
                res += max.peek();
                res %= 20171109;
            }
            sb.append("#").append(t).append(" ").append(res).append("\n");
        }
        System.out.println(sb);
    }
}