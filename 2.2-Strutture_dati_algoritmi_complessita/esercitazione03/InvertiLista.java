import java.util.*;

public class InvertiLista {

    private static LinkedList<Integer> appoggio = new LinkedList<Integer>();

    public static void invertiLista(LinkedList<Integer> list) {
        if (list.isEmpty()) {
            return;
        } else {
            appoggio.addLast(list.poll());
            invertiLista(list);
            list.addFirst(appoggio.poll());
        }
    }
}
