public class Diploma extends Document{
    private String tip;
    private String institutia;
    private String nume;

    public Diploma(String dataArhivarii, int nrPagini, String tip, String institutia, String nume) {
        super(dataArhivarii, nrPagini);
        this.tip = tip;
        this.institutia = institutia;
        this.nume = nume;
    }

    public String getTip() {
        return tip;
    }

    public void setTip(String tip) {
        this.tip = tip;
    }

    public String getInstitutia() {
        return institutia;
    }

    public void setInstitutia(String institutia) {
        this.institutia = institutia;
    }

    public String getNume() {
        return nume;
    }

    public void setNume(String nume) {
        this.nume = nume;
    }
    //TODO: toString

    @Override
    public String toString() {
        return "Diploma{" +
                "tip='" + tip + '\'' +
                ", institutia='" + institutia + '\'' +
                ", nume='" + nume + '\'' +
                '}';
    }
}
