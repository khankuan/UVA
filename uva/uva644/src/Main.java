import java.util.*;

public class Main {
	public static void main(String[] args){
		Scanner scans = new Scanner(System.in);
		boolean pass = true;
		int test = 1;
		ArrayList<String> arr = new ArrayList<String>();
		while(scans.hasNext()){		
			String input = scans.nextLine();
			if (input.charAt(0) == '9'){
				if (pass == true)
					System.out.println("Set "+test+" is immediately decodable");
				else
					System.out.println("Set "+test+" is not immediately decodable");
				pass = true;
				arr.clear();
				test++;
				continue;
			}		
			
			if (pass){
				for (int i = 0; i < arr.size(); i++){
					if (arr.get(i).indexOf(input) == 0 || input.indexOf(arr.get(i)) == 0){
						pass = false;
						break;
					}
				}
				arr.add(input);
			}		
		}
	}
}
