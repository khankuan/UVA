import java.util.*;
import java.math.*;

public class Main {
	static BigInteger[] fibAns;

	static BigInteger fib(int x){
	    if (fibAns[x].compareTo(new BigInteger("-1")) != 0)
	       return fibAns[x];
	    fibAns[x] = fib(x-1).add(fib(x-2));
	    return fibAns[x];
	}

	public static void main(String args[]){
	    int input;
	    fibAns = new BigInteger[5100];
	    for (int i = 2; i < 5100; i++)
	    	fibAns[i] = new BigInteger("-1");
	    fibAns[0] = new BigInteger("0");
	    fibAns[1] = new BigInteger("1");
	    Scanner scans = new Scanner(System.in);
	    
	    while(scans.hasNext()){
	    	input = scans.nextInt();
	        System.out.println("The Fibonacci number for "+ input +" is " + fib(input));
	        
	    }
	}
}
