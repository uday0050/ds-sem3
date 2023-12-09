interface LibraryItem<T> {
    void search(T id) throws NotFoundException;
    void display();
}

class Student implements LibraryItem<Integer>, Runnable{
    String name;
    int regno;

    public Student(String name, int regno) {
        this.name = name;
        this.regno = regno;
    }

    public void search(Integer regnoToSearch) throws NotFoundException {
        if (regnoToSearch.equals(regno)) {
            System.out.println("Student Found: " + name + ", RegNo: " + regno);
        } else {
            throw new NotFoundException("Student Not Found");
        }
    }

    public void display() {
        System.out.println("Student: " + name + ", RegNo: " + regno);
    }
    public void run(){
        Student newStudent = new Student("New Student", 103);
            try {
                newStudent.search(103); // Found
            } catch (NotFoundException e) {
                System.out.println(e.getMessage());
            }
    }
}

class Book implements LibraryItem<String> {
    String name;
    String id;

    public Book(String name, String id) {
        this.name = name;
        this.id = id;
    }


    public void search(String idToSearch) throws NotFoundException {
        if (idToSearch.equals(id)) {
            System.out.println("Book Found: " + name + ", ID: " + id);
        } else {
            throw new NotFoundException("Book Not Found");
        }
    }


    public void display() {
        System.out.println("Book: " + name + ", ID: " + id);
    }
}

class NotFoundException extends Exception {
    String message;
    public NotFoundException(String message) {
        this.message=message;    
    }
    public String getMessage(){
        return message;
    }

}
class BookThread implements Runnable {
    public void run() {
        Book newBook = new Book("New Book", "NB303");
        try {
            newBook.search("NB303"); // Found
        } catch (NotFoundException e) {
            System.out.println(e.getMessage());
        }
    }
}

public class SystemL{
    public static void main(String[] args) {
        // Creating students
        Student student1 = new Student("John Doe", 101);
        Thread studentThread = new Thread(student1);

        // Creating books
        Book book1 = new Book("Introduction to Java", "J101");
        BookThread bk = new BookThread();
        Thread bookThread = new Thread(bk);

        // Thread to take input details of students
        // Thread studentThread = new Thread(() -> {
        //     Student newStudent = new Student("New Student", 103);
        //     try {
        //         newStudent.search(103); // Found
        //     } catch (NotFoundException e) {
        //         System.out.println(e.getMessage());
        //     }
        // });

        // Thread to take input details of books
        // Thread bookThread = new Thread( {
        //     Book newBook = new Book("New Book", "NB303");
        //     try {
        //         newBook.search("NB303"); // Found
        //     } catch (NotFoundException e) {
        //         System.out.println(e.getMessage());;
        //     }
        // });

        studentThread.start();
        bookThread.start();
        

        try {
            studentThread.join();
            bookThread.join();
        } catch (InterruptedException e) {
            System.out.println(e);
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
