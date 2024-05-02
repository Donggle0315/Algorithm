import java.util.*;

public class GraphTraversal {
    public static int n;
    public static boolean[] visited;
    public static int[][] data;

    public static void dfs(int start) {
        if (visited[start]) return;
        visited[start] = true;
        for (int i = 0; i < n; i++) {
            if (data[start][i] == 1 && !visited[i]) {
                dfs(i);
            }
        }
    }

    public static void bfs(int start) {
        Queue<Integer> q = new LinkedList<>();
        q.add(start);

        while (!q.isEmpty()) {
            int now = q.poll();
            if (visited[now]) continue;
            visited[now] = true;

            for (int i = 0; i < n; i++) {
                if (data[now][i] == 1 && !visited[i]) {
                    q.add(i);
                }
            }
        }
    }
}
