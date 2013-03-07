import java.util.*;

public class Main {
	public static void main(String args[]){
		Scanner scans = new Scanner(System.in);
		boolean isLeft = true;
		String current;
		while (scans.hasNextLine()){
			current = scans.nextLine();
			for (int i = 0; i < current.length(); i++){
				if (current.charAt(i) == '"'){
					if (isLeft){
						isLeft = false;
						System.out.printf("``");
					}
					else{
						isLeft = true;
						System.out.printf("''");
					}
				} else
					System.out.printf("%c", current.charAt(i));
			}
			System.out.println("");
		}
	}
}
