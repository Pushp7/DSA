/*Implementation of Binary search tree using linked list*/
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

struct node
{
    int item;
    struct node *left, *right;
};

// Function to create a new node
struct node* createNode(int data)
{
    struct node *n;
    n = (struct node*)malloc(sizeof(struct node));
    n->item = data;
    n->left = NULL;
    n->right = NULL;
    return n;
}

// Function to insert a node in the BST
void insertNode(struct node **r, int data)
{
    struct node *n, *ptr;
    n = createNode(data);

    if (*r == NULL) {
        *r = n;
    } else {
        ptr = *r;
        while (1) {
            if (ptr->item == data) {  // Duplicate
                free(n);
                printf("Duplicate Value\n");
                break;
            } else if (data < ptr->item) {
                if (ptr->left == NULL) {
                    ptr->left = n;
                    break;
                } else {
                    ptr = ptr->left;
                }
            } else {
                if (ptr->right == NULL) {
                    ptr->right = n;
                    break;
                } else {
                    ptr = ptr->right;
                }
            }
        }
    }
}

// Function to find the minimum value node in the right subtree
struct node* findMin(struct node *root)
{
    while (root->left != NULL)
        root = root->left;
    return root;
}

// Function to delete a node from the BST
struct node* deleteNode(struct node *root, int data)
{
    if (root == NULL) {
        printf("Data not found in the tree\n");
        return root;
    }

    if (data < root->item) {
        root->left = deleteNode(root->left, data);
    } else if (data > root->item) {
        root->right = deleteNode(root->right, data);
    } else {
        // Node with one or no child
        if (root->left == NULL) {
            struct node *temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct node *temp = root->left;
            free(root);
            return temp;
        }

        // Node with two children
        struct node *temp = findMin(root->right);  // Find the inorder successor
        root->item = temp->item;
        root->right = deleteNode(root->right, temp->item);
    }
    return root;
}

// Function for inorder traversal
void inorderTraverse(struct node *root)
{
    if (root == NULL)
        return;
    inorderTraverse(root->left);
    printf("%d ", root->item);
    inorderTraverse(root->right);
}

// Function for preorder traversal
void preorderTraverse(struct node *root)
{
    if (root != NULL) {
        printf("%d ", root->item);
        preorderTraverse(root->left);
        preorderTraverse(root->right);
    }
}

// Function for postorder traversal
void postorderTraverse(struct node *root)
{
    if (root != NULL) {
        postorderTraverse(root->left);
        postorderTraverse(root->right);
        printf("%d ", root->item);
    }
}

// Menu function
int menu()
{
    int choice;
    printf("\n1. Insert data");
    printf("\n2. Delete data");
    printf("\n3. Display all data");
    printf("\n4. Exit\n");
    printf("\nEnter your choice: ");
    scanf("%d", &choice);
    return choice;
}

// Main function
int main()
{
    struct node *root = NULL;
    int data;

    while (1) {
        system("cls");
        switch (menu()) {
            case 1:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                insertNode(&root, data);
                break;
            case 2:
                printf("Enter data to delete: ");
                scanf("%d", &data);
                root = deleteNode(root, data);
                break;
            case 3:
                printf("Data: ");
                inorderTraverse(root);
                printf("\n");
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice! Try again...\n");
        }
        getch();
    }

    return 0;
}
