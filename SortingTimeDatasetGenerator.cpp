
#include "stdafx.h"

#include "SortingTimeDatasetGenerator.h"

using namespace std;
using namespace chrono;


int main()
{
	unsigned long int j, size, lowerLimit = 0, upperLimit, sort_percentage;

	time_t t;
	/* Intializes random number generator */
	srand((unsigned)time(&t));

	//std::ofstream output_file("sorted.txt");
	//for (const auto &e : temp) output_file << e << "\n";

	for (size = 10; size < RAND_MAX; size *= SIZE_ITR_FACTOR)
	{
		for (upperLimit = 30; upperLimit < RAND_MAX; upperLimit *= UPPERL_ITR_FACTOR)
		{
			for (sort_percentage = 0; sort_percentage <= 100; sort_percentage += 10)
			{
				sortingParameters params;

				unsigned long int upperLimitTemp = upperLimit;

				params.size = size / SIZE_ITR_FACTOR + rand() % (size - size / SIZE_ITR_FACTOR);
				upperLimit = upperLimit / UPPERL_ITR_FACTOR + rand() % (upperLimit - upperLimit / UPPERL_ITR_FACTOR);

				params.range = upperLimit - lowerLimit;
				params.sortPercentage = sort_percentage;
				params.dataType = U_LONG_INT;
				params.dataStructType = VECTOR;

				params.display();
				cout << params.toString() << endl;

				vector<unsigned long int> inputVector;
				for (j = 0; j <= params.size - 1; j++) {
					unsigned long int temp = lowerLimit + rand() % (upperLimit - lowerLimit + 1);
					inputVector.push_back(temp);
				}

				if (sort_percentage == 100)
					sort(inputVector.begin(), inputVector.end() - 1);
				else if (sort_percentage)
					sort(inputVector.begin(), inputVector.begin() + params.size * sort_percentage / 100);

				SortCaller objSortCaller = SortCaller(inputVector, params);
				objSortCaller.CallSortOnVector();

				upperLimit = upperLimitTemp;
			}
		}
	}


	getchar();


	return 0;
}
