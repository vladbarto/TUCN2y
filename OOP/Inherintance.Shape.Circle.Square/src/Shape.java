public abstract class Shape {
    private String name;
    public static int howManyShapes;

    public Shape(String name) {
        this.name = name;
        howManyShapes++;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }
    public abstract double calculateArea();
    @Override
    public String toString() {
        return "Shape{" +
                "name='" + name + '\'' +
                '}';
    }
}
