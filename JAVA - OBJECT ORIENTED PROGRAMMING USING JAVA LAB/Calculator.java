// Make a calculator program using simple class
import java.util.Scanner;
public class Calculator {
    public static void add(int a, int b) {
        System.out.println("Result: " + (a + b));
    }
    public static void subtract(int a, int b) {
        System.out.println("Result: " + (a - b));
    }
    public static void multiply(int a, int b) {
        System.out.println("Result: " + (a * b));
    }
    public static void divide(int a, int b) {
        if (b != 0) {
            System.out.println("Result: " + (a / b));
        }
        else {
            System.out.println("Division by zero is not allowed");
        }
    }
}
class Main {
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
            switch (q) {
                case '+':
                    Calculator.add(a, b);
                    break;
                case '-':
                    Calculator.subtract(a, b);
                    break;
                case '*':
                    Calculator.multiply(a, b);
                    break;
                case '/':
                    Calculator.divide(a, b);
                    break;
            }
        }
        else {
            System.out.println("Invalid Input");
        }
        scanner.close();
    }
}