import javax.print.Doc;
import java.util.ArrayList;

public class Angajat {
    private String nume;
    private String email;
    private String adresa;
    private ArrayList<Document> documente;//documentele in gestiunea acestui angajat

    public Angajat(String nume, String email, String adresa) {
        this.nume = nume;
        this.email = email;
        this.adresa = adresa;
    }

    public String getNume() {
        return nume;
    }

    public void setNume(String nume) {
        this.nume = nume;
    }

    public String getEmail() {
        return email;
    }

    public void setEmail(String email) {
        this.email = email;
    }

    public String getAdresa() {
        return adresa;
    }

    public void setAdresa(String adresa) {
        this.adresa = adresa;
    }

    public ArrayList<Document> getDocumente() {
        return documente;
    }

    public void setDocumente(ArrayList<Document> documente) {
        this.documente = documente;
    }
    public void addDocumentInGestiune(Document doc){
        if(documente.size()<10)//un angajat poate lua maxim 10 documente
        {
            documente.add(doc);
        }
    }
    public boolean checkIfDocExists(int alCateleaDoc){
        if(alCateleaDoc > documente.size() - 1)
            return true;
        return false;
    }
    public void getRidOfDocumentInGestiune(Document doc){
        if(documente.size()>0){
            //ceva sub zero ne-ar genera ceva eroare
            for(int i = 0; i < documente.size(); i++){
                if(doc.getId().equals(documente.get(i).getId()))
                    documente.remove(doc);
            }
        }
    }
    public void getInstitutiiDePeDiplome(){
        for(Document i: documente){
            if(i instanceof Diploma){
                System.out.println(((Diploma) i).getInstitutia());
            }
        }
    }
}
