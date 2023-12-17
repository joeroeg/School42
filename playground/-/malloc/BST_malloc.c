#include <stdlib.h>
#include <stdio.h>

#define CUSTOM_MALLOC(tree, size) custom_malloc(tree, size, __FILE__, __LINE__)

typedef struct TreeNode {
    void *ptr;                  // Pointer to the allocated memory
    size_t size;                // Size of the memory block
    const char *file;           // File in which the allocation was made
    int line;                   // Line number of the allocation
    struct TreeNode *left;      // Pointer to the left child
    struct TreeNode *right;     // Pointer to the right child
} TreeNode;



typedef struct {
    TreeNode *root;             // Root of the tree
} MemoryTree;



TreeNode* insertTreeNode(TreeNode *node, void *ptr, size_t size, const char *file, int line) {
    if (node == NULL) {
        TreeNode *newNode = (TreeNode *)malloc(sizeof(TreeNode));
        newNode->ptr = ptr;
        newNode->size = size;
        newNode->file = file;
        newNode->line = line;
        newNode->left = newNode->right = NULL;
        return newNode;
    }

    if (ptr < node->ptr) {
        node->left = insertTreeNode(node->left, ptr, size, file, line);
    } else {
        node->right = insertTreeNode(node->right, ptr, size, file, line);
    }
    return node;
}

TreeNode* findMinimum(TreeNode *node) {
    TreeNode *current = node;
    while (current && current->left != NULL) {
        current = current->left;
    }
    return current;
}


TreeNode* deleteTreeNode(TreeNode *root, void *ptr) {
    // Base case
    if (root == NULL) {
        return root;
    }

    // If the ptr to be deleted is smaller than the root's ptr,
    // then it lies in the left subtree
    if (ptr < root->ptr) {
        root->left = deleteTreeNode(root->left, ptr);
    }
    // If the ptr to be deleted is greater than the root's ptr,
    // then it lies in the right subtree
    else if (ptr > root->ptr) {
        root->right = deleteTreeNode(root->right, ptr);
    }
    // If ptr is the same as root's ptr, then this is the node to be deleted
    else {
        // Node with only one child or no child
        if (root->left == NULL) {
            TreeNode *temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            TreeNode *temp = root->left;
            free(root);
            return temp;
        }

        // Node with two children: Get the inorder successor (smallest in the right subtree)
        TreeNode *temp = findMinimum(root->right);

        // Copy the inorder successor's content to this node
        root->ptr = temp->ptr;
        root->size = temp->size;

        // Delete the inorder successor
        root->right = deleteTreeNode(root->right, temp->ptr);
    }

    return root;
}

void memoryTreeInsert(MemoryTree *tree, void *ptr, size_t size, const char *file, int line) {
    tree->root = insertTreeNode(tree->root, ptr, size, file, line);
}


void *custom_malloc(MemoryTree *tree, size_t size, const char *file, int line) {
    void *ptr = malloc(size);
    if (ptr) {
        memoryTreeInsert(tree, ptr, size, file, line);
    }
    return ptr;
}


void custom_free(MemoryTree *tree, void *ptr) {
    if (ptr) {
        tree->root = deleteTreeNode(tree->root, ptr);  // Implement this function
        free(ptr);
    }
}

// Initialize MemoryTree
MemoryTree *createMemoryTree() {
    MemoryTree *tree = (MemoryTree *)malloc(sizeof(MemoryTree));
    if (tree) {
        tree->root = NULL;
    }
    return tree;
}



void traverseAndClean(TreeNode *node, int *leakCount) {
    if (node == NULL) {
        return;
    }

    traverseAndClean(node->left, leakCount);

    (*leakCount)++;
    printf("Leak #%d: Memory Address=%p, Size=%zu bytes, File: %s, Line: %d\n",
           *leakCount, node->ptr, node->size, node->file, node->line);

    traverseAndClean(node->right, leakCount);
    free(node);
}



void cleanupMemoryTree(MemoryTree *tree) {
    if (tree == NULL) {
        return;
    }

    int leakCount = 0;
    // Start the traversal and cleanup from the root
    traverseAndClean(tree->root, &leakCount);

    if (leakCount == 0) {
        printf("No memory leaks detected.\n");
    } else {
        printf("Total leaks detected: %d\n", leakCount);
    }

    // Set the root to NULL after cleanup
    tree->root = NULL;
}


// Example usage in main
int main() {
    MemoryTree *tree = createMemoryTree();

	int *data1 = (int *)CUSTOM_MALLOC(tree, sizeof(int) * 10);
	int *data2 = (int *)CUSTOM_MALLOC(tree, sizeof(int) * 20); // This will be leaked
	int *data3 = (int *)CUSTOM_MALLOC(tree, sizeof(int) * 5);


    custom_free(tree, data1);

    // Check for leaks and clean up the tree
    cleanupMemoryTree(tree);

    // Free the MemoryTree structure itself
    free(tree);

    return 0;
}


