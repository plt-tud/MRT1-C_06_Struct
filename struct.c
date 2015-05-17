/** Strukturen in C, MRT1, LUR (c) 2007 */
#include <stdio.h>	// prototyp für printf

// Deklaration der Struktur bauteil
struct bauteil {
		long number;
		char type;
		double value; // <- dieses letzte Semikolon muss sein
		};
		
int main() {
	long d;
 	struct bauteil bt;
 	
 	// Initialisierung von Strukturen
	struct bauteil btv[4] = {
		{ 1 },
		{ 2, 'R' },
		{ },
		{ 4, 'A', 100.0 } // <- hier darf KEIN Komma sein
	};
	
	// Zugriff auf die Elemente mit dem Punktoperator 
	bt.number = 5;
	bt.type = 'c';
	bt.value = 8.0;
	
	// Die Größe der Struktur in Bytes ist zur Übersetzungszeit bekannt
	d = sizeof(bt);
	d = sizeof(struct bauteil);
	// ist aber ungleich der Teilchengröße
	d = sizeof(bt.number) + sizeof(bt.type) + sizeof(bt.value);
	
	// Indexoperator hat Vorrang vor Punktoperator,
	// Adresse ist zur Übersetzungszeit bekannt:
	// 2 * sizeof(struct bauteil) + offset von type
	btv[2].type = 'C';
	
	return 0;
}
