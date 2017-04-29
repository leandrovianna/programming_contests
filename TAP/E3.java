import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigInteger;
import java.util.*;

public class E3 {
    public static void main(String[] args) {
        List<Long> primes = new ArrayList<>();
        BigInteger a, b;
        String s;
        long v, min, max, p1, p2, p3, p4;

        FastReader reader = new FastReader();

        while (true) {
            primes.clear();

            s = reader.next();
            if (!Objects.equals(s, ""))
                a = new BigInteger(s);
            else break;

            s = reader.next();
            if (!Objects.equals(s, ""))
                b = new BigInteger(s);
            else break;

            for (BigInteger i = a; i.compareTo(b) <= 0; i = i.add(BigInteger.ONE)) {
                if (i.isProbablePrime(6)) {
                    primes.add(i.longValue());
                }
            }

            min = b.longValue();
            max = p1 = p2 = p3 = p4 = 0;

            for (int i = 1; i < primes.size(); i++) {
                v = primes.get(i) - primes.get(i-1);
                if (v < min) {
                    min = v;
                    p1 = primes.get(i-1);
                    p2 = primes.get(i);
                }

                if (v > max) {
                    max = v;
                    p3 = primes.get(i-1);
                    p4 = primes.get(i);
                }
            }

            if (p1 == 0)
                System.out.println("No two primes exist");
            else
                System.out.println("Closest = "+p1+","+p2+" and Furthest: "+p3+","+p4);
        }

    }

    private static class FastReader
    {
        BufferedReader br;
        StringTokenizer st;

        public FastReader()
        {
            br = new BufferedReader(new
                    InputStreamReader(System.in));
        }

        String next()
        {
            while (st == null || !st.hasMoreElements())
            {
                try
                {
                    String str = br.readLine();
                    if( str == null ) return "";
                    st = new StringTokenizer(str);
                }
                catch (IOException e)
                {
                    return "";
                }
            }
            return st.nextToken();
        }

        int nextInt()
        {
            return Integer.parseInt(next());
        }

        long nextLong()
        {
            return Long.parseLong(next());
        }

        double nextDouble()
        {
            return Double.parseDouble(next());
        }

        String nextLine()
        {
            String str = "";
            try
            {
                str = br.readLine();
            }
            catch (IOException e)
            {
                e.printStackTrace();
            }
            return str;
        }
    }
}
