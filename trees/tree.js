const LEFT = Symbol('left');
const RIGHT = Symbol('right');


class BinaryTreeNode {
  constructor(value) {
    this.value = value;
    this.left = null;
    this.right = null;
    this.meta = {};
    this.parent = null;
    this.parentSide = null;
  }

  // tag::setAndUpdateParent[]
  /**
   * Set a left node descendants.
   * Also, children get associated to parent.
   */
  setLeftAndUpdateParent(node) {
    this.left = node;
    if (node) {
      node.parent = this;
      node.parentSide = LEFT;
    }
  }

  /**
   * Set a right node descendants.
   * Also, children get associated to parent.
   */
  setRightAndUpdateParent(node) {
    this.right = node;
    if (node) {
      node.parent = this;
      node.parentSide = RIGHT;
    }
  }
  // end::setAndUpdateParent[]

  /**
   * Tell if is parent's left or right child
   *
   * @returns {string} side (left or right) this node is of its parent
   */
  get parentChildSide() {
    if (this.parent) {
      return this.isParentLeftChild ? 'left' : 'right';
    }

    return 'root';
  }

  /**
   * Return true if this node is its parent left child
   */
  get isParentLeftChild() {
    return this.parentSide === LEFT;
  }

  /**
   * Return true if this node is its parent right child
   */
  get isParentRightChild() {
    return this.parentSide === RIGHT;
  }

  /**
   * Node is leaf is it has no descendants
   */
  get isLeaf() {
    return !this.left && !this.right;
  }

  /**
   * Get sibling of current node
   */
  get sibling() {
    const { parent } = this;
    if (!parent) return null;
    return parent.right === this ? parent.left : parent.right;
  }

  /**
   * Get parent sibling = uncle (duh)
   */
  get uncle() {
    const { parent } = this;
    if (!parent) return null;
    return parent.sibling;
  }

  get grandparent() {
    const { parent } = this;
    return parent && parent.parent;
  }

  /**
   * Get color
   */
  get color() {
    return this.meta.color;
  }

  /**
   * Set Color
   */
  set color(value) {
    this.meta.color = value;
  }

  // tag::avl[]
  /**
   * @returns {Number} left subtree height or 0 if no left child
   */
  get leftSubtreeHeight() {
    return this.left ? this.left.height + 1 : 0;
  }

  /**
   * @returns {Number} right subtree height or 0 if no right child
   */
  get rightSubtreeHeight() {
    return this.right ? this.right.height + 1 : 0;
  }

  /**
   * Get the max height of the subtrees.
   *
   * It recursively goes into each children calculating the height
   *
   * Height: distance from the deepest leaf to this node
   */
  get height() {
    return Math.max(this.leftSubtreeHeight, this.rightSubtreeHeight);
  }

  /**
   * Returns the difference the heights on the left and right subtrees
   */
  get balanceFactor() {
    return this.leftSubtreeHeight - this.rightSubtreeHeight;
  }
  // end::avl[]

  /**
   * Serialize node's values
   */
  toValues() {
    return {
      value: this.value,
      left: this.left && this.left.value,
      right: this.right && this.right.value,
      parent: this.parent && this.parent.value,
      parentSide: this.parentSide,
    };
  }

  /**
   * Get and Set data value
   * @param {any} value (optional) if not provided is a getter, otherwise a setter.
   */
  data(value) {
    if (value === undefined) {
      return this.meta.data;
    }
    this.meta.data = value;
    return this;
  }

  /**
   * Convert Binary tree from an iterable (e.g. array)
   * @param {array|string} iterable - The iterable
   */
  static from(iterable = []) {
    const toBinaryTree = (array, index = 0) => {
      if (index >= array.length) return null;
      const node = new BinaryTreeNode(array[index]);
      node.setLeftAndUpdateParent(toBinaryTree(array, index * 2 + 1));
      node.setRightAndUpdateParent(toBinaryTree(array, index * 2 + 2));
      return node;
    };
    return toBinaryTree(Array.from(iterable));
  }
}

