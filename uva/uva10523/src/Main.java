import java.math.BigInteger;
import java.util.*;


public class Main {

	public static void main(String args[]){
	    int n,a;
	    Scanner scans = new Scanner(System.in);
	    while(scans.hasNext()){
	    	n = scans.nextInt();
	    	
	    	a = scans.nextInt();
	    	if (n == 0){
	    		System.out.println(0);
	    		continue;
	    	}
	       BigInteger sum = new BigInteger(""+0);
	       
	       BigInteger first = new BigInteger(a+"");
	       sum = sum.add(first);
	       for (int i = 2; i < n+1 ;i++){
	    	   first = first.divide(new BigInteger((i-1)+"")).multiply(new BigInteger(i+"")).multiply(new BigInteger(a+""));
	    	   sum = sum.add(first);
	       }
	       
	       System.out.println(sum);
	    }
	}

}
