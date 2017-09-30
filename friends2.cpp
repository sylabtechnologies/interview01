#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <map>
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

typedef map<string, StrVector> FriendMap;
typedef FriendMap::iterator MapIter;

StrVector friends_id(string&, MyVector&);
void print_vector(StrVector&);

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

	FriendMap mymap;

	for (MyIter iter = employees_input.begin(); iter != employees_input.end(); ++iter) {

		StrVector result = friends_id((*iter).at(0), friendships_input);
		mymap.insert(std::make_pair((*iter).at(0), result));

	}

	for (MapIter iter = mymap.begin(); iter != mymap.end(); ++iter) {

		cout << (*iter).first.c_str() << ": ";
		print_vector((*iter).second);

		if (std::next(iter) != mymap.end())
			cout << "," << endl;
		else
			break;
	}

	cout << endl;

	return 0;

}

void print_vector(StrVector& myinput)
{

	cout << "[";

	for (StrIter iter = myinput.begin(); iter != myinput.end(); ++iter)
	{
		cout << iter->c_str();
		if (std::next(iter) !=  myinput.end()) cout << ", ";
	}

	cout << "]";

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





