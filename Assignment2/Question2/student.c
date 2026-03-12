/*
 * Assignment 2 / Question 2 / student.c
 * ------------------------------------------------------------
 * Check if a BST is an AVL tree
 *
 * Implement:
 *   bool isAVL(struct TreeNode* root);
 *
 * AVL (for this assignment) means:
 * 1) strict BST property (no duplicates)
 * 2) height-balanced: abs(height(left) - height(right)) <= 1 at every node
 *
 * Rules:
 * - Do NOT allocate new nodes.
 * - Do NOT modify the tree.
 * - Do NOT print anything.
 *
 * Build/Run (from Assignment2 folder):
 *   make run2
 */

#include <stdbool.h>
#include <stddef.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int checkAVL(struct TreeNode* node, struct TreeNode* minNode, struct TreeNode* maxNode) {
	if(node == NULL) {
		return 0;
	}
	if(minNode != NULL && node->val <= minNode->val) return -1;
	if(maxNode != NULL && node->val >= maxNode->val) return -1;

	
	int leftHeight = checkAVL(node->left, minNode, node);
	if(leftHeight == -1) return -1;

	int rightHeight = checkAVL(node->right, node, maxNode);
	if(rightHeight == -1) return -1;

	int diff = leftHeight - rightHeight;
	if(diff < -1 || diff > 1) {
		return -1;
	}

	if(leftHeight > rightHeight) {
		return 1 + leftHeight;
	} else {
		return 1 + rightHeight;
	}
}	


bool isAVL(struct TreeNode* root) {
	if(checkAVL(root, NULL, NULL) != -1) {
		return true;
	}
	(void)root;
	return false;
}
    // TODO: implement
    // Hint: One common O(n) approach:
    // - Use a recursive helper that returns the subtree height,
    //   and returns -1 if subtree is invalid (BST violation or unbalanced).

      		
