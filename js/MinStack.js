/*** Min Stack problem in js ***/

/**
 * Stack class is the base class which does push pop on stack.
 * SpecialStack class is the main stack we will be perform operations on.
 * SpecialStack internally maintains a temporary stack which stores min values pushed onto stack so far.
 * When an item is pushed into SpecialStack, if [item] < [top item of temp stack], then it pushes item on to temp stack and calls basic class Stack push
 * When an item is popped from SpecialStack, if [poppeditem] = [top item of temp stack], then an item is popped from temp stack.
 */
 
var Stack = function(sizeOfStack) {
    var stackSize = sizeOfStack;
    var stackArr = [];
    var head = -1;

    this.getItemFromStackArrAtIndex = function(index) {
        return stackArr[index];
    };
    this.putIntoStackArr = function(index, item) {
        stackArr[index] = item;
    };
    this.getHead = function() {
        return head;
    };
    this.setHead = function(tempHead) {
        head = tempHead;
    }
    this.isFull = function() {
        if(head === sizeOfStack-1) {
            return true;
        } else {
            return false;
        }
    };
    this.isEmpty = function() {
        if(head == -1) {
            return true;
        } else {
            return false;
        }
    };
    this.getSize = function() {
        return head+1;
    };
    this.getTopElement = function() {
        if(!this.isEmpty())
            return stackArr[head];
        else
            return -99999;
    }
}

Stack.prototype.push = function(item) {
    if(this.isFull()) {
        console.log("Stack is full!!");
        return false;
    }
    var head = this.getHead();
    this.setHead(++head);
    this.putIntoStackArr(head, item);
    return true;
};
Stack.prototype.pop = function() {
    if(this.isEmpty()) {
        console.log("Stack is empty!!");
        return false;
    }
    var head = this.getHead();
    var poppedItem = this.getItemFromStackArrAtIndex(head);
    this.setHead(--head);
    return poppedItem;
};

var SpecialStack = function (size) {
    Stack.call(this, size);
    this.temperoryStack = new Stack(size);
    this.getMin = function() {
        return this.temperoryStack.getTopElement();
    };
    this.push = function(element) {
        if(Stack.prototype.push.call(this, element)){
            if(this.temperoryStack.isEmpty() || element <= this.temperoryStack.getTopElement()) {
                this.temperoryStack.push(element);
            }
        }
    };
    this.pop = function() {
        var poppedElement = Stack.prototype.pop.call(this);
        console.log(" popped item "+ poppedElement);
        if(poppedElement == this.temperoryStack.getTopElement()) {
            this.temperoryStack.pop();
        }
    };
};

SpecialStack.prototype = Object.create(Stack.prototype);

function main() {
    var sizeOfStack = 5;
    var stack = new SpecialStack(sizeOfStack);
    stack.push(16);
    stack.push(15);
    console.log(" Get min from stack - "+stack.getMin());
    stack.push(29);
    stack.push(10);
    console.log(" Get min from stack - "+stack.getMin());
    stack.push(18);
    stack.push(5);
    console.log(" Get min from stack - "+stack.getMin());
    stack.pop();
    stack.push(5);
    console.log(" Get min from stack - "+stack.getMin());
}

main();
