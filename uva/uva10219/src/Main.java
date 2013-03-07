import java.math.BigInteger;
import java.util.*;


public class Main {
	
	static BigInteger choose(int n, int k){
		int k1 = 2;
		BigInteger ans = new BigInteger("1");
		int times = k;
		for (int i = 0; i < times; i++){
			ans = ans.multiply(new BigInteger(new String(n+"")));
			n--;
			while (k >= k1 && ans.mod(new BigInteger(new String(k+""))).equals(BigInteger.ZERO)){ 
				ans = ans.divide(new BigInteger(new String(k+"")));
				k--;
			}
			while (k >= k1 && ans.mod(new BigInteger(new String(k1+""))).equals(BigInteger.ZERO)){ 
				ans = ans.divide(new BigInteger(new String(k1+"")));
				k1++;
			}
		}
		return ans;
	}
	
	public static void main(String args[]){
		Scanner scans = new Scanner(System.in);
		
		while (scans.hasNext()){
			int n = scans.nextInt();
			int k = scans.nextInt();
			
			System.out.println((int)(Math.log10(choose(n,k).doubleValue())+1));
			
		}
		
	}
}
