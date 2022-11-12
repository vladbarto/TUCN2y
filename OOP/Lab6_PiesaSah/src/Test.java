import java.util.ArrayList;
public class Test {
    public static void main(String[] args){
        System.out.println("Hallo Leute");
        ///PiesaSah[] tabla = new PiesaSah[16];
        ArrayList<PiesaSah> tabla = new ArrayList<>();
        PiesaSah piesa = new Pion("pion1", 2, 2, "alb");
        tabla.add(piesa);
        piesa = new Pion("pion2", 3, 2, "alb");
        tabla.add(piesa);

        System.out.println(tabla.size());
        for(PiesaSah item: tabla)
            System.out.println(item.toString());

        for(int i = 0; i < tabla.size(); i++) {
            tabla.get(i).mutaPiesa(2, 3);
        }
        for(PiesaSah item: tabla)
            System.out.println(item.toString());
    }
}

