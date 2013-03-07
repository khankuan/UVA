import java.util.Arrays;
import java.util.LinkedList;
import java.util.PriorityQueue;
import java.util.Scanner;
import java.util.Vector;

class IntegerPair implements Comparable{
	public IntegerPair(int o, int t){
		first = o; 
		second = t;
	}
	public int first,second;
	@Override
	public int compareTo(Object arg0) {
		if (((IntegerPair)arg0).first == this.first)
			return this.second - ((IntegerPair)arg0).second;
		else
			return this.first - ((IntegerPair)arg0).first;
	}
}

public class Main {
	void run(){
		Scanner scans = new Scanner(System.in);
		int V,E,hotelcount;
	    while(true){
	        V = scans.nextInt();
	        if (V == 0)
	           break;
	        Vector<Vector<IntegerPair>> adjList = new Vector<Vector<IntegerPair>>();
	        for (int i = 0; i < V;i++)
	        	adjList.add(new Vector<IntegerPair>());
	        
	        hotelcount = scans.nextInt();
	        hotelcount += 2;
	        int[] hotels = new int[hotelcount+2];
	        
	        for (int i = 0; i < hotelcount-2; i++){    
	            int input = scans.nextInt();
	            hotels[i] = input-1;
	        }
	        hotels[hotelcount-2] = 0;
	        hotels[hotelcount-1] = V-1;

	        E = scans.nextInt();
	        for (int i = 0; i < E; i++){
	            int from = scans.nextInt();
	            int to = scans.nextInt();
	            int amt = scans.nextInt();
	            from--;
	            to--;
	            adjList.get(from).add(new IntegerPair(to,amt));
	            adjList.get(to).add(new IntegerPair(from,amt));
	        }
	        
	        Vector<Vector<Integer>> adjList2 = new Vector<Vector<Integer>>();
	        for (int i = 0; i < V;i++)
	        	adjList2.add(new Vector<Integer>());
	        
	        for (int h = 0; h < hotelcount; h++){
	            int[] weights = new int[V];
	            for (int i = 0; i < V; i++)
	                weights[i] = 100000000;
	            int source = hotels[h];
	            weights[source] = 0;
	            PriorityQueue<IntegerPair> Q = new PriorityQueue<IntegerPair>();
	            Q.add(new IntegerPair(0, source));
	            
	            while (!Q.isEmpty()){
	                IntegerPair cur = Q.poll();
	               	if (cur.first > weights[cur.second])
	               		continue;
	                if (cur.first > 600)
	                   break;         	
	                for (int i = 0; i < adjList.get(cur.second).size(); i++) {
	                    int next = adjList.get(cur.second).get(i).first;
	                    int later = cur.first + adjList.get(cur.second).get(i).second;
	                	if (later < weights[next]) {
	                		weights[next] = later ;
	                		Q.add(new IntegerPair(weights[next], next));
	                	}
	                }
	            }
	            for (int i = h+1; i < hotelcount; i++){
	                if (weights[hotels[i]] < 601 && hotels[i] != source){
	                   adjList2.get(source).add(hotels[i]);
	                   adjList2.get(hotels[i]).add(source); 
	                }
	            }
	        }

	        boolean[] visited = new boolean[V];
	        Arrays.fill(visited, false);
	        LinkedList<IntegerPair> Qbfs = new LinkedList<IntegerPair>();
	        int source = 0;
	        Qbfs.add(new IntegerPair(0,source));
	        
	        int ans = -1;
	        while (!Qbfs.isEmpty()){
	            IntegerPair cur = Qbfs.pollFirst();//System.out.println((cur.second+1)+ " "+cur.first);
	            if (visited[cur.second])
	               continue;
	            visited[cur.second] = true;
	            if (cur.second == V-1){
	               ans = cur.first-1;
	               break;
	            }

	            for (int i = 0; i < adjList2.get(cur.second).size(); i++) {
	                int next = adjList2.get(cur.second).get(i);
	                if (!visited[next])              
	                   Qbfs.add(new IntegerPair(cur.first+1,next));
	            }
	        }
	        
	        System.out.println(ans);
	    }
	}
	
	public static void main(String[] args){
		Main mymain = new Main();
		mymain.run();
	}
}
