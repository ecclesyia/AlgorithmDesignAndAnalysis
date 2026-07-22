import sys

def demonstrate_constant_time(n):
    operations = 0
    a = 10
    operations += 1
    b = 20
    operations += 1
    sum_val = a + b
    operations += 1
    print("O(1) Constant Time:")
    print(f"  Input size (n): {n}")
    print(f"  Actual operations counted: {operations}\n")

def demonstrate_logarithmic_time(n):
    operations = 0
    temp = n
    print("O(log n) Logarithmic Time:")
    print(f"  Dividing input size {n} by 2 repeatedly:")
    while temp > 1:
        print(f"    Current value: {temp}")
        temp //= 2
        operations += 1
    print(f"  Input size (n): {n}")
    print(f"  Actual operations counted: {operations}\n")

def demonstrate_linear_time(n):
    operations = 0
    for i in range(n):
        operations += 1
    print("O(n) Linear Time:")
    print(f"  Input size (n): {n}")
    print(f"  Actual operations counted: {operations}\n")

def demonstrate_linearithmic_time(n):
    operations = 0
    for i in range(n):
        temp = n
        while temp > 1:
            temp //= 2
            operations += 1
    print("O(n log n) Linearithmic Time:")
    print(f"  Input size (n): {n}")
    print(f"  Actual operations counted: {operations}\n")

def demonstrate_quadratic_time(n):
    operations = 0
    for i in range(n):
        for j in range(n):
            operations += 1
    print("O(n^2) Quadratic Time:")
    print(f"  Input size (n): {n}")
    print(f"  Actual operations counted: {operations} (n * n)\n")

def main():
    n = 16
    print("=== Time Complexity Visualizer ===")
    print("This program counts operations to demonstrate theoretical time complexities.\n")
    demonstrate_constant_time(n)
    demonstrate_logarithmic_time(n)
    demonstrate_linear_time(n)
    demonstrate_linearithmic_time(n)
    demonstrate_quadratic_time(n)
    input("Press Enter to exit...")

if __name__ == "__main__":
    main()
