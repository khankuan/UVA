import java.util.*;

public class Main {
	
	static int maximise(int m, int k){
		if (m < 0)
			return Integer.MIN_VALUE;
		if (k == C)
			return M - m;
		
		if (memo[m][k] != -1)
			return memo[m][k];
		
		int max = 0;
		for (int i = 0; i < cost.get(k).size(); i++)
			max = Math.max(max, maximise(m-cost.get(k).get(i),k+1));
		
		memo[m][k] = max;
		return max;
	}
	
	static Vector<Vector<Integer>> cost;
	static int[][] memo;
	static int C, M;
	
	public static void main(String args[]){
		Scanner scans = new Scanner(System.in);
		
		int testcount = scans.nextInt();
		for (int test = 0; test < testcount; test++){
			M = scans.nextInt();
			C = scans.nextInt();
			memo = new int[200][C];
			for (int i = 0; i < 200; i++)
				Arrays.fill(memo[i], -1);
			cost = new Vector<Vector<Integer>>();
			for (int i = 0; i < C; i++){
				cost.add(new Vector<Integer>());
				int num = scans.nextInt();
				for (int j = 0; j < num; j++)
					cost.get(i).add(scans.nextInt());
			}
			int ans = maximise(M,0);
			if (ans == 0)
				System.out.println("no solution");
			else
				System.out.println(ans);
		}
		
	}
}
