class ExampleClass<T> {
    T ob;
    public ExampleClass(T value) {
        ob = value;
    }
    public void showType() {
        System.out.println("Type of this object: " + ob.getClass().getName());
    }
    public T getOb(){
        return ob;
    }
}

public class gen {
    public static void main(String[] args) {
        // Create an instance of ExampleClass
        ExampleClass<Integer> ob = new ExampleClass<Integer>(50);

        // Call the showType method on the object
        ob.showType();
        int value = ob.getOb();
        System.out.println("Value: " + value);
    }
}

