import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		String[] scan = scanner.nextLine().split("");
		scanner.close();
		int count = 0;
		for(String value: scan) {
			if(value.equals("1")) count++;
		}
		System.out.println(count);
	}
}
