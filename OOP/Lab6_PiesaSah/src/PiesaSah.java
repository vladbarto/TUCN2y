public abstract class PiesaSah {
    private String numePiesa;
    private int coordX;
    private int coordY;
    String culoare;

    public PiesaSah(String numePiesa, int coordX, int coordY, String culoare) {
        this.numePiesa = numePiesa;
        this.coordX = coordX;
        this.coordY = coordY;
        this.culoare = culoare;
    }

    public String getNumePiesa() {
        return numePiesa;
    }

    public int getCoordX() {
        return coordX;
    }

    public int getCoordY() {
        return coordY;
    }

    public String getCuloare() {
        return culoare;
    }

    public void setCoordX(int coordX) {
        this.coordX = coordX;
    }

    public void setCoordY(int coordY) {
        this.coordY = coordY;
    }
//nu voi seta pieselor nume si culori noi
    public abstract void mutaPiesa(int new_coordX, int new_coordY);

    @Override
    public String toString() {
        return "PiesaSah{" +
                "numePiesa='" + numePiesa + '\'' +
                ", coordX=" + coordX +
                ", coordY=" + coordY +
                ", culoare='" + culoare + '\'' +
                '}';
    }
}
