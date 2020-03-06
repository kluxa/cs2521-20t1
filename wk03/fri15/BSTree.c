
#include <stdlib.h>

#include "BSTree.h"

/**
 * Returns the number of nodes in the tree.
 */
int TreeNumNodes(BSTree t) {
    if (t == NULL) {
        return 0;
    } else {
        return 1 + TreeNumNodes(t->left) + TreeNumNodes(t->right);
    }
}

/**
 * Returns the number of internal nodes in the tree. An internal node is
 * a  node  that  has  one  or more children, i.e., a node that is not a
 * leaf.
 */
int countInternal(BSTree t) {
    if (t == NULL) {
        return 0;
    } else if (t->left == NULL && t->right == NULL) {
        return 0;
    } else {
        return 1 + countInternal(t->left) + countInternal(t->right);
    }
}

/**
 * Returns the depth of the node containing the given key in the tree if
 * it exists, or -1 otherwise.
 */
int nodeDepth(BSTree t, int key) {
    if (t == NULL) {
        return -1;
    } else if (t->value == key) {
        return 0;
    } else if (key > t->value) {
        int depth = nodeDepth(t->right, key);
        if (depth == -1) return -1;
        return 1 + depth;
    } else {
        int depth = nodeDepth(t->left, key);
        if (depth == -1) return -1;
        return 1 + depth;
    }
}

/**
 * Returns  the  height  of  the given tree. The height of a tree is the
 * number  of  edges  on  the  longest path from the root node to a leaf
 * node. The height of an empty tree is -1.
 */
int treeHeight(BSTree t) {
    if (t == NULL) {
        return -1;
    } else {
        int lh = treeHeight(t->left);
        int rh = treeHeight(t->right);
        return 1 + (lh > rh ? lh : rh);

        /* // ^ this is the same as
        if (lh > rh) {
            return 1 + lh;
        } else {
            return 1 + rh;
        }
        */
    }
}
