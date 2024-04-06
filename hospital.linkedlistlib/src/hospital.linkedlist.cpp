//#include "hospital.linkedlist.hpp"
//
//template <typename T>
//HospitalLinkedList <T> :: HospitalLinkedList () 
//{
//
//	vHead = nullptr;
//	vTail = nullptr;
//
//}
//
//template <typename T>
//HospitalLinkedList <T> :: ~HospitalLinkedList () 
//{
//
//		tNode <T> * temp = nullptr;
//
//	while (vHead != nullptr) {
//
//		temp = vHead;
//		vHead = vHead -> uNext;
//		delete temp;
//		temp = nullptr;
//
//	}
//
//}
//
//template <typename T> 
//void HospitalLinkedList <T> :: InsertEnd (T pParam) 
//{
//		
//		tNode <T> * temp = new tNode <T>;
//		tNode <T> * itr = nullptr;
//
//	temp -> uData = pParam;
//	temp -> uNext = nullptr;
//	temp -> uPrev = nullptr;
//
//	if (vHead == nullptr) {
//
//		vHead = temp;
//		vTail = temp;
//
//	} else {
//
//		itr = vHead;
//
//		while (itr->uNext != nullptr) {
//
//			itr = itr -> uNext;
//
//		}
//
//		itr -> uNext = temp;
//		temp -> uPrev = itr;
//		vTail = temp;
//	}
//
//}
//
//template <typename T> 
//void HospitalLinkedList <T> :: Print () 
//{
//
//		tNode <T> * temp = vHead;
//
//	while (temp != nullptr) {
//
//		temp -> uData.Display ();
//		temp = temp -> uNext;
//
//	}
//
//}
//
//template <typename T> 
//void HospitalLinkedList <T> :: DeleteAt (unsigned int pInd) 
//{
//		
//		tNode <T> *		itr		= vHead;
//		unsigned int	count	= 0;
//
//	if (pInd == 0) {
//
//		if (vHead == nullptr) {
//
//			return;
//
//		}
//		
//		vHead = vHead -> uNext;
//		vHead -> uPrev = nullptr;
//		delete itr;
//		itr = nullptr;
//		return;
//	}
//
//	
//	while (itr != nullptr && count < pInd) {
//
//		itr = itr -> uNext;
//		count++;
//
//	}
//
//	if (itr == nullptr) {
//
//		printf ("Index out of bounds\n");
//
//	}
//
//	if (itr->uNext != nullptr) {
//
//		itr -> uNext -> uPrev = itr -> uPrev;
//
//	}
//
//	itr -> uPrev -> uNext = itr -> uNext;
//	free (itr);
//
//}
//
//template <typename T>
//tNode <T> * HospitalLinkedList <T> :: GetTail () 
//{
//
//	return vTail;
//
//}
//
//template <typename T>
//unsigned int HospitalLinkedList <T> :: NodeCount () 
//{
//
//		unsigned int count		= 0;
//		tNode <T> * temp		= vHead;
//
//	while (temp != nullptr) {
//
//		count++;
//		temp = temp -> uNext;
//
//	}
//
//	return count;
//
//}
