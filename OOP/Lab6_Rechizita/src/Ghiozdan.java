import java.util.ArrayList;

public class Ghiozdan {

    private ArrayList<Rechizita> rechizite;
    //private Rechizita[] rechizitie;

    public Ghiozdan() {
        rechizite = new ArrayList<>();
        //rechizite = new Rechizita[20];
    }

    public void addRechizita(Rechizita rechizita) {
        rechizite.add(rechizita);
    }

    public void listItems() {
        for(Rechizita r: rechizite) {
            System.out.println(r.getNume());
        }
    }

    public void listManual() {
        for(Rechizita r: rechizite) {
            if(r instanceof Manual) {
                System.out.println(r.getNume());
            }

        }
    }

    public int getNrRechizite() {
        return rechizite.size();
    }

    public int getNrCaiete() {
        int count =0;
        for(Rechizita r: rechizite) {
            if( r instanceof Caiet) {
                count++;
            }
        }

        return count;
    }
}

