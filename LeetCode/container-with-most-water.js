/**
 * @param {number[]} height
 * @return {number}
 */
 /**
 * https://leetcode.com/problems/container-with-most-water/submissions/
 */
var maxArea = function(height) {
    var p1 = 0;
    var p2 = height.length -1;
    var max = 0;
    var inBetween = height.length -1;
    while (p1 <= p2) {
        var line1 = height[p1];
        var line2 = height[p2];
        var least = line1 <= line2 ? line1 : line2;
        var newMax = least * inBetween;
        if (newMax > max) {
            max = newMax;
        }
        if (line1 <= line2) {
            p1 += 1;	
        } else {
            p2 -= 1;
        }
        inBetween -= 1;
    }
    return max;
};
