public class Circle extends Shape{
    private int R;
    private static final double PI = 3.1416;

    public Circle(String name, int r) {
        super(name);
        R = r;
    }

    public int getR() {
        return R;
    }

    public void setR(int r) {
        R = r;
    }
    public double calculateArea(){
        return (double)R*PI;
    }
}
