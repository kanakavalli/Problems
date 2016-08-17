/* package codechef; // don't place package name! */

import java.util.*;
import java.lang.*;
import java.io.*;

/* Name of the class has to be "Main" only if the class is public. */
class CutRodDP
{
    private static int cutRod(int[] prices, int size) {
        if(size == 0)
            return 0;
        int q = -100;
        for(int i=1; i<=size; i++) {
            q = Math.max(q, prices[i-1]+cutRod(prices, size-i));
        }
        return q;
    }
	public static void main (String[] args) throws java.lang.Exception {
		int[] prices = {1, 5, 8, 9, 10, 17, 17, 20, 24, 30};
		int cutRodOfSize = 10;
		//System.out.println("------"+Math.max(-2147483648, 10));
		int maxRevenue = cutRod(prices, cutRodOfSize);
		System.out.println("Max revence is "+maxRevenue);
	}
}
