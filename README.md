# Pretty Printer for (deeply) nested STL containers

```cpp
#include "prettyprint.hpp" //include the library

int main() {
	// I asked ChatGPT to generate some random nested data structures

	// Simple vector of integers
	std::vector<int> vec1 = { 1, 2, 3, 4, 5 };

	// Nested vector of vectors
	std::vector<std::vector<int>> nestedVec = { {1, 2, 3}, {4, 5}, {6} };

	// Map of string to integer
	std::map<std::string, int> map1 = { {"one", 1}, {"two", 2}, {"three", 3} };

	// Nested map of string to vector of integers
	std::map<std::string, std::vector<int>> nestedMap = {
		{"group1", {1, 2, 3}},
		{"group2", {4, 5, 6}},
		{"group3", {7, 8, 9}}
	};

	// Set of integers
	std::set<int> set1 = { 10, 20, 30 };

	// Nested set of sets
	std::set<std::set<int>> nestedSet = { {1, 2}, {3, 4}, {5} };

	// Unordered map of string to set of integers
	std::unordered_map<std::string, std::set<int>> unorderedMap = {
		{"a", {1, 2, 3}},
		{"b", {4, 5}},
		{"c", {6}}
	};

	// Pair of integer and string
	std::pair<int, std::string> pair1 = { 42, "answer" };

	// Vector of pairs
	std::vector<std::pair<std::string, int>> vecOfPairs = {
		{"apple", 1}, {"banana", 2}, {"cherry", 3}
	};

	// Priority queue (example of unsupported type)
	std::priority_queue<int> pq;
	pq.push(10);
	pq.push(20);
	pq.push(30);
	// Note: Priority queues can't be directly iterated. You'll need to extract items for printing.



	std::vector<std::vector<std::map<std::string, int>>> deepNestedVec = {
	{
		{{"a", 1}, {"b", 2}},
		{{"c", 3}, {"d", 4}}
	},
	{
		{{"e", 5}, {"f", 6}},
		{{"g", 7}, {"h", 8}}
	}
	};

	// Map of string to vector of set of pairs
	std::map<std::string, std::vector<std::set<std::pair<int, std::string>>>> deepNestedMap = {
		{"group1", {{{1, "one"}, {2, "two"}}, {{3, "three"}}}},
		{"group2", {{{4, "four"}, {5, "five"}}, {{6, "six"}}}}
	};

	// Unordered map of set of map of vector
	std::unordered_map<std::string, std::set<std::map<std::string, std::vector<int>>>> crazyNestedMap = {
		{"level1", {{{"key1", {1, 2, 3}}, {"key2", {4, 5}}}}},
		{"level2", {{{"key3", {6, 7, 8}}, {"key4", {9}}}}}
	};

	// Vector of deque of list of pairs
	std::vector<std::deque<std::list<std::pair<std::string, int>>>> nestedContainers = {
		{
			{{"item1", 10}, {"item2", 20}},
			{{"item3", 30}}
		},
		{
			{{"item4", 40}, {"item5", 50}},
			{{"item6", 60}}
		}
	};

	// Nested array of map of vector of set
	std::vector<std::map<std::string, std::vector<std::set<int>>>> arrayNestedMap = {
		std::map<std::string, std::vector<std::set<int>>>{
			{"groupA", {{1, 2}, {3, 4}}},
			{"groupB", {{5, 6}, {7}}}
		},
		std::map<std::string, std::vector<std::set<int>>>{
			{"groupC", {{8, 9}, {10}}},
			{"groupD", {{11}, {12, 13}}}
		}
	};

	// Insanely nested vector
	std::vector<std::vector<std::vector<std::vector<int>>>> insaneVec = {
		{{{1, 2}, {3, 4}}, {{5, 6}, {7, 8}}},
		{{{9, 10}, {11, 12}}, {{13, 14}, {15, 16}}}
	};


	// To print them (prefix and suffix are optional)
	prettyprinter::print_black(vec1, "\nPrefix: vec1--->\n", "<---vec1");
	prettyprinter::print_red(vec1, "\nPrefix: vec1--->\n", "<---vec1");
	prettyprinter::print_green(vec1, "\nPrefix: vec1--->\n", "<---vec1");
	prettyprinter::print_yellow(vec1, "\nPrefix: vec1--->\n", "<---vec1");
	prettyprinter::print_blue(vec1, "\nPrefix: vec1--->\n", "<---vec1");
	prettyprinter::print_purple(vec1, "\nPrefix: vec1--->\n", "<---vec1");
	prettyprinter::print_cyan(vec1, "\nPrefix: vec1--->\n", "<---vec1");
	prettyprinter::print_white(vec1, "\nPrefix: vec1--->\n", "<---vec1");
	prettyprinter::print_black(nestedVec, "\nPrefix: nestedVec--->\n", "<---nestedVec");
	prettyprinter::print_red(nestedVec, "\nPrefix: nestedVec--->\n", "<---nestedVec");
	prettyprinter::print_green(nestedVec, "\nPrefix: nestedVec--->\n", "<---nestedVec");
	prettyprinter::print_yellow(nestedVec, "\nPrefix: nestedVec--->\n", "<---nestedVec");
	prettyprinter::print_blue(nestedVec, "\nPrefix: nestedVec--->\n", "<---nestedVec");
	prettyprinter::print_purple(nestedVec, "\nPrefix: nestedVec--->\n", "<---nestedVec");
	prettyprinter::print_cyan(nestedVec, "\nPrefix: nestedVec--->\n", "<---nestedVec");
	prettyprinter::print_white(nestedVec, "\nPrefix: nestedVec--->\n", "<---nestedVec");
	prettyprinter::print_black(map1, "\nPrefix: map1--->\n", "<---map1");
	prettyprinter::print_red(map1, "\nPrefix: map1--->\n", "<---map1");
	prettyprinter::print_green(map1, "\nPrefix: map1--->\n", "<---map1");
	prettyprinter::print_yellow(map1, "\nPrefix: map1--->\n", "<---map1");
	prettyprinter::print_blue(map1, "\nPrefix: map1--->\n", "<---map1");
	prettyprinter::print_purple(map1, "\nPrefix: map1--->\n", "<---map1");
	prettyprinter::print_cyan(map1, "\nPrefix: map1--->\n", "<---map1");
	prettyprinter::print_white(map1, "\nPrefix: map1--->\n", "<---map1");
	prettyprinter::print_black(nestedMap, "\nPrefix: nestedMap--->\n", "<---nestedMap");
	prettyprinter::print_red(nestedMap, "\nPrefix: nestedMap--->\n", "<---nestedMap");
	prettyprinter::print_green(nestedMap, "\nPrefix: nestedMap--->\n", "<---nestedMap");
	prettyprinter::print_yellow(nestedMap, "\nPrefix: nestedMap--->\n", "<---nestedMap");
	prettyprinter::print_blue(nestedMap, "\nPrefix: nestedMap--->\n", "<---nestedMap");
	prettyprinter::print_purple(nestedMap, "\nPrefix: nestedMap--->\n", "<---nestedMap");
	prettyprinter::print_cyan(nestedMap, "\nPrefix: nestedMap--->\n", "<---nestedMap");
	prettyprinter::print_white(nestedMap, "\nPrefix: nestedMap--->\n", "<---nestedMap");
	prettyprinter::print_black(set1, "\nPrefix: set1--->\n", "<---set1");
	prettyprinter::print_red(set1, "\nPrefix: set1--->\n", "<---set1");
	prettyprinter::print_green(set1, "\nPrefix: set1--->\n", "<---set1");
	prettyprinter::print_yellow(set1, "\nPrefix: set1--->\n", "<---set1");
	prettyprinter::print_blue(set1, "\nPrefix: set1--->\n", "<---set1");
	prettyprinter::print_purple(set1, "\nPrefix: set1--->\n", "<---set1");
	prettyprinter::print_cyan(set1, "\nPrefix: set1--->\n", "<---set1");
	prettyprinter::print_white(set1, "\nPrefix: set1--->\n", "<---set1");
	prettyprinter::print_black(nestedSet, "\nPrefix: nestedSet--->\n", "<---nestedSet");
	prettyprinter::print_red(nestedSet, "\nPrefix: nestedSet--->\n", "<---nestedSet");
	prettyprinter::print_green(nestedSet, "\nPrefix: nestedSet--->\n", "<---nestedSet");
	prettyprinter::print_yellow(nestedSet, "\nPrefix: nestedSet--->\n", "<---nestedSet");
	prettyprinter::print_blue(nestedSet, "\nPrefix: nestedSet--->\n", "<---nestedSet");
	prettyprinter::print_purple(nestedSet, "\nPrefix: nestedSet--->\n", "<---nestedSet");
	prettyprinter::print_cyan(nestedSet, "\nPrefix: nestedSet--->\n", "<---nestedSet");
	prettyprinter::print_white(nestedSet, "\nPrefix: nestedSet--->\n", "<---nestedSet");
	prettyprinter::print_black(unorderedMap, "\nPrefix: unorderedMap--->\n", "<---unorderedMap");
	prettyprinter::print_red(unorderedMap, "\nPrefix: unorderedMap--->\n", "<---unorderedMap");
	prettyprinter::print_green(unorderedMap, "\nPrefix: unorderedMap--->\n", "<---unorderedMap");
	prettyprinter::print_yellow(unorderedMap, "\nPrefix: unorderedMap--->\n", "<---unorderedMap");
	prettyprinter::print_blue(unorderedMap, "\nPrefix: unorderedMap--->\n", "<---unorderedMap");
	prettyprinter::print_purple(unorderedMap, "\nPrefix: unorderedMap--->\n", "<---unorderedMap");
	prettyprinter::print_cyan(unorderedMap, "\nPrefix: unorderedMap--->\n", "<---unorderedMap");
	prettyprinter::print_white(unorderedMap, "\nPrefix: unorderedMap--->\n", "<---unorderedMap");
	prettyprinter::print_black(pair1, "\nPrefix: pair1--->\n", "<---pair1");
	prettyprinter::print_red(pair1, "\nPrefix: pair1--->\n", "<---pair1");
	prettyprinter::print_green(pair1, "\nPrefix: pair1--->\n", "<---pair1");
	prettyprinter::print_yellow(pair1, "\nPrefix: pair1--->\n", "<---pair1");
	prettyprinter::print_blue(pair1, "\nPrefix: pair1--->\n", "<---pair1");
	prettyprinter::print_purple(pair1, "\nPrefix: pair1--->\n", "<---pair1");
	prettyprinter::print_cyan(pair1, "\nPrefix: pair1--->\n", "<---pair1");
	prettyprinter::print_white(pair1, "\nPrefix: pair1--->\n", "<---pair1");
	prettyprinter::print_black(vecOfPairs, "\nPrefix: vecOfPairs--->\n", "<---vecOfPairs");
	prettyprinter::print_red(vecOfPairs, "\nPrefix: vecOfPairs--->\n", "<---vecOfPairs");
	prettyprinter::print_green(vecOfPairs, "\nPrefix: vecOfPairs--->\n", "<---vecOfPairs");
	prettyprinter::print_yellow(vecOfPairs, "\nPrefix: vecOfPairs--->\n", "<---vecOfPairs");
	prettyprinter::print_blue(vecOfPairs, "\nPrefix: vecOfPairs--->\n", "<---vecOfPairs");
	prettyprinter::print_purple(vecOfPairs, "\nPrefix: vecOfPairs--->\n", "<---vecOfPairs");
	prettyprinter::print_cyan(vecOfPairs, "\nPrefix: vecOfPairs--->\n", "<---vecOfPairs");
	prettyprinter::print_white(vecOfPairs, "\nPrefix: vecOfPairs--->\n", "<---vecOfPairs");
	prettyprinter::print_black(deepNestedVec, "\nPrefix: deepNestedVec--->\n", "<---deepNestedVec");
	prettyprinter::print_red(deepNestedVec, "\nPrefix: deepNestedVec--->\n", "<---deepNestedVec");
	prettyprinter::print_green(deepNestedVec, "\nPrefix: deepNestedVec--->\n", "<---deepNestedVec");
	prettyprinter::print_yellow(deepNestedVec, "\nPrefix: deepNestedVec--->\n", "<---deepNestedVec");
	prettyprinter::print_blue(deepNestedVec, "\nPrefix: deepNestedVec--->\n", "<---deepNestedVec");
	prettyprinter::print_purple(deepNestedVec, "\nPrefix: deepNestedVec--->\n", "<---deepNestedVec");
	prettyprinter::print_cyan(deepNestedVec, "\nPrefix: deepNestedVec--->\n", "<---deepNestedVec");
	prettyprinter::print_white(deepNestedVec, "\nPrefix: deepNestedVec--->\n", "<---deepNestedVec");
	prettyprinter::print_black(deepNestedMap, "\nPrefix: deepNestedMap--->\n", "<---deepNestedMap");
	prettyprinter::print_red(deepNestedMap, "\nPrefix: deepNestedMap--->\n", "<---deepNestedMap");
	prettyprinter::print_green(deepNestedMap, "\nPrefix: deepNestedMap--->\n", "<---deepNestedMap");
	prettyprinter::print_yellow(deepNestedMap, "\nPrefix: deepNestedMap--->\n", "<---deepNestedMap");
	prettyprinter::print_blue(deepNestedMap, "\nPrefix: deepNestedMap--->\n", "<---deepNestedMap");
	prettyprinter::print_purple(deepNestedMap, "\nPrefix: deepNestedMap--->\n", "<---deepNestedMap");
	prettyprinter::print_cyan(deepNestedMap, "\nPrefix: deepNestedMap--->\n", "<---deepNestedMap");
	prettyprinter::print_white(deepNestedMap, "\nPrefix: deepNestedMap--->\n", "<---deepNestedMap");
	prettyprinter::print_black(crazyNestedMap, "\nPrefix: crazyNestedMap--->\n", "<---crazyNestedMap");
	prettyprinter::print_red(crazyNestedMap, "\nPrefix: crazyNestedMap--->\n", "<---crazyNestedMap");
	prettyprinter::print_green(crazyNestedMap, "\nPrefix: crazyNestedMap--->\n", "<---crazyNestedMap");
	prettyprinter::print_yellow(crazyNestedMap, "\nPrefix: crazyNestedMap--->\n", "<---crazyNestedMap");
	prettyprinter::print_blue(crazyNestedMap, "\nPrefix: crazyNestedMap--->\n", "<---crazyNestedMap");
	prettyprinter::print_purple(crazyNestedMap, "\nPrefix: crazyNestedMap--->\n", "<---crazyNestedMap");
	prettyprinter::print_cyan(crazyNestedMap, "\nPrefix: crazyNestedMap--->\n", "<---crazyNestedMap");
	prettyprinter::print_white(crazyNestedMap, "\nPrefix: crazyNestedMap--->\n", "<---crazyNestedMap");
	prettyprinter::print_black(nestedContainers, "\nPrefix: nestedContainers--->\n", "<---nestedContainers");
	prettyprinter::print_red(nestedContainers, "\nPrefix: nestedContainers--->\n", "<---nestedContainers");
	prettyprinter::print_green(nestedContainers, "\nPrefix: nestedContainers--->\n", "<---nestedContainers");
	prettyprinter::print_yellow(nestedContainers, "\nPrefix: nestedContainers--->\n", "<---nestedContainers");
	prettyprinter::print_blue(nestedContainers, "\nPrefix: nestedContainers--->\n", "<---nestedContainers");
	prettyprinter::print_purple(nestedContainers, "\nPrefix: nestedContainers--->\n", "<---nestedContainers");
	prettyprinter::print_cyan(nestedContainers, "\nPrefix: nestedContainers--->\n", "<---nestedContainers");
	prettyprinter::print_white(nestedContainers, "\nPrefix: nestedContainers--->\n", "<---nestedContainers");
	prettyprinter::print_black(arrayNestedMap, "\nPrefix: arrayNestedMap--->\n", "<---arrayNestedMap");
	prettyprinter::print_red(arrayNestedMap, "\nPrefix: arrayNestedMap--->\n", "<---arrayNestedMap");
	prettyprinter::print_green(arrayNestedMap, "\nPrefix: arrayNestedMap--->\n", "<---arrayNestedMap");
	prettyprinter::print_yellow(arrayNestedMap, "\nPrefix: arrayNestedMap--->\n", "<---arrayNestedMap");
	prettyprinter::print_blue(arrayNestedMap, "\nPrefix: arrayNestedMap--->\n", "<---arrayNestedMap");
	prettyprinter::print_purple(arrayNestedMap, "\nPrefix: arrayNestedMap--->\n", "<---arrayNestedMap");
	prettyprinter::print_cyan(arrayNestedMap, "\nPrefix: arrayNestedMap--->\n", "<---arrayNestedMap");
	prettyprinter::print_white(arrayNestedMap, "\nPrefix: arrayNestedMap--->\n", "<---arrayNestedMap");
	prettyprinter::print_black(insaneVec, "\nPrefix: insaneVec--->\n", "<---insaneVec");
	prettyprinter::print_red(insaneVec, "\nPrefix: insaneVec--->\n", "<---insaneVec");
	prettyprinter::print_green(insaneVec, "\nPrefix: insaneVec--->\n", "<---insaneVec");
	prettyprinter::print_yellow(insaneVec, "\nPrefix: insaneVec--->\n", "<---insaneVec");
	prettyprinter::print_blue(insaneVec, "\nPrefix: insaneVec--->\n", "<---insaneVec");
	prettyprinter::print_purple(insaneVec, "\nPrefix: insaneVec--->\n", "<---insaneVec");
	prettyprinter::print_cyan(insaneVec, "\nPrefix: insaneVec--->\n", "<---insaneVec");
	prettyprinter::print_white(insaneVec, "\nPrefix: insaneVec--->\n", "<---insaneVec");
	return 0;
}
```


