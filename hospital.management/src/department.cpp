#include "department.hpp"
#include "hospital.string.hpp"

// This function compares 2 strings and returns whether they are equal or not
// It first converts the char * strings to HospitalString objects and 
// using the overloaded == operator, we check the condition

bool IsSame (char const * pStr1, char const * pStr2) 
{

		HospitalString s1 = pStr1;
		HospitalString s2 = pStr2;

	return (s1 == s2);

}

// Deleting all the nodes of both the linked lists
Department :: ~Department () 
{

	uDoctors.DeleteAll ();
	uPatients.DeleteAll ();

}

// Searching the doctors list by the help of Id,
// The return value of this function is the pointer to the
// Doctor whose Id matches with the pId otherwise nullptr
Doctor * Department :: SearchDoctorsById (int pId) 
{

		// Storing the tail of the doctor pointers' list
		// to traverse for searching the id
		tNode <Doctor *> * temp = uDoctors.GetTail ();

	while (temp != nullptr) {

		if (temp -> uData -> GetId () == pId) {

			return temp -> uData;

		}

		temp = temp -> uPrev;

	}

	// printf ("Id not found\n");
	return nullptr;

}

// Searching the patients list by the help of Id,
// The return value of this function is the pointer to the
// Patient whose Id matches with the pId otherwise nullptr
Patient * Department :: SearchPatientsById (int pId) 
{

		tNode <Patient *> * temp = uPatients.GetTail ();

	while (temp != nullptr) {

		if (temp -> uData -> GetId () == pId) {

			return temp -> uData;

		}

		temp = temp -> uPrev;

	}

	// printf ("Id not found\n");
	return nullptr;

}

// Searching the doctors list by the help of Name
// Upon finding the pointer whose vName matches the 
// pName, it automatically calls the display of that object
void Department :: SearchDoctorsByName (char const * pName) 
{

		tNode <Doctor *> * temp = uDoctors.GetTail ();

	while (temp != nullptr) {

		if (IsSame (temp -> uData -> GetName(), pName)) {

			temp -> uData -> Display ();

		}

		temp = temp -> uPrev;

	}

	// printf ("Id not found\n");

}

// Searching the patients list by the help of Name
// Upon finding the pointer whose vName matches the 
// pName, it automatically calls the display of that object
void Department :: SearchPatientsByName (char const * pName) 
{

		tNode <Patient *>				*	temp = uPatients.GetTail ();

	while (temp != nullptr) {

		if (IsSame (temp -> uData -> GetName (), pName)) {

			temp -> uData -> Display ();

		}

		temp = temp -> uPrev;

	}

	// printf ("Id not found\n");

}
