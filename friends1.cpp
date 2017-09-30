#include "stdafx.h"
#include <iostream>
#include <vector>
#include <iterator>
using namespace std;

/*
Suppose you are creating an internal networking site for your company. You have two data sets to work with. The first data set is the employees at your company, and the second is all the pairs of employees who are virtually friends so far. It does not matter which employee's ID is in which column, the friendships are bidirectional.

You want to know who�s friends with whom. You need to implement a function that, given the employees and friendships as parameters, returns this data in the form of an adjacency list representation. This should associate each employee ID to his/her friends on the site.

Sample Output
1: [2, 3, 6],
2: [1, 4],
3: [1],
4: [2],
6: [1],
9: []

*/

typedef vector<string> StrVector;
typedef StrVector::iterator StrIter;

typedef vector<StrVector> MyVector;
typedef MyVector::iterator MyIter;

StrVector friends_id(string&, MyVector&);

int main() {

	MyVector employees_input = {
		{ "1", "Richard", "Engineering" },
		{ "2", "Erlich", "HR" },
		{ "3", "Monica", "Business" },
		{ "4", "Dinesh", "Engineering" },
		{ "6", "Carla", "Engineering" },
		{ "9", "Laurie", "Directors" }
	};

	MyVector friendships_input = {
		{ "1", "2" },
		{ "1", "3" },
		{ "1", "6" },
		{ "2", "4" }
	};

	for (MyIter iter = employees_input.begin(); iter != employees_input.end(); ++iter) {

		cout << (*iter).at(0).c_str() << ": [";

		StrVector result = friends_id((*iter).at(0), friendships_input);

		for (StrIter iter1 = result.begin(); iter1 != result.end(); ++iter1)
		{
			cout << iter1->c_str();
			if (std::next(iter1) != result.end()) cout << ", ";
		}

		cout << " ]";

		if (std::next(iter) != employees_input.end()) cout << "," << endl;
	}

	cout << endl;

	return 0;

}

StrVector friends_id(string& my_id, MyVector& friends)
{
	StrVector result;

	for (MyIter iter = friends.begin(); iter != friends.end(); ++iter)
	{
		if (my_id == (*iter).at(0))
			result.push_back((*iter).at(1));
		else if (my_id == (*iter).at(1))
			result.push_back((*iter).at(0));
	}

	return result;

}





