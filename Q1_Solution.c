#include <stdio.h>
#include <stdlib.h>

typedef enum TypeTag
{
    ADD,
    SUB,
    MUL,
    FIBO
} TypeTag;

typedef struct Node
{
    int data;
    TypeTag type;
    struct Node *next;
} Node;

int dp[1000] = {0}; // array for storing pre-computed values for fibonacci program

Node *addition(int a, int b)
{
    Node *n = malloc(sizeof(Node));
    n->data = a + b;
    return n;
}

Node *multiplication(int a, int b)
{
    Node *n = malloc(sizeof(Node));
    n->data = a * b;
    return n;
}

// createNode receives type(ADD/MUL)
// and returns a pointer to another function based on the type, which receive two integers
// and return a node
Node *(*createNode(int n))(int, int)
{
    if (n == ADD)
    {
        Node *(*newnode)(int, int) = &addition;
        return newnode;
    }
    else if (n == MUL)
    {
        Node *(*newnode)(int, int) = &multiplication;
        return newnode;
    }
    else return NULL;
}

Node *subtraction(Node *a, Node *b)
{
    Node *newnode = malloc(sizeof(Node));
    if(a==NULL) return NULL;

    if (b != NULL)
    {
        newnode->data = a->data - b->data;
        return newnode;
    }

    else
    {
        // used Dynamic Programming memoization
        // an array dp is used to store the values of fibonacci of previous nos
        // so the function does not calculate fibonacci of a no repeatedly
        int n = a->data;
        if (n == 0)
        {
            newnode->data = 0;
            return newnode;
        }

        if (n == 1)
        {
            newnode->data = 1;
            return newnode;
        }

        if (dp[n] != 0)
        {
            newnode->data = dp[n];
            return newnode;
        }

        Node *node1 = malloc(sizeof(Node));
        node1->data = n - 1;
        node1 = subtraction(node1, NULL);
        Node *node2 = malloc(sizeof(Node));
        node2->data = n - 2;
        node2 = subtraction(node2, NULL);
        newnode->data = node1->data + node2->data;
        dp[n] = newnode->data;
        return newnode;
    }
}

// createNodeSub receives type
// and returns a pointer to another function based on the type, which receive two nodes
// and return a node
Node *(*createNodeSub(int n))(Node *, Node *)
{
    if (n==SUB)
    {
        Node *(*newnode)(Node *, Node *) = &subtraction;
        return newnode;
    }
    return NULL;
}

Node* ABS(Node *a)
{
    Node *newnode = malloc(sizeof(Node));
    newnode->data=a->data;
    if (newnode->data<0)
    {
        newnode->data*=-1;
    }
    return newnode;
}

void calc(Node *a)
{
    printf("%d\n", a->data);
}

int main()
{
    
    Node *add = (*createNode(ADD))(10, 6);
    Node *mul = (*createNode(MUL))(5, 4);
    Node *sub = (*createNodeSub(SUB))(add, mul);
    Node *fibo = (*createNodeSub(SUB))(ABS(sub), NULL);

    calc(add);
    calc(mul);
    calc(sub);
    calc(fibo); // fibo(4)=3
    return 0;
}