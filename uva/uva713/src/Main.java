import java.math.BigInteger;
import java.util.Scanner;


public class Main {
	public static void main(String args[]){
		
		Scanner scans = new Scanner(System.in);
		int testcases = scans.nextInt();

		for (int test = 0; test < testcases; test++){
			StringBuilder a = new StringBuilder(scans.next());
			StringBuilder b = new StringBuilder(scans.next());
			a = a.reverse();
			b = b.reverse();
			BigInteger ai = new BigInteger(a.toString()), bi = new BigInteger(b.toString());
			ai = ai.add(bi);
			while (ai.mod(new BigInteger("10")).equals(new BigInteger("0")))
				ai = ai.divide(new BigInteger("10"));
			StringBuilder ans = new StringBuilder(ai.toString());
			ans = ans.reverse();
			System.out.println(ans);
		}
	}
}
