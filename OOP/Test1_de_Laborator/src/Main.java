import java.util.ArrayList;

public class Main {
    public static void main(String[] args) {
        ///////CERINTA 1
        ArrayList<Document> arhiva = new ArrayList<Document>();
        ArrayList<Angajat> listaAngajati = new ArrayList<Angajat>();
        Angajat dummy = new Angajat("dummy", "dummy", "dummy");
        Angajat VB = new Angajat("Bartolomei Vlad", "vladbartolomei@gmail.com", "Plopilor 48, CJ-N");
        Angajat CP = new Angajat("Cornel Pop", "corneladrianpop@gmail.com", "Undeva in Dej 45, Dej");
        Angajat IG = new Angajat("Ion Giosan", "igiosan@cs.utcluj.ro", "Undeva in Alba, 79, Alba Iulia");
        Document D1 = new Diploma("12/12/2001", 3, "de merit", "TUCN", "licenta");
        Document D2 = new Diploma("06/05/2022", 3, "honoris", "UBB", "doctorat");
        ArrayList<String> beneficiariD3 = new ArrayList<String>();
        beneficiariD3.add(VB.getNume());
        beneficiariD3.add("Dragos Lisman");
        Document D3 = new Testament("13/09/2007", 10, beneficiariD3, "13/02/2006");
        arhiva.add(D1);
        arhiva.add(D2);
        arhiva.add(D3);
        arhiva.add(D2);
        ////////CERINTA 2
        Service.primesteDocumentInGestiune(VB, arhiva.get(0), arhiva);
        Service.primesteDocumentInGestiune(CP, arhiva.get(2), arhiva);
        Service.primesteDocumentInGestiune(IG, arhiva.get(1), arhiva);
        Service.returneazaDocumentDinGestiune(IG, 0, arhiva);
        Service.returneazaDocumentDinGestiune(VB, 0, arhiva);
        Service.returneazaDocumentDinGestiune(CP, 0, arhiva);
        ///////CERINTA 3
        int diplome = 0;
        int testamente = 0;
        int facturi = 0;
        for(Document i: arhiva){
            if(i instanceof Diploma)
                diplome++;
            if(i instanceof Testament)
                testamente++;
            if(i instanceof Factura)
                facturi++;
        }
        System.out.println("Avem in arhiva la acest moment:");
        System.out.println("-> "+diplome+" diplome");
        System.out.println("-> "+testamente+" testamente");
        System.out.println("-> "+facturi+" facturi");
///////////CERINTA 4
        VB.getInstitutiiDePeDiplome();
    ///////CERINTA 5
        listaAngajati.add(dummy);
        listaAngajati.add(VB);
        listaAngajati.add(CP);
        listaAngajati.add(IG);
        Service.angajatCuMinimDeDocInGestiune(listaAngajati);
    }
}
