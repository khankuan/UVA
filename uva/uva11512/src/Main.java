import java.util.Arrays;
import java.util.Scanner;


public class Main {
	public static int M = 2005;
	public static String str;
	
	//	Construct Suffix Array
	static int[] RA = new int[M];
	static int[] tempRA = new int[M];
	static int[] SA = new int[M];
	static int[] tempSA = new int[M];
	static int[] c = new int[M];
	static int n;
	
	//	Compute LCP
	static int[] Phi = new int[M];
	static int[] PLCP = new int[M];
	static int[] LCP = new int[M];
	
	//	Compute LCS
	static int high;
	static int highSA;
	
	static void countingSort(int k){
		int i, sum, maxi = Math.max(M,n);
		Arrays.fill(c, 0);
		for (i = 0; i < n; i++){
			c[i + k < n ? RA[i + k] : 0]++;
		}
		for (i = sum = 0; i < maxi; i++){
			int t = c[i];
			c[i] = sum;
			sum += t;
		}
		for (i = 0; i < n; i++)
			tempSA[c[SA[i] + k < n ? RA[SA[i] + k] : 0]++] = SA[i];
		
		for (i = 0; i < n; i++)
			SA[i] = tempSA[i];
	}
	
	static void constructSA(){
		int i, k ,r;
		for (i = 0; i < n; i++){
			RA[i] = str.charAt(i);
			SA[i] = i;
		}
		for (k = 1; k < n; k <<= 1){
			countingSort(k);
			countingSort(0);
			tempRA[SA[0]] = r = 0;
			for (i = 1; i < n; i++){
				tempRA[SA[i]] = 
					(RA[SA[i]] == RA[SA[i-1]] && RA[SA[i]+k] == RA[SA[i-1]+k]) ? r : ++r;
			}
			for (i = 0; i < n; i++)
				RA[i] = tempRA[i];
		}
	}
	
	static void computeLCP(){
		int i, L;
		Phi[SA[0]] = -1;
		for (i = 1; i < n; i++)
			Phi[SA[i]] = SA[i-1];
		for (i = L = 0; i < n; i++){
			if (Phi[i] == -1){
				PLCP[i] = 0;
				continue;
			}
			
			while(i+L < n && Phi[i]+L < n){
				if (str.charAt(i+L) != str.charAt(Phi[i] + L))
					break;
				L++;
			}
			
			PLCP[i] = L;
			L = Math.max(L-1,0);
		}
		for (i = 1; i < n; i++)
			LCP[i] = PLCP[SA[i]];
	}
	
	static void getLRS(){
		high = -1;
		for(int i = 1; i < n; i++){
			if (LCP[i] > high){
				high = LCP[i];
				highSA = i;
			}
		}
	}
	
	public static void main(String[] args){
		M = 2005;
		RA = new int[M];
		tempRA = new int[M];
		SA = new int[M];
		tempSA = new int[M];
		c = new int[M];
		Phi = new int[M];
		PLCP = new int[M];
		LCP = new int[M];
		
		Scanner scans = new Scanner(System.in);
		int testcases = scans.nextInt();
		scans.nextLine();
		for (int test = 0; test < testcases; test++){

			str = scans.nextLine()+".";
			n = str.length();
			constructSA();
			computeLCP();
			getLRS();

			if (high <= 0){
				System.out.println("No repetitions found!");
				continue;
			}
			
			int count = 0;
			String ans = str.substring(SA[highSA],SA[highSA] + high);
			StringBuilder remains = new StringBuilder(str);
			while (true){
				if (remains.length() == 0)
					break;
				int found = remains.indexOf(ans);
				if (found < 0)
					break;
				remains = remains.delete(0, found+1);
				count++;
			}
			System.out.println(ans + " "+count);
		}
	}
}
