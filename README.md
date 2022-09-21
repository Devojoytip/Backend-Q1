# Backend-Q1

As per the instructions a node datatype has 3 members - data(datatype - int), type(datatype - TypeTag), pointer to a next node(not used)

To create a node with given 2 data values and operation specified(ADD/MUL/SUB) 
We use createNode (for ADD/MUL) and createNodeSub (for SUB/ finding fibonacci)

createNode - receives type and returns a pointer to another function based on the type which receives 2 integers (a & b), and returns a node
1. If type == ADD, returns a pointer to a function which returns a node with data = a+b
2. If type == MUL, returns a pointer to a function which returns a node with data = a*b
3. Else returns NULL

createNodeSub - receives type and returns a pointer to another function (subtraction) which receives 2 nodes (node1 and node2)

subtraction - receives 2 nodes (node1 and node2)
1. If node1 is NULL returns NULL
2. If node2 is not NULL, returns a node with data = subtraction result of the data of node1 and node2
3. If node2 is NULL, returns a node with data = fibonacci of the data of the node1

Fibonacci is calculated using Dynamic Programming (Memoization)
The computed values are stored in the array dp 
n = node1->data
If the fibonacci of the number is already calculated, we just create a node and return it with data = fibonacci value of n
Else we create 2 nodes - nodeX with data = fibonacci(n-1) and nodeY with data = fibonacci(n-2) and resultant node has data = nodeX->data + nodeY->data

ABS - takes input a node and returns a node with data = absolute value of the data of the input node 
