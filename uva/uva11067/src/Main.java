import java.util.Arrays;
import java.util.Scanner;


public class Main {
	static long memo[][];
	static int h;
	static int w;
	
	static long dp(int x, int y){
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

	    while (true){    
	    	h = scans.nextInt();
	        w = scans.nextInt();
	        if (h == 0 && w == 0)
	        	break;
	        h++;w++;
	        memo = new long[h][w];
	        for (int i = 0; i < h; i++){
	            Arrays.fill(memo[i], -1);
	        }
	        
	        boolean invalid = false;
	        int wolf = scans.nextInt();
	        for (int i = 0; i < wolf; i++){
	        	int x,y;
	        	x = scans.nextInt();
	        	y = scans.nextInt();
	        	if (x == 0 && y == 0){
	        		System.out.println("There is no path.");
	        		invalid = true;
	        		break;
	        	}
	        	memo[x][y] = -2;
	        }
	        if (invalid)
	        	continue;
	        long ans = dp(0,0);
	        if (ans == 0)
	        	System.out.println("There is no path.");
	        else if (ans == 1)
	        	System.out.println("There is one path from Little Red Riding Hood's house to her grandmother's house.");
	        else
	        	System.out.println("There are " + ans + " paths from Little Red Riding Hood's house to her grandmother's house.");
	    }
	}

}
