#ifndef FIFO_CHAR_H
#define FIFO_CHAR_H

#include <stdbool.h>
#include <stdlib.h>

/*
*kolejka FIFO dla pojedynczych znak�w (opr�cz \0), ktory jest znakiem specjalnym (nie moze byc uzywany do przechowywania w liscie)
w tej bibliotece znajduj� si� funkcje do obs�ugi Listy FIFO
*/



//----------------typy danych----------------

typedef struct List_memb_ch {
	struct List_memb_ch* next;
	char val;
}List_memb_ch;

typedef struct List_ch {
	List_memb_ch* begin;
	int size;
}List_ch;



//----------------funkcje----------------

/*
funkcja tworz�ca list� FIFO na wska�niku do struktury List
!wskaznik musi byc zainicjalizowany na poczatku wartoscia NULL

@param lista wskaznik na wskaznik do struktury do pracy na li�cie
@return (true) gdy inicjalizacja sie powiod�a (false) w przeciwnym wypadku
*/
bool ListCh_Create(List_ch** lista);

/*
funkcja dodajaca element na koniec listy FIFO

@param lista wskaznik na list� element�w na kt�rej pracujemy
@param val wartosc do umieszczenia na liscie
@return (true) gdy dodanie sie powiod�o (false) w przeciwnym wypadku
*/
bool ListCh_Push(List_ch* lista, const char val);

/*
funkcja zwracaj�ca wskaznik na znak na pocz�tku listy

@param lista wskaznik na list� element�w na kt�rej pracujemy
@return wartosc na pierwszym miejscu na liscie lub NULL(0) gdy takiego nie ma lub wystapi� blad
*/
char ListCh_Front(List_ch* lista);

/*
funkcja usuwaj�ca element z pocz�tku listy FIFO

@param lista wskaznik na list� element�w na kt�rej pracujemy
@return (true) gdy usuniecie sie powiod�o (false) w przeciwnym wypadku
*/
bool ListCh_Pop(List_ch* lista);

/*
funkcja usuwaj�ca wszystkie elementy z listy FIFO

@param lista wskaznik na list� element�w na kt�rej pracujemy
*/
void ListCh_Clear(List_ch* lista);

/*
funkcja usuwaj�ca list� FIFO

@param lista wskaznik na list� element�w na kt�rej pracujemy
@return (true) jezeli udalo sie wykonac operacje usuwania listy (false) w przeciwnym przypadku
*/
bool ListCh_Delete(List_ch** lista);

/*
funkcja zwracaj�ca aktualn� wielko�c listy lista

@param lista wskaznik na list� element�w na kt�rej pracujemy
@return aktualna wielko�� listy
*/
int ListCh_GetSize(List_ch* lista);

#endif //FIFO_CHAR_H
