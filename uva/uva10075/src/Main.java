import java.util.*;

public class Main {
	static long INF = 100000000;
	static double PI = 3.141592653589793;
	static long gcDistance(double pLat, double pLong,
                    double qLat, double qLong, double radius) {
	    pLat *= PI / 180; pLong *= PI / 180;
	    qLat *= PI / 180; qLong *= PI / 180;
	    return Math.round(radius * Math.acos(Math.cos(pLat)*Math.cos(pLong)*Math.cos(qLat)*Math.cos(qLong) +
	                         Math.cos(pLat)*Math.sin(pLong)*Math.cos(qLat)*Math.sin(qLong) +
	                         Math.sin(pLat)*Math.sin(qLat)));
	}

	  
	  
	public static void main(String[] args){
		Scanner scans = new Scanner(System.in);
		int test = 1;
		while(true){
			int V = scans.nextInt();
			int E = scans.nextInt();
			int Q = scans.nextInt();
	        
			if (V == 0 && E == 0 && Q == 0)
	           break;
			scans.nextLine();
			if (test > 1)
				System.out.println("");
	        
	        double[] p = new double[V];
	        double[] q = new double[V];
	        TreeMap<String,Integer> names = new TreeMap<String,Integer>();
	        
	        
	        for (int i = 0; i < V; i++){
	            String n = scans.next();
	            p[i] = scans.nextDouble();
	            q[i] = scans.nextDouble();
	            scans.nextLine();
	            names.put(n, i);
	        }       
	        
	        long[][] APSP = new long[V][V];
	        for (int i = 0; i < V; i++)
	        	Arrays.fill(APSP[i],INF);
	        
	        for (int i = 0; i < E; i++){
	        	String one = scans.next();
	        	String two = scans.next();
	        	scans.nextLine();
	        	int onei = names.get(one);
	        	int twoi = names.get(two);
	        	APSP[onei][twoi] = gcDistance(p[onei], q[onei], // 3D version
	        			p[twoi], q[twoi], 6378);
	        }
	        
	        for (int k = 0; k < V; k++)
	        	for (int i = 0; i < V; i++)
	        		for (int j = 0; j < V; j++)
	        			APSP[i][j] = Math.min(APSP[i][j],APSP[i][k] + APSP[k][j]);
	        
	        System.out.println("Case #"+test);
	        for (int i = 0; i < Q; i++){
	        	String one = scans.next();
	        	String two = scans.next();
	        	scans.nextLine();
	        	int onei = names.get(one);
	        	int twoi = names.get(two);
	        	if (APSP[onei][twoi] != INF)
	        		System.out.println((APSP[onei][twoi]) + " km");
	        	else
	        		System.out.println("no route exists");
	        }
	        test++;
		}
	}
}
