import java.math.BigDecimal;
import java.util.Scanner;

public class Main {

	public static void main(String args[]){
		Scanner scans = new Scanner(System.in);
		int testcases = scans.nextInt();
		scans.nextLine();
		for (int test = 0; test< testcases; test++){
			String a = scans.next();
			String b = scans.next();
			BigDecimal ans = (new BigDecimal(a)).add(new BigDecimal(b));

			
			if (ans.compareTo(BigDecimal.ZERO) == 0) {
		        System.out.println("0.0");
		        continue;
		      }

		      char output[] = ans.toString().toCharArray();
		      int len = output.length - 1;

		      while (len >= 0 && output[len] == '0') len--;
		      if (len >= 0 && output[len] == '.') {
		        len++;
		        output[len] = '0';
		      }

		      for (int i = 0; i <= len; i++) 
		    	  System.out.print(output[i]);
		      System.out.println();	
		}
	}
}
