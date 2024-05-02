public class SegmentTree {
    public static int[] segTree;
    public static int[] data;

    public static void build(int idx, int start, int end) {
        if (start == end) {
            segTree[idx] = data[start - 1];
            return;
        }

        int mid = (int)((start + end) / 2);
        build(idx * 2, start, mid);
        build(idx * 2 + 1, mid + 1, end);
        segTree[idx] = segTree[idx * 2] + segTree[idx * 2 + 1];
    }

    public static int query(int idx, int start, int end, int left, int right) {
        if (end < left || right < start) return 0;
        if (left <= start && end <= right) return segTree[idx];

        int mid = (int)((start + end) / 2);
        int leftChild = query(idx * 2, start, mid, left, right);
        int rightChild = query(idx * 2 + 1, mid + 1, end, left, right);
        return leftChild + rightChild;
    }

    public static void update(int idx, int start, int end, int value, int updateIdx) {
        if (updateIdx < start || end < updateIdx) return;
        segTree[idx] += value;
        if (start == end) return;
        int mid = (int)((start + end) / 2);
        update(idx * 2, start, mid, value, updateIdx);
        update(idx * 2 + 1, mid + 1, end, value, updateIdx);
    }
}
