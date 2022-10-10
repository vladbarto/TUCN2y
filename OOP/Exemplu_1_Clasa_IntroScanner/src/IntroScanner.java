import java.util.*;
public class IntroScanner
{
	public static void main(String[] args)
	{
		//... Initializare
		String nume; // Declara o variabila pentru nume.
		Scanner in = new Scanner(System.in);
		
		//... Scrie o explicatie si citeste intrarea
		System.out.println("Care e numele tau, prietene?");
		nume = in.nextLine(); // Citeste o linie de la consola.
		
		//... Afiseaza linia citita inainte
		System.out.println("Du-ma la seful vostru, " + nume);
		
		//... Citeste un intreg si apoi in afiseaza
		System.out.println("Introduceti un intreg: ");
		int val = in.nextInt();
		System.out.println("Numarul de tip intreg citit este: " + val );
		
		//... Citeste un numar real si apoi in afiseaza
		float f;
		System.out.println("Introduceti un numar real: ");
		f = in.nextFloat();
		System.out.println("Numarul de tip float citit este: " + f);
		
		//... Inchiderea citirii prin intermediul Scanner
		in.close();
	}
}