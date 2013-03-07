import java.util.*;

public class Main {
	
	public static void main(String args[]){

	    Vector<String> str = new Vector<String>();
	    Vector<String> str2 = new Vector<String>();
	    int[] counted = new int[1000];
	    Arrays.fill(counted, 0);
	    Scanner scans = new Scanner(System.in);

	    while(true){
	        String input = new String();
	        input = scans.next();
	        if (input.compareTo("#") == 0)
	           break;
	        
	        str.add(input);
	        str2.add(input.toLowerCase());
	    }
	    
	    for (int i = 0; i < str2.size(); i++){
	    	char[] arr = str2.get(i).toCharArray();
	    	Arrays.sort(arr);
	    	StringBuilder temp = new StringBuilder();
	    	temp.append(arr);
	    	str2.set(i,new String(temp));
	    }

	        
	    for (int i = 0; i < str.size(); i++){
	        if (counted[i] == 1)
	           continue;
	        int j;
	        for (j = i+1; j < str2.size(); j++){
	            if (str2.get(i).compareTo(str2.get(j)) == 0)
	               counted[i] = counted[j] = 1;
	        }
	    }
	   
	    
	    Vector<String> str3 = new Vector<String>();
	    for (int i = 0; i < str.size(); i++){
	        if (counted[i] == 0)
	           str3.add(str.get(i));
	    }
	    
	    Collections.sort(str3);
	    for (int i = 0; i < str3.size(); i++)
	        System.out.printf("%s\n",str3.get(i));
	    
	}
}
