import java.util.*;

public class GraphServices {

	public static <V> void distances(Graph<V> g) {
		for (Node<V> n : g.getNodes()) {
			initialize(g);
			HashMap<Node<V>, Integer> res = calculate_distances(g, n);
			print(res, g, n);
		}
	}

	private static <V> void initialize(Graph<V> g) {
		for (Node<V> n : g.getNodes()) {
			n.stato = Node.Stato.UNEXPLORED;
		}
	}

	private static <V> HashMap<Node<V>, Integer> calculate_distances(Graph<V> g, Node<V> s) {
		MinHeap<Node<V>> heap = new MinHeap<Node<V>>();
		HashMap<Node<V>, HeapEntry<Node<V>>> map = new HashMap<Node<V>, HeapEntry<Node<V>>>();
		HashMap<Node<V>, Integer> out = new HashMap<Node<V>, Integer>();
		for (Node<V> v : g.getNodes()) {
			if (v == s) {
				map.put(v, heap.insert(0, v));
			} else {
				map.put(v, heap.insert(100000, v));
			}
		}

		while (!heap.isEmpty()) {
			HeapEntry<Node<V>> he = heap.removeMin();
			out.put(he.getValue(), he.getKey());
			Node<V> u = he.getValue();

			for (Edge<V> e : g.getOutEdges(u)) {
				Node<V> v = e.getTarget();
				if (map.get(v).getKey() > he.getKey() + e.getWeight()) {
					HeapEntry<Node<V>> vv = map.get(v);
					map.put(v, heap.replaceKey(vv, he.getKey() + e.getWeight()));
				}
			}
		}
		return out;
	}

	private static <V> void print(HashMap<Node<V>, Integer> res, Graph<V> g, Node<V> n) {
		System.out.print("Distanze dal punto " + n.getElement() + " [");
		System.out.print(n.getElement() + ":" + res.get(n));
		for (Node<V> v : g.getNodes()) {
			if (v != n) {
				System.out.print(", " + v.getElement() + ":" + res.get(v));
			}
		}
		System.out.println("]");
	}
}
