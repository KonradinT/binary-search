#include "binary_search.h"

namespace binary_search {

	std::size_t find(const std::vector<int>& data, int number) { 

		const int* ptr = data.data(); // ptr points to the start of data and only has read-only access to data
		size_t len = data.size(); 

		while (len > 0) { 
  
			size_t mid = len / 2;
			const int value_at_mid = *(ptr + mid); // value_at_mid = dereference of the address of mid
							       // value_at_mid is read-only

			// value at mid is number
			// return the index of mid
			if (value_at_mid == number) {
				return ptr+mid - data.data(); // return address of mid - address of start of data
							      // meaning: return index of mid relative to the whole data vector
			}	

			// value of mid is greater than number
			// only look at the first half of array 
			if (value_at_mid > number) {
				len -= mid; // reduce len to only look at half of data
				if (mid == 0) {
					len--; // prevents len from staying at len == 1 to prevent infinite loop
				}
			}

			// value of mid is smaller than number
			// only look at second half of array
			if (value_at_mid < number) {
				ptr += mid + 1; // move ptr to point at element after mid
				len -= (mid + 1); // reduce len to only look at half of the data - 1 to exclude mid
			}

			// only one element is left and its number
			// return the index of ptr
			if (len == 1 && *ptr == number) {
				return ptr - data.data(); // return address of ptr - address of start of data 
							  // meaning: return index of element to which ptr points
			}
		}
		// throw domain_error when number is not in data
		throw std::domain_error("number is not in data.");
	}

}  // namespace binary_search
