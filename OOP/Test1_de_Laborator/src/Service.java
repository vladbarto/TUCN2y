import java.util.ArrayList;

public class Service {
    public static void primesteDocumentInGestiune(Angajat a, Document doc, ArrayList<Document> arhiva){
        if(a.getDocumente().size()<10)//un angajat poate lua maxim 10 documente
        {
            a.addDocumentInGestiune(doc);
            for(int i = 0; i < arhiva.size(); i++){
                if(doc.getId().equals(arhiva.get(i).getId()) &&
                doc.getDataArhivarii().equals(arhiva.get(i).getDataArhivarii()) &&
                doc.getNrPagini() == arhiva.get(i).getNrPagini())
                    arhiva.remove(arhiva.get(i));
            }
        }
    }
    public static void returneazaDocumentDinGestiune(Angajat a, int alCateleaDoc, ArrayList<Document> arhiva){
        if(a.checkIfDocExists(alCateleaDoc)==true){
            //if false, nu fa nimic. Teoretic nu ar trebui sa se ajunga in acest caz nicicum
            Document doc = a.getDocumente().get(alCateleaDoc);
            arhiva.add(doc);
        }
    }

    public static void angajatCuMinimDeDocInGestiune(ArrayList<Angajat> a){
        int min = a.get(0).getDocumente().size();
        Angajat angajatmin = a.get(0);
        for(Angajat x: a){
            if(x.getDocumente().size() < min){
                angajatmin = x;
                min = x.getDocumente().size();
            }
        }
        System.out.println("Angajatul cu cele mai putine documente in gestiune este: " + angajatmin.getNume());
    }
}
