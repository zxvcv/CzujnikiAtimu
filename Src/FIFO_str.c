#include "FIFO_str.h"

bool ListStr_Create(List_str** lista)
{
	if ((*lista) != NULL) //lista nie jest pusta
		return false;
	
	*lista = (List_str*)malloc(sizeof(List_str));
	(*lista)->begin = NULL;
	(*lista)->size = 0;
	return true;
}


bool ListStr_Push_C(List_str* lista, const char* val, const int val_size)
{
	if (lista == NULL) //lista jest niezainicjalizowana
		return false;

	//int i = 0;
	//while (val[i] != '\0') { ++i; } //obliczanie d³ugoœci ci¹gu znaków

	if (lista->size == 0)
	{
		lista->begin = (List_memb_str*)malloc(sizeof(List_memb_str));
		lista->begin->next = NULL;
		lista->begin->val = (char*)malloc(sizeof(*val)*(val_size + 1));
		strncpy(lista->begin->val, val, val_size);
		lista->begin->val[val_size] = '\0';
		lista->size += 1;
	}
	else
	{
		List_memb_str* prev = NULL;
		List_memb_str* memb = lista->begin;
		while (memb != NULL)
		{
			prev = memb;
			memb = memb->next;
		}
		prev->next = (List_memb_str*)malloc(sizeof(List_memb_str));
		prev->next->next = NULL;
		prev->next->val = (char*)malloc(sizeof(*val)*(val_size + 1));
		strncpy(prev->next->val, val, val_size);
		prev->next->val[val_size] = '\0';
		lista->size += 1;
	}
	return true;
}


bool ListStr_Push_NC(List_str* lista, char* val)
{
	if (lista == NULL) //lista jest niezainicjalizowana
		return false;

	if (lista->size == 0)
	{
		lista->begin = (List_memb_str*)malloc(sizeof(List_memb_str));
		lista->begin->next = NULL;
		lista->begin->val = val;
		lista->size += 1;
	}
	else
	{
		List_memb_str* prev = NULL;
		List_memb_str* memb = lista->begin;
		while (memb != NULL)
		{
			prev = memb;
			memb = memb->next;
		}
		prev->next = (List_memb_str*)malloc(sizeof(List_memb_str));
		prev->next->next = NULL;
		prev->next->val = val;
		lista->size += 1;
	}
	return true;
}


const char* ListStr_Front(List_str* lista)
{
	if (lista == NULL || lista->size == 0) //lista jest niezainicjalizowana
		return NULL;

	return lista->begin->val;
}


bool ListStr_Pop_C(List_str* lista)
{
	if (lista == NULL || lista->size == 0) //lista jest niezainicjalizowana
	{
		return false;
	}


	if (lista->size == 1)
	{
		free(lista->begin->val);
		free(lista->begin);
		lista->begin = NULL;
		lista->size = 0;
	}
	else
	{
		List_memb_str* del = lista->begin;
		lista->begin = lista->begin->next;
		free(del->val);
		free(del);
		lista->size -= 1;
	}
	return true;
}


bool ListStr_Pop_NC(List_str* lista)
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
		List_memb_str* del = lista->begin;
		lista->begin = lista->begin->next;
		free(del);
		lista->size -= 1;
	}
	return true;
}


void ListStr_Clear_C(List_str* lista)
{
	while (ListStr_Pop_C(lista)) {}
}


void ListStr_Clear_NC(List_str* lista)
{
	while (ListStr_Pop_NC(lista)) {}
}


bool ListStr_Delete_C(List_str** lista)
{
	if ((*lista) == NULL)
		return false;
	ListStr_Clear_C(*lista);
	free(*lista);
	*lista = NULL;
	return true;
}


bool ListStr_Delete_NC(List_str** lista)
{
	if ((*lista) == NULL)
		return false;
	ListStr_Clear_NC(*lista);
	free(*lista);
	*lista = NULL;
	return true;
}


int ListStr_GetSize(List_str* lista)
{
	return lista->size;
}


//---------kolejka FIFO--END
