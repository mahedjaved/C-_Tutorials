// ------------------------------------------------------------------------------- //
#include <iostream>
#include <list>
#include <opencv2/imgproc.hpp>				// this was imported to add circles BTW
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
// ------------------------------------------------------------------------------- //



// --------------------------------------------------------------------------------------------------- //

// **ADD ANY HELPER FUNCS HERE **
void EmptyGuy2()
{
	// ...
}

class Hash 
{
	int BUCKET;					// sets the number of buckets

	// setup a pointer to an array that holds the buckets
	std::list<int> *table;

public:

	Hash(int V);			// this is just the constructor

	// insert a key into a HASH:: Insert: Move to the bucket corresponds to the above calculated hash index and insert the new node at the end of the list.
	void insertItem(int x);

	// delete from a table:: To delete a node from hash table, , , search the list in the current bucket to find and remove the node with the given key (if found).  
	void deleteItem(int key);

	// hash function to map values to key, this is a typical hash function which basically modulo divides the key into the number of buckets
	int hashfunction(int x) 
	{
		// the 'x' represents the key
		return (x % BUCKET);
	}

	// show all the hashes
	void displayHash();

};


// make an instantiation of this class ! the int "b" defines how many or what is the size of the bucket
Hash::Hash(int b) 
{
	// "this" command is used equivalent to "super" in Python
	this->BUCKET = b;
	table = new std::list<int>[BUCKET];
}

// modify the parent method insertItem
void Hash::insertItem(int key) 
{
	// make a hash value (i.e. index) based on an inserted key
	int index = hashfunction(key);

	// then move this at the back of the list
	table[index].push_back(key);
}

// modify the delete item parent method
void Hash::deleteItem(int key) 
{
	//step1) calculate the hash index for the key
	int hashIndex = hashfunction(key);

	//step2) move to the bucket corresponds to the calculated hash index, hmm I dont understand the use of i != here BTW; DBT? Does it mean keep iterating but not reach the end ?? hmm ??
	std::list<int> ::iterator i;			// make an iterator object that will iterate to the list

	std::cout << "Hash begin is " << table[hashIndex].begin() << "Hash end is " << table[hashIndex].end() << std::endl;

	for (i = table[hashIndex].begin(); i != table[hashIndex].end(); i++)
	{
		//step3) if you find the appropriate key we are looking for then break the iteration 
		if (*i == key)
		{
			break;
		}
	}

	// if the key is not in the table then delete the entry
	if (i != table[hashIndex].end()) 
	{
		table[hashIndex].erase(i);
	}
}


// finally to update the display hash table
void Hash::displayHash() 
{
	for (int i = 0 ; i < BUCKET; i++) 
	{
		// print all the elements of the bucket
		std::cout << i;

		// loop through the table for that particular entry 'i' and print out its records
		for (auto x : table[i]) 
		{
			std::cout << " --> " << x;
		}
		std::cout << std::endl;
	}
}

// --------------------------------------------------------------------------------------------------- //





// --------------------------------------------------------------------------------------------------- //

//int hashMainFunction()
int main()
{
	
	/*Particular in this code we explore the idea of chaining or what I call "LINKING" addresses, the main idea is to make each cell of the hash point to a linked list of records that have the SAME HASH VALUE*/

	// first setup an array that contains the keys to be mapped
	int a[] = { 15, 11, 27, 8, 12 };

	// get the size of the hash table
	int n = sizeof(a) / sizeof(a[0]);

	// insert the keys into the hash table
	Hash h(7);

	// insert the 'a' into 'h'
	for (int i = 0 ; i < n ; i++)
	{
		h.insertItem(a[i]);
	}

	// display the hash before deletion
	std::cout << "This is the table BEFORE deletion" << std::endl;
	h.displayHash();

	// now delete item 12
	h.deleteItem(12);

	std::cout << "This is the table AFTER deletion" << std::endl;
	h.displayHash();

	system("PAUSE");

	return 0;
}

// ----
