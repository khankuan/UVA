import java.util.*;

public class Main {

	// Segment Tree Library: The segment tree is stored like a heap array
	static void st_build(Vector<Integer> st, Vector<Integer> A, int vertex,
			int L, int R) {
		if (L == R) // as L == R, either one is fine
			st.set(vertex, A.get(L)); // store the index
		else { // recursively compute the values in the left and right subtrees
			int nL = 2 * vertex, nR = 2 * vertex + 1;
			st_build(st, A, nL, L, (L + R) / 2);
			st_build(st, A, nR, (L + R) / 2 + 1, R);
			st.set(vertex, (st.get(nL) >= st.get(nR)) ? st.get(nL) : st.get(nR));
		}
	}

	static void st_create(Vector<Integer> st, Vector<Integer> A) { // if
																	// original
																	// array
		// size is N,
		// the required segment tree array length is 2*2^(floor(log2(N)) + 1);
		int len = (int) (2 * Math.pow(2.0,
				Math.floor((Math.log((double) A.size()) / Math.log(2.0)) + 1)));
		for (int i = 0; i < len; i++)
			st.add(0); // create vector of size `len' and fill it with zeroes
		st_build(st, A, 1, 0, (int) A.size() - 1); // recursive build
	}

	static int st_rmq(Vector<Integer> st, Vector<Integer> A, int vertex, int L,
			int R, int i, int j) {
		if (i > R || j < L)
			return -1; // current segment outside query range
		if (L >= i && R <= j)
			return st.get(vertex); // inside query range

		// compute the min position in the left and right part of the interval
		int p1 = st_rmq(st, A, 2 * vertex, L, (L + R) / 2, i, j);
		int p2 = st_rmq(st, A, 2 * vertex + 1, (L + R) / 2 + 1, R, i, j);

		// return the position where the overall minimum is
		if (p1 == -1)
			return p2; // if we try to access segment outside query
		if (p2 == -1)
			return p1; // same as above
		return (p1 >= p2) ? p1 : p2;
	}

	static int st_rmq(Vector<Integer> st, Vector<Integer> A, int i, int j) { // function
		// overloading
		return st_rmq(st, A, 1, 0, (int) A.size() - 1, i, j);
	}

	static Vector<Integer> st,freq;

	public static void main(String args[]) {
		Scanner scans = new Scanner(System.in);
		TreeMap<Integer,Integer> start = new TreeMap<Integer,Integer>();
		TreeMap<Integer,Integer> end = new TreeMap<Integer,Integer>();
		//int[] start = new int[400005];
		//int[] end = new int[400005];
		while (true) {
			int num, qcount;			
			num = scans.nextInt();
			int[] arr = new int[num];
			if (num == 0)
				break;
			qcount = scans.nextInt();

			int i = 1;
			freq = new Vector<Integer>();
			arr[0] = scans.nextInt();
			//start[arr[0] + 100000] = 0;
			start.put(arr[0], 1);
			while (true) {
				if (i == num)
					break;
				arr[i] = scans.nextInt();
				if (arr[i] != arr[i - 1]) {
					//end[arr[i - 1] + 100000] = i - 1;
					//start[arr[i] + 100000] = i;
					end.put(arr[i-1],i-1);
					start.put(arr[i],i);
					//int count = i - start[arr[i - 1] + 100000];
					int count = i - start.get(arr[i-1]);
					for (int j = i - count; j < i; j++)
						freq.add(count);
				}
				i++;
			}
			//end[arr[i - 1]] = i - 1;
			//int count = i - start[arr[i - 1] + 100000];
			end.put(arr[i-1],i-1);
			int count = i - start.get(arr[i-1]);
			for (int j = i - count; j < i; j++)
				freq.add(count);

			st = new Vector<Integer>();
			st_create(st, freq);

			for (int j = 0; j < qcount; j++) {
				int from = scans.nextInt();
				int to = scans.nextInt();
				from--;
				to--;
				int qStart = 0, qEnd = 0, x, y;

				if (from > 0) {
					if (arr[from] == arr[from - 1]) {
						//x = end[arr[from] + 100000] + 1;
						x = end.get(arr[from]) + 1;
						if (x > to)
							x = to + 1;
						qStart = x - from;
					} else
						x = from;
				} else
					x = from;
				if (to < num - 1) {
					if (arr[to] == arr[to + 1]) {
						//y = start[arr[to] + 100000] - 1;
						y = start.get(arr[to]) - 1;
						if (y < from)
							y = from - 1;
						qEnd = to - y;
					} else
						y = to;
				} else
					y = to;

				int highest = Math.max(qStart, qEnd);
				if (x == y)
					highest = Math.max(highest, 1);
				else if (x < y)
					highest = Math.max(highest,
							Math.min(st_rmq(st, freq, x, y), y - x + 1));

				System.out.println(highest);
			}

		}
	}
}
