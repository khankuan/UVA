import java.util.*;

public class Main {
  public static void main(String[] args){
	Scanner scans = new Scanner(System.in);
	while(scans.hasNext()){
		String a = scans.next();
		String b = scans.next();
		scans.nextLine();
	    
		int i = 0;
		int at = 0;
		while (i < a.length() && at < b.length()){
			while (at < b.length() && b.charAt(at) != a.charAt(i))
				at++;
			if (at >= b.length() && b.charAt(at-1) != a.charAt(i))
				break;
			i++;
			at++;
		}
		if (i == a.length())
			System.out.println("Yes");
		else
			System.out.println("No");
	  
	    
	}
  }
}
