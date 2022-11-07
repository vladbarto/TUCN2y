public class Manual extends Rechizita {

    public Manual(String eticheta){
        super(eticheta);
    }

    public String getNume() {
        return super.getEticheta()
                + " Manual"; //afisati eticheta care e in parinte

    }
}
