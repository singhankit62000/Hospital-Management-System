#ifndef HOSPITAL_LINKEDLIST_HPP
#define HOSPITAL_LINKEDLIST_HPP

#include <stdio.h>

class Doctor;

template <typename T>
struct tNode {

	T				uData;
	tNode <T>	*	uPrev;
	tNode <T>	*	uNext;

};

template <typename T>
class HospitalLinkedList {

	public:
						HospitalLinkedList		();
						~HospitalLinkedList		();
		void			InsertEnd				(T pParam);
		void			DeleteAt				(unsigned int pInd);
		void			DeleteAll				();
		void			Print					();
		tNode <T> *		GetTail					();
		unsigned int    NodeCount				();
		int				FindId					(T pParam);

		// TODO: Function to sort a linked list alphabetically
		//void			SortAlphabetically		();
		// 
		// TODO: Function to sort a linked list date-wise -> use the date comparator function
		//void			SortDatewise			();

	
	private:
		tNode <T>	*	vHead;
		tNode <T>	*	vTail;

};

#include "hospital.linkedlist.hxx"

#endif // !HOSPITAL_LINKEDLIST_HPP