public class Fractie implements Numeric{
    private int num;//numarator
    private int denom = 1;//denominator

    public Fractie(int num, int denom) {
        this.num = num;
        this.denom = denom;
    }

    public int getNum() {
        return num;
    }

    public void setNum(int num) {
        this.num = num;
    }

    public int getDenom() {
        return denom;
    }

    public void setDenom(int denom) {
        this.denom = denom;
    }
}
