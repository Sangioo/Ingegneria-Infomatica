import java.util.HashSet;
import java.util.LinkedList;
import java.util.List;
import java.util.Scanner;
import java.io.File;
import java.io.FileNotFoundException;

public class Graph<V> {
    private LinkedList<Node<V>> nodes;

    public Graph() {
        nodes = new LinkedList<Node<V>>();
    }

    public List<Node<V>> getNodes() {
        return (List<Node<V>>) nodes;
    }

    public List<Node<V>> getNeighbors(Node<V> n) {
        return (List<Node<V>>) n.outEdges;
    }

    public Node<V> addNode(V value) {
        Node<V> n = new Node<V>();
        n.state = Node.Status.UNEXPLORED;
        n.value = value;
        n.outEdges = new LinkedList<Node<V>>();
        nodes.add(n);
        return n;
    }

    public void addEdge(Node<V> s, Node<V> t) {
        s.outEdges.add(t);
        t.outEdges.add(s);
    }

    public V getNodeValue(Node<V> n) {
        return n.value;
    }

    public void removeEdge(Node<V> v1, Node<V> v2) {
        v1.outEdges.remove(v2);
        v2.outEdges.remove(v1);
    }

    public void removeNode(Node<V> v) {
        List<Node<V>> l = getNeighbors(v);
        for (Node<V> n : l) {
            this.removeEdge(v, n);
        }
        nodes.remove(v);
    }

    public static <V> Graph<V> readFF(File input) {
        Graph<V> g = new Graph<V>();

        try {
            Scanner scan = new Scanner(input);
            String row = scan.nextLine().strip();
            int nn = Integer.parseInt(row.split(" ")[0]);

            for (int i = 0; i < nn; i++) {
                g.addNode(null);
            }

            while (scan.hasNextLine()) {
                row = scan.nextLine().strip();
                int n1 = Integer.parseInt(row.split(" ")[0]);
                int n2 = Integer.parseInt(row.split(" ")[1]);

                Node<V> s = g.nodes.get(n1 - 1);
                Node<V> t = g.nodes.get(n2 - 1);

                if (g.getNeighbors(s).contains(t) || g.getNeighbors(t).contains(s)) {
                    continue;
                }
                g.addEdge(s, t);
            }

            scan.close();

            return g;
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }
        return null;
    }

    public String printAdj() {
        StringBuilder s = new StringBuilder();
        for (Node<V> n : nodes) {
            s.append("[ " + n.value + ": ");
            for (Node<V> v : n.outEdges) {
                s.append(v.value + ", ");
            }
            s.append("]\n");
        }
        return s.toString();
    }

    @Override
    public String toString() {
        int nodes = this.nodes.size();
        int edges = 0;

        HashSet<String> e = new HashSet<String>();
        StringBuilder s = new StringBuilder();
        for (Node<V> n : this.nodes) {
            int i_n = this.nodes.indexOf(n) + 1;

            for (Node<V> v : n.outEdges) {
                int i_v = this.nodes.indexOf(v) + 1;

                if (!e.contains(i_n + " " + i_v) && !e.contains(i_v + " " + i_n)) {
                    s.append(i_n + " " + i_v + "\n");
                    e.add(i_n + " " + i_v);
                    edges++;
                }
            }
        }

        return nodes + " " + edges + "\n" + s.toString();
    }

    public int nConComp() {
        return 0;
    }

    public List<Graph<V>> getConComp() {
        return null;
    }

    /* Classe interna che descrive il generico nodo del grafo */
    public static class Node<V> implements Cloneable {
        public enum Status {
            UNEXPLORED, EXPLORED, EXPLORING
        }

        protected V value;
        protected LinkedList<Node<V>> outEdges;

        protected Status state; // tiene traccia dello stato di esplorazione

        @Override
        public String toString() {
            return "Node [value=" + value + ", state=" + state + "]";
        }

        @Override
        protected Object clone() throws CloneNotSupportedException {
            return super.clone();
        }
    }
}
