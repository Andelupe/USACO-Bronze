import java.util.*;
import java.io.*;

public class nearestValue {

    public static class index {
        int index;
        int number;

        public index(int value1, int value2) {
            index = value1;
            number = value2;
        }
    }

    public static void main(String[]args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        StringBuilder sb = new StringBuilder();

        int N = Integer.parseInt(st.nextToken());
        Stack<index> stack = new Stack<index>();

        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++) {
            index temp = new index(i + 1, Integer.parseInt(st.nextToken()));

            check(sb, stack, temp);

            if (i != N - 1) {
                sb.append(" ");
            }
        }

        System.out.println(sb);
    }

    public static void check(StringBuilder sb, Stack<index> stack, index temp) {
        if (stack.isEmpty()) {
            stack.add(temp);
            sb.append(0);

        } else if (stack.peek().number < temp.number) {
            sb.append(stack.peek().index);
            stack.add(temp);
        } else {
            stack.pop();
            check(sb, stack, temp);
        }
    }
}