import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();

       int i = 1, j = 1, sum = 1, res = 0;
       while (i <= j) {
           if(n == sum) {
               res++;
               j++;
               sum += j;
           }
           else if(n < sum) {
               sum -= i;
               i++;
           }
           else {
               j++;
               sum += j;
           }
       }
        System.out.println(res);
    }
}