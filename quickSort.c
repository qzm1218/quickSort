#include <stdio.h>

void switchTwoValues(int *piValues, int index1, int index2)
{
	int tmp = *(piValues + index1);
	*(piValues + index1) = *(piValues + index2);
	*(piValues + index2) = tmp;
}

void quickSort(int *piValues, int iLeft, int iRight)
{
	char cFlags = 0;
	int iLeftTmp = iLeft;
	int iRightTmp = iRight;

	if(iLeft >= iRight)
	{
		return;
	}

	while(iLeft != iRight)
	{
		if(cFlags == 0)
		{
			//move left
			if(*(piValues + iLeft) > *(piValues + iRight))
			{
				switchTwoValues(piValues, iLeft, iRight);
				cFlags = 1;
				continue;
			}else
			{
				iLeft++;
			}
		}else
		{
			//move right
			if(*(piValues + iLeft) > *(piValues + iRight))
			{
				switchTwoValues(piValues, iLeft, iRight);
				cFlags = 0;
				continue;
			}else
			{
				iRight--;
			}
		}	
	}

	if(iLeft - 1 > iLeftTmp)
	{
		quickSort(piValues, iLeftTmp, iLeft - 1);
	}
	
	if(iLeft + 1 < iRightTmp)
	{
		quickSort(piValues, iLeft + 1, iRightTmp);
	}
}

void printArray(int *piValues, int num)
{
	int i = 0;
	for(; i < num; i++)
	{
		printf("%d ", *(piValues + i));
	}
}

int main(int argc, char *argv[])
{
	int values[] = {1,3,30,10,8,4,5,2,89,34,64,63,61};
	printf("before sort... \n");	
	printArray(values, 13);
	printf("\n");
	quickSort(values, 1, 12);
	printf("after sort... \n");	
	printArray(values, 13);
	printf("\n");
	return 0;

}
