public class DisjointSet {
    public static int[] parent;
    public static int[] height;
    public static int N;
    
    public static void init() {
        parent = new int[N];
        for (int i = 0; i < N; i++) {
            parent[i] = i;
        }
        height = new int[N];
    }

    public static int find(int x) {
        if (x == parent[x]) return x;
        parent[x] = find(parent[x]);
        return parent[x];
    }

    public static void union(int x, int y) {
        int px = find(x);
        int py = find(y);
        if (px == py) return;
        if (height[px] < height[py]) {
            int temp = px;
            px = py;
            py = temp;
        }
        parent[py] = px;
        if (height[py] == height[px]) height[px]++;
    }
}