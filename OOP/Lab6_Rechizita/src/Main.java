import java.lang.reflect.Array;
import java.net.StandardSocketOptions;
import java.util.ArrayList;

public class Main {
    public static void main(String[] args) {
        Ghiozdan ghiozdan = new Ghiozdan();

        Rechizita c1 = new Caiet("POO");
        Rechizita c2 = new Caiet("AF");
        Rechizita c3 = new Caiet("MSI");

        Rechizita m1 = new Caiet("Fizica");
        Rechizita m2 = new Caiet("PSN");
        Rechizita m3 = new Caiet("Electrotehnica");

        ghiozdan.addRechizita(c1);
        ghiozdan.addRechizita(c3);
        ghiozdan.addRechizita(m1);

        ghiozdan.listItems();
        ghiozdan.listManual();

        System.out.println(ghiozdan.getNrRechizite());
//ce ar mai fi interesant:
        ArrayList<Rechizita> listaRechizite = new ArrayList<>();

        listaRechizite.add(c1);
        listaRechizite.add(c2);
        listaRechizite.add(c3);
        listaRechizite.add(m1);
        listaRechizite.add(m2);
        listaRechizite.add(m3);

        ghiozdan.addRechizita(c1);
        listaRechizite.remove(c1);
    }
}