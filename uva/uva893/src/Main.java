import java.util.*;

public class Main {
	public static void main(String args[]){
		Scanner scans = new Scanner(System.in);
		while (true){
			int addition = scans.nextInt();
			int day = scans.nextInt();
			int month = scans.nextInt();
			int year = scans.nextInt();
			if (addition + day + month + year == 0)
				break;
			GregorianCalendar cal = new GregorianCalendar(year, month-1, day,0,0,0);
			cal.add(Calendar.DATE, addition);
			System.out.printf("%d %d %d\n", cal.get(Calendar.DAY_OF_MONTH), cal.get(Calendar.MONTH)+1, cal.get(Calendar.YEAR));
		}
	}
}
