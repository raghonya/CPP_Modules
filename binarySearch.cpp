#include <iostream>
#include <vector>

void	binarySearch(std::vector<int> &arr, int low, int high, int insert)
{
	int		mid = low + (high - low) / 2;

	std::cout << "low, mid, high: " << low << " " << mid << " " << high << std::endl;
	if (high - low == 1)
	{
		if (insert <= arr[low])
			arr.insert(arr.begin() + low, insert);
		else if (arr[high] <= insert)
			arr.insert(arr.begin() + high + 1, insert);
		else
			arr.insert(arr.begin() + low + 1, insert);
	}
	else if (high == low)
	{
		if (arr[low] <= insert)
			arr.insert(arr.begin() + low + 1, insert);
		else
			arr.insert(arr.begin() + low, insert);
	}
	else if (arr[mid] <= insert)
		binarySearch(arr, mid + 1, high, insert);
	else if (insert <= arr[mid])
		binarySearch(arr, low, mid - 1, insert);
}

int	main()
{
	std::vector<int> arr;

	// arr.push_back(1);
	// arr.push_back(4);
	// arr.push_back(8);
	// arr.push_back(11);
	// arr.push_back(25);
	arr.push_back(28);
	// arr.push_back(41);
	// arr.push_back(43);

	std::vector<int> insert;

	insert.push_back(5);
	insert.push_back(17);
	insert.push_back(12);
	insert.push_back(200);
	insert.push_back(39);
	insert.push_back(7);
	insert.push_back(0);
	insert.push_back(4);
	insert.push_back(4);
	insert.push_back(4);

	std::cout << "PERVI VEKTR: " << std::endl;
	for (std::vector<int>::iterator begin = insert.begin(); begin < insert.end(); ++begin)
	{
		std::cout << *begin << " ";
	}
	std::cout << std::endl;
	std::cout << std::endl;
	for (int i = 0; i < insert.size(); ++i)
	{
		for (std::vector<int>::iterator begin = arr.begin(); begin < arr.end(); ++begin)
		{
			std::cout << *begin << " ";
		}
		std::cout << std::endl;
		binarySearch(arr, 0, arr.size() - 1, insert[i]);
		std::cout << "element: " << insert[i] << std::endl;
		for (std::vector<int>::iterator begin = arr.begin(); begin < arr.end(); ++begin)
		{
			std::cout << *begin << " ";
		}
		std::cout << std::endl;
		std::cout << std::endl;
	}
}