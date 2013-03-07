import java.util.*;


public class Main {
	public static void main(String args[]){
		Scanner scans = new Scanner(System.in);
		
		int test = 1;
		while(true){
			int Z = scans. nextInt();;
			int I = scans. nextInt();
			int M = scans. nextInt();
			int L = scans. nextInt();
			
			if (Z == 0 && I == 0 && M == 0 && L == 0)
				break;
			
			int count = 0;
			
			int first = L;
			int second = L;
			
			first = (Z*first+I)%M;
			
			second = (Z*second+I)%M;
			second = (Z*second+I)%M;
						
			count++;
			
			while (first != second){
				first = (Z*first+I)%M;
				
				second = (Z*second+I)%M;
				second = (Z*second+I)%M;
							
				count++;
			}
			
			System.out.println("Case "+test+": "+count);
			test++;
			
		}
	}
}
