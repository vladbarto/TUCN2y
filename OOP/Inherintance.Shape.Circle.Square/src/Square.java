public class Square extends Shape{
    private int latura;
    public Square(String name) {
        super(name);
    }

    public int getLatura() {
        return latura;
    }

    public void setLatura(int latura) {
        this.latura = latura;
    }
    public double calculateArea(){
        return (double)latura*latura;
    }
}
