public class MaxGap {

    public static int maxGap(int[] array, int start, int end) {
		if (end - start <= 2) {
			return array[end-1] - array[start];
		} else {
			int medium = (int) Math.floor((end + start)/2);
			
			int max_sx = maxGap(array, start, medium);
			int max_dx = maxGap(array, medium, end);
			int max_med = array[medium] - array[medium-1];
			
			if (max_sx > max_dx) {
				if (max_sx > max_med) return max_sx;
				return max_med;
			} else {
				if (max_dx > max_med) return max_dx;
				return max_med;
			}
		}
    }
}
