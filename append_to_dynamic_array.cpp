#include "append_to_dynamic_array.h"


int* append_to_dynamic_array(
		int* arr,
		int &logical_size,
		int &actual_size,
		int added_value
		)
{
	if (logical_size > actual_size)
	{
		delete[] arr;
		arr = nullptr;
		throw "Error! Logical size do not over actual size!";
	}

	if (logical_size < actual_size)
	{
		arr[logical_size] = added_value;
		++logical_size;
		return arr;
	}

	actual_size *= 2;
	int* new_arr = new int[actual_size]();

	for (int i = 0; i < logical_size; ++i)
	{
		new_arr[i] = arr[i];
	}

	delete[] arr;
	arr = nullptr;

	new_arr[logical_size] = added_value;
	++logical_size;

	return new_arr;
}
