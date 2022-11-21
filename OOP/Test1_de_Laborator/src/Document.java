public abstract class Document {
    private String dataArhivarii;
    private int nrPagini;
    private String id;//nrOrdine+concatenatDataArh
    private static int nrOrdine;

    public Document(String dataArhivarii, int nrPagini) {
        nrOrdine++;
        this.dataArhivarii = dataArhivarii;
        this.nrPagini = nrPagini;
        this.id = nrOrdine+dataArhivarii;
    }

    public String getDataArhivarii() {
        return dataArhivarii;
    }

    public void setDataArhivarii(String dataArhivarii) {
        this.dataArhivarii = dataArhivarii;
    }

    public int getNrPagini() {
        return nrPagini;
    }

    public void setNrPagini(int nrPagini) {
        this.nrPagini = nrPagini;
    }

    public String getId() {
        return id;
    }

    public void setId(String id) {
        this.id = id;
    }

    public static int getNrOrdine() {
        return nrOrdine;
    }

    public static void setNrOrdine(int nrOrdine) {
        Document.nrOrdine = nrOrdine;
    }
    //TODO: toString

    @Override
    public abstract String toString();
}