![](https://github.com/hansalemaos/stl_pretty_print/blob/main/screenshots/2024-11-20%2009_56_05-Window.png?raw=true)

![](https://github.com/hansalemaos/stl_pretty_print/blob/main/screenshots/2024-11-20%2009_56_18-Window.png?raw=true)

![](https://github.com/hansalemaos/stl_pretty_print/blob/main/screenshots/2024-11-20%2009_56_35-Window.png?raw=true)

![](https://github.com/hansalemaos/stl_pretty_print/blob/main/screenshots/2024-11-20%2009_56_54-Window.png?raw=true)

![](https://github.com/hansalemaos/stl_pretty_print/blob/main/screenshots/2024-11-20%2009_57_07-Window.png?raw=true)

![](https://github.com/hansalemaos/stl_pretty_print/blob/main/screenshots/2024-11-20%2009_57_28-Window.png?raw=true)

![](https://github.com/hansalemaos/stl_pretty_print/blob/main/screenshots/2024-11-20%2009_57_44-Window.png?raw=true)

![](https://github.com/hansalemaos/stl_pretty_print/blob/main/screenshots/2024-11-20%2009_58_09-Window.png?raw=true)

![](https://github.com/hansalemaos/stl_pretty_print/blob/main/screenshots/2024-11-20%2009_55_31-Window.png?raw=true)
