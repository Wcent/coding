// sort.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>

using namespace std;

//
void insertSort(int *array, int len);
void shellSort(int *array, int len);

void output(int *array, int len)
{
    for (int i=0; i<len; i++)
	     cout<<" "<<array[i];
		 cout<<endl;
}


int main()
{
//    int c[] = {7, 2, 8, 2, 1, 0, 3, 6, 9, 8};
//	int c[] = {0, 0, 1, 2, 3, 3, 3, 6, 7, 8};
	int c[] = {1};
//	int c[] = {0, 1, 3};
    
//	int d[] = {7, 2, 8, 2, 1, 0, 3, 6, 9, 8};
//	int d[] = {0, 0, 1, 2, 3, 3, 3, 6, 7, 8};
	int d[] = {1};
//	int d[] = {0, 1, 3};
    int len = 1;
	
	cout<<"array:";
	output(c, len);
	cout<<"insert sort:";
	insertSort(c, len);
	output(c, len);
	cout<<endl;
	
	cout<<"array:";
	output(d, len);
	cout<<"shell sort:";
	insertSort(d, len);
	output(d, len);
	cout<<endl;
	
	return 0;
}

//
void insertSort(int *array, int len)
{
	int i, j;
    int temp;
	
    for (i=1; i<len; i++)
	{
	    temp = array[i];
	    for (j=i; j>0; j--)
		{
		    if (array[j-1] <= temp)
			    break;
				
			array[j] = array[j-1];
		}
		array[j] = temp;
	}
}

//
void shellSort(int *array, int len)
{
    int i, j;
    int gap;
	int temp;
	
	gap = len;
	while( (gap /= 2) )
	{
	    for (i=gap; i<len; i+=gap)
		{
		    temp = array[i];
		    for (j=i; j-gap>=0; j-=gap)
			{
			    if (array[j-gap] <= temp)
				    break;
				array[j] = array[j-gap];
			}		
			array[j] = temp;
		}
	}
}
