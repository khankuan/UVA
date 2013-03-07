import java.util.*;

public class Main {

	public static void main(String[] args){
		Scanner scans = new Scanner(System.in);
		int test = 1;
		while(scans.hasNext()){
			int n = scans.nextInt();
			if (n == 0)
				break;
			scans.nextLine();
			StringBuilder source = new StringBuilder();
			StringBuilder target = new StringBuilder();
			for (int i = 0; i < n; i++){
				source.append(scans.next());
				target.append(i+1);
			}
			scans.nextLine();
			if (source.toString().equals(target.toString())){
				System.out.println("Case "+test+": 0");
				test++;
				continue;
			}
			HashMap<String,Integer> length = new HashMap<String,Integer>();
			LinkedList<StringBuilder> list = new LinkedList<StringBuilder>();
			list.add(source.append('a'));
			list.add(target.append('b'));
			
			StringBuilder next = null;
			boolean ans = false;
			int ansI = 0;
			length.put(source.toString(),0);
			length.put(target.toString(),0);
			
			while(!list.isEmpty()){
				next = list.pollFirst();
				int at = length.get(next.toString());
				
				char firsta = 'b';
				if (next.charAt(next.length()-1) == 'b')
					firsta = 'a';
				
				for (int i = 0; i < n; i++){
					for (int j = i; j < n; j++){
						for (int k = 0; k < n; k++){
							if (k == i)
								continue;
							if (k < i){
								StringBuilder adding = new StringBuilder(next);
								CharSequence moving = adding.subSequence(i, j+1);
								adding.delete(i, j+1);
								adding.insert(k,moving);
								list.add(adding);
								StringBuilder check = new StringBuilder(adding);
								check.setCharAt(check.length()-1,firsta);
								if (length.containsKey(check.toString())){
									ans = true;
									ansI = length.get(check.toString())+at+1;
									break;
								} else if (!length.containsKey(adding.toString()))
									length.put(adding.toString(), at+1);
							} else if (k > j){
								StringBuilder adding = new StringBuilder(next);
								CharSequence moving = adding.subSequence(j+1,k);
								adding.delete(j+1,k);
								adding.insert(i,moving);
								list.add(adding);
								StringBuilder check = new StringBuilder(adding);
								check.setCharAt(check.length()-1,firsta);
								if (length.containsKey(check.toString())){
									ans = true;
									ansI = length.get(check.toString())+at+1;
									break;
								} else if (!length.containsKey(adding.toString()))
									length.put(adding.toString(), at+1);
							}
						}
						if (ans)
							break;
					}
					if (ans)
						break;
				}
				if (ans)
					break;
			}
			if (ans)
				System.out.println("Case "+test+": "+ansI);
			test++;
		}
		
	}
	
}
