import java.util.*;
import java.io.*;

public class shovel {
    
    public static void main(String[]args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int K = Integer.parseInt(st.nextToken());
        int N = Integer.parseInt(st.nextToken());
        int rslt = 0;
        int Oremain = K % 10;
        int Cremain = -1;
        int current = 1;

        
        while (Cremain != N) {
            if (Oremain == N) {
                rslt++;
                break;
            }
            Cremain = (Oremain * current) % 10;
            current++;
            rslt++;

            if (Oremain == 0 || Cremain == 0) {
                break;
            }
        }
        System.out.println(rslt);
    }
}
