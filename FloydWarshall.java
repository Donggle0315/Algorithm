import java.util.*;

public class FloydWarshall {
    public static Integer INF = Integer.MAX_VALUE;
    public static int n;
    public static int[][] distance;

    public static void init(){
        distance = new int[n][n];

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                distance[i][j] = INF;
            }
        }
    }

    public static void floydWarshall(){
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    distance[i][j] = Math.min(distance[i][j], distance[i][k] + distance[k][j]);
                }
            }
        }
    }
}
