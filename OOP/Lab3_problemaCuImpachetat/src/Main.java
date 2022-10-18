
public class Main {
	int virsta, sex, inaltime;
	short info_impachetata;
	. . .
	// împachetare
	info_impachetata = (short)((((virsta << 1) | sex) << 8) | inaltime);
	. . .
	// despachetare
	inaltime = info_impachetata & 0xff;
	sex = (info_impachetata >>> 8) & 1;
	virsta = (info_impachetata >>> 9) & 0x7f;
}
