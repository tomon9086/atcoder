import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		String[] scan = scanner.nextLine().split(" ");
		int mul = Integer.parseInt(scan[0]) * Integer.parseInt(scan[1]);
		scanner.close();
		System.out.println(mul % 2 == 0 ? "Even" : "Odd");
	}
}
