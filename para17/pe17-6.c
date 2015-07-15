bool BinarySearch(int * arr, int size, int key);

bool BinarySearch(int * arr, int size, int key)
{
	int left = 0;
	int right = size - 1;
	int mid = 0;
	
	while(left <= right)
	{
		mid = (left + right) / 2;
		if(key == *(arr + mid))
		{
			return true;	
		}
		if(key < *(arr + mid))
		{
			right = mid - 1;
		}
		if(key > *(arr + mid))
		{
			left = mid + 1;
		}
	}
	
	return false;
}