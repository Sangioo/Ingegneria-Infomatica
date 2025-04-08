public class MatriceSparsa {
	private int m, n;
	private Elem head;

    private class Elem{
		int i;
		int j;
		int x;
		Elem next;

		Elem(int i, int j, int x, Elem next) {
			this.i = i;
			this.j = j;
			this.x = x;
			this.next = next;
		}
    }


    public MatriceSparsa(int m, int n) {
		this.m = m;
		this.n = n;
		this.head = null;
    }

    public int getNumRow() {
        return this.m;
    }

    public int getNumCol() {
        return this.n;
    }

    public void set(int i, int j, int x) {
		if (x == 0) return;
		if (head == null) {
			head = new Elem(i, j, x, null);
		} else {
			set_help(i, j, x, head);
		}
    }

    private void set_help(int i, int j, int x, Elem e) {
		if (e.i == i && e.j == j) {
			e.x = x;
			return;
		} else if (e.next == null) {
			Elem n = new Elem(i, j, x, e.next);
			e.next = n;
			return;
		} else {
			set_help(i, j, x, e.next);
		}
	}

    public int get(int i, int j) {
        return get_help(i, j, head);
    }

    private int get_help(int i, int j, Elem e) {
		if (e.i == i && e.j == j) {
			return e.x;
		} else if (e.next == null) {
			return 0;
		} else {
			return get_help(i, j, e.next);
		}
	}

    public String toString() {
        StringBuilder ss = new StringBuilder();
		for (int i=0; i<m; i++) {
			for (int j=0; j<n; j++) {
				int x = this.get(i, j);
				if (x < 10) {
					ss.append(x + "  ");
				} else {
					ss.append(x + " ");
				}
			}
			ss.append("\n");
		}
        return ss.toString();
    }

    public MatriceSparsa add(MatriceSparsa mat1, MatriceSparsa mat2) {
        if (mat1.getNumCol() != mat2.getNumCol() || mat1.getNumRow() != mat2.getNumRow()) return null;

		int m = mat1.getNumRow(), n = mat1.getNumCol();
        MatriceSparsa mat = new MatriceSparsa(m, n);
        for (int i=0; i<m; i++) {
			for (int j=0; j<n; j++) {
				mat.set(i, j, mat1.get(i, j) + mat2.get(i, j));
			}
		}
		return mat;
    }

    public MatriceSparsa tra(MatriceSparsa mat) {
        int m = mat.getNumRow(), n = mat.getNumCol();
        MatriceSparsa out = new MatriceSparsa(m, n);
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                out.set(i, j, mat.get(j, i));
            }
        }
        return out;
    }

    public MatriceSparsa mul(MatriceSparsa mat1, MatriceSparsa mat2) {
        if (mat1.getNumCol() != mat2.getNumRow()) return null;

        int m = mat1.getNumRow(), n = mat2.getNumCol();
        MatriceSparsa out = new MatriceSparsa(m, n);
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                int num = 0;
                for (int k=0; k<mat2.getNumCol(); k++) {
                    num += mat1.get(i, k) * mat2.get(k, j);
                }
                out.set(i, j, num);
            }
        }
        return this.tra(out);
    }
}
