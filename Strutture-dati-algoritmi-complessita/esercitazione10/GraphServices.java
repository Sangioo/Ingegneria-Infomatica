import java.util.LinkedList;

public class GraphServices<V> {
    private static int time;

    public static <V> void sweep(Graph<V> g) {
        g.resetStatus();
        time = 0;
        for (Graph.Node<V> n : g.getNodes()) {
            if (n.state == Graph.Node.Status.UNEXPLORED) {
                sweepVisit(g, n);
            }
        }
    }

    private static <V> void sweepVisit(Graph<V> g, Graph.Node<V> n) {
        time++;
        n.timestamp = time;
        n.state = Graph.Node.Status.EXPLORING;

        for (Graph.Node<V> neighbor : n.outEdges) {
            if (neighbor.state == Graph.Node.Status.UNEXPLORED) {
                System.out.println(n.value + " -> " + neighbor.value + ": TREE");
                sweepVisit(g, neighbor);
            } else if (neighbor.state == Graph.Node.Status.EXPLORING) {
                System.out.println(n.value + " -> " + neighbor.value + ": BACK");
            } else if (neighbor.state == Graph.Node.Status.EXPLORED) {
                if (neighbor.timestamp > n.timestamp) {
                    System.out.println(n.value + " -> " + neighbor.value + ": FORWARD");
                } else {
                    System.out.println(n.value + " -> " + neighbor.value + ": CROSS");
                }
            }
        }

        time++;
        n.state = Graph.Node.Status.EXPLORED;
    }

    public static <V> void topologicalSort(Graph<V> g) {
        g.resetStatus();
        time = 0;
        LinkedList<Graph.Node<V>> l = new LinkedList<Graph.Node<V>>();
        for (Graph.Node<V> n : g.getNodes()) {
            if (n.state == Graph.Node.Status.UNEXPLORED) {
                topVisit(g, n, l);
            }
        }

        // FAIL
        if (l.size() != g.getNodes().size()) {
            System.out.println("grafo ciclico!\n");
            return;
        }

        // SUCCESS
        for (Graph.Node<V> n : l) {
            System.out.print(n.value + ", ");
        }
        System.out.println();
    }

    private static <V> void topVisit(Graph<V> g, Graph.Node<V> n, LinkedList<Graph.Node<V>> l) {
        time++;
        n.state = Graph.Node.Status.EXPLORING;

        for (Graph.Node<V> neighbor : n.outEdges) {
            if (neighbor.state == Graph.Node.Status.UNEXPLORED) {
                topVisit(g, neighbor, l);
            } else if (neighbor.state == Graph.Node.Status.EXPLORING) {
                return;
            }
        }

        time++;
        n.timestamp = time;
        n.state = Graph.Node.Status.EXPLORED;
        l.addFirst(n);
    }

    public static <V> void strongConnectedComponents(Graph<V> g) {
        g.resetStatus();
    }
}
