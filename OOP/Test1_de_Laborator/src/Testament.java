import java.util.ArrayList;

public class Testament extends Document{
    private ArrayList<String> numeBeneficiari;
    private String dataIntocmirii;

    public Testament(String dataArhivarii, int nrPagini, ArrayList<String> numeBeneficiari, String dataIntocmirii) {
        super(dataArhivarii, nrPagini);
        this.numeBeneficiari = numeBeneficiari;
        this.dataIntocmirii = dataIntocmirii;
    }

    public ArrayList<String> getNumeBeneficiari() {
        return numeBeneficiari;
    }

    public void setNumeBeneficiari(ArrayList<String> numeBeneficiari) {
        this.numeBeneficiari = numeBeneficiari;
    }

    public String getDataIntocmirii() {
        return dataIntocmirii;
    }

    public void setDataIntocmirii(String dataIntocmirii) {
        this.dataIntocmirii = dataIntocmirii;
    }
    //TODO: toString

    @Override
    public String toString() {
        return "Testament{" +
                "numeBeneficiari=" + numeBeneficiari +
                ", dataIntocmirii='" + dataIntocmirii + '\'' +
                '}';
    }
}
