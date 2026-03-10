import java.util.Scanner;

class Main
{
	public static void main(String args[]) throws Exception
	{
		Scanner sc = new Scanner(System.in);
		int n, sum = 0;
		String s;
		char[] num;
		
		n = sc.nextInt();
		s = sc.next();
		
		num = s.toCharArray();
		for(int i = 0; i < n; i++)
			sum += num[i] - '0';
		
		System.out.println(sum);
	}
}