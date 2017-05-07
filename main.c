# include <stdio.h>
# include <stdlib.h>

struct node {

    int data;

    struct node *leftChild;
    struct node *rightChild;

};

struct node *root = NULL;

void insert (int data) {

    struct node *tempNode = (struct node*) malloc( sizeof(struct node) );
    struct node *current;
    struct node *parent;

    tempNode -> data = data;
    tempNode -> leftChild = NULL;
    tempNode -> rightChild = NULL;

    /// If tree is empty
    if (root == NULL) {

        root = tempNode;

    } else {

        current = root;
        parent = NULL;

        while (1) {

            parent = current;

            /// Go to the left of the tree
            if (data < parent -> data) {

                current = current -> leftChild;

                /// Insert to the left
                if (current == NULL) {

                    parent -> leftChild = tempNode;
                    return;

                }

            } else { /// Go to the right of the tree

                current = current -> rightChild;

                /// Insert to the right
                if (current == NULL) {

                    parent -> rightChild = tempNode;
                    return;

                }

            }

        }

    }

}


struct node *search (int data) {

    struct node *current = root;
    printf("Visiting elements: ");

    while (current -> data != data) {

        if (current != NULL) {

            printf("%d ", current -> data);

            /// Go to the left of the tree
            if (current -> data > data) {

                current = current -> leftChild;

            } else { /// Go to the right of the tree

                current = current -> rightChild;

            }

            /// Not found
            if (current == NULL) {

                return NULL;

            }

        }

    }

    return current;

}


void pre_order_traversal (struct node *root) {

    if (root != NULL) {

        printf("%d ", root -> data);
        pre_order_traversal(root -> leftChild);
        pre_order_traversal(root -> rightChild);

    }

}


void inorder_traversal (struct node *root) {

    if (root != NULL) {

        inorder_traversal(root -> leftChild);
        printf("%d ", root -> data);
        inorder_traversal(root -> rightChild);

    }

}


void post_order_traversal (struct node *root) {

    if (root != NULL) {

        post_order_traversal(root -> leftChild);
        post_order_traversal(root -> rightChild);
        printf("%d ", root -> data);

    }

}

int main()
{

    int iterator;
    int array[7] = { 12, 5, 17, 19, 16, 25, 22 };

    for (iterator = 0; iterator < 7; iterator++) {

        insert(array[iterator]);

    }

    post_order_traversal(root);

    return 0;
}
