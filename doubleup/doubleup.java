import java.math.BigInteger;
import java.util.Scanner;
import java.util.Stack;

class DoubleUp {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        Stack<BigInteger> s = new Stack<>();

        Integer n = scanner.nextInt();
        BigInteger t;

        for (int i = 0; i < n; i++) {
            t = scanner.nextBigInteger();

            Boolean finished = true;
            while (finished) {
                if (s.empty() || t.compareTo(s.peek()) == -1) {
                    s.push(t);
                    finished = false;
                } else if (t.compareTo(s.peek()) == 0) {
                    t = t.multiply(BigInteger.valueOf(2));
                    s.pop();
                } else {
                    s.pop();
                }
            }
        }

        while (s.size() != 1)
            s.pop();

        System.out.println(s.peek());

        scanner.close();
    }
}
