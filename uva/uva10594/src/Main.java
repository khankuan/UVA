import java.util.*;

class IntegerPair implements Comparable{
	public IntegerPair(long o, int t){
		first = o; 
		second = t;
	}
	public long first;
	public int second;
	@Override
	public int compareTo(Object arg0) {
		if (((IntegerPair)arg0).first == this.first)
			return this.second > ((IntegerPair)arg0).second? 1:0;
		else
			return this.first > ((IntegerPair)arg0).first? 1:0;
	}
}


public class Main {
	int V, E;
	long mf,f,cap,target;
	Vector<Vector<Integer>> adjList = new Vector<Vector<Integer>>();
	long[][] cost = new long[105][105];
	long[][] flow = new long[105][105];
	int[] p = new int[105];
	long INF = 10000000000000000l;
	
	void augment(int v, long minEdge) {
	     if (v == 1) { 
	           f = minEdge; 
	           return; 
	     } else if (p[v] > 0) {
	            if (minEdge < cap-flow[p[v]][v])
	                augment(p[v], minEdge);
	            else
	                augment(p[v], cap-flow[p[v]][v]);
	            if (flow[p[v]][v] >= flow[v][p[v]]){
	               flow[v][p[v]] -= f;
	               flow[p[v]][v] += f;
	            } else {
	              flow[v][p[v]] += f;
	              flow[p[v]][v] -= f;
	            }    
	     }
	}
	
	void run(){
		Scanner scans = new Scanner(System.in);
		while(true){
			V = scans.nextInt();
	        V++;
	        adjList.clear();
	        for (int i = 0; i < V ;i++)
	        	adjList.add(new Vector<Integer>());
	        for (int i = 0; i < V; i++)
	        	Arrays.fill(flow[i], 0);
	        E = scans.nextInt();
	        for (int i = 0; i < E; i++){
	            int first = scans.nextInt(), second = scans.nextInt();
	            long third = scans.nextLong();
	            adjList.get(first).add(second);
	            adjList.get(second).add(first);
	            cost[first][second] = cost[second][first] = third;
	        }
	        target = scans.nextLong();
	        cap = scans.nextLong();
	                
	        mf = 0;
	        while (true) {
	            f = 0;
	            Arrays.fill(p,-1);
	            long[] weights = new long[V];
	            for (int i = 0; i < V ; i++)
	                weights[i] = INF;
	            PriorityQueue<IntegerPair> current_span = new PriorityQueue<IntegerPair>();
	            weights[1] = 0;
	            current_span.add(new IntegerPair(0,1));
	            while (!current_span.isEmpty()){
	            	  IntegerPair cur = current_span.poll();
	                  if (cur.first > weights[cur.second])
	                     continue;
	                  if (cur.first > weights[V-1])
	                     break;
	                  for (int i = 0; i < adjList.get(cur.second).size(); i++){
	                      int next = adjList.get(cur.second).get(i);
	                      if (flow[cur.second][next] < cap &&
	                      cur.first + cost[cur.second][next] < weights[next]){
	                         if (flow[cur.second][next] >= flow[next][cur.second])
	                             weights[next] = cur.first + cost[cur.second][next];
	                         else
	                             weights[next] = cur.first - cost[cur.second][next];
	                         current_span.add(new IntegerPair(weights[next],next));
	                         p[next] = cur.second;
	                      }
	                }          
	            }
	          
	            augment(V-1, INF);
	            
	            if (f == 0) 
	               break;
	            mf += Math.min(weights[V-1]*f,target*weights[V-1]);
	            target -= f;
	            if (target <= 0)
	               break;   
	        }
	        if (target <= 0)
	            System.out.println(mf);
	        else
	            System.out.println("Impossible.");
	    }
	}
	
	public static void main(String[] args){
		Main m = new Main();
		m.run();
	}
}
