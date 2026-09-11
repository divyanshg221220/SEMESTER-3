// Inheritance
// Make a class Calculator to provide basic functions like addition, subtraction, etc. as the member functions and upgrade it to the ScientificCalcualtor by inheritance by adding log and exponent functionality.
import java.util.Scanner;
class Calculator {
    public void add(int a, int b) {
        System.out.println("Result: " + (a + b));
    }
    public void subtract(int a, int b) {
        System.out.println("Result: " + (a - b));
    }
    public void multiply(int a, int b) {
        System.out.println("Result: " + (a * b));
    }
    public void divide(int a, int b) {
        if (b != 0) {
            System.out.println("Result: " + (a / b));
        } else {
            System.out.println("Division by zero is not allowed");
        }
    }
}
class ScientificCalculator extends Calculator {
    public void log(int a) {
        System.out.println("Result: " + Math.log(a));
    }
    public void exponent(int a, int b) {
        System.out.println("Result: " + Math.pow(a, b));
    }
}
class ScientificCalculatorMain {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.println("Enter + for Addition");
        System.out.println("Enter - for Subtraction");
        System.out.println("Enter * for Multiplication");
        System.out.println("Enter / for Division");
        System.out.println("Enter l for Logarithm");
        System.out.println("Enter e for Exponentiation");
        System.out.print("Enter your choice: ");
        char q = scanner.next().charAt(0);
        if (q == '+' || q == '-' || q == '*' || q == '/' || q == 'l' || q == 'e') {
            ScientificCalculator scientificcalculator = new ScientificCalculator();
            if (q == 'l') {
                System.out.print("Enter logarithm number: ");
                int a = scanner.nextInt();
                scientificcalculator.log(a);
            } else if (q == 'e') {
                System.out.print("Enter base number: ");
                int a = scanner.nextInt();
                System.out.print("Enter exponent number: ");
                int b = scanner.nextInt();
                scientificcalculator.exponent(a, b);
            } else {
                System.out.print("Enter first number: ");
                int a = scanner.nextInt();
                System.out.print("Enter second number: ");
                int b = scanner.nextInt();
                switch (q) {
                    case '+':
                        scientificcalculator.add(a, b);
                        break;
                    case '-':
                        scientificcalculator.subtract(a, b);
                        break;
                    case '*':
                        scientificcalculator.multiply(a, b);
                        break;
                    case '/':
                        scientificcalculator.divide(a, b);
                        break;
                }
            }
        } else {
            System.out.println("Invalid Input");
        }
        scanner.close();
    }
}