import java.util.*;

class Pair {
  public String first;
  public int second;

  public Pair(String f, int s) {
    first = f;
    second = s;
  }

}



public class Main {
	
	public void fill(int type, int start, int end){
		int cur = 0;
		int index = 0;
		while (true){
			Pair temp = chain.get(index);
			if (temp.first.length() * temp.second + cur < start)
				break;
			cur += chain.get(index).second;
			index++;
		}
		
		
		
	}
	
	public LinkedList<Pair> chain;
	
	public static void main(String args[]){
		Scanner scans = new Scanner(System.in);
		int testcount = scans.nextInt();
	    String input;
	    LinkedList<Pair> chain = new LinkedList<Pair>();
	    for (int test = 0; test < testcount; test++){
	        int set = scans.nextInt();
	        int pcount = 0;
	        int times;   
	        for (int seti = 0; seti < set; seti++){              
	            times = scans.nextInt();
	            scans.next();            
	            input = scans.nextLine();
	            scans.next();
	            chain.addLast(new Pair(input,times));
	        }

	        
	        int action = scans.nextInt();
	        scans.nextLine();
	        System.out.printf("Case %d:\n",test+1);
	        int qcount = 0;
	        for (int actioni = 0; actioni < action; actioni++){

	            String type = scans.next();
	            int first = scans.nextInt(), second = scans.nextInt();
           
	            scans.nextLine();
	            if (type.charAt(0) == 'F')
	            	fill(1,first,second);
	            else if (type.charAt(0) == 'E')
	            	fill(0,first,second);
	            else if (type.charAt(0) == 'I')
	                inverse(first,second);
	            else{
	               qcount++;
	               printf("Q%d: %d\n", qcount, query(first, second));
	            }


	        }
	        
	    }    
	    system("pause");
	    return 0;
	}
}
