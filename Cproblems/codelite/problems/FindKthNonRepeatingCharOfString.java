package problems;

import java.util.Arrays;

public class FindKthNonRepeatingCharOfString {

	public static void main(String[] args) {
		String inputStrig = "geeksforgeeks";
		int kValue = 4;
		char kThNonRepeatingChar = findKthNonRepeatingChar(inputStrig, kValue);
		if(kThNonRepeatingChar == 0)
			System.out.println("Character not found");
		else 
			System.out.println(" kThNonRepeatingChar char "+ kThNonRepeatingChar);
	}

	private static char findKthNonRepeatingChar(String inputString, int kValue) {
		String uniqueChars = "";
		int inputStrLength = inputString.length();
		int[] charHashArr = new int[26];
		char kThNonRepeatingChar = 0;
		Arrays.fill(charHashArr, 0);
		for (int i = 0; i < inputStrLength; i++) {
			int asciiValue = (int) inputString.charAt(i);
			if(charHashArr[asciiValue - 97] == 0)
				uniqueChars = uniqueChars + inputString.charAt(i);
			charHashArr[asciiValue - 97] += 1;
		}
		int count = 0;
		for(int j=0; j<uniqueChars.length(); j++){
			int ascii = (int) uniqueChars.charAt(j);
			int index = ascii - 97;
			if(charHashArr[index] == 1)
				count++;
			if(count == kValue) {
				kThNonRepeatingChar = uniqueChars.charAt(j);
				break;
			}
		}
		return kThNonRepeatingChar;
	}
}
