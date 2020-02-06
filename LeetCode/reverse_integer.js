/**
 * @param {number} x
 * @return {number}
 */
var reverse = function(x) {
    var multiplyWith = 1;
    var outputArr = [];
    var isNegative = false;
    if(x < 0){
        isNegative = true;
        x *= -1;
    }
    while(x > 0) {
        outputArr.push(x%10);
        x = Math.floor(x/10);
        multiplyWith = multiplyWith*10;
    }
    multiplyWith = multiplyWith/10;
    var reverse = 0;
    for(var i=0; i<outputArr.length; i++) {
        reverse += outputArr[i] * multiplyWith;
        multiplyWith = multiplyWith/10;
    }
    if(isNegative){
        reverse *= -1;
    }
    var range = Math.pow(2,31);
    if(reverse > range-1 || reverse < (range*-1)) {
        return 0;
    }
    return reverse;
};
