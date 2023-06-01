#include <iostream>

struct vertex
{
	float x;
	float y;
	float r;
	float g;
	float b;
	struct vertex* next; 
};

void inputData(struct vertex** list,float x,float y,float r,float g,float b)
{
	struct vertex* newData = new vertex();
	newData->x = x;
	newData->y = y;
	newData->r = r;
	newData->g = g;
	newData->b = b;
	newData->next = NULL;
	if(*list == NULL)
	{
		*list = newData;
		return;
	}
	struct vertex* tmp = *list;
	while(tmp->next != NULL)
	{
		tmp = tmp->next;
	}
	tmp->next = newData;
	return;
}


void printData(struct vertex* list)
{
	struct vertex* tmp = list;
	std::cout << list->x << std::endl;
	while(tmp != NULL)
	{
		std::cout << "x:" << tmp->x << std::endl << "y:" << tmp->y << std::endl << "r:" << tmp->r << std::endl << "g:" << tmp->g << std::endl << "b:" << tmp->b << std::endl;
		tmp = tmp->next;
 	}
}