import java.util.Scanner;
// import java.util.List;
// import java.util.Arrays;

public class Main {
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		String s = scanner.nextLine();
		scanner.close();
		// System.out.println(check(s) ? "YES" : "NO");
		boolean result = false;
		String[] add = { "dream", "dreamer", "erase", "eraser" };
		for(int i = 0; i < add.length; i++) {
			String[] arr = s.split(add[add.length - i - 1]);
			s = "";
			for(String v: arr) {
				s += v;
			}
			// System.out.println(s);
			if(s.length() == 0) {
				result = true;
				break;
			}
		}
		System.out.println(result ? "YES" : "NO");
	}
	// public static boolean check(String s) {
	// 	boolean result = false;
	// 	String[] add = { "dream", "dreamer", "erase", "eraser" };
	// 	for(int i = 0; i < add.length; i++) {
	// 		String[] arr = s.split(add[add.length - i - 1]);
	// 		s = "";
	// 		for(String v: arr) {
	// 			s += v;
	// 		}
	// 		// System.out.println(s);
	// 		if(s.length() == 0) {
	// 			result = true;
	// 			break;
	// 		}
	// 	}
	// 	return result;
	// }
}
