// Demonstrate working of Abstract class in Multi level inheritance
// Make Abstract class AbstractCalculator having four functions add, multiply, division and subtraction. 
import java.util.Scanner;
abstract class AbstractCalculator {
    abstract void add(int a, int b);
    abstract void subtract(int a, int b);
    abstract void multiply(int a, int b);
    abstract void divide(int a, int b);
}
abstract class BasicCalculator extends AbstractCalculator {
    public void add(int a, int b) {
        System.out.println("Result: " + (a + b));
    }
    public void subtract(int a, int b) {
        System.out.println("Result: " + (a - b));
    }
}
class AdvancedCalculator extends BasicCalculator {
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
class AbstractCalculatorMain {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.println("Enter + for Addition");
        System.out.println("Enter - for Subtraction");
        System.out.println("Enter * for Multiplication");
        System.out.println("Enter / for Division");
        System.out.print("Enter your choice: ");
        char q = scanner.next().charAt(0);
        if (q == '+' || q == '-' || q == '*' || q == '/') {
            System.out.print("Enter first number: ");
            int a = scanner.nextInt();
            System.out.print("Enter second number: ");
            int b = scanner.nextInt();
            AdvancedCalculator calculator = new AdvancedCalculator();
            switch (q) {
                case '+':
                    calculator.add(a, b);
                    break;
                case '-':
                    calculator.subtract(a, b);
                    break;
                case '*':
                    calculator.multiply(a, b);
                    break;
                case '/':
                    calculator.divide(a, b);
                    break;
            }
        } else {
            System.out.println("Invalid Input");
        }
        scanner.close();
    }
}