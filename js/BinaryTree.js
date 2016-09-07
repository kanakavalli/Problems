var BinaryTree = function() {
    var root = null;
    this.createNode = function(data) {
        var node = {};
        node.data = data;
        node.left = null;
        node.right = null;
        return node;
    };
    this.setRoot = function(node) {
        root = node;
    };
    this.getRoot = function() {
        return root;
    };
    this.addLeftNodeForParent = function(parentNode, childNode) {
        parentNode.left = childNode;
    };
    this.addRightNodeForParent = function(parentNode, childNode) {
        parentNode.right = childNode;
    };
};
BinaryTree.prototype.InOrder = function(node) {
    if(node === null) {
        return;
    }
    this.printInOrder(node.left);
    console.log(" "+ node.data);
    this.printInOrder(node.right);
};
BinaryTree.prototype.GetDiameter = function(node) {
    if(node == null) {
        return {
            "height" : 0,
            "diameter" : 0
        }
    }
    var left = this.GetDiameter(node.left);
    var right = this.GetDiameter(node.right);
    var leftDiameter = left.diameter;
    var rightDiameter = right.diameter;
    var rootDiameter = left.height + right.height + 1;
    var finalDiameter = Math.max(rootDiameter, Math.max(leftDiameter, rightDiameter));
    var maxHeight = Math.max(left.height, right.height) + 1;
    return {
        "height" : maxHeight,
        "diameter" : finalDiameter
    };
};

BinaryTree.prototype.GetHeight = function(node) {
    if(node == null)
        return 0;
    var leftHeight = this.GetHeight(node.left);
    var rightHeight = this.GetHeight(node.right);
    return Math.max(leftHeight, rightHeight) +1;
};

function main() {
    var tree = new BinaryTree();
    var node1 = tree.createNode(1);
    var node2 = tree.createNode(2);
    var node3 = tree.createNode(3);
    var node4 = tree.createNode(4);
    var node5 = tree.createNode(5);
    var node6 = tree.createNode(6);
    var node7 = tree.createNode(7);
    var node8 = tree.createNode(8);
    tree.setRoot(node1);
    tree.addLeftNodeForParent(node1, node2);
    tree.addRightNodeForParent(node1, node3);
    tree.addLeftNodeForParent(node2, node4);
    tree.addRightNodeForParent(node2, node5);
    tree.addLeftNodeForParent(node4, node8);
    tree.addLeftNodeForParent(node5, node6);
    tree.addRightNodeForParent(node6, node7);
    
    tree.InOrder(tree.getRoot());
    var height = tree.GetHeight(tree.getRoot());
    console.log("Height of tree is "+height);
    var diameter = tree.GetDiameter(tree.getRoot());
    console.log("Diameter of tree is "+diameter.diameter);
}
