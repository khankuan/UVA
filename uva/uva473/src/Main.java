import java.util.*;

public class Main {
	
	static int n,t,m;
	static int[] tracks;
	static int[][][] memo;
	
	int dp(int at, int minutesleft, int tracksleft){
		if (at >= n || tracksleft < 0 || minutesleft < 0)
			return 0;
		
		if (memo[at][minutesleft][tracksleft] != -1)
			return memo[at][minutesleft][tracksleft];
		
		int ans = dp(at+1,minutesleft,tracksleft);
				
		if (tracksleft > 0)
			ans = Math.max(ans,dp(at,t,tracksleft-1));
			
		if (tracks[at] <= minutesleft)
			ans = Math.max(ans, dp(at+1,minutesleft-tracks[at],tracksleft)+1);
		
		memo[at][minutesleft][tracksleft] = ans;
		return ans;
	}
	
	void run(){
		Scanner scans = new Scanner(System.in);
		int testcases = scans.nextInt();
		
		for (int test = 0; test < testcases; test++){
			n = scans.nextInt();
			t = scans.nextInt();
			m = scans.nextInt();
			scans.nextLine();
			tracks = new int[n];
			
			String input = scans.nextLine();
			String[] trackstring = input.split(", ");
			for (int i = 0; i < n;i++)
				tracks[i] = Integer.parseInt(trackstring[i]);
			
			memo = new int[n][t+1][m+1];
			for (int i = 0; i < n; i++)
				for (int j = 0; j < t+1; j++)
					Arrays.fill(memo[i][j], -1);
			if (test != 0)
				System.out.println("");
			System.out.println(dp(0,t,m-1));
		}
	}
	
	public static void main(String[] args){
		Main myuva = new Main();
		myuva.run();
	}
}
