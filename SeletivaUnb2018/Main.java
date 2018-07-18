import java.util.*;
import java.math.BigInteger;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        long n = sc.nextLong();

        BigInteger big = BigInteger.valueOf(n);

        if (n == 1 || big.isProbablePrime(15)) {
            System.out.println("Nao");
        } else {
            long ans = 1;

            if (n <= 1000000000L) {
                for (long i = 2; i * i <= n; i++) {
                    if (n % i == 0) {
                        ans = i;
                        break;
                    }
                }
            } else {
                ans = pollard_rho(n);
            }

            System.out.println("Sim");
            System.out.printf("%d %d\n", ans, n / ans);
        }
    }

    private static long abs_val(long x) {
        if (x < 0) return -x;
        else return x;
    }

    private static long gcd(long a, long b) {
        return b == 0 ? a : gcd(b, a % b);
    }

    private static long pollard_rho(long n) {
        int i = 0, k = 2;
        long x = 3, y = 3;

        while (true) {
            i++;
            x = (mulmod(x, x, n) + n - 1) % n;
            long d = gcd(abs_val(y - x), n);
            if (d != 1 && d != n) return d;
            if (i == k) {
                y = x;
                k *= 2;
            }
        }
    }

    private static long mulmod(long a, long b, long c) {
        long x = 0, y = a % c;
        while (b > 0) {
            if (b % 2 == 1) x = (x + y) % c;
            y = (y * 2) % c;
            b /= 2;
        }
        return x % c;
    }
}
