import java.util.ArrayList;

public class Ghiozdan {

    private ArrayList<Rechizita> rechizite;
    public Ghiozdan(){
        rechizite = new ArrayList<>();
        //rechizite = new Rechizita[20];
    }
    public void addRechizita(Rechizita rechizita) {
        rechizite.add(rechizita);
    }
    public void listItems(){
        for(Rechizita r: rechizite){
            if(r instanceof Manual)
            {
                System.out.println(r.getEticheta());//getNume()?
            }
        }
    }
    public int getNrRechizite(){
        return rechizite.size();
    }
    public int getNrCaiete(){
        int count = 0;
        for(Rechizita r: rechizite){
            if(r instanceof Caiet){
                count++;
            }
        }
    }

}

