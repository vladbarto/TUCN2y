import jdk.jshell.execution.Util;

import java.util.ArrayList;
import java.util.Arrays;

public class Utilizator {
    private String username;
    private String email;
    private String numeComplet;
    private String status;//casatorit, single, in a relationship
    private ArrayList<Utilizator> prieteni = new ArrayList<Utilizator>();
    private ArrayList<Pagina> followedPages = new ArrayList<Pagina>();
    public Utilizator(){
        this("Dummy", "Dummy", "Dummy", "Dummy");
    }
    public Utilizator(String username, String email, String numeComplet, String status) {
        this.username = username;
        this.email = email;
        this.numeComplet = numeComplet;
        this.status = status;
    }

    public String getUsername() {
        return username;
    }

    public void setUsername(String username) {
        this.username = username;
    }

    public String getEmail() {
        return email;
    }

    public void setEmail(String email) {
        this.email = email;
    }

    public String getNumeComplet() {
        return numeComplet;
    }

    public void getFriendsWithGivenStatus(String status){
        for(Utilizator i:prieteni)
            if(i.status.equals(status))
                System.out.println(i.getNumeComplet());
    }

    public void setNumeComplet(String numeComplet) {
        this.numeComplet = numeComplet;
    }

    public String getStatus() {
        return status;
    }

    public void setStatus(String status) {
        this.status = status;
    }

    public ArrayList<Utilizator> getPrieteni() {
        return prieteni;
    }

    public void setPrieteni(ArrayList<Utilizator> prieteni) {
        this.prieteni = prieteni;
    }

    public ArrayList<Pagina> getFollowedPages() {
        return followedPages;
    }

    public void setFollowedPages(ArrayList<Pagina> followedPages) {
        this.followedPages = followedPages;
    }

    @Override
    public String toString() {
        return "Utilizator{" +
                "username='" + username + '\'' +"\n"+
                ", email='" + email + '\'' +"\n"+
                ", numeComplet='" + numeComplet + '\'' +"\n"+
                ", status='" + status + '\'' +"\n"+'}';
    }

    public void showInfoAboutUser(){
        System.out.println("Utilizator{"+"username='" + username + '\'');
        System.out.println(", email='" + email + '\'');
        System.out.println(", numeComplet='" + numeComplet + '\'');
        System.out.println(", status='" + status + '\'');
        System.out.println(", prieteni:[");
        for(Utilizator i : prieteni)
            System.out.println(i.getNumeComplet()+" ");
        System.out.println("]\n, pagini apreciate:[");
        for(Pagina i: followedPages)
            System.out.println(i.getNume()+" ");
        System.out.println("]\n");
    }

    public void addFriend(Utilizator prieten) {
        //test if utilizatorul transmis e deja prieten
        int ok = 0;
        for(Utilizator i:prieteni)
        {
            if(prieten.getNumeComplet().equals(i.getNumeComplet()))
                ok = 1;
        }
        if(ok==0)
            prieteni.add(prieten);
    }

    public void removeFriend(Utilizator prietenDat) {
        for (int i = 0; i < prieteni.size(); i++) {
            if (prietenDat.getUsername().equals(prieteni.get(i).getUsername())) {
                prieteni.remove(i);
            }
        }
    }

    public void follow(Pagina pagina) {
        //=like
        int ok = 0;
        for (Pagina i : followedPages) {
            if (pagina.getNume().equals(i.getNume()))
                ok = 1;
        }
        if (ok == 0) {
            followedPages.add(pagina);
            pagina.newFollower();
        }
    }


    public void unfollow(Pagina pagina) {
        //=dislike
        for (int i = 0; i < followedPages.size(); i++) {
            if (pagina.getNume().equals(followedPages.get(i).getNume()))
            {
                followedPages.remove(i);
                pagina.lostAnFollower();
            }
        }
    }

    public void unfollowPagesWithGivenActivityDomain(String actDom){
        for(int i = 0; i < followedPages.size(); i++){
            if(followedPages.get(i).getActivityDomain().equals(actDom))
                unfollow(followedPages.get(i));
        }
    }
    public boolean isFollowingThisPage(Pagina page){
        for(Pagina i:followedPages)
        {
            if(page.getNume().equals(i.getNume()))
                return true;
        }
        return false;
    }
    public void showListOfFriends(){
        System.out.println("Friends of "+numeComplet+" are:");
        for(Utilizator i:prieteni){
            System.out.println("->"+i.getNumeComplet());
        }
    }
}
