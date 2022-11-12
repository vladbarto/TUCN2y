public class Pion extends PiesaSah {

    public Pion(String numePiesa, int coordX, int coordY, String culoare) {
        super(numePiesa, coordX, coordY, culoare);
    }

    @Override
    public void mutaPiesa(int new_coordX, int new_coordY){
        if(new_coordX == super.getCoordX() &&
        new_coordY == super.getCoordY() + 1 && new_coordX >=1 && new_coordX <= 8
        && new_coordY >=1 && new_coordY <=8) {
            super.setCoordX(new_coordX);
            super.setCoordY(new_coordY);
        }
    }
}
