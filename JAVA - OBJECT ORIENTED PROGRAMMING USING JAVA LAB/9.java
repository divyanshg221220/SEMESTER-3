// Exception Handling
// Make a class to catch an exception created by division by zero and any other exception along with finally block.
// Use multiple catch blocks.
import java.util.InputMismatchException;
import java.util.Scanner;
class ExceptionHandlingMain {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        try {
            System.out.print("Enter first number: ");
            int a = scanner.nextInt();
            System.out.print("Enter second number: ");
            int b = scanner.nextInt();
            int result = a / b;
            System.out.println("Result: " + result);
        } catch (ArithmeticException e) {
            System.out.println("Error: Division by zero is not allowed");
        } catch (InputMismatchException e) {
            System.out.println("Error: Invalid input");
        } finally {
            System.out.println("Execution completed");
            scanner.close();
        }
    }
}