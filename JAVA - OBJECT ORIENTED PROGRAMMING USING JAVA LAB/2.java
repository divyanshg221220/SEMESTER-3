// Create a Student Class with Getter and Setter Functions and create object in separate Main class
import java.util.Scanner;
class Student {
    private int enrolNo;
    private String name;
    public enum Gender {
        MALE, FEMALE
    }
    private Gender gender;
    private int date, month, year;
    private String batch, branch;
    public int getEnrolNo() {
        return enrolNo;
    }
    public void setEnrolNo(int enr) {
        this.enrolNo = enr;
    }
    public String getName() {
        return name;
    }
    public void setName(String s) {
        this.name = s;
    }
    public Gender getGender() {
        return gender;
    }
    public void setGender(Gender g) {
        this.gender = g;
    }
    public int getDate() {
        return date;
    }
    public void setDate(int date) {
        this.date = date;
    }
    public int getMonth() {
        return month;
    }
    public void setMonth(int month) {
        this.month = month;
    }
    public int getYear() {
        return year;
    }
    public void setYear(int year) {
        this.year = year;
    }
    public String getBatch() {
        return batch;
    }
    public void setBatch(String batch) {
        this.batch = batch;
    }
    public String getBranch() {
        return branch;
    }
    public void setBranch(String branch) {
        this.branch = branch;
    }
}
class StudentMain {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        Student student = new Student();
        System.out.print("Enter Enrolment Number: ");
        int enr = scanner.nextInt();
        student.setEnrolNo(enr);
        System.out.print("Enter Name: ");
        String s = scanner.next();
        student.setName(s);
        System.out.print("Enter Gender (M/F): ");
        char g = scanner.next().charAt(0);
        if (g == 'M' || g == 'm') {
            student.setGender(Student.Gender.MALE);
        } else if (g == 'F' || g == 'f') {
            student.setGender(Student.Gender.FEMALE);
        } else {
            System.out.println("Invalid Input");
        }
        System.out.print("Enter Date of Birth (dd mm yyyy): ");
        int date = scanner.nextInt();
        int month = scanner.nextInt();
        int year = scanner.nextInt();
        student.setDate(date);
        student.setMonth(month);
        student.setYear(year);
        System.out.print("Enter Batch and Branch (batch branch): ");
        String batch = scanner.next();
        student.setBatch(batch);
        String branch = scanner.next();
        student.setBranch(branch);
        System.out.println("\nStudent Details");
        System.out.println("Enrolment Number: " + student.getEnrolNo());
        System.out.println("Name: " + student.getName());
        System.out.println("Gender: " + student.getGender());
        System.out.println("Date of Birth: " + student.getDate() + "/" + student.getMonth() + "/" + student.getYear());
        System.out.println("Batch and Branch: " + student.getBatch() + " - " + student.getBranch());
        scanner.close();
    }
}
