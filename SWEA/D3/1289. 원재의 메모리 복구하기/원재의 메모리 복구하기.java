import java.util.*;
import java.io.*;

public class Solution {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        int t = Integer.parseInt(br.readLine());
        for (int i = 1; i <= t; i++) {
            long x = Long.parseLong(br.readLine(), 2);
            sb.append(String.format("#%d %d\n", i, Long.bitCount(x ^ x >> 1)));
        }
        System.out.println(sb);
    }
}
