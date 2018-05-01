import java.util.Scanner;
// import java.util.List;
// import java.util.Arrays;

public class Main {
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		// int N = scanner.nextInt();
		// String[] a_array = scanner.nextLine().split(" ");
		// scanner.close();
		// List<String> a_str = Arrays.asList(a_array);
		// int[] a = a_str.stream().mapToInt(Integer::parseInt).toArray();
		// int[] points = new int[2];
		// for(int i = 0; i <= N; i++) {
		// 	points[i % 2] = max(a);
		// }
		// System.out.println(points[0] - points[1]);
		String[] scan = new String[2];
		for(int i = 0; i < 2; i++) {
			scan[i] = scanner.nextLine();
		}
		scanner.close();
		int N = Integer.parseInt(scan[0]);
		String[] a = scan[1].split(" ");
		int[] points = { 0, 0 };
		for(int i = 1; i <= N; i++) {
			// System.out.println(String.valueOf(points[0]) + ", " + String.valueOf(points[1]));
			int maxIndex = maxIndex(a);
			points[(i - 1) % 2] += Integer.parseInt(a[maxIndex]);
			a[maxIndex] = String.valueOf(-1);
		}
		System.out.println(points[0] - points[1]);
	}
	public static int max(int[] arr) {
		int max = arr[0];
		for(int v: arr) {
			if(max < v) max = v;
		}
		return max;
	}
	public static int maxIndex(String[] arr) {
		int maxIndex = 0;
		for(int i = 0; i < arr.length; i++) {
			if(Integer.parseInt(arr[maxIndex]) < Integer.parseInt(arr[i])) maxIndex = i;
		}
		return maxIndex;
	}
}
