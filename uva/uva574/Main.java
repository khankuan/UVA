import java.util.ArrayList;
import java.util.Scanner;


public class Main {

	static int sum;
	static int n;
	static Scanner scans = new Scanner(System.in);
	static ArrayList<Integer> arr = new ArrayList<Integer>();
	static ArrayList<Integer> count = new ArrayList<Integer>();
	static ArrayList<Integer> taken = new ArrayList<Integer>();
	static boolean haveSolution;
	
	public static void main(String[] args){
		while(scans.hasNext()){
			sum = scans.nextInt();
			n = scans.nextInt();
			
			//	If n == 0, end
			if (n == 0)
				break;
			
			//	Store inputs
			arr.clear();
			count.clear();
			taken.clear();
			for (int i = 0; i < n; i++){
				int next = scans.nextInt();
				if (i > 0 && arr.get(arr.size()-1) == next)
					count.set(count.size()-1, count.get(count.size()-1)+1);
				else {
					arr.add(next);
					count.add(1);
					taken.add(0);
				}	
			}
			
			System.out.println("Sums of "+sum+":");
			haveSolution = false;
			sums(sum, 0);
			if (!haveSolution)
				System.out.println("NONE");
		}
	}
	
	public static void sums(int remainder, int cur){
		//	Base condition: If cur == arr.size(), remainder == 0
		if (remainder == 0){
			//	Store the string
			StringBuilder print = new StringBuilder();
			for (int i = 0; i < cur; i++)
				for (int j = 0; j < taken.get(i); j++)
					print.append(arr.get(i)+"+");
			
			//	Delete last +
			if (print.length() > 0)
				print.deleteCharAt(print.length()-1);
			
			System.out.println(print);
			haveSolution = true;
			return;
		}
	
		//	No more numbers to take, return (Note that if combination is valid, it is printed in the remainder check)
		if (cur == arr.size())
			return;
		
		//	Take cur element if sum result is not negative, either take 0 or 1 or ... or count
		for (int i = count.get(cur); i >= 0; i--){
			if (remainder >= arr.get(cur)*i){
				taken.set(cur, i);
				sums(remainder-arr.get(cur)*i, cur+1);
			}
		}
	}
}
