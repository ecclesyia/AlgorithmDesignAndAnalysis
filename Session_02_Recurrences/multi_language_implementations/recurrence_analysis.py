import sys

def print_indent(depth):
    print("  |  " * depth, end="")

def get_address(depth):
    # Simulated stack address starting at 0x7ffebfaf1000 and growing down
    base = 0x7ffebfaf1000
    return f"0x{base - depth * 0x30:x}"

def calculate_factorial(n, depth):
    print_indent(depth)
    print(f"Entering factorial({n}). Address of n: {get_address(depth)}")
    if n <= 1:
        print_indent(depth)
        print(f"Base Case reached for factorial({n}). Returning 1.")
        return 1
    sub_result = calculate_factorial(n - 1, depth + 1)
    result = n * sub_result
    print_indent(depth)
    print(f"Exiting factorial({n}) -> returning {n} * {sub_result} = {result}")
    return result

def calculate_fibonacci(n, depth, branch):
    print_indent(depth)
    print(f"Entering fibonacci({n}) [{branch} branch]. Address of n: {get_address(depth)}")
    if n == 0:
        print_indent(depth)
        print("Base Case: fibonacci(0) = 0. Returning.")
        return 0
    if n == 1:
        print_indent(depth)
        print("Base Case: fibonacci(1) = 1. Returning.")
        return 1
    left = calculate_fibonacci(n - 1, depth + 1, "Left")
    right = calculate_fibonacci(n - 2, depth + 1, "Right")
    result = left + right
    print_indent(depth)
    print(f"Exiting fibonacci({n}) -> returning {left} + {right} = {result}")
    return result

def main():
    val = 5
    print("=== Recursion & Stack Frame Visualizer ===\n")
    print(f"--- PART 1: Linear Recursion - Factorial({val}) ---")
    fact = calculate_factorial(val, 0)
    print(f"\nFactorial of {val} is: {fact}\n")
    print("--------------------------------------------------\n")
    print("--- PART 2: Tree Recursion - Fibonacci(4) ---")
    fib = calculate_fibonacci(4, 0, "Root")
    print(f"\nFibonacci of 4 is: {fib}\n")
    input("Press Enter to exit...")

if __name__ == "__main__":
    main()
