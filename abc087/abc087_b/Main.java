import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		Integer[] scan = new Integer[4];
		for(int i = 0; i < 4; i++) {
			scan[i] = scanner.nextInt();
		}
		scanner.close();
		int count = 0;
		for(int i = 0; i <= scan[0]; i++) {
			for(int j = 0; j <= scan[1]; j++) {
				for(int k = 0; k <= scan[2]; k++) {
					if(500 * i + 100 * j + 50 * k == scan[3]) count++;
				}
			}
		}
		System.out.println(count);
	}
}
