import java.util.*;
import java.io.*;

public class boxers {
    
    public static void main(String[]args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        int current = 0;
        PriorityQueue<Integer> test = new PriorityQueue<Integer>();
        int rslt = 0;

        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++) {
            test.add(Integer.parseInt(st.nextToken()));
        }
        
        for (int i = 0; i < N; i++) {
            int help = test.poll();
            if (help - 1 > current) {
                rslt++;
                current = help - 1;
            } else if (help > current) {
                rslt++;
                current = help;
            } else if (help + 1 > current) {
                rslt++;
                current = help + 1;
            }
        }
        System.out.println(rslt);
    }
}