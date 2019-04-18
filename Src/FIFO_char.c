#include "FIFO_char.h"


bool ListCh_Create(List_ch** lista)
{
	if ((*lista) != NULL) //lista nie jest pusta
		return false;
	
	*lista = (List_ch*)malloc(sizeof(List_ch));
	(*lista)->begin = NULL;
	(*lista)->size = 0;
	return true;
}


bool ListCh_Push(List_ch* lista, const char val)
{
	if (lista == NULL) //lista jest niezainicjalizowana
		return false;

	if (lista->size == 0)
	{
		lista->begin = (List_memb_ch*)malloc(sizeof(List_memb_ch));
		lista->begin->next = NULL;
		lista->begin->val = val;
		lista->size += 1;
	}
	else
	{
		List_memb_ch* prev = NULL;
		List_memb_ch* memb = lista->begin;
		while (memb != NULL)
		{
			prev = memb;
			memb = memb->next;
		}
		prev->next = (List_memb_ch*)malloc(sizeof(List_memb_ch));
		prev->next->next = NULL;
		prev->next->val = val;
		lista->size += 1;
	}
	return true;
}


char ListCh_Front(List_ch* lista)
{
	if (lista == NULL || lista->size == 0) //lista jest niezainicjalizowana
		return (char)0;

	return lista->begin->val;
}


bool ListCh_Pop(List_ch* lista)
{
	if (lista == NULL || lista->size == 0) //lista jest niezainicjalizowana
	{
		return false;
	}


	if (lista->size == 1)
	{
		free(lista->begin);
		lista->begin = NULL;
		lista->size = 0;
	}
	else
	{
		List_memb_ch* del = lista->begin;
		lista->begin = lista->begin->next;
		free(del);
		lista->size -= 1;
	}
	return true;
}


void ListCh_Clear(List_ch* lista)
{
	while (ListCh_Pop(lista)) {}
}


bool ListCh_Delete(List_ch** lista)
{
	if ((*lista) == NULL)
		return false;
	ListCh_Clear(*lista);
	free(*lista);
	*lista = NULL;
	return true;
}


int ListCh_GetSize(List_ch* lista)
{
	return lista->size;
}


//---------kolejka FIFO--END
