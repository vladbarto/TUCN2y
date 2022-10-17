import java.util.Scanner;

public class Problema4_3 {
	public static void main(String[] args)
	{
		//punctul A
		//zona de declarare-initializare
		String s = new String("AbeCEd02ar1xyzti al doilea  cuv");
		int L = s.length();
		int vowels = 0, consoles = 0;
		char c;
		boolean isVowel = false;
		
		//zona de prelucrare convenabila a stringului s
		s = s.toLowerCase();
		///s = s.replaceAll("\\s+", "");
		System.out.println("s este " + s);
		
		//zona de contorizare
		for(int i = 0; i < L; i++)
		{
			isVowel = false;
			c = s.charAt(i);
			if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
			{
				vowels++;
				isVowel = true;
			}
			else if (isVowel == false)
			{
				if(c >= 'a' && c <= 'z')
					consoles++;
			}
				
		}
		
		//zona de afisare - punctul A
		System.out.println("Numarul de vocale din "+s+" este "+vowels+"\n");
		System.out.println("Numarul de consoane din "+s+" este "+consoles+"\n");
		
		//------------------------------------------
		//punctul B
		//zona de declarare
		Scanner in = new Scanner(System.in);
		System.out.println(s+" Introduceti de la tastatura o litera: ");
		String x = in.next();
		c = x.charAt(0);
		System.out.println("Verificare ca s-a citit litera buna: echo >> " + c);
		char cnou;
		
		//zona de cautare + printare
		for(int i = 0; i < L; i++)
		{
			cnou = s.charAt(i);
			if(c == cnou)
				System.out.println("\t" + c + " pe pozitia " + i + "\n");	
		}
	}
}
