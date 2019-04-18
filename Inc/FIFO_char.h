#ifndef FIFO_CHAR_H
#define FIFO_CHAR_H

#include <stdbool.h>
#include <stdlib.h>

/*
*kolejka FIFO dla pojedynczych znaków (oprócz \0), ktory jest znakiem specjalnym (nie moze byc uzywany do przechowywania w liscie)
w tej bibliotece znajduj¹ siê funkcje do obs³ugi Listy FIFO
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
funkcja tworz¹ca listê FIFO na wskaŸniku do struktury List
!wskaznik musi byc zainicjalizowany na poczatku wartoscia NULL

@param lista wskaznik na wskaznik do struktury do pracy na liœcie
@return (true) gdy inicjalizacja sie powiod³a (false) w przeciwnym wypadku
*/
bool ListCh_Create(List_ch** lista);

/*
funkcja dodajaca element na koniec listy FIFO

@param lista wskaznik na listê elementów na której pracujemy
@param val wartosc do umieszczenia na liscie
@return (true) gdy dodanie sie powiod³o (false) w przeciwnym wypadku
*/
bool ListCh_Push(List_ch* lista, const char val);

/*
funkcja zwracaj¹ca wskaznik na znak na pocz¹tku listy

@param lista wskaznik na listê elementów na której pracujemy
@return wartosc na pierwszym miejscu na liscie lub NULL(0) gdy takiego nie ma lub wystapi³ blad
*/
char ListCh_Front(List_ch* lista);

/*
funkcja usuwaj¹ca element z pocz¹tku listy FIFO

@param lista wskaznik na listê elementów na której pracujemy
@return (true) gdy usuniecie sie powiod³o (false) w przeciwnym wypadku
*/
bool ListCh_Pop(List_ch* lista);

/*
funkcja usuwaj¹ca wszystkie elementy z listy FIFO

@param lista wskaznik na listê elementów na której pracujemy
*/
void ListCh_Clear(List_ch* lista);

/*
funkcja usuwaj¹ca listê FIFO

@param lista wskaznik na listê elementów na której pracujemy
@return (true) jezeli udalo sie wykonac operacje usuwania listy (false) w przeciwnym przypadku
*/
bool ListCh_Delete(List_ch** lista);

/*
funkcja zwracaj¹ca aktualn¹ wielkoœc listy lista

@param lista wskaznik na listê elementów na której pracujemy
@return aktualna wielkoœæ listy
*/
int ListCh_GetSize(List_ch* lista);

#endif //FIFO_CHAR_H
