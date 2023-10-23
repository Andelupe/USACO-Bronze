import java.util.*;
import java.io.*;

public class moocast {

    public static class cow {
        double x, y, range;

        public cow(double value1, double value2, double value3) {
            x = value1;
            y = value2;
            range = value3;
        }
    }

    static ArrayList<Integer>[] adj;
    static int[] rslt;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new FileReader("moocast.in"));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        adj = new ArrayList[N];
        int[] rslt = new int[N];
        int max = 0;

        cow[] input = new cow[N];

        for (int i = 0; i < N; i++) {
            adj[i] = new ArrayList<Integer>();
            st = new StringTokenizer(br.readLine());
            double x = Double.parseDouble(st.nextToken());
            double y = Double.parseDouble(st.nextToken());
            double range = Double.parseDouble(st.nextToken());
            cow temp = new cow(x, y, range);
            input[i] = temp;
        }

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (j == i)
                    continue;
                if ((((input[j].x - input[i].x) * (input[j].x - input[i].x))
                        + ((input[j].y - input[i].y) * (input[j].y - input[i].y))) <= (input[i].range * input[i].range)) {
                    adj[i].add(j);
                }
            }
        }

        for (int i = 0; i < N; i++) {
            boolean[] test = new boolean[N];
            dfs(i, i, rslt, adj, test);
            max = Math.max(rslt[i], max);
        }
        PrintWriter out = new PrintWriter ("moocast.out");
        out.println(max);
        
        br.close();
        out.close();
    }

    public static void dfs(int current, int stay, int[] rslt, ArrayList<Integer>[] adj, boolean[] test) {
        rslt[stay]++;
        test[current] = true;
        for (int i = 0; i < adj[current].size(); i++) {
            if (test[adj[current].get(i)] == false) {
                dfs(adj[current].get(i), stay, rslt, adj, test);
            }
        }
        return;
    }
}

// boolean adj[N][N];
// for (int i = 0; i < N; i++) {
//     for (int j = 0; j < N; j++) {
//         if (j == i)
//             continue;
//         if ((((input[j].x - input[i].x) * (input[j].x - input[i].x))
//                 + ((input[j].y - input[i].y) * (input[j].y - input[i].y))) <= (input[i].range * input[i].range)) {
//             adj[i][j] = 1;
//         }
//     }
// }

//     public static void bfs(int current, int stay, int[] rslt, ArrayList<Integer>[] adj, boolean[] test) {
//         int count = 0;
        
//         Queue<Integer> q = new LinkedList<Integer>();
//         q.add(current);

//         while (!q.isEmpty()) {
//             current = q.poll();
//             test[current] = true;
//             count++;
//             for (int i: adj[current]) {
//                 if (!test[i]) {
//                     q.add(i);
//                 }
//             }
//         }

//         rslt[stay] = count;
//     }
// }