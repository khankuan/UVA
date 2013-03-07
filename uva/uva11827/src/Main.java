import java.util.*;

public class Main {
	public static long gcd(int a, int b){
		if(b > 0)
			return gcd(b,a%b);
		return a;
	}
	
	public static void main(String args[]){
		Scanner scans = new Scanner(System.in);
		int testcases = scans.nextInt();
		scans.nextLine();
		
		for (int test = 0; test < testcases; test++){
			String input = scans.nextLine();
			String[] num = input.split(" ");
			
			long max = 0;
			for (int i = 0; i < num.length; i++){
				for (int j = i+1; j < num.length; j++){
					int first = Integer.parseInt(num[i]);
					int second = Integer.parseInt(num[j]);
					long gcdij = gcd(first,second);

					if (gcdij > max)
						max = gcdij;
				}
			}
			System.out.println(max);
		}
	}
}
