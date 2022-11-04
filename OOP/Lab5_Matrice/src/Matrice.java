import java.util.Arrays;

public class Matrice {
    private static final int DIMENSION = 2;
    Complex[][] matrice;

    public Matrice() {
        matrice = new Complex[DIMENSION][DIMENSION];
    }
    public void setValue(int i, int j, Complex value){
        matrice[i][j] = value;
    }
    public static void showMatrix(Matrice m) {
        for(int i=0;i<DIMENSION;i++) {
            for(int j=0;j<DIMENSION;j++) {
                System.out.println(m.getValue(i, j));
            }

        }
    }
    public Complex getValue(int i, int j){
        return matrice[i][j];
    }
    //public static void adunare(Matrice m1, Matrice m2){
    public Matrice adunare(Matrice m1, Matrice m2){
        Matrice rezultat = new Matrice();
        for(int i = 0; i < DIMENSION; i++){
            for(int j = 0; j < DIMENSION; j++){
                Complex c1 = m1.getValue(i, j);
                Complex c2 = m2.getValue(i, j);
                int intreg = c1.getIntreg() + c2.getIntreg();
                int imag = c1.getImaginar() + c2.getImaginar();

                Complex rez = new Complex(intreg, imag);
                rezultat.setValue(i, j, rez);
            }
        }
        return rezultat;
    }

    public static void inmultireCuScalar(int alpha, Matrice m){
        for(int i = 0; i < DIMENSION; i++)
        {
            for(int j = 0; j < DIMENSION; j++)
            {
                Complex z = new Complex(m.getValue(i, j).getIntreg(), m.getValue(i, j).getImaginar());
                z.setIntreg(alpha * z.getIntreg());
                z.setImaginar(alpha * z.getImaginar());
                m.setValue(i, j, z);
            }
        }
    }
    public static void scadere(Matrice m1, Matrice m2){
        /*Matrice rezultat = new Matrice();
        Matrice.inmultireCuScalar(-1, m2);
        rezultat.adunare(m1, m2);
        showMatrix(rezultat);*/
        Matrice rezultat = new Matrice();
        for(int i = 0; i < DIMENSION; i++){
            for(int j = 0; j < DIMENSION; j++){
                Complex c1 = m1.getValue(i, j);
                Complex c2 = m2.getValue(i, j);
                int intreg = c1.getIntreg() - c2.getIntreg();
                int imag = c1.getImaginar() - c2.getImaginar();

                Complex rez = new Complex(intreg, imag);
                rezultat.setValue(i, j, rez);
            }
        }
        showMatrix(rezultat);
    }
    public static void main(String[] args){
        Complex c1 = new Complex(1,3);
        Complex c2 = new Complex(1,3);
        Complex c3 = new Complex(1,3);
        Complex c4 = new Complex(1,3);

        Complex c5 = new Complex(2,1);
        Complex c6 = new Complex(2,1);
        Complex c7 = new Complex(2,1);
        Complex c8 = new Complex(2,1);

        Matrice m1= new Matrice();
        m1.setValue(0, 0, c1);
        m1.setValue(0, 1, c2);
        m1.setValue(1, 0, c3);
        m1.setValue(1, 1, c4);

        Matrice m2= new Matrice();
        m2.setValue(0, 0, c5);
        m2.setValue(0, 1, c6);
        m2.setValue(1, 0, c7);
        m2.setValue(1, 1, c8);

        //Matrice.adunare(m1, m2);
        //Matrice.inmultireCuScalar(-1, m1);
        scadere(m1, m2);
        String s = new String("POO");
        String t = new String("AF");
        s = t + "1";
        System.out.println(s);
    }
}
