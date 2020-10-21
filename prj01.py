import numpy as np
import easynn as nn
import easynn_golden as golden
import sys

sys.setrecursionlimit(100*100)

# Create a numpy array of 10 rows and 5 columns.
# Set the element at row i and column j to be i+j.
def Q1():
    arr = np.zeros((10, 5))
    row, col = arr.shape
    for i in  range(0, row):    
        for j in range(0, col):
            arr[(i, j)] = i+j
    return arr

# Add two numpy arrays together.
def Q2(a, b):
    added_array = np.add(a, b)
    return added_array

# Multiply two 2D numpy arrays using matrix multiplication.
def Q3(a, b):
    ans = np.matmul(a, b)
    return ans

# For each row of a 2D numpy array, find the column index
# with the maximum element. Return all these column indices.
def Q4(a):
    row, col = a.shape
    max_indices = []
    for i in range(0, row):
        max_element = max(a[i])
        result = np.where(a[i] == max_element)
        max_indices.append(result[0][0])
    return max_indices

# Solve Ax = b.
def Q5(A, b):
    x = np.linalg.solve(A, b)
    return x

# Return an EasyNN expression for a+b.
def Q6():
    a = nn.Input("a")
    b = nn.Input("b")
    return a + b

# Return an EasyNN expression for a+b*c.
def Q7():
    a = nn.Input("a")
    b = nn.Input("b")
    c = nn.Input("c")
    return a+b*c

# Given A and b, return an EasyNN expression for Ax+b.
def Q8(A, b):
    A = nn.Const(A)
    x = nn.Input("x")
    b = nn.Const(b)
    c = A*x+b
    return c

def pow(base, expo):
    if expo==1:
        return base
    elif expo==0: 
        return 1
    else:
        return base*pow(base, expo-1)


# Given n, return an EasyNN expression for x**n.
def Q9(n):
    x = nn.Input("x")
    c = pow(x, n)
    return c

# Return an EasyNN expression to compute
# the element-wise absolute value |x|.
def Q10():
    relu = nn.ReLU()
    x = nn.Input('x')
    y = relu(x)
    d = relu(-x)
    a = y + d
    return a