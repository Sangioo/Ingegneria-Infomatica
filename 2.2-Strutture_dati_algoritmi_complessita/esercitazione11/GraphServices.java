import java.util.*;

public class GraphServices {

    public static <V> void bfs(Graph<V> g) {
        LinkedList<Node<V>> q = new LinkedList<Node<V>>();

        for (Node<V> n : g.getNodes()) {
            n.state = Node.Status.UNEXPLORED;
        }

        for (Node<V> n : g.getNodes()) {
            if (n.state == Node.Status.UNEXPLORED) {
                bfs_aux(n, g, q);
            }
        }

        System.out.print("[ ");
        for (Node<V> n : q) {
            System.out.print(n.getValue() + ", ");
        }
        System.out.println("]");
    }

    private static <V> void bfs_aux(Node<V> s, Graph<V> g, LinkedList<Node<V>> l) {
        s.state = Node.Status.EXPLORING;

        LinkedList<Node<V>> q = new LinkedList<Node<V>>();
        q.add(s);

        while (!q.isEmpty()) {
            Node<V> u = q.pop();
            l.addLast(u);
            for (Edge<V> e : g.getOutEdges(u)) {
                Node<V> v = e.getTarget();
                if (v.state == Node.Status.UNEXPLORED) {
                    v.state = Node.Status.EXPLORING;
                    q.addLast(v);
                }
            }
            u.state = Node.Status.EXPLORED;
        }
    }

    public static <V> void sssp(Graph<V> g, Node<V> source) {
        MinHeap<Node<V>> not_visited = new MinHeap<Node<V>>();
        HashMap<Node<V>, HeapEntry<Node<V>>> nv_aux = new HashMap<Node<V>, HeapEntry<Node<V>>>();
        HashSet<Node<V>> visited = new HashSet<Node<V>>();

        for (Node<V> v : g.getNodes()) {
            if (v == source) {
                source.dist = 0;
            } else {
                v.dist = Integer.MAX_VALUE;
            }
            HeapEntry<Node<V>> e = not_visited.insert(v.dist, v);
            nv_aux.put(v, e);
        }

        while (!not_visited.isEmpty()) {
            System.out.println(not_visited.getMin());
            Node<V> u = not_visited.removeMin().getValue();
            visited.add(u);
            for (Edge<V> e : g.getOutEdges(u)) {
                Node<V> v = e.getTarget();
                relax(u, v, e.getWeight());
                not_visited.replaceKey(nv_aux.get(v), v.dist);
            }
        }

        for (Node<V> n : visited) {
            System.out.println("[ " + n.getValue() + ", dist = " + n.dist + " ]");
        }
    }

    private static <V> void relax(Node<V> u, Node<V> v, int w) {
        if (v.dist > u.dist + w) {
            v.dist = u.dist + w;
        }
    }

    public static <V> void mst(Graph<V> G) {

    }
}
