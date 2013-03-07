import java.util.*;


public class Main {
	static int high(int a, int c){
		int ans = 1;
		int PFi = 0;
		int oldc = c;
		while (primes.get(PFi)*primes.get(PFi) <= oldc){
			int cnt1 = 0;
			int cnt2 = 0;
			while ( a % primes.get(PFi) == 0 ) {
				a /= primes.get(PFi);
				cnt1++;
			}
			while ( c % primes.get(PFi) == 0 ) {
				c /= primes.get(PFi);
				cnt2++;
			}
			if ( cnt2 > cnt1 ) {
				for (int i = 0; i < cnt2; i++)
					ans *= primes.get(PFi);
			}

			PFi++;
		}
		if ( a == 1 && c > 1 ) ans *= c;
		
		return ans;
	}
	
	static ArrayList<Integer> primes = new ArrayList<Integer>();
	static ArrayList<Integer> aprimes = new ArrayList<Integer>();
	static ArrayList<Integer> cprimes = new ArrayList<Integer>();
	
	public static void main(String args[]){

		int sievesize = 10000001;
		BitSet bs = new BitSet(sievesize);
		bs.set(2, bs.size(), true);

		for (long i =2; i <= sievesize; i++){
			if (bs.get((int)i)){
				for (long j = i*i; j <= sievesize; j += i)
					bs.set((int)j,false);
				
				primes.add((int)i);
			}
		}

		
		Scanner scans = new Scanner(System.in);
		int testcases = scans.nextInt();	
		
		for (int test = 0; test < testcases; test++){
			int a = scans.nextInt();
			int c = scans.nextInt();
			
			if (c % a != 0){
				System.out.println("NO SOLUTION");
				continue;
			}
			
			System.out.println(high(a,c));
		}
	}
}
