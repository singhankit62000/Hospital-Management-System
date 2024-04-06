#ifndef HOSPITAL_LINKEDLIST_HXX
#define HOSPITAL_LINKEDLIST_HXX

#include "hospital.linkedlist.hpp"
#include "doctor.hpp"

template <typename T>
HospitalLinkedList <T> :: HospitalLinkedList () 
{

	vHead = nullptr;
	vTail = nullptr;

}

template <typename T>
HospitalLinkedList <T> :: ~HospitalLinkedList () 
{

	DeleteAll ();

}

template <typename T>
void HospitalLinkedList <T> :: DeleteAll () 
{

		tNode <T> * temp = nullptr;

	while (vHead != nullptr) {

		temp = vHead;
		vHead = vHead -> uNext;
		delete temp;
		temp = nullptr;

	}

}

template <typename T> 
void HospitalLinkedList <T> :: InsertEnd (T pParam) 
{
		
		tNode <T> * temp = new tNode <T>;
		tNode <T> * itr = nullptr;

	temp -> uData = pParam;
	temp -> uNext = nullptr;
	temp -> uPrev = nullptr;

	if (vHead == nullptr) {

		vHead = temp;
		vTail = temp;

	} else {

		itr = vHead;

		while (itr -> uNext != nullptr) {

			itr = itr -> uNext;

		}

		itr -> uNext = temp;
		temp -> uPrev = itr;
		vTail = temp;

	}

}

template <typename T> 
void HospitalLinkedList <T> :: Print () 
{

		tNode <T> * temp = vHead;

	while (temp != nullptr) {

		temp -> uData -> Display ();
		printf ("\n------------------\n");
		temp = temp -> uNext;

	}

}

// Traverses the whole list and returns the id (0 based)
// where the pParam matches the uData.

template <typename T>
int HospitalLinkedList <T> :: FindId (T pParam) 
{
	
		tNode <T> * temp  = vHead;
		int			count = 0;

	while (temp != nullptr) {

		if (temp -> uData == pParam) {

			return count;

		}

		temp = temp -> uNext;
		count++;

	}

	return -1;

}

// Traverse the list and deletes the node at the pInd index 
// if present, otherwise safely returns

template <typename T> 
void HospitalLinkedList <T> :: DeleteAt (unsigned int pInd) 
{
		
		tNode <T> *		itr		= vHead;
		unsigned int	count	= 0;

	if (vHead == nullptr) {

		return;

	}

	if (vHead == vTail and pInd == 0) {

		vHead = nullptr;
		vTail = nullptr;

		delete itr;
		itr = nullptr;

		return;

	}

	if (pInd == 0) {
		
		itr = vHead;

		if (vHead -> uNext != nullptr) {

			vHead -> uNext -> uPrev = nullptr;

		}

		vHead = vHead -> uNext;

		delete itr;
		itr = nullptr;

		return;
	}

	
	while (itr != nullptr && count <= pInd) {

		itr = itr -> uNext;
		count++;

	}

	if (itr == nullptr) {

		printf ("Index out of bounds\n");

	}

	if (itr -> uNext != nullptr) {

		itr -> uNext -> uPrev = itr -> uPrev;

	} else if (itr -> uNext == nullptr) {

		vTail = itr -> uPrev;

	}

	itr -> uPrev -> uNext = itr -> uNext;

	delete itr;
	itr = nullptr;

}

template <typename T>
tNode <T> * HospitalLinkedList <T> :: GetTail () 
{

	return vTail;

}

template <typename T>
unsigned int HospitalLinkedList <T> :: NodeCount () 
{

		unsigned int count		= 0;
		tNode <T> * temp		= vHead;

	while (temp != nullptr) {

		count++;
		temp = temp -> uNext;

	}

	return count;

}

#endif // !HOSPITAL_LINKEDLIST_HXX