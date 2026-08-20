import java.util.*;
import java.io.*;

public class Solution {
    static int n;
    static List<Node> ary = new ArrayList<>();
    // 세그먼트 트리
    static int seg[];

    static void update(int p, int val) {
        p += n;
        seg[p] = val;
        p >>= 1;
        while(p > 0) {
            seg[p] = Math.max(seg[p << 1], seg[p << 1 | 1]);
            p >>= 1;
        }
    }

    static int query(int end) {
        int start = n;
        end += n;

        int res = 0;
        while(start <= end) {
            if((start & 1) == 1) {
                res = Math.max(res, seg[start]);
                start++;
            }
            if((end & 1) == 0) {
                res = Math.max(res, seg[end]);
                end--;
            }
            start >>= 1;
            end >>= 1;
        }
        return res;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        StringTokenizer st;
        int T = Integer.parseInt(br.readLine());
        int in, res;
        for(int t = 1; t <= T; t++) {
            n = Integer.parseInt(br.readLine());
            st = new StringTokenizer(br.readLine());
            ary.clear();
            seg = new int[n * 2];
            res = 0;
            for(int i = 0; i < n; i++) {
                in = Integer.parseInt(st.nextToken());
                ary.add(new Node(i, in));
            }
            ary.sort((n1, n2) -> Integer.compare(n1.val, n2.val));
            for(Node it : ary) {
                int count = query(it.idx - 1);
                update(it.idx, count + 1);
                res = Math.max(res, query(it.idx));
            }
            
            sb.append("#").append(t).append(" ").append(res).append("\n");
        }
        System.out.println(sb);
    }
}

class Node {
    public Node(int idx, int val) {
        this.idx = idx;
        this.val = val;
    }
    public int idx;
    public int val;
}
