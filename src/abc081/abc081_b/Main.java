import java.util.Scanner;
import java.util.Arrays;

public class Main {
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		int n = Integer.parseInt(scanner.nextLine());
		String[] a_str = scanner.nextLine().split(" ");
		scanner.close();
		Integer[] a = new Integer[n];
		for(int i = 0; i < n; i++) {
			a[i] = Integer.parseInt(a_str[i]);
		}
		// int max = Arrays.stream(a).reduce(0, (p, c) -> { return Math.max(p, c); });
		// int min = Arrays.stream(a).reduce(max, (p, c) -> { return Math.min(p, c); });
		// int result = (int)(min / 2);
		boolean canDevide = true;
		int count = 0;
		while(canDevide) {
			for(int v: a) {
				if(v % 2 != 0) canDevide = false;
			}
			if(canDevide) {
				for(int i = 0; i < a.length; i++) {
					a[i] = (int)(a[i] / 2);
				}
				count++;
			}
		}
		System.out.println(count);
	}
}
