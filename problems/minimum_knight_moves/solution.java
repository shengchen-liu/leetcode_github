class Solution {
    private static final int[] d = {2, 1, 2, -1, 2, -1, -2, 1, 2}; // 8 possible moves.
    private static final int p = 601;
    public int minKnightMoves(int x, int y) {
        x = Math.abs(x); y = Math.abs(y); // Use the symmetric property.
        Queue<Integer> q = new LinkedList<>();
        q.offer(0);
        Set<Integer> seen = new HashSet<>(q);
        for (int steps = 0; !q.isEmpty(); ++steps) {
            for (int sz = q.size(); sz > 0; --sz) {
                int i = q.peek() / p, j = q.poll() % p;
                if (i == x && j == y) 
                    return steps;
                for (int k = 0; k < 8; ++k) {
                    int r = i + d[k], c = j + d[k + 1];
                    if (r >= -2 && c >= -2 && seen.add(r * p + c)) {
                        q.offer(r * p + c);
                    }
                }
            }
        }
        return -1;
    }
}