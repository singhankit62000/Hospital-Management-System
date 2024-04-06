#include "hospital.string.hpp"
#include <stdio.h>
#include <conio.h>
#include <new>
using namespace std;

HospitalString :: HospitalString () 
{

	vStr = new (nothrow) char [INITIAL_STRING_SIZE];
	vSize = 0;
	vCapacity = INITIAL_STRING_SIZE;

}

HospitalString :: HospitalString (char const * pStr) 
{

		size_t len	= 0;
		size_t i	= 0;

	vCapacity = INITIAL_STRING_SIZE;
	vSize	  = 0;

	if (pStr == nullptr) {

		vStr = new (nothrow) char [vCapacity];
		return;

	}

	while (pStr[len] != END_OF_STRING) {
	
		len++;
			
	}

	while (vCapacity <= len) {

		vCapacity *= 2;

	}

	vStr = new (nothrow) char [vCapacity];

	if (vStr == nullptr) {

		printf ("Memory allocation failed\n");
		return;

	}

	for (i = 0; i < len; i++) {

		vStr[i] = pStr[i];

	}

	vStr[len] = END_OF_STRING;
	vSize = len;

}

HospitalString :: HospitalString (HospitalString &pObj) 
{

	vCapacity = pObj.vCapacity;
	vSize = pObj.vSize;

	vStr = new (nothrow) char [vCapacity];

	if (vStr == nullptr) {

		printf ("Memory allocation failed\n");
		vSize = 0;
		vCapacity = 0;
		return;

	}

	for (size_t i = 0; i <= vSize; i++) {

		vStr[i] = pObj.vStr[i];

	}

}

HospitalString :: ~HospitalString () 
{

	if (vStr != nullptr) {

		delete [] vStr;

	}

	vStr = nullptr;

}

void HospitalString :: InputString () 
{

		char ch = END_OF_STRING;
	
	while (true) {

		ch = (char) _getch ();

		if (ch == BACKSPACE) {

			printf ("\b \b");
			PopBack ();

		} else if (ch == ENTER_KEY || ch == ESCAPE) {

			PushBack (END_OF_STRING);
			return;

		} else {

			printf ("%c", ch);
			PushBack (ch);

		}

	}

}

void HospitalString :: Clear () 
{

	while (vSize > 0) {

		PopBack ();

	}

}

bool HospitalString :: Empty () 
{

	if (vSize == 0) {

		return true;

	} else if (vStr[0] == END_OF_STRING) {

		return true;

	}

	return false;
}
 
bool HospitalString :: operator == (HospitalString & pObj) 
{	
		size_t itr = 0;

	if (vSize != pObj.vSize) {

		return false;

	}

	for (itr = 0; itr < vSize; itr++) {

		if (vStr[itr] != pObj.vStr[itr]) {

			return false;

		}

	}

	return true;

}

HospitalString & HospitalString :: operator = (HospitalString & pObj) 
{

		char * temp = nullptr;

	if (this == &pObj) {

		return *this;

	}

	temp = new (nothrow) char [pObj.vCapacity];

	if (temp == nullptr) {
		
		printf ("Memory allocation failed\n");
		return *this;

	}

	if (vStr != nullptr) {

		delete [] vStr;
	}

	vStr = nullptr;
	vStr = temp;
	vSize = pObj.vSize;
	vCapacity = pObj.vCapacity;

	for (size_t i = 0; i <= vSize; i++) {

		vStr[i] = pObj.vStr[i];

	}

	return *this;

}

HospitalString& HospitalString :: operator = (const char * pStr)
{

		size_t len = 0;

	if (vStr != nullptr) {
			
		delete [] vStr;
		vStr = nullptr;

	}

	while (pStr[len++] != END_OF_STRING);

	vStr = new (nothrow) char [len];

	if (vStr == nullptr) {

		printf ("Memory allocation failed.\n");
		vSize = 0;
		vCapacity = 0;
		return *this;

	}

	for (size_t i = 0; i < len; i++) {

		vStr[i] = pStr[i];

	}

	vStr [len] = END_OF_STRING;
	vSize = len - 1;
	vCapacity = len;

	return *this;

}

void HospitalString :: PushBack (char pCh) 
{

	char * str_temp	= nullptr;

	if (vStr == nullptr) {

		vCapacity = INITIAL_STRING_SIZE;
		vStr = new (nothrow) char [vCapacity];

		if (vStr == nullptr) {

			return;

		}

	} else if (vSize + 1 == vCapacity) {

		vCapacity *= 2;

		str_temp = new (nothrow) char [vCapacity];

		if (str_temp == nullptr) {

			return;

		}

		for (size_t i = 0; i < vSize; i++) {

			str_temp[i] = vStr[i];

		}

		str_temp = vStr;

	}

	vStr[vSize] = pCh;
	vStr[++vSize] = END_OF_STRING;

}

void HospitalString :: PopBack () 
{

	if (vSize > 0) {

		vSize--;
		vStr [vSize] = END_OF_STRING;

	}

}

char HospitalString :: operator [] (int pInd) 
{

	if (pInd < 0 || pInd >= vSize) {

		printf ("Index out of bounds\n");
		return END_OF_STRING;

	}
	
	return vStr [pInd];

}

char const * HospitalString :: GetString () 
{

	return vStr;

}

bool HospitalString :: operator < (HospitalString &pObj) 
{

		size_t	it			= 0;
		size_t	len_this	= this -> vSize;
		size_t	len_obj		= pObj.vSize;
		char *	str_this	= this -> vStr;
		char *	str_obj		= pObj.vStr;

	if (len_this < len_obj) {

		return true;

	} else if ((len_this > len_obj) || (*this == pObj)) {

		return false;

	}

	while (it < len_this && str_this[it] <= str_obj[it]) {

		it++;

	}

	if (it == len_this) {

		return true;

	}

	return false;

}
 
size_t HospitalString :: Length () 
{

	return vSize;

}

size_t HospitalString :: Capacity () 
{

	return vCapacity;

}