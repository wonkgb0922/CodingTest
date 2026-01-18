import java.io.*;
import java.util.LinkedList;
import java.util.StringTokenizer;

public class Main  {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        st = new StringTokenizer(br.readLine());

        LinkedList<Node> l = new LinkedList<>();

        for(int i = 0; i < n; i++) {
            int now = Integer.parseInt(st.nextToken());
            while(!l.isEmpty() && l.getLast().value > now)
                l.removeLast();
            l.addLast(new Node(i, now));

            if (l.getFirst().index <= i - m)
                l.removeFirst();
            bw.write(l.getFirst().value + " ");
        }
        br.close();
        bw.close();
    }

    static class Node {
        public int index;
        public int value;

        public Node(int index, int value) {
            this.index = index;
            this.value = value;
        }
    }
}