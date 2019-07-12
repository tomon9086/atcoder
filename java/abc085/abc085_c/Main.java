import java.util.Scanner;
// import java.util.List;
// import java.util.Arrays;

public class Main {
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		String[] scan = scanner.nextLine().split(" ");
		scanner.close();
		int n = Integer.parseInt(scan[0]);
		int y = Integer.parseInt(scan[1]);
		String result = "-1 -1 -1";
		for(int i = 0; i <= n; i++) {
			for(int j = 0; j <= n; j++) {
				int k = n - i - j;
				if(k < 0) continue;
				if(i * 10000 + j * 5000 + k * 1000 == y) {
					result = String.valueOf(i) + " " + String.valueOf(j) + " " + String.valueOf(k);
					break;
				}
			}
		}
		System.out.println(result);
	}
}
