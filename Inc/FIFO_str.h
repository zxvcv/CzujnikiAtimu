#ifndef FIFO_STRING_H
#define FIFO_STRING_H

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

/*
*kolejka FIFO dla ci¹gów znaków (string)
w tej bibliotece znajduj¹ siê funkcje do obs³ugi Listy FIFO na 2 sposoby:
1 - podawana wartoœæ przez wskaznik na ci¹g znaków jest kopiowana i alokowana jest dla kopii osobna pamieæ
2 - wskaŸnik podany w wywo³aniu funkcji jest zapisywany bezpoœrednio na liœcie i przy usuwaniu takeigo elementu jest te¿ zwalniana pamiêæ dla takiego wskaŸnika

Dziêki czemu nie musimy usuwac zawartoœci tych wskaŸników na koñcu programu (miejsce w pamieci (funkcja free()) jest wywo³ywana
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
funkcja tworz¹ca listê FIFO na wskaŸniku do struktury List
!wskaznik musi byc zainicjalizowany na poczatku wartoscia NULL

@param lista wskaznik na wskaznik do struktury do pracy na liœcie
@return (true) gdy inicjalizacja sie powiod³a (false) w przeciwnym wypadku
*/
bool ListStr_Create(List_str** lista);

/*
funkcja dodajaca element na koniec listy FIFO
funkcja typu C(COPY) - u¿ywaj¹ca strn_cpy() przy inicjalizacji elementu listy tworzy kopie wartosci spod wskaznika i inicjalizuje ni¹ watroœæ na liscie

@param lista wskaznik na listê elementów na której pracujemy
@param val wskaznik na wartosc która zostanie przekopiowania i przechowywana na liscie
@param val_size dlugosc ciagu znakow val (wszystkich wlacznie z '\0'
@return (true) gdy dodanei sie powiod³o (false) w przeciwnym wypadku
*/
bool ListStr_Push_C(List_str* lista, const char* val, const int val_size);

/*
funkcja dodajaca element na koniec listy FIFO
funkcja typu NC(NO COPY) - nie u¿ywaj¹ca strn_cpy() przy inicjalizacji elementu listy tylko wyko¿ystujaca podany wskaznik
!!! trzeba podawaæ wskaŸnik wskazuj¹cy na miejsce w pamieæi zaalokowane wczeœniej przez funkcjê malloc()

@param lista wskaznik na listê elementów na której pracujemy
@param val wskaznik na wartosc który zostanie umieszczony na liscie
@return (true) gdy dodanei sie powiod³o (false) w przeciwnym wypadku
*/
bool ListStr_Push_NC(List_str* lista, char* val);

/*
funkcja zwracaj¹ca wskaznik na ci¹g znaków na pocz¹tku listy

@param lista wskaznik na listê elementów na której pracujemy
@return wskaznik na pierwszy element na liscie lub NULL gdy takeigo nie ma lub wystapi³ blad
*/
const char* ListStr_Front(List_str* lista);

/*
funkcja usuwaj¹ca element z pocz¹tku listy FIFO
funkcja typu C(COPY) - nale¿y uzywaæ je¿eli wczeœniej element zosta³ zainicjalizowany funkcj¹ List_Pusch_C

@param lista wskaznik na listê elementów na której pracujemy
@return (true) gdy usuniecie sie powiod³o (false) w przeciwnym wypadku
*/
bool ListStr_Pop_C(List_str* lista);

/*
funkcja usuwaj¹ca element z pocz¹tku listy FIFO
funkcja typu NC(NO COPY) - nale¿y uzywaæ je¿eli wczeœniej element zosta³ zainicjalizowany funkcj¹ List_Pusch_NC

@param lista wskaznik na listê elementów na której pracujemy
@return (true) gdy usuniecie sie powiod³o (false) w przeciwnym wypadku
*/
bool ListStr_Pop_NC(List_str* lista);

/*
funkcja usuwaj¹ca wszystkie elementy z listy FIFO
funkcja typu C(COPY) - nale¿y uzywaæ je¿eli wczeœniej elementy zosta³y zainicjalizowane funkcj¹ List_Pusch_C
!!! nie wolno u¿ywaæ gdy lista zosta³a inicjalizowana jednoczeœnie funkcjami List_Pusch_C i List_Pusch_NC

@param lista wskaznik na listê elementów na której pracujemy
*/
void ListStr_Clear_C(List_str* lista);

/*
funkcja usuwaj¹ca wszystkie elementy z listy FIFO
funkcja typu NC(NO COPY) - nale¿y uzywaæ je¿eli wczeœniej elementy zosta³y zainicjalizowane funkcj¹ List_Pusch_NC
!!! nie wolno u¿ywaæ gdy lista zosta³a inicjalizowana jednoczeœnie funkcjami List_Pusch_C i List_Pusch_NC

@param lista wskaznik na listê elementów na której pracujemy
*/
void ListStr_Clear_NC(List_str* lista);

/*
funkcja usuwaj¹ca listê FIFO
funkcja typu C(COPY) - nale¿y uzywaæ je¿eli wczeœniej elementy zosta³y zainicjalizowane funkcj¹ List_Pusch_C
!!! nie wolno u¿ywaæ gdy lista zosta³a inicjalizowana jednoczeœnie funkcjami List_Pusch_C i List_Pusch_NC

@param lista wskaznik na listê elementów na której pracujemy
@return (true) jezeli udalo sie wykonac operacje usuwania listy (false) w przeciwnym przypadku
*/
bool ListStr_Delete_C(List_str** lista);

/*
funkcja usuwaj¹ca listê FIFO
funkcja typu NC(NO COPY) - nale¿y uzywaæ je¿eli wczeœniej elementy zosta³y zainicjalizowane funkcj¹ List_Pusch_NC
!!! nie wolno u¿ywaæ gdy lista zosta³a inicjalizowana jednoczeœnie funkcjami List_Pusch_C i List_Pusch_NC

@param lista wskaznik na listê elementów na której pracujemy
@return (true) jezeli udalo sie wykonac operacje usuwania listy (false) w przeciwnym przypadku
*/
bool ListStr_Delete_NC(List_str** lista);

/*
funkcja zwracaj¹ca aktualn¹ wielkoœc listy list

@param lista wskaznik na listê elementów na której pracujemy
@return aktualna wielkoœæ listy
*/
int ListStr_GetSize(List_str* lista);

#endif //FIFO_STRING_H
