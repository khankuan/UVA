import java.math.BigInteger;
import java.util.*;

public class Main {
	static boolean didWork ;
	public static BigInteger sqrt(BigInteger A) 
	{
	    BigInteger temp = A.shiftRight(BigInteger.valueOf(A.bitLength()).shiftRight(1).intValue()), result = null;
	    while (true)
	    {
	        result = temp.add(A.divide(temp)).shiftRight(1);
	        if (!temp.equals(result))
	            temp = result;
	        else
	            break ;
	    }
	    didWork = false ;
	    if (result.multiply(result).equals(A))
	        didWork = true ;
	    
	    return result;
	}
	
	
	public static void main(String[] args){
		Scanner scans = new Scanner(System.in);
		int testcases = scans.nextInt();
		scans.nextLine();
		for (int test = 0; test < testcases; test++){
			if (test > 0)
				System.out.println("");
			String input = scans.next();
			scans.nextLine();
			System.out.println(sqrt(new BigInteger(input)));
		}
	}
}
