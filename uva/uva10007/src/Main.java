import java.math.BigInteger;
import java.util.Scanner;

public class Main {
	
	
	public static void main(String args[]){
		BigInteger[] memo = new BigInteger[305];
		Scanner scans = new Scanner(System.in);

		memo[1] = new BigInteger("1");
		for (int i = 1; i < 300; i++){
			int x = ((2*i+2)*(2*i+1));
			int y = ((i+2));
			
			memo[i+1] = (new BigInteger(Integer.toString(x))).
					multiply(memo[i]).divide(new BigInteger(Integer.toString(y)));
		}
		
		while(true){
			int n = scans.nextInt();
			if (n == 0)
				break;
			System.out.println(memo[n]);
		}
	}
}
