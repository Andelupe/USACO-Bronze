import java.util.*;
import java.io.*;

public class highcard {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new FileReader("src/highcard.in"));
        int N = Integer.parseInt(br.readLine());
        HashSet<Integer> Ocard = new HashSet<Integer>();
        int rslt = 0; 
        int OV = 0;

        for (int i = 0; i < N; i++) Ocard.add(Integer.parseInt(br.readLine()));
        
        for (int i = 1; i < (2 * N) + 1; i++) {
            if (Ocard.contains(i)) {
                OV++;
            } else if (OV > 0) {
                OV--; rslt++;
            }
        }
        
        PrintWriter out = new PrintWriter("src/highcard.out");
        out.println(rslt);
        out.close();
        br.close();
    }
}