import java.util.*;

public class Main{

    public static void main(String[] args){
        Scanner scans = new Scanner(System.in);
        scans.nextLine();
        while(true){
            String input = scans.nextLine();
            if (input.charAt(0) == '_')
                break;
            int total = 0;
            if (input.charAt(1) == 'o') total += 128;
            if (input.charAt(2) == 'o') total += 64;
            if (input.charAt(3) == 'o') total += 32;
            if (input.charAt(4) == 'o') total += 16;
            if (input.charAt(5) == 'o') total += 8;
            if (input.charAt(7) == 'o') total += 4;
            if (input.charAt(8) == 'o') total += 2;
            if (input.charAt(9) == 'o') total += 1;
            System.out.printf("%c",(char)total);
        }
    }


} 