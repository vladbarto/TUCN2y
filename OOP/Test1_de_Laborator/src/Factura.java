import java.util.ArrayList;

public class Factura extends Document{
//TODO: toString
    private ArrayList<ArrayList<Integer>> achizitii;
    private int dimensPeLung;
    private int dimensPeLat;

    public Factura(String dataArhivarii, int nrPagini) {
        super(dataArhivarii, nrPagini);
    }
    //TODO: add element in matrice
    /*public void addElemInMatrice(int val){
        for(int i = 0; i <= dimensPeLung; i++){
            for(int j = 0; j <= dimensPeLat; j++)
            {

            }
        }
    }*/
    @Override
    public String toString() {
        return "Factura{" +
                "achizitii=" + achizitii +
                '}';
    }

}
