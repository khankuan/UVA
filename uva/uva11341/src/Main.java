import java.util.*;

public class Main {

	static int n,m;
	static int memo[][][];
	static int arr[][];
	
	static int dp(int x, int y, int remain){
		if (remain == 0){
			if (x == n)
				return 0;
			
			else
				return -100000000;
		}
		if (x == n)
			return 0;
		
		if (memo[x][y][remain] != -100000000)
			return memo[x][y][remain];
		
		int ans = -100000000;
		if (arr[x][y] >= 5)
			ans = Math.max(ans, dp(x+1,0,remain-1) + arr[x][y]);
		if (y < m - 1)
			ans = Math.max(ans, dp(x,y+1,remain-1));
		memo[x][y][remain] = ans;
		return ans;
	}
	
	public static void main(String args[]){
	    
	    Scanner scans = new Scanner(System.in);
	    int testcases = scans.nextInt();
	    for (int test = 0; test < testcases; test++){
	        n = scans.nextInt();
	        m = scans.nextInt();
	        memo = new int[n][m][101];
	        for (int i = 0;i < n; i++)
	            for (int j =0;j < m; j++)
	                for (int k = 0; k < 101; k++)
	                    memo[i][j][k] = -100000000;
	        
	        arr = new int[n][m];
	        for (int i = 0; i < n; i++)
	            for (int j = 0; j < m; j++)
	                arr[i][j] = scans.nextInt();
	        
  
	        int max = dp(0,0,m);
	        
	        if (((double)max)/((double)n)+1e-9 < 5.0)
	            System.out.println("Peter, you shouldn't have played billiard that much.");
	        else
	            System.out.printf("Maximal possible average mark - %.2f.\n",((double)max+1e-9)/((double)n));
	            

	    }
		
		
	}
}
