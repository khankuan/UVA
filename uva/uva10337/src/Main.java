import java.util.*;


public class Main {

	static int fly(int x, int y){
		if (x == dist){
			if (y == 0)
				return 0;
			else
				return 100000000;
		}
		if (y > h-1 || y < 0 || (y == 0 && x !=0))
			return 100000000;
			
		if (memo[x][y] != -1) return memo[x][y];
		
		int min = 100000000;
		min = Math.min(min, 60 - map.get(y).get(x) + fly(x+1, y+1));
		min = Math.min(min, 30 - map.get(y).get(x) + fly(x+1, y));
		min = Math.min(min, 20 - map.get(y).get(x) + fly(x+1, y-1));
		memo[x][y] = min;
		return min;
	}
	
	private static int memo[][];
	private static Vector <Vector<Integer>> map;
	private static int dist, h = 10;
	
	public static void main(String args[]){
		Scanner scans = new Scanner(System.in);
		int testcount = scans.nextInt();
		for (int test = 0; test < testcount; test++){
			dist = scans.nextInt()/100;
			scans.nextLine();

			map = new Vector<Vector<Integer>>();
			for (int i = 0; i < 10; i++)
				map.add(new Vector<Integer>());
			
			for (int i = 9; i >= 0; i--){		
				for (int j = 0; j < dist; j++)
					map.get(i).add(scans.nextInt());
			}

			memo = new int[dist][h];
			for (int i = 0; i < dist; i++)
				Arrays.fill(memo[i], -1);
			System.out.println(fly(0,0));
			

			System.out.println("");
		}
		
	}
}
