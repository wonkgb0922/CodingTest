import java.util.Scanner;

class Main
{
	public static void main(String args[]) throws Exception
	{
		Scanner sc = new Scanner(System.in);
		int n, in;
		long sum = 0, max = 0;
		n = sc.nextInt();
		
		
		for(int i = 0; i < n; i++) {
			in = sc.nextInt();
			if(max < in) max = in;
			sum += in;
		}
		
		System.out.println(sum * 100.0 / max / n);
	}
}