import java.math.BigInteger;
import java.util.*;


public class Main {
	public static void main(String args[]){
		Scanner scans = new Scanner(System.in);
		while(scans.hasNext()){
			String num = scans.nextLine();
			if (num.compareTo("0") == 0){
				System.out.println("0!");
				System.out.println(1);
				continue;
			}
			int numInt = Integer.parseInt(num);
			BigInteger bigNum = new BigInteger(num);
			for (int i = numInt-1; i > 1; i--)
				bigNum = bigNum.multiply(new BigInteger(Integer.toString(i)));
			
			System.out.println(numInt + "!");
			System.out.println(bigNum);
		}
	}
}
