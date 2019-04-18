#ifndef FIFO_STRING_H
#define FIFO_STRING_H

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

/*
*kolejka FIFO dla ci�g�w znak�w (string)
w tej bibliotece znajduj� si� funkcje do obs�ugi Listy FIFO na 2 sposoby:
1 - podawana warto�� przez wskaznik na ci�g znak�w jest kopiowana i alokowana jest dla kopii osobna pamie�
2 - wska�nik podany w wywo�aniu funkcji jest zapisywany bezpo�rednio na li�cie i przy usuwaniu takeigo elementu jest te� zwalniana pami�� dla takiego wska�nika

Dzi�ki czemu nie musimy usuwac zawarto�ci tych wska�nik�w na ko�cu programu (miejsce w pamieci (funkcja free()) jest wywo�ywana
w funkcji List_Pop()
*/



//----------------typy danych----------------

typedef struct List_memb_str {
	struct List_memb_str* next;
	char* val;
}List_memb_str;

typedef struct List_str {
	List_memb_str* begin;
	int size;
}List_str;



//----------------funkcje----------------

/*
funkcja tworz�ca list� FIFO na wska�niku do struktury List
!wskaznik musi byc zainicjalizowany na poczatku wartoscia NULL

@param lista wskaznik na wskaznik do struktury do pracy na li�cie
@return (true) gdy inicjalizacja sie powiod�a (false) w przeciwnym wypadku
*/
bool ListStr_Create(List_str** lista);

/*
funkcja dodajaca element na koniec listy FIFO
funkcja typu C(COPY) - u�ywaj�ca strn_cpy() przy inicjalizacji elementu listy tworzy kopie wartosci spod wskaznika i inicjalizuje ni� watro�� na liscie

@param lista wskaznik na list� element�w na kt�rej pracujemy
@param val wskaznik na wartosc kt�ra zostanie przekopiowania i przechowywana na liscie
@param val_size dlugosc ciagu znakow val (wszystkich wlacznie z '\0'
@return (true) gdy dodanei sie powiod�o (false) w przeciwnym wypadku
*/
bool ListStr_Push_C(List_str* lista, const char* val, const int val_size);

/*
funkcja dodajaca element na koniec listy FIFO
funkcja typu NC(NO COPY) - nie u�ywaj�ca strn_cpy() przy inicjalizacji elementu listy tylko wyko�ystujaca podany wskaznik
!!! trzeba podawa� wska�nik wskazuj�cy na miejsce w pamie�i zaalokowane wcze�niej przez funkcj� malloc()

@param lista wskaznik na list� element�w na kt�rej pracujemy
@param val wskaznik na wartosc kt�ry zostanie umieszczony na liscie
@return (true) gdy dodanei sie powiod�o (false) w przeciwnym wypadku
*/
bool ListStr_Push_NC(List_str* lista, char* val);

/*
funkcja zwracaj�ca wskaznik na ci�g znak�w na pocz�tku listy

@param lista wskaznik na list� element�w na kt�rej pracujemy
@return wskaznik na pierwszy element na liscie lub NULL gdy takeigo nie ma lub wystapi� blad
*/
const char* ListStr_Front(List_str* lista);

/*
funkcja usuwaj�ca element z pocz�tku listy FIFO
funkcja typu C(COPY) - nale�y uzywa� je�eli wcze�niej element zosta� zainicjalizowany funkcj� List_Pusch_C

@param lista wskaznik na list� element�w na kt�rej pracujemy
@return (true) gdy usuniecie sie powiod�o (false) w przeciwnym wypadku
*/
bool ListStr_Pop_C(List_str* lista);

/*
funkcja usuwaj�ca element z pocz�tku listy FIFO
funkcja typu NC(NO COPY) - nale�y uzywa� je�eli wcze�niej element zosta� zainicjalizowany funkcj� List_Pusch_NC

@param lista wskaznik na list� element�w na kt�rej pracujemy
@return (true) gdy usuniecie sie powiod�o (false) w przeciwnym wypadku
*/
bool ListStr_Pop_NC(List_str* lista);

/*
funkcja usuwaj�ca wszystkie elementy z listy FIFO
funkcja typu C(COPY) - nale�y uzywa� je�eli wcze�niej elementy zosta�y zainicjalizowane funkcj� List_Pusch_C
!!! nie wolno u�ywa� gdy lista zosta�a inicjalizowana jednocze�nie funkcjami List_Pusch_C i List_Pusch_NC

@param lista wskaznik na list� element�w na kt�rej pracujemy
*/
void ListStr_Clear_C(List_str* lista);

/*
funkcja usuwaj�ca wszystkie elementy z listy FIFO
funkcja typu NC(NO COPY) - nale�y uzywa� je�eli wcze�niej elementy zosta�y zainicjalizowane funkcj� List_Pusch_NC
!!! nie wolno u�ywa� gdy lista zosta�a inicjalizowana jednocze�nie funkcjami List_Pusch_C i List_Pusch_NC

@param lista wskaznik na list� element�w na kt�rej pracujemy
*/
void ListStr_Clear_NC(List_str* lista);

/*
funkcja usuwaj�ca list� FIFO
funkcja typu C(COPY) - nale�y uzywa� je�eli wcze�niej elementy zosta�y zainicjalizowane funkcj� List_Pusch_C
!!! nie wolno u�ywa� gdy lista zosta�a inicjalizowana jednocze�nie funkcjami List_Pusch_C i List_Pusch_NC

@param lista wskaznik na list� element�w na kt�rej pracujemy
@return (true) jezeli udalo sie wykonac operacje usuwania listy (false) w przeciwnym przypadku
*/
bool ListStr_Delete_C(List_str** lista);

/*
funkcja usuwaj�ca list� FIFO
funkcja typu NC(NO COPY) - nale�y uzywa� je�eli wcze�niej elementy zosta�y zainicjalizowane funkcj� List_Pusch_NC
!!! nie wolno u�ywa� gdy lista zosta�a inicjalizowana jednocze�nie funkcjami List_Pusch_C i List_Pusch_NC

@param lista wskaznik na list� element�w na kt�rej pracujemy
@return (true) jezeli udalo sie wykonac operacje usuwania listy (false) w przeciwnym przypadku
*/
bool ListStr_Delete_NC(List_str** lista);

/*
funkcja zwracaj�ca aktualn� wielko�c listy list

@param lista wskaznik na list� element�w na kt�rej pracujemy
@return aktualna wielko�� listy
*/
int ListStr_GetSize(List_str* lista);

#endif //FIFO_STRING_H
