// Write a program to count number of units produced from a manufacturing unit.
// Write a program to count number of units produced from a manufacturing unit. Hint: use static variables to count number of objects created.
import java.util.Scanner;
class Car {
    static int objCount = 0;
    Car() {
        objCount++;
    }
    static int getObjCount() {
        return objCount;
    }
}
class ManufacturingUnit {
    public void pSum(int count) {
        for (int i = 0; i < count; i++) {
            new Car();
        }
    }
}
class ManufacturingUnitMain {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        ManufacturingUnit manufacturingUnit = new ManufacturingUnit();
        System.out.print("Enter the number of units to produce: ");
        int count = scanner.nextInt();
        manufacturingUnit.pSum(count);
        System.out.println("Total number of car produced: " + Car.getObjCount());
        int noOfWheels = 4;
        System.out.println("Total number of wheels produced: " + noOfWheels * Car.getObjCount());
        scanner.close();
    } 
}