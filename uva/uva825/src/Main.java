import java.util.Arrays;
import java.util.Scanner;


public class Main {
	static int memo[][];
	static int h;
	static int w;
	
	static int dp(int x, int y){
	    if (x == h-1 && y == w-1)
	       return 1;
	    if (memo[x][y] != -1)
	       return memo[x][y];
	       
	    int total = 0;
	    if (x+1 < h && memo[x+1][y] != -2)
	       total += dp(x+1,y);
	    if (y+1 < w && memo[x][y+1] != -2)
	       total += dp(x,y+1);
	    memo[x][y] = total;
	    return total;
	}


	public static void main(String args[]){
	    Scanner scans = new Scanner(System.in);
		int testcases = scans.nextInt();
	    boolean first = true;
	    for (int test = 0; test < testcases; test++){    
	        if (first)
	        	first = false;
	        else
	        	System.out.println();
	    	h = scans.nextInt();
	        w = scans.nextInt();
	        memo = new int[h][w];
	        for (int i = 0; i < h; i++){
	            Arrays.fill(memo[i], -1);
	        }

	        String str;
	        str = scans.nextLine();
	        String[] split;
	        for (int i = 0; i < h; i++){
	            str = scans.nextLine();
	            split = str.split(" ");
	            for (int j = 1; j < split.length; j++)
	                memo[i][Integer.parseInt(split[j])-1] = -2;
	        }
	        System.out.printf("%d\n",dp(0,0));
	    }
	}

}
