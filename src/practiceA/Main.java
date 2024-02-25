import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		String[] scan;
		scan = new String[3];
		for(int i = 0; i < 3; i++) {
			scan[i] = scanner.nextLine();
		}
		scanner.close();
		// String str = "";
		// for(Scanner value: scan) {
		// 	str += value.nextLine();
		// }
		// System.out.println(str);
		int a = Integer.parseInt(scan[0]);
		String[] bc = scan[1].split(" ");
		int b = Integer.parseInt(bc[0]);
		int c = Integer.parseInt(bc[1]);
		String d = scan[2];
		String result = new Integer(a + b + c).toString() + " " + d;
		System.out.println(result);
	}
}
