#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* createNode(int data) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

struct Node* insert(struct Node* root, int data) {
    if (root == NULL)
        return createNode(data);

    if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);

    return root;
}

void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void preorder(struct Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct Node* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

void levelOrder(struct Node* root) {
    if (root == NULL)
        return;

    struct Node* queue[100];
    int front = 0, rear = 0;

    queue[rear++] = root;

    while (front < rear) {
        struct Node* temp = queue[front++];
        printf("%d ", temp->data);

        if (temp->left)
            queue[rear++] = temp->left;
        if (temp->right)
            queue[rear++] = temp->right;
    }
}

void findMax(struct Node* root) {
    if (root == NULL) {
        printf("Tree is empty\n");
        return;
    }

    struct Node* parent = NULL;
    struct Node* current = root;

    while (current->right != NULL) {
        parent = current;
        current = current->right;
    }

    printf("Maximum Node Value: %d\n", current->data);
    if (parent != NULL)
        printf("Parent Node Value: %d\n", parent->data);
    else
        printf("The node is root, no parent.\n");
}

int countNodes(struct Node* root) {
    if (root == NULL)
        return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}
 
int height(struct Node* root) {
    if (root == NULL)
        return -1;
    int lh = height(root->left);
    int rh = height(root->right);
    return (lh > rh ? lh : rh) + 1;
}

int main() {
    struct Node* root = NULL;
    int choice, data;

    for(;;) {
        printf("\n--- Binary Search Tree Menu ---\n");
        printf("1. Insert\n");
        printf("2. DFS Traversals\n");
        printf("3. BFS Traversal\n");
        printf("4. Find Maximum Node\n");
        printf("5. Count Nodes\n");
        printf("6. Find Height\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter value to insert: ");
            scanf("%d", &data);
            root = insert(root, data);
            break;

        case 2:
            printf("Inorder Traversal: ");
            inorder(root);
            printf("\nPreorder Traversal: ");
            preorder(root);
            printf("\nPostorder Traversal: ");
            postorder(root);
            printf("\n");
            break;

        case 3:
            printf("Level Order Traversal: ");
            levelOrder(root);
            printf("\n");
            break;

        case 4:
            findMax(root);
            break;

        case 5:
            printf("Total Nodes: %d\n", countNodes(root));
            break;

        case 6:
            printf("Height of Tree: %d\n", height(root));
            break;

        case 7:
            printf("Exiting...\n");
            break;

        default:
            printf("Invalid choice!\n");
        }
    }

    return 0;
}