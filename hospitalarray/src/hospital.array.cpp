//#include "hospital.array.hpp"
//
//template <typename T> 
//HospitalArray <T> :: HospitalArray () 
//{
//
//	vSize = 0;
//	vCapacity = INITIAL_ARRAY_CAPACITY;
//	vArray = new (nothrow) T [vCapacity];
//
//}
//
//template <typename T>
//HospitalArray <T> :: HospitalArray (size_t pSize) 
//{
//
//	vSize = pSize;
//	vCapacity = pSize;
//	vArray = new (nothrow) T [pSize] (); 
//
//}
//
//template <typename T> 
//HospitalArray <T> :: ~HospitalArray () 
//{
//
//	if (vArray != nullptr) {
//
//		delete [] vArray;
//
//	}
//
//	vArray = nullptr;
//
//}
//
//template <typename T> 
//void HospitalArray <T> :: PushBack (T pParam) 
//{
//
//	if (vSize == vCapacity) {
//
//		IncreaseCapacity (vCapacity + 1);
//
//	}
//
//	vArray [vSize++] = pParam; 
//
//}
//
//
//template <typename T> 
//void HospitalArray <T> :: IncreaseCapacity (size_t pSize) 
//{
//
//		size_t		new_capacity = vCapacity;
//		T		*	temp;
//
//	while (new_capacity <= pSize) {
//
//		new_capacity *= 2;
//
//	}
//	
//	temp = new (nothrow) T [new_capacity] ();
//	
//	if (temp == nullptr) {
//
//		printf ("Memory allocation failed.\n");
//		return;
//
//	}
//
//	for (size_t i = 0; i < vSize; i++) {
//
//		temp [i] = vArray [i];
//
//	}
//
//	delete [] vArray;
//	vArray = temp;
//	vCapacity = new_capacity;
//
//}
//
//template <typename T> 
//void HospitalArray <T> :: PopBack () 
//{
//
//	if (vSize > 0) {
//
//		vSize--;
//
//	}
//
//}
//
//template <typename T>
//size_t HospitalArray <T> :: Size () 
//{
//
//	return vSize;
//
//}
//
//template <typename T>
//size_t HospitalArray <T> :: Capacity () 
//{
//
//	return vCapacity;
//
//}
//
//template <typename T>
//T  HospitalArray <T> :: operator [] (size_t pInd) 
//{
//
//	if (pInd >= 0 && pInd < vSize) {
//
//		return vArray [pInd];
//
//	}
//
//	printf ("Index out of bounds!\n");
//
//}
//
//template <typename T> 
//void HospitalArray <T> :: SendToEnd (size_t pInd) 
//{
//		T temp;
//
//	if (pInd < 0 || pInd >= vSize) {
//
//		printf ("Index out of bounds\n");
//		return;
//
//	}
//
//	temp = vArray [pInd];
//	vArray [pInd] = vArray [vSize - 1];
//	vArray [vSize - 1] = temp;
//
//
//}