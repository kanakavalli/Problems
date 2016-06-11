package sorts;

public class BubbleSort {

	public static void main(String[] args) {
		int[] inputArray = { 3, 23, 46, 2, 3, 1, 6 };
		int[] sortedArray = bubbleSort(inputArray);
		System.out.println("Sorted array is " + sortedArray.toString());
	}

	private static int[] bubbleSort(int[] inputArray) {
		int inputArrLen = inputArray.length;
		for (int i = 0; i < inputArrLen; i++) {
			for (int j = 0; j < inputArrLen - 1; j++) {
				if (inputArray[j] > inputArray[j + 1]) {
					int temp = inputArray[j];
					inputArray[j] = inputArray[j + 1];
					inputArray[j + 1] = temp;
				}
			}
		}
		return inputArray;
	}
}
