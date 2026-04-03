public class Driver {
	
	private Driver() {}
	
	public static void main(String[] args) {
		Graph<String> gra = new Graph<String>();
	
		Node<String> a = new Node<String>(new String("a"));
		Node<String> b = new Node<String>(new String("b"));		
		Node<String> c = new Node<String>(new String("c"));		
		Node<String> d = new Node<String>(new String("d"));
		Node<String> e = new Node<String>(new String("e"));
		Node<String> f = new Node<String>(new String("f"));
		
		gra.insertNode(a); 		
		gra.insertNode(b); 		
		gra.insertNode(c); 		
		gra.insertNode(d); 		
		gra.insertNode(e); 		
		gra.insertNode(f); 		
	
		gra.insertEdge(a, b, 2);
		gra.insertEdge(a, c, 1);
		gra.insertEdge(a, d, 5);
		gra.insertEdge(b, c, 2);
		gra.insertEdge(b, d, 3);
		gra.insertEdge(c, d, 3);
		gra.insertEdge(c, e, 1);		
		gra.insertEdge(e, d, 1);
		gra.insertEdge(d, f, 5);		
		gra.insertEdge(e, f, 2);
		
		System.out.println("Grafo:");
		System.out.println(gra);
		
				
		
		// Test per cammini minimi
		System.out.println("Cammini minimi da tutti i nodi:");
		System.out.println();
		System.out.println("Il tuo programma dovrebbe stampare:");
		System.out.println("Distanze dal nodo c [c:0, e:1, d:2, f:3, b:100000, a:100000]");
		System.out.println("Distanze dal nodo e [c:100000, e:0, d:1, f:2, b:100000, a:100000]");
		System.out.println("Distanze dal nodo d [c:100000, e:100000, d:0, f:5, b:100000, a:100000]");
		System.out.println("Distanze dal nodo f [c:100000, e:100000, d:100000, f:0, b:100000, a:100000]");
		System.out.println("Distanze dal nodo b [c:2, e:3, d:3, f:5, b:0, a:100000]");
		System.out.println("Distanze dal nodo a [c:1, e:2, d:3, f:4, b:2, a:0]");
		System.out.println();
		System.out.println("Il tuo programma stampa:");
		GraphServices.distances(gra);
		System.out.println("");

		
	}
}
