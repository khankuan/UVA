import java.util.*;


public class Main {
	public static void main(String args[]){
		Scanner scans = new Scanner(System.in);
		
		while(true){
			int n = scans. nextInt();
			if (n == 0)
				break;
			ArrayList<Integer> ans = new ArrayList<Integer>();
			int parity = 0;
			while(n > 0){
				ans.add(n%2);
				if ((n%2) == 1)
					parity++;
				n/=2;
				
			}
			
			System.out.printf("The parity of ");
			for (int i = ans.size()-1; i >= 0; i--)
				System.out.printf("%d",ans.get(i));
			System.out.println(" is "+parity+" (mod 2).");
			
		}
	}
}
