import java.util.List;
import java.util.Arrays;

public class Test {
	public static void main(String[] args) {
		// List<Integer> list = Arrays.asList(1, 2, 3, 4, 5);
		List<Integer> list = Arrays.asList(12, 8, 5, 2, 9);
		// int result = list.stream().reduce(0, (p, c) -> { return p + c; });
		int max = list.stream().reduce(0, (p, c) -> { return Math.max(p, c); });
		int result = list.stream().reduce(max, (p, c) -> { return Math.min(p, c); });
		// System.out.println(list.get(3));
		System.out.println(result);
	}
}