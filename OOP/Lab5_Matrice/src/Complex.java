public class Complex {
    private int intreg;
    private int imaginar;

    public Complex(int intreg, int imaginar) {
        this.intreg = intreg;
        this.imaginar = imaginar;
    }

    public int getIntreg() {
        return intreg;
    }

    public void setIntreg(int intreg) {
        this.intreg = intreg;
    }

    public int getImaginar() {
        return imaginar;
    }

    public void setImaginar(int imaginar) {
        this.imaginar = imaginar;
    }

    @Override
    public String toString() {
        return   intreg + "+" +
                 imaginar + "i";
    }
}
