import java.util.*;

public class Main {
	public static void main(String[] args) {
		Scanner scans = new Scanner (System.in);
		
		while ( scans.hasNext() ) {
			int n = scans.nextInt();
			String str = scans.next();
			HashMap <String, Integer> m = new HashMap <String, Integer> ();
			
			for ( int i = 0; i < str.length() - n + 1; i++ ) {
				String subs = str.substring(i, i + n);
				if ( m.containsKey(subs))
					m.put(str.substring(i, i + n), m.get(subs) + 1);
				else m.put(str.substring(i, i + n), 1);
			}
			
			Set s = m.entrySet();
			Iterator it = s.iterator();
			
			String ans = "";
			int max = 0;
			
			while ( it.hasNext() ) {
				Map.Entry k = (Map.Entry)it.next();
				String key = (String) k.getKey();
				int val = (Integer) k.getValue();
				
				if ( val > max ) {
					max = val;
					ans = key;
				}
			}
			
			System.out.println(ans);
		}
	}
}
