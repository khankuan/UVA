import java.math.BigInteger;
import java.util.Scanner;

public class Main {
	
	public static long[][] matMul(long[][] a, long[][] b){
		long[][] ans = new long[2][2];
		for (int i = 0; i < 2; i++){
			for (int j = 0; j < 2; j++){
				ans[i][j] = 0;
				for (int k = 0; k < 2; k++){
					ans[i][j] += a[i][k]*b[k][j];
					ans[i][j] = ans[i][j]%mpower;
				}
			}
		}

		return ans;
	}
	
	public static long[][] matPow(long[][] base, int p){
		long[][] ans = new long[2][2];
		int i,j;
		for (i = 0; i < 2; i++){
			for (j = 0; j < 2; j++){
				if (i == j)
					ans[i][j] = 1;
				else
					ans[i][j] = 0;
			}
		}

		while (p > 0){
			if (p % 2 == 1)
				ans = matMul(ans,base);
			base = matMul(base,base);
			p /= 2;
		}
		return ans;
	}
	
	public static long mpower;
	
	public static void main(String args[]){
		Scanner scans = new Scanner(System.in);
		while(scans.hasNext()){
			int n = scans.nextInt();
			int m = scans.nextInt();
			mpower = (int) Math.pow(2, m);
			
			long[][] ansM = new long[2][2];
			ansM[0][0] = 1;
			ansM[0][1] = 1;
			ansM[1][0] = 1;
			ansM[1][1] = 0;
			ansM = matPow(ansM, n);
			System.out.println(ansM[0][1]);
		}
	}
}
