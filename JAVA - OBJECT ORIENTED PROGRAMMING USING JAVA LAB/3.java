// WAP to display data of student class defined in University Package.
// WAP to extend the Program with student details like, rollNo, Name, and Institute Code, etc. using Getter and Setter functions, keeping in mind that the data members are not allowed to be accessed directly and shall be accessed via member functions only.
// 1. Make the Student Class part of University Package.
// 2. Make a separate file for Main Class which is a part of default package and import university package in the same to input and print student data.
// Hint: Use Access Modifiers and Packages.
import java.util.Scanner;
import University.UniversityStudent;
class UniversityStudentMain {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        UniversityStudent UniversityStudent = new UniversityStudent();
        System.out.print("Enter Roll Number: ");
        int rollNo = scanner.nextInt();
        UniversityStudent.setRollNo(rollNo);
        System.out.print("Enter Name: ");
        String name = scanner.next();
        UniversityStudent.setName(name);
        System.out.print("Enter Institute Code: ");
        String instituteCode = scanner.next();
        UniversityStudent.setInstituteCode(instituteCode);
        System.out.println("\nStudent Details:");
        System.out.println("Roll Number: " + UniversityStudent.getRollNo());
        System.out.println("Name: " + UniversityStudent.getName());
        System.out.println("Institute Code: " + UniversityStudent.getInstituteCode());
        scanner.close();
    }
}