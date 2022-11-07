public class Caiet extends Rechizita {

    public Caiet(String eticheta){
        super(eticheta);
    }

    public String getNume() {
        return super.getEticheta()
                + " Caiet"; //afisati eticheta care e in parinte

    }
}
