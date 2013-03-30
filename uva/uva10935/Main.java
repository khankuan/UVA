import java.util.ArrayList;
import java.util.Scanner;


public class Main {
	public static void main(String[] args){
		Scanner scans = new Scanner(System.in);
		
		while (scans.hasNext()){
			int n = scans.nextInt();
			if (n == 0)
				return;
			
			//	Init deck
			ArrayList<Integer> deck = new ArrayList<Integer>();
			for (int i = 0; i < n; i++)
				deck.add(i+1);
			
			//	While more than 1 card remaining	
			StringBuilder print = new StringBuilder("Discarded cards: ");
			while (deck.size() > 1){
				//	Throw away top card
				print.append(deck.remove(0)+", ");
				
				//	Move next top card to bottom
				deck.add(deck.remove(0));
			}
			
			//	Print solution
			if (print.length() > "Discarded cards: ".length())
				print.deleteCharAt(print.length()-1);	//	remove last comma
				
			print.deleteCharAt(print.length()-1);	//	remove last space
			System.out.println(print);
			System.out.println("Remaining card: "+deck.get(0));
		}
	}
}
