#include <stdio.h>
#include <stdlib.h>

typedef struct tree_node {
    int data;
    struct tree_node *left;
    struct tree_node *right;
} stree;

stree *find(stree *, int);
stree *findmin(stree *);
stree *findmax(stree *);
stree *insert(stree *, int);
stree *del_data(stree *, int);
void travel(stree *);
void del_tree(stree *);

int main(void)
{
    int num;
    stree *t = NULL, *max, *min;
    
    puts("Enter data and end with -1");
    while (1)
    {
        scanf("%d", &num);
        if (num == -1)
            break;
        t = insert(t, num);
    }
    puts("There are data nodes:");
    travel(t);
    puts("\nEnter the data you want to delete:");
    scanf("%d", &num);
    t = del_data(t, num);
    travel(t);
    puts("\nEnter the data you want to insert:");
    scanf("%d", &num);
    t = insert(t, num);
    travel(t);
    max = findmax(t);
    min = findmin(t);
    printf("\nMax is %d , and Min is %d.\n", max->data, min->data);
    del_tree(t);
    return 0;
}

stree *find(stree *root, int data)
{
    if (root == NULL)
        return NULL;
    if (data < root->data)
        return find(root->left, data);
    else if (data > root->data)
        return find(root->right, data);
    return root;
}
stree *findmin(stree *root)
{
    if (root == NULL)
        return NULL;
    else if (root->left == NULL)
        return root;
    return findmin(root->left);
}
stree *findmax(stree *root)
{
    if (root != NULL)
        while (root->right != NULL)
            root = root->right;
    return root;
}
stree *insert(stree *root, int data)
{
    if (root == NULL)
    {
        root = (stree*)malloc(sizeof(stree));
        root->data = data;
        root->left = NULL;
        root->right = NULL;
    }
    else if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);

    return root;
}
stree *del_data(stree *root, int data)
{
    stree *tmp;

    if (root == NULL)
        printf("Not Found\n");
    else if (data < root->data)
        root->left = del_data(root->left, data);
    else if (data > root->data)
        root->right = del_data(root->right, data);
    else if (root->left && root->right)
    {
        tmp = findmin(root->right);
        root->data = tmp->data;
        root->right = del_data(root->right, root->data);
    }
    else
    {
        tmp = root;

        if (root->left == NULL)
            root = root->right;
        else if (root->right == NULL)
            root = root->left;
        free(tmp);
    }
    return root;
}
void travel(stree *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        travel(root->left);
        travel(root->right);
    }
}
void del_tree(stree *root)
{
    if (root != NULL)
    {
        del_tree(root->left);
        del_tree(root->right);
        free(root);
    }
}
