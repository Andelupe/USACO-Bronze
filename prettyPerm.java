import java.io.*;
import java.util.*;

public class prettyPerm {
    public static void main(String[]args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken());
        int[] tests = new int[N];
        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            tests[i] = Integer.parseInt(st.nextToken());
        }

        for (int i = 0; i < tests.length; i++) {
            int current = 1;
            StringBuilder sb = new StringBuilder();
            if (tests[i] % 2 == 0) {
                printEven(current, sb, tests[i]);
            } else {
                printOdd(current, sb, tests[i]);
            }
            System.out.println(sb);
        }
    }

    public static void printEven(int current, StringBuilder sb, int end) {
        if (current >= end) return;
        int temp = current + 1;
        sb.append(temp + " " + current + " ");
        current += 2;
        printEven(current, sb, end);
    }

    public static void printOdd(int current, StringBuilder sb, int end) {
        int temp = current + 1;
        if (current == end - 2) {
            sb.append(end + " " + current + " " + temp);
            return;
        } else {
            sb.append(temp + " " + current + " ");
            current += 2;
            printOdd(current, sb, end);
        }
    }
}
