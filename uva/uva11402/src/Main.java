import java.util.*;

public class Main {

	public static void main(String args[]){
		Scanner scans = new Scanner(System.in);
		int testcount = scans.nextInt();
		long t1 = System.nanoTime();
		for (int test = 0; test < testcount; test++){
			int num = scans.nextInt();
			System.out.printf("Case %d:\n",test+1);
			int count = 0;
			BitSet pirates = new BitSet(1024000);
			pirates.clear();
			for (int i = 0; i < num; i++){
				int times = scans.nextInt();
				scans.nextLine();
				String input = scans.nextLine();
				for ( int j = 0; j < times; j++){
					for (int k = 0; k < input.length(); k++){
						if (input.charAt(k) == '1')
							pirates.set(count,true);
						else
							pirates.set(count,false);
						count++;
					}
				}
			}
			
			int actions = scans.nextInt();
			int qcount = 0;
			for (int i = 0; i < actions; i++){
				String type = scans.next();
				int from = scans.nextInt();
				int to = scans.nextInt();
				if (type.charAt(0) == 'F')
					pirates.set(from,to+1,true);
				else if (type.charAt(0) == 'E')
					pirates.set(from,to+1,false);
				else if (type.charAt(0) == 'I')
					pirates.flip(from,to+1);
				else {
					qcount++;
					System.out.printf("Q%d: %d\n", qcount, pirates.get(from,to+1).cardinality());
				}long t2 = System.nanoTime();
		System.out.printf("%f\n",(t2-t1)/1E9);
			}

		}
		
	}
	
}
