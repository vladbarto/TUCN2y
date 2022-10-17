import java.util.*;

public class MainClass {
	public static void main(String[] Args) {
		
		//Citim intregi si ii afisam pana cand dam de zero (0).
		int x, val;
		/*Scanner in = new Scanner(System.in);
		
		do
		{
		//nota: printf-ul din C este EGAL cu urmatorul rahat:
		System.out.println("Consola asteapta sa introduci un numar int: ");
		
		x = in.nextInt();
		
		//punem un mesaj in care afisam numarul
		System.out.println("Log: numarul afisat este " + x);
		}	while (x != 0) ;*/
		

		//-----------------------------------------------------------------------------------------------------
		//Incercam acum sa citim pana cand apare altceva decat numar intreg
		int y;
		
		//do
		//{
		//nota: printf-ul din C este EGAL cu urmatorul rahat:
		System.out.println("Consola asteapta sa introduci un numar int: ");
		
		y = Integer.parseInt(nextInt());
		
		//aruncam o eroare in cazul in care x-ul citit nu este un int
		/*try
		{
			y.isDigit();
			break;
		}
		catch(Exception e)
		{
			System.out.println("Ce s-a citit in consola nu e cifra! " + e);
		}*/
		if(y>=0 && y <=9)
		//punem un mesaj in care afisam numarul
			System.out.println("Log: numarul afisat este " + x);
		//}	while (y.isdigit) ;
		else System.out.println("no, amu ii bai");
	}

}
