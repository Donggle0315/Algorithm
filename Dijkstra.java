import java.util.*;

public class Dijkstra {
    
    public static Integer INF = Integer.MAX_VALUE;
    public static int[] distance;
    public static PriorityQueue<int[]> pq = new PriorityQueue<>();
    public static ArrayList<int[]>[] edges;

    public static void init(int N) {
        distance = new int[N];
        for (int i = 0; i < N; i++) {
            distance[i] = INF;
        }
    }

    public static void dijkstra(int start) {
        distance[start] = 0;
        pq.add(new int[]{0, start});

        while(!pq.isEmpty()) {
            int[] tmp = pq.poll();
            int weight = tmp[0];
            int now = tmp[1];

            if (distance[now] < weight) continue;
            for (int[] next : edges[now]) {
                int nextWeight = next[0] + weight;
                if (nextWeight < distance[next[1]]) {
                    distance[next[1]] = nextWeight;
                    pq.add(new int[]{nextWeight, next[1]});
                }
            }
        }
    }
}
