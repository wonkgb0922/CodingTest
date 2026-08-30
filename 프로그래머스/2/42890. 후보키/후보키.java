import java.util.*;

class Solution {
    static String[][] relation;
    static int n, m;
    static int res, cnt;
    static Set<Integer> set = new HashSet<>();
    static List<String> list = new ArrayList<>();
    static List<Integer> lazy = new ArrayList<>();
    
    static void dfs(int idx, int state, int k) {
        for(Integer it : lazy) {
            if((it & state) == it) return;
        }
        if(idx == m) {
            if(state == 0) return;
            if(k > 0) return;
            System.out.printf("%04d\n", Integer.parseInt(Integer.toBinaryString(state)));
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < m; j++) {
                    if((state & (1 << j)) > 0) {
                        list.add(relation[i][j]);
                    }
                }
                set.add(Objects.hash(List.copyOf(list)));
                list.clear();
            }
            if(set.size() == n) {
                //System.out.println(Integer.toBinaryString(state));
                cnt++;
                // res |= state;
                lazy.add(state);
            }
            set.clear();
            return;
        }
        dfs(idx + 1, state, k);
        if(k > 0)
            dfs(idx + 1, state | (1 << idx), k - 1);
    }
    
    public int solution(String[][] relation) {
        int answer = 0;
        this.relation = relation;
        n = relation.length;
        m = relation[0].length;
        
        for(int i = 1; i <= m; i++) {
            dfs(0, 0, i);
        }
        return cnt;
    }
}