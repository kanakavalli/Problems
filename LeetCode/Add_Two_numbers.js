/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */
/**
 * @param {ListNode} l1
 * @param {ListNode} l2
 * @return {ListNode}
 */
function ListNode(val) {
    this.val = val;
    this.next = null;
}
var addTwoNumbers = function(l1, l2) {
    debugger;
    var output = null;
    var head = output;
    var carry = 0;
    while(l1 && l2) {
        var total = l1.val + l2.val + carry;
        var baseVal = total;
        if (total > 9) {
            carry = Math.floor(total/10);
            baseVal = (total % 10);
        } else {
            carry = 0;
        }
        var newNode = new ListNode(baseVal);
        if(output){
            output.next = newNode;
            output = output.next;
        } else {
            output = newNode;
            head = output;
        }
        l1 = l1.next;
        l2 = l2.next;
    }
    var val = l1 ? l1.val : (l2 ? l2.val : -1);
    var leftOutLL = l1 ? l1 : (l2 ? l2 : null);
    
    while(leftOutLL) {
        total = leftOutLL.val + carry;
        if(total > 9) {
            carry = Math.floor(total/10);
            baseVal = (total % 10);
            output.next = new ListNode(baseVal);
            output = output.next;
            leftOutLL = leftOutLL.next;
        } else {
            carry = 0;
            output.next = new ListNode(total);
            if(leftOutLL.next) {
                output.next.next = leftOutLL.next;    
            }
            break;
        }
    }
    if(carry > 0){
        output.next = new ListNode(carry);
    }
    return head;
};
