#include <stdio.h>//printf
#include <string.h>//strlen

int TwoCutSerach(int arr[],char target)
{
	int left = 0;
	int max_size = 7;
	int right = max_size - 1;
	int middle = 0;
  	while(left <= right)
	{
  		middle = (left + right)/2;
  		if(arr[middle] > target)
   		 {
    	  	right = middle-1;
    	}
  		else if(arr[middle] < target)
    	{
      		left = middle+1;
    	}
		else if(arr[middle] == target)
		{
			printf("Middle is :%d\n",middle);
			return middle;
		}
	}
	printf("未找到!\b");
	return -1;	
}

int main()
{
	int arr[] = {1,2,3,4,5,6,9,11};
	TwoCutSerach(arr,5);
  	return 0;
}