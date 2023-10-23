import java.io.*;
import java.util.*;

public class trafficLight {

    public static class Segment {
        int start, end;
        boolean isDelete;

        public Segment(int value1, int value2) {
            start = value1;
            end = value2;
        }

        public int length() {
            return end - start;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int X = Integer.parseInt(st.nextToken());
        int N = Integer.parseInt(st.nextToken());
        StringBuilder sb = new StringBuilder();

        TreeSet<Segment> ts = new TreeSet<Segment>((s1, s2) -> s1.start != s2.start ? s1.start - s2.start : s2.end - s1.end);
        PriorityQueue<Segment> pq = new PriorityQueue<Segment>((s1, s2) -> s2.length() - s1.length());

        st = new StringTokenizer(br.readLine());
        Segment s = new Segment(0, X);
        pq.add(s);
        ts.add(s);

        for (int i = 0; i < N; i++) {
            int tempI = Integer.parseInt(st.nextToken());
            Segment tempS = new Segment(tempI, X);
            Segment s1 = ts.lower(tempS);
            Segment s2 = ts.higher(tempS);
            if (s2 != null)
                tempS.end = s2.start;

            if (s1 != null)
                s1.isDelete = true;

            ts.add(tempS);
            pq.add(tempS);

            if (s1 != null) {
                Segment s3 = new Segment(s1.start, tempS.start);
                
                pq.add(s3);
                ts.add(s3);
            }
            while (pq.peek().isDelete) {
                pq.poll(); ts.pollFirst();
            }
            
            sb.append(pq.peek().length());
            if (i != N - 1)
                sb.append(" ");
            
        }

        System.out.println(sb);
    }
}