interface LibraryItem<T, U> {
    void search(T id) throws NotFoundException;
    void display();
}

class Student<T> implements LibraryItem<T, Integer> {
    private String name;
    private int regno;

    public Student(String name, int regno) {
        this.name = name;
        this.regno = regno;
    }

    @Override
    public void search(Integer regnoToSearch) throws NotFoundException {
        if (regnoToSearch.equals(regno)) {
            System.out.println("Student Found: " + name + ", RegNo: " + regno);
        } else {
            throw new NotFoundException("Student Not Found");
        }
    }

    @Override
    public void display() {
        System.out.println("Student: " + name + ", RegNo: " + regno);
    }
}

class Book<U> implements LibraryItem<String, U> {
    private String name;
    private U id;

    public Book(String name, U id) {
        this.name = name;
        this.id = id;
    }

    @Override
    public void search(String idToSearch) throws NotFoundException {
        if (idToSearch.equals(String.valueOf(id))) {
            System.out.println("Book Found: " + name + ", ID: " + id);
        } else {
            throw new NotFoundException("Book Not Found");
        }
    }

    @Override
    public void display() {
        System.out.println("Book: " + name + ", ID: " + id);
    }
}

class NotFoundException extends RuntimeException {
    public NotFoundException(String message) {
        super(message);
    }
}

public class LibrarySystem {
    public static void main(String[] args) {
        // Creating students
        Student<Integer> student1 = new Student<>("John Doe", 101);

        // Creating books
        Book<String> book1 = new Book<>("Introduction to Java", "J101");

        // Thread to take input details of students
        Thread studentThread = new Thread(() -> {
            Student<Integer> newStudent = new Student<>("New Student", 103);
            try {
                newStudent.search(103); // Found
            } catch (NotFoundException e) {
                System.out.println(e.getMessage());
            }
        });

        // Thread to take input details of books
        Thread bookThread = new Thread(() -> {
            Book<String> newBook = new Book<>("New Book", "NB303");
            try {
                newBook.search("NB303"); // Found
            } catch (NotFoundException e) {
                System.out.println(e.getMessage());
            }
        });

        studentThread.start();
        bookThread.start();

        try {
            studentThread.join();
            bookThread.join();
        } catch (InterruptedException e) {
            e.printStackTrace();
        }

        // Searching for a student and a book
        try {
            student1.search(101); // Found
            book1.search("J101"); // Found
            student1.search(102); // Not Found
            book1.search("XYZ123"); // Not Found
        } catch (NotFoundException e) {
            System.out.println(e.getMessage());
        }
    }
}

