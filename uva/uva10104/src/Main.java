import java.util.Scanner;

public class Main {
	static long x,y,d;
	
	public static void extendedEuclid(long a, long b){
		if (b == 0){
			x = 1;
			y = 0;
			d = a;
			return;
		}
		extendedEuclid(b, a%b);
		long x1 = y;
		long y1 = x - (a/b)*y;
		x = x1;
		y = y1;
	}
	
	public static void main(String args[]){
		Scanner scans = new Scanner(System.in);
		
		while(scans.hasNext()){
			long a = scans.nextLong();
			long b = scans.nextLong();
			extendedEuclid(a,b);
			System.out.println(x+" "+y+" "+d);
		}
	}
}