BinaryTreeNode.RIGHT = RIGHT;
BinaryTreeNode.LEFT = LEFT;

class BinarySearchTree {
  class BinarySearchTree {
    constructor() {
      this.root = null;
      this.size = 0;
    }
    // end::snippet[]

    // tag::add[]
    /**
     * Insert value on the BST.
     *
     * If the value is already in the tree,
     * then it increases the multiplicity value
     * @param {any} value node's value to insert in the tree
     * @returns {BinaryTreeNode} newly added node
     */
    add(value) {
      let node = new BinaryTreeNode(value);

      if (this.root) {
        const { found, parent } = this.findNodeAndParent(value); // <1>
        if (found) { // duplicated: value already exist on the tree
          found.meta.multiplicity = (found.meta.multiplicity || 1) + 1; // <2>
          node = found;
        } else if (value < parent.value) {
          parent.setLeftAndUpdateParent(node);
        } else {
          parent.setRightAndUpdateParent(node);
        }
      } else {
        this.root = node;
      }

      this.size += 1;
      return node;
    }
    // end::add[]

    /**
     * Find if a node is present or not
     * @param {any} value node to find
     * @returns {boolean} true if is present, false otherwise
     */
    has(value) {
      return !!this.find(value);
    }

    // tag::find[]
    /**
     * @param {any} value value to find
     * @returns {BinaryTreeNode|null} node if it found it or null if not
     */
    find(value) {
      return this.findNodeAndParent(value).found;
    }


    /**
     * Recursively finds the node matching the value.
     * If it doesn't find, it returns the leaf `parent` where the new value should be appended.
     * @param {any} value Node's value to find
     * @param {BinaryTreeNode} node first element to start the search (root is default)
     * @param {BinaryTreeNode} parent keep track of parent (usually filled by recursion)
     * @returns {object} node and its parent like {node, parent}
     */
    findNodeAndParent(value, node = this.root, parent = null) {
      if (!node || node.value === value) {
        return { found: node, parent };
      } if (value < node.value) {
        return this.findNodeAndParent(value, node.left, node);
      }
      return this.findNodeAndParent(value, node.right, node);
    }
    // end::find[]

    /**
     * Get the node with the max value of subtree: the right-most value.
     * @param {BinaryTreeNode} node subtree's root
     * @returns {BinaryTreeNode} right-most node (max value)
     */
    getRightmost(node = this.root) {
      if (!node || !node.right) {
        return node;
      }
      return this.getMax(node.right);
    }

    // tag::leftMost[]
    /**
     * Get the node with the min value of subtree: the left-most value.
     * @param {BinaryTreeNode} node subtree's root
     * @returns {BinaryTreeNode} left-most node (min value)
     */
    getLeftmost(node = this.root) {
      if (!node || !node.left) {
        return node;
      }
      return this.getMin(node.left);
    }
    // end::leftMost[]


    // tag::remove[]
    /**
     * Remove a node from the tree
     * @returns {boolean} false if not found and true if it was deleted
     */
    remove(value) {
      const { found: nodeToRemove, parent } = this.findNodeAndParent(value); // <1>

      if (!nodeToRemove) return false; // <2>

      // Combine left and right children into one subtree without nodeToRemove
      const removedNodeChildren = this.combineLeftIntoRightSubtree(nodeToRemove); // <3>

      if (nodeToRemove.meta.multiplicity && nodeToRemove.meta.multiplicity > 1) { // <4>
        nodeToRemove.meta.multiplicity -= 1; // handles duplicated
      } else if (nodeToRemove === this.root) { // <5>
        // Replace (root) node to delete with the combined subtree.
        this.root = removedNodeChildren;
        if (this.root) { this.root.parent = null; } // clearing up old parent
      } else if (nodeToRemove.isParentLeftChild) { // <6>
        // Replace node to delete with the combined subtree.
        parent.setLeftAndUpdateParent(removedNodeChildren);
      } else {
        parent.setRightAndUpdateParent(removedNodeChildren);
      }

      this.size -= 1;
      return true;
    }
    // end::remove[]

