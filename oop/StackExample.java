import java.util.ArrayList;
import java.util.List;

class GenericStack<T> {
    private List<T> stack;

    public GenericStack() {
        stack = new ArrayList<>();
    }

    public void push(T item) {
        stack.add(item);
    }

    public T pop() {
        if (isEmpty()) {
            throw new IllegalStateException("Stack is empty");
        }
        return stack.remove(stack.size() - 1);
    }

    public boolean isEmpty() {
        return stack.isEmpty();
    }
}

class Student {
    private String name;
    private int regNo;

    public Student(String name, int regNo) {
        this.name = name;
        this.regNo = regNo;
    }

    @Override
    public String toString() {
        return "Student{name='" + name + "', regNo=" + regNo + '}';
    }
}

class Employee {
    private String name;
    private int employeeId;

    public Employee(String name, int employeeId) {
        this.name = name;
        this.employeeId = employeeId;
    }

    @Override
    public String toString() {
        return "Employee{name='" + name + "', employeeId=" + employeeId + '}';
    }
}

public class StackExample {
    public static void main(String[] args) {
        // Using the generic stack with Student objects
        GenericStack<Student> studentStack = new GenericStack<>();
        studentStack.push(new Student("John Doe", 101));
        studentStack.push(new Student("Jane Smith", 102));

        while (!studentStack.isEmpty()) {
            Student poppedStudent = studentStack.pop();
            System.out.println("Popped Student: " + poppedStudent);
        }

        // Using the generic stack with Employee objects
        GenericStack<Employee> employeeStack = new GenericStack<>();
        employeeStack.push(new Employee("Alice Johnson", 201));
        employeeStack.push(new Employee("Bob Williams", 202));

        while (!employeeStack.isEmpty()) {
            Employee poppedEmployee = employeeStack.pop();
            System.out.println("Popped Employee: " + poppedEmployee);
        }
    }
}

