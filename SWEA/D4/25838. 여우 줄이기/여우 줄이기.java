import java.util.Scanner;
import java.util.Stack;
import java.io.FileInputStream;

/*
   사용하는 클래스명이 Solution 이어야 하므로, 가급적 Solution.java 를 사용할 것을 권장합니다.
   이러한 상황에서도 동일하게 java Solution 명령으로 프로그램을 수행해볼 수 있습니다.
 */
class Solution
{
	public static void main(String args[]) throws Exception
	{
		Scanner sc = new Scanner(System.in);
		int T;
		T=sc.nextInt();
		int n;
		String s;
		Stack<Integer> st = new Stack<>();
		for(int test_case = 1; test_case <= T; test_case++)
		{
			n = sc.nextInt();
			s = sc.next();
			st.clear();
			for(int i = 0; i < s.length(); i++) {
				char c = s.charAt(i);
				if (c == 'f')
					st.push(0);
				else if(c == 'o') {
					if (!st.empty() && st.peek() == 0)
						st.push(1);
					else st.push(-1);
				}
				else if (c == 'x') {
					if (!st.empty() && st.peek() == 1) {
						st.pop();
						st.pop();
					}
					else
						st.push(-1);
				}
				else
					st.push(-1);
			}
			System.out.println(st.size());
		}
	}
}