public class Complex implements Numeric{
    private int re;
    private int im;

    public Complex(int re, int im) {
        this.re = re;
        this.im = im;
    }

    public int getRe() {
        return re;
    }

    public void setRe(int re) {
        this.re = re;
    }

    public int getIm() {
        return im;
    }

    public void setIm(int im) {
        this.im = im;
    }

    @Override
    public void aduna(Numeric a) {

    }
}