    // tag::combine[]
    /**
     * Combine left into right children into one subtree without given parent node.
     *
     * @example combineLeftIntoRightSubtree(30)
     *
     *      30*                             40
     *    /     \                          /  \
     *   10      40      combined        35   50
     *     \    /  \    ---------->     /
     *     15  35   50                 10
     *                                   \
     *                                    15
     *
     * It takes node 30 left subtree (10 and 15) and put it in the
     * leftmost node of the right subtree (40, 35, 50).
     *
     * @param {BinaryTreeNode} node
     * @returns {BinaryTreeNode} combined subtree
     */
    combineLeftIntoRightSubtree(node) {
      if (node.right) {
        const leftmost = this.getLeftmost(node.right);
        leftmost.setLeftAndUpdateParent(node.left);
        return node.right;
      }
      return node.left;
    }
    // end::combine[]

    // tag::bfs[]
    /**
     * Breath-first search for a tree (always starting from the root element).
     * @yields {BinaryTreeNode}
     */
    * bfs() {
      const queue = new Queue();

      queue.add(this.root);

      while (!queue.isEmpty()) {
        const node = queue.remove();
        yield node;

        if (node.left) { queue.add(node.left); }
        if (node.right) { queue.add(node.right); }
      }
    }
    // end::bfs[]

    // tag::dfs[]
    /**
     * Depth-first search for a tree (always starting from the root element)
     * @see preOrderTraversal Similar results to the pre-order transversal.
     * @yields {BinaryTreeNode}
     */
    * dfs() {
      const stack = new Stack();

      stack.add(this.root);

      while (!stack.isEmpty()) {
        const node = stack.remove();
        yield node;

        if (node.right) { stack.add(node.right); }
        if (node.left) { stack.add(node.left); }
      }
    }
    // end::dfs[]

    // tag::inOrderTraversal[]
    /**
     * In-order traversal on a tree: left-root-right.
     * If the tree is a BST, then the values will be sorted in ascendent order
     * @param {BinaryTreeNode} node first node to start the traversal
     * @yields {BinaryTreeNode}
     */
    * inOrderTraversal(node = this.root) {
      if (node && node.left) { yield* this.inOrderTraversal(node.left); }
      yield node;
      if (node && node.right) { yield* this.inOrderTraversal(node.right); }
    }
    // end::inOrderTraversal[]

    // tag::preOrderTraversal[]
    /**
     * Pre-order traversal on a tree: root-left-right.
     * Similar results to DFS
     * @param {BinaryTreeNode} node first node to start the traversal
     * @yields {BinaryTreeNode}
     */
    * preOrderTraversal(node = this.root) {
    }
    // end::preOrderTraversal[]

    // tag::postOrderTraversal[]
    /**
     * Post-order traversal on a tree: left-right-root.
     * @param {BinaryTreeNode} node first node to start the traversal
     * @yields {BinaryTreeNode}
     */
    * postOrderTraversal(node = this.root) {
      if (node.left) { yield* this.postOrderTraversal(node.left); }
      if (node.right) { yield* this.postOrderTraversal(node.right); }
      yield node;
    }
    // end::postOrderTraversal[]

    /**
     * Represent Binary Tree as an array.
     *
     * Leaf nodes will have two `undefined` descendants.
     *
     * The array representation of the binary tree is as follows:
     *
     * First element (index=0) is the root.
     * The following two elements (index=1,2) are descendants of the root: left (a) and right (b).
     * The next two elements (index=3,4) are the descendants of a
     * The next two elements (index=5,6) are the descendants of b and so on.
     *
     *  0     1            2             3       4        5       6        n
     * [root, a=root.left, b=root.right, a.left, a.right, b.left, b.right, ...]
     *
     * You can also find the parents as follows
     *
     * e.g.
     * Parent 0: children 1,2
     * Parent 1: children 3,4
     * Parent 2: children 5,6
     * Parent 3: children 7,8
     *
     * Given any index you can find the parent index with the following formula:
     *
     * parent = (index) => Math.floor((index-1)/2)
     */
}
