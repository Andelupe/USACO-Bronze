import java.util.*;
import java.io.*;

public class adjDiff {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            int T = Integer.parseInt(st.nextToken());
            int[] test = new int[T];
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < T; j++) {
                test[j] = Integer.parseInt(st.nextToken());
            }
            Arrays.sort(test);

            if (T % 2 == 0) {
                int start = (T / 2) - 1;
                StringBuilder sb = new StringBuilder();
                int add = 1;
                for (int j = start; j >= 0; j--) {
                    sb.append(test[j] + " " + test[j + add] + " ");
                    add += 2;
                }
                sb.delete(sb.length() - 1, sb.length() + 2);
                System.out.println(sb);
            } else {
                StringBuilder sb = new StringBuilder();
                int start = (T - 1) / 2;
                sb.append(test[start] + " ");
                start--;
                int add = 2;
                for (int j = start; j >= 0; j--) {
                    sb.append(test[j] + " " + test[j + add] + " ");
                    add += 2;
                }
                sb.delete(sb.length() - 1, sb.length() + 2);
                System.out.println(sb);
            }
        }
    }
}