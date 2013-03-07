import java.util.*;

class IntegerPair implements Comparable{
	public IntegerPair(int a,int b){
		first = a;
		second = b;
	}
	public int first,second;
	public int first(){
		return first;
	}
	public int second(){
		return second;
	}
	@Override
	public int compareTo(Object arg0) {
		if (this.first == ((IntegerPair)arg0).first)
			return this.second - ((IntegerPair)arg0).second;
		else
			return this.first - ((IntegerPair)arg0).first;
	}
	
}

class Main {
	int N; // number of items in the supermarket. V = N+1
	int K; 
	int E;
	int[] shoppingList;
	Vector<Vector<IntegerPair> > T = new Vector<Vector<IntegerPair> >(); 


	int memo[][];
	int[][] minD;


	int Query() {
		int answer = 0;

		memo = new int[K + 1][];
		for (int i = 0; i < K + 1; i++) {
			memo[i] = new int[1 << K];
			Arrays.fill(memo[i], -1);
		}

		//	find SSSP between all starting point+all items
		minD = new int[K + 1][K + 1];
		minD[0] = Dijkstra(0);
		for (int i = 0; i < K-1 ; i++)
			minD[i + 1] = Dijkstra(shoppingList[i]);
		for (int j = 0; j < K; j++)
			minD[K][j] = minD[j][K];
		minD[K][K] = 0;

		DP_Market(0, 0);	//	start dp
		answer = memo[0][0];
		return answer;
	}

	// You can add extra function if needed
	// --------------------------------------------

	//	DP after getting SSSP between any 2 points.
	int DP_Market(int u, int vis) {
		if (vis == (1 << K) - 1)	//	if all visited, go back to counter
			return minD[u][0];
		if (memo[u][vis] != -1)	//	memoised
			return memo[u][vis];
		memo[u][vis] = 100000000;	//	default

		//	add weight between u to next item and set next item visited bit as visited
		for (int i = 0; i < K; i++) {
			if (((vis >> i) & 1) == 0) {
				memo[u][vis] = Math.min(memo[u][vis], minD[u][i + 1]
						+ DP_Market(i + 1, vis | (1 << i)));
			}
		}
		return memo[u][vis];
	}

	//	SSSP
	int[] Dijkstra(int from) {
		int[] weights = new int[N];
		Arrays.fill(weights, 10000000);
		PriorityQueue<IntegerPair> current_span = new PriorityQueue<IntegerPair>();
		weights[from] = 0;
		current_span.add(new IntegerPair(0, from));
		while (!current_span.isEmpty()) {
			IntegerPair cur = current_span.poll();
			if (cur.first > weights[cur.second])
				continue;
			boolean isOver = true;
			for (int u = 0; u < K; u++){	//	check if all require items are reached
				if (weights[cur.second()] < weights[shoppingList[u]]){
					isOver = false;
					break;
				}
			}
			if (isOver == true){
	            break;
	        }
			
			
			for (int i = 0; i < T.get(cur.second()).size(); i++) {
				IntegerPair curn = T.get(cur.second()).get(i);
				if (cur.first() + curn.second < weights[curn.first]) {
					weights[curn.first] = cur.first() + curn.second;
					current_span.add(new IntegerPair(weights[curn.first], curn.first));
				}
			}
		}
		// -------------------------------------------------------------------------
		int[] items_weight = new int[K + 1];
		items_weight[0] = weights[0];
		for (int j = 0; j < K; j++)
			items_weight[j + 1] = weights[shoppingList[j]];
		return items_weight;
	}

	void run(){
		// do not alter this method
		Scanner sc = new Scanner(System.in);
		int TC = sc.nextInt(); // there will be several test cases
		while (TC-- > 0) {
			// read the information of the complete graph with N+1 vertices
			N = sc.nextInt();
			E = sc.nextInt();
			T.clear();
			for (int i = 0; i < N; i++)
				T.add(new Vector<IntegerPair>());
			int from, to, amt;
	        for (int i = 0; i < E; i++){
	        	from = sc.nextInt();
	        	to= sc.nextInt();
	        	amt= sc.nextInt();	
	            T.get(from).add(new IntegerPair(to,amt));
	            T.get(to).add(new IntegerPair(from,amt));
	        }
			
			K = sc.nextInt(); // K is the number of items to be bought
			shoppingList = new int[K];
			for (int i = 0; i < K; i++)
				shoppingList[i] = sc.nextInt();
				
			
			System.out.println(Query());
		}
	}
	
	public static void main(String[] args) {
		Main mymain = new Main();
		mymain.run();
	}
}
