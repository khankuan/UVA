import java.util.*;


public class Main {
	public static void main(String args[]){
		Scanner scans = new Scanner(System.in);
	
		
		ArrayList<Long> humble = new ArrayList<Long>();
		
		TreeSet<Long> H = new TreeSet<Long>();
		H.add((long)1);
		humble.add((long)1);
		int at = 0;
	    while ( H.size () < 9000 ) {
	    	Iterator<Long> it = H.iterator();
	    	for (int j = 0 ; j < at; j++)
	    		it.next();
	    	long i = it.next();humble.add(i);
	        H.add(i * 2);
	        H.add(i * 3);
	        H.add(i * 5);
	        H.add(i * 7);
	        at++;
	    }
	    
	    //humble = new ArrayList<Integer>(H);

		while(true){
			int n = scans.nextInt();
			
			if (n == 0)
				break;
			
			if (n%10 == 1 && (n % 100) / 10 != 1 )
				System.out.println("The "+n+"st humble number is "+humble.get(n)+".");
			else if (n%10 == 2 && (n % 100) / 10 != 1 )
				System.out.println("The "+n+"nd humble number is "+humble.get(n)+".");
			else if (n%10 == 3 && (n % 100) / 10 != 1 )
				System.out.println("The "+n+"rd humble number is "+humble.get(n)+".");
			else
				System.out.println("The "+n+"th humble number is "+humble.get(n)+".");
		}
	}
}
