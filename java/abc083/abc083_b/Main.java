import java.util.Scanner;
import java.util.List;
import java.util.Arrays;

public class Main {
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		String[] scan = scanner.nextLine().split(" ");
		scanner.close();
		// List<String> scanStr = Arrays.asList(scanArray);
		// int[] scan = scanStr.stream().mapToInt(Integer::parseInt).toArray();
		int count = 0;
		for(int i = 0; i <= Integer.parseInt(scan[0]); i++) {
			String[] n = String.valueOf(i).split("");
			int sum = 0;
			for(String v: n) {
				sum += Integer.parseInt(v);
			}
			if(Integer.parseInt(scan[1]) <= sum && sum <= Integer.parseInt(scan[2])) {
				count += i;
				// System.out.println(String.valueOf(i) + " : " + String.valueOf(sum));
			}
		}
		System.out.println(count);
	}
}
