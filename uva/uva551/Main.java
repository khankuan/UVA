import java.util.ArrayList;
import java.util.Scanner;

//Main class must be called "Main" for Uva submission
public class Main {	
	
	
	public static void main(String[] args){
		Scanner scans = new Scanner(System.in);
		
		//	Repeatedly take input lines
		while (scans.hasNext()){
			String input = scans.nextLine();
			
			//	Stack for tracking bracklets
			ArrayList<Character> bracklets = new ArrayList<Character>();
			
			//	Result
			boolean isProper = true;
			int doubleCount = 0;
			
			//	Read character by character
			int i;
			for (i = 0 ; i < input.length(); i++){
				char currentChar = input.charAt(i);
				//System.out.printf("%d %c\n",i,currentChar);
				//	Switch case for each bracklet type
				switch (currentChar){
					//	Open bracklets
					case '(':
						bracklets.add('(');
						//	Case of "(*", we must ensure i is not the last character
						if (i + 1 < input.length()){
							char nextChar = input.charAt(i+1);
							if (nextChar == '*'){
								bracklets.add('*');
								i++;	//	We can skip the next char in input since it is a *
								doubleCount++;
							}
						}
						break;
						
					case '[':
						bracklets.add('[');
						break;
					
					case '<':
						bracklets.add('<');
						break;
					
					case '{':
						bracklets.add('{');
						break;
						
						
						
					//	Close bracklets
					case ')':
						//	Remove bracklet if matches
						if (bracklets.size() > 0 && bracklets.get(bracklets.size()-1) == '(')
							bracklets.remove(bracklets.size()-1);
						else 
							isProper = false;
						break;
					
					case ']':
						//	Remove bracklet if matches
						if (bracklets.size() > 0 && bracklets.get(bracklets.size()-1) == '[')
							bracklets.remove(bracklets.size()-1);
						else 
							isProper = false;
						break;
					
					case '>':
						//	Remove bracklet if matches
						if (bracklets.size() > 0 && bracklets.get(bracklets.size()-1) == '<')
							bracklets.remove(bracklets.size()-1);
						else 
							isProper = false;
						break;
					
					case '}':
						//	Remove bracklet if matches
						if (bracklets.size() > 0 && bracklets.get(bracklets.size()-1) == '{')
							bracklets.remove(bracklets.size()-1);
						else
							isProper = false;
						break;
					
					case '*':
						//	Check if have chars left
						if (i + 1 < input.length()){
							char nextChar = input.charAt(i+1);
							
							//	Check if it is a bracklet
							if (nextChar == ')'){
								//	Remove bracklet if matches
								if (bracklets.size() > 0 && bracklets.get(bracklets.size()-1) == '*')
									bracklets.remove(bracklets.size()-1);
								else
									isProper = false;
								
								//	Remove '('
								if (bracklets.size() > 0){
									bracklets.remove(bracklets.size()-1);
									i++;
									doubleCount++;
								} else
									isProper = false;
							}
						}
						break;
						
					//	Others
					default:
						break;
				}
				
				if (isProper == false)
					break;
			}
			
			if (isProper == false || bracklets.size() > 0){
				System.out.println("NO "+(i-doubleCount+1));
			}
			else
				System.out.println("YES");
				
		}
	}
}
