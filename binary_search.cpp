#include "binary_search.h"

namespace binary_search {

	std::size_t find(const std::vector<int>& data, int number) { 

		const int* ptr = data.data(); // ptr points to the start of data
		size_t len = data.size(); 

		while (len > 0) { 
  
			size_t mid = len / 2;
			const int value_at_mid = ptr[mid]; 
	
			// return the index of mid
			if (value_at_mid == number) {
				return ptr+mid - data.data(); // return index of mid relative to the whole data vector
			}	

			// only look at the first half of array 
			if (value_at_mid > number) {
				len = mid;
			}
		
			// only look at second half of array
			if (value_at_mid < number) {
				ptr += mid + 1; 
				len -= (mid + 1); 
			}	
		}
	
		throw std::domain_error("number is not in data.");
	}

}  // namespace binary_search
