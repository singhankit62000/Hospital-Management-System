#include "hospital.hpp"
#include "hospital.string.hpp"
#include <new>
using namespace std;

// Disclaimer: I may have not handled invalid inputs in some places

// These static data members are considered for generating
// Ids for patients, doctors, nurses, etc

int Hospital::sGeneralDocCount;
int Hospital::sOrthoDocCount;
int Hospital::sCardioDocCount;
int Hospital::sNeuroDocCount;
int Hospital::sGeneralPatCount;
int Hospital::sOrthoPatCount;
int Hospital::sCardioPatCount;
int Hospital::sNeuroPatCount;
int Hospital::sNurseCount;

// This function compares 2 strings and returns whether they are equal or not
// It first converts the char * strings to HospitalString objects and 
// using the overloaded == operator, we check the condition
bool IsStrSame (char const * pStr1, char const * pStr2) 
{

		HospitalString s1 = pStr1;
		HospitalString s2 = pStr2;

	return (s1 == s2);

}

// Function to convert String to Integer
int StrToInt (char const * pStr) 
{

		int				res = 0;
		HospitalString	s	= pStr;

	if (s.Length () < 3) {

		return -1;

	}

	pStr++;
	pStr++;

	while (*pStr != '\0') {

		res = res * 10 + (*pStr - 48);
		pStr++;

	}
	
	return res;

}


// Deleting all the nodes of the
// vNurse linkedlist
Hospital :: ~Hospital () 
{

	vNurses.DeleteAll ();

}

void Hospital :: DisplayMainMenu () 
{
		int		ch;
		bool	flag = true;

	while (flag) {

		printf ("\n\n==============================================================\n");
		printf ("\tWelcome to Hospital Management System\t\n");
		printf ("==============================================================\n\n");

		printf ("Enter any of the below keys to proceed\n\n");
		printf ("0. Exit\n");
		printf ("1. Add a doctor\n");
		printf ("2. Add a patient\n");
		printf ("3. Add a nurse\n");
		printf ("4. Search by name\n");
		printf ("5. Search by Id\n");
		printf ("6. Display all doctors\n");
		printf ("7. Display all nurses\n");
		printf ("8. Display all patients\n");
		printf ("9. Add bill charges\n");
		printf ("10. Generate Bill\n");
		printf ("11. Remove a nurse\n");
		printf ("12. Remove a patient\n");
		printf ("13. Remove a doctor\n");
		printf ("14. Add doctor to an existing patient\n");
		printf ("\n");
		scanf_s ("%d", &ch);

		switch (ch) {

			case 0: 
					flag = false;
					break;					
			case 1: 
					AddDoctor ();
					break;
			case 2: 
					AddPatient ();
					break;
			case 3: 
					AddNurse ();
					break;
			case 4: 
					SearchByName ();
					break;
			case 5:
					SearchById ();
					break;
			case 6:
					DisplayAllDoctors ();
					break;
			case 7:
					DisplayAllNurses ();
					break;
			case 8:
					DisplayAllPatients ();
					break;
			case 9:
					AddBillCharges ();
					break;
			case 10:
					GenerateBill ();
					break;
			case 11:
					RemoveNurse ();
					break;
			case 12:
					RemovePatient ();
					break;
			case 13:
					RemoveDoctor ();
					break;
			case 14:
					AssignDoctorToPatient ();
					break;
			default: 
					printf ("Invalid input\n");

		};

	}

}

void Hospital :: AddDoctor () 
{

		HospitalString	name;
		HospitalDate	join_date;
		bool			flag		=  true;
		int				ch;

	while (name.Empty()) {

		name.Clear ();
		printf ("\nEnter the name of the doctor\n");
		name.InputString ();

	}

	printf ("\nEnter the date of joining of the doctor\n");
	join_date.GetDate ();

	while (flag) {

		printf ("\nEnter the choice of department from the following:\n1. General\n2. Ortho\n3. Cardio\n4. Neuro\n");
		scanf_s ("%d", &ch);
		
		// All the cases here, call the constructor of Doctor class with the given inputs
		// and insert the pointer to that object at the end of the uDoctors linked list
		switch (ch) {

			case 1: 
					vGeneral.uDoctors.InsertEnd (new (nothrow) Doctor (name.GetString (), join_date, sGeneralDocCount++, 0));
					flag = false;
					break;
			case 2: 
					vOrtho.uDoctors.InsertEnd (new (nothrow) Doctor (name.GetString (), join_date, sOrthoDocCount++, 1));
					flag = false;
					break;
			case 3: 
					vCardio.uDoctors.InsertEnd (new (nothrow) Doctor (name.GetString (), join_date, sCardioDocCount++, 2));
					flag = false;
					break;
			case 4: 
					vNeuro.uDoctors.InsertEnd (new (nothrow) Doctor (name.GetString (), join_date, sNeuroDocCount++, 3));
					flag = false;
					break;
			default: 
					printf ("Invalid choice\n");
					printf ("\nEnter the choice of department from the following:\n1. General\n2. Ortho\n3. Cardio\n4. Neuro\n");
					scanf_s ("%d", &ch);
					continue;

		};

	}

}

void Hospital :: AddNurse () 
{

		HospitalString  name;
		HospitalDate	join_date;

	while (name.Empty()) {

		name.Clear ();
		printf ("\nEnter the name of the nurse\n");
		name.InputString ();

	}

	printf ("\nEnter the date of joining of the nurse\n");
	join_date.GetDate ();

	// We call the constructor of Nurse class with the given inputs
	// and insert the pointer to that object at the end of the vNurses linked list
	vNurses.InsertEnd (new (nothrow) Nurse (name.GetString (), join_date, sNurseCount++));

}

void Hospital :: AddPatient () 
{

		HospitalString  name;
		HospitalDate	join_date;
		bool			flag		=  true;
		int				ch;

	while (name.Empty()) {

		name.Clear ();
		printf ("\nEnter the name of the patient\n");
		name.InputString ();

	}

	printf ("\nEnter the date of admission of the patient\n");
	join_date.GetDate ();

	while (flag) {

		printf ("\nEnter the choice of department from the following:\n1. General\n2. Ortho\n3. Cardio\n4. Neuro\n");
		scanf_s ("%d", &ch);

		// All the cases here, call the constructor of Patient class with the given inputs
		// and insert the pointer to that object at the end of the uPatients linked list
		switch (ch) {

			case 1: 
					vGeneral.uPatients.InsertEnd (new (nothrow) Patient (name.GetString (), join_date, sGeneralPatCount++, 0));
					CheckAvailability (0);
					flag = false;
					break;
			case 2: 
					vOrtho.uPatients.InsertEnd (new (nothrow) Patient (name.GetString (), join_date, sOrthoPatCount++, 1));
					CheckAvailability (1);
					flag = false;
					break;
			case 3: 
					vCardio.uPatients.InsertEnd (new (nothrow) Patient (name.GetString (), join_date, sCardioPatCount++, 2));
					CheckAvailability (2);
					flag = false;
					break;
			case 4: 
					vNeuro.uPatients.InsertEnd (new (nothrow) Patient (name.GetString (), join_date, sNeuroPatCount++, 3));
					CheckAvailability (3);
					flag = false;
					break;
			default: 
					printf ("\nInvalid choice\n");
					printf ("Invalid choice\n");
					printf ("\nEnter the choice of department from the following:\n1. General\n2. Ortho\n3. Cardio\n4. Neuro\n");
					scanf_s ("%d", &ch);
					continue;

		};

	}

}

// Searching the nurses list by the help of Id,
// The return value of this function is the pointer to the
// Nurse whose Id matches with the pId otherwise nullptr
Nurse * Hospital :: SearchNursesById (int pId) 
{

		tNode <Nurse *> * temp = vNurses.GetTail ();

	while (temp != nullptr) {

		if (temp -> uData -> GetId () == pId) {

			return temp -> uData;

		}

		temp = temp -> uPrev;

	}

	return nullptr;

}


// Takes the id as input, and calls the respective
// SearchById functions.

// The id has 3 parts:
// 1. First character indicates the department
// 2. Second character indicates whether patient, doctor or nurse
// 3. Rest is the actual vId stored in that object

void Hospital :: SearchById	() 
{

		int						id;
		HospitalString			str_id;
		int						dep				= 0;
		Patient			*		pat_ptr			= nullptr;
		Doctor			*		doc_ptr			= nullptr;

	printf ("\nEnter the id: ");
	str_id.InputString ();

	id = StrToInt (str_id.GetString ());

	printf ("\n-----------------------\n");
	if (str_id[0] == 'G' or str_id[0] == 'g') {

		dep = 1;
		
		if (str_id[1] == 'D' or str_id[1] == 'd') {

			doc_ptr = vGeneral.SearchDoctorsById (id);
			
			if (doc_ptr != nullptr) {

				doc_ptr -> Display ();

			}

		}
		else if (str_id[1] == 'P' or str_id[1] == 'p') {

			pat_ptr = vGeneral.SearchPatientsById (id);
			
			if (pat_ptr != nullptr) {

				pat_ptr -> Display ();

			}

		}

	} else if (str_id[0] == 'O' or str_id[0] == 'o') {

		dep = 2;

		if (str_id[1] == 'D' or str_id[1] == 'd') {

			doc_ptr = vOrtho.SearchDoctorsById (id);
			
			if (doc_ptr != nullptr) {

				doc_ptr -> Display ();

			}

		}
		else if (str_id[1] == 'P' or str_id[1] == 'p') {

			pat_ptr = vOrtho.SearchPatientsById (id);
			
			if (pat_ptr != nullptr) {

				pat_ptr -> Display ();

			}

		}

	} else if (str_id[0] == 'C' or str_id[0] == 'c') {

		dep = 3;

		if (str_id[1] == 'D' or str_id[1] == 'd') {

			doc_ptr = vCardio.SearchDoctorsById (id);
			
			if (doc_ptr != nullptr) {

				doc_ptr -> Display ();

			}

		}
		else if (str_id[1] == 'P' or str_id[1] == 'p') {

			pat_ptr = vCardio.SearchPatientsById (id);
			
			if (pat_ptr != nullptr) {

				pat_ptr -> Display ();

			}

		}

	} else if (str_id[0] == 'N' or str_id[0] == 'n') {

		dep = 4;

		if (str_id[1] == 'D' or str_id[1] == 'd') {

			doc_ptr = vNeuro.SearchDoctorsById (id);
			
			if (doc_ptr != nullptr) {

				doc_ptr -> Display ();

			}

		} else if (str_id[1] == 'P' or str_id[1] == 'p') {

			pat_ptr = vNeuro.SearchPatientsById (id);
			
			if (pat_ptr != nullptr) {

				pat_ptr -> Display ();

			}

		} else if (str_id[1] == 'N' or str_id[1] == 'n') {

			Nurse * temp = SearchNursesById (id);
			temp -> Display ();

		}

	} else {

		printf ("Invalid Id\n");
		return;

	}

}

// Takes the name as input, and calls the
// SearchByName functions for all the lists

void Hospital :: SearchByName () 
{

		HospitalString					str;
		tNode <Nurse *>		*			nurse_itr = vNurses.GetTail ();

	while (str.Empty()) {

		str.Clear ();
		printf ("\nEnter the name\n");
		str.InputString ();

	}

	printf ("\n-----------------------\n");

	printf ("\nList of doctors with the matching name: \n");
	printf ("=======================================\n");
	vGeneral.SearchDoctorsByName (str.GetString ());
	vOrtho.SearchDoctorsByName (str.GetString ());
	vCardio.SearchDoctorsByName (str.GetString ());
	vNeuro.SearchDoctorsByName (str.GetString ());

	printf ("\nList of patients with the matching name: \n");
	printf ("=======================================\n");
	vGeneral.SearchPatientsByName (str.GetString ());
	vOrtho.SearchPatientsByName (str.GetString ());
	vCardio.SearchPatientsByName (str.GetString ());
	vNeuro.SearchPatientsByName (str.GetString ());

	printf ("\nList of nurses with the matching name: \n");
	printf ("=======================================\n");
	while (nurse_itr != nullptr) {

		if (IsStrSame (nurse_itr -> uData -> GetName (), str.GetString ())) {

			nurse_itr -> uData -> Display ();

		}

		nurse_itr = nurse_itr -> uPrev;

	}

}


// Checks if any nurse is available / free

// Takes the patient pointer to check which patient needs 
// a nurse to be assigned which later will be stored as 
// uPatient pointer.
void Hospital :: CheckNurseAvailability (Patient *pPatPtr) 
{
		
		bool				nurse_flag	= false;
		tNode <Nurse *> *	nurse_itr	= vNurses.GetTail ();

	if (pPatPtr == nullptr) {

		return;

	}

	while (nurse_itr != nullptr) {

		if (nurse_itr -> uData -> uAvailable) {

			nurse_itr -> uData -> uPatient = pPatPtr;
			nurse_itr -> uData -> uAvailable = false;
			nurse_flag = true;
			break;

		}

		nurse_itr = nurse_itr -> uPrev;

	}

	if (nurse_flag == false) {

		printf ("\nNo nurses available in the hospital right now, please add someone\n");
		AddNurse ();

		vNurses.GetTail () -> uData -> uPatient = pPatPtr;
		vNurses.GetTail () -> uData -> uAvailable = false;

	}

}

// Checks availability of doctors and nurses
// takes department code as parameter which makes
// it easier to know which department of doctors 
// to check for assigning

// Department codes:
// 0. General
// 1. Ortho
// 2. Cardio
// 3. Neuro

void Hospital :: CheckAvailability (int pDep) 
{
		HospitalString			str_id;
		int						id;
		Doctor			*		temp				= nullptr;
		Department		*		department			= nullptr;
		bool					doc_assigned		= false;

	if (pDep == 0) {

		department = &vGeneral;

	} else if (pDep == 1) {

		department = &vOrtho;

	} else if (pDep == 2) {

		department = &vCardio;

	} else if (pDep == 3) {

		department = &vNeuro;

	}

	if (department -> uDoctors.NodeCount () > 0) {

		department -> uDoctors.Print ();
		printf ("\nEnter the id of the doctor to be assigned:   ");

		while (doc_assigned == false) {

			str_id.InputString ();
			printf ("\n");

			id = StrToInt (str_id.GetString ());
			temp = department -> SearchDoctorsById (id);
			
			if (temp != nullptr) {

				department -> uPatients.GetTail () -> uData -> uDoctors.InsertEnd (temp);
				temp -> uPatients.InsertEnd (department -> uPatients.GetTail () -> uData);
				doc_assigned = true;

			} else {

				printf ("\nInvalid doctor Id entered\nEnter valid doctor id: ");
				str_id.Clear ();

			}

		}

	} else {

		printf ("\nNo doctors available at the department, please add someone\n");

		while (department -> uDoctors.NodeCount() <= 0) {

			AddDoctor ();

		}

		// Adding the pointer to the last added doctor of the General department to the last added patient 
		// of the General department
		department -> uPatients.GetTail () -> uData -> uDoctors.InsertEnd (department -> uDoctors.GetTail () -> uData);
		department -> uDoctors.GetTail () -> uData -> uPatients.InsertEnd (department -> uPatients.GetTail () -> uData);

	}

	CheckNurseAvailability (department -> uPatients.GetTail () -> uData);

}

void Hospital :: DisplayAllDoctors () 
{

	printf ("\nGeneral Department doctors:\n");
	printf ("==============================\n");
	vGeneral.uDoctors.Print ();

	printf ("\nOrtho Department doctors:\n");
	printf ("==============================\n");
	vOrtho.uDoctors.Print ();

	printf ("\nCardio Department doctors:\n");
	printf ("==============================\n");
	vCardio.uDoctors.Print ();

	printf ("\nNeuro Department doctors:\n");
	printf ("==============================\n");
	vNeuro.uDoctors.Print ();

}

void Hospital :: DisplayAllPatients () 
{

	printf ("\nGeneral Department patients:\n");
	printf ("==============================\n");
	vGeneral.uPatients.Print ();

	printf ("\nOrtho Department patients:\n");
	printf ("==============================\n");
	vOrtho.uPatients.Print ();

	printf ("\nCardio Department patients:\n");
	printf ("==============================\n");
	vCardio.uPatients.Print ();

	printf ("\nNeuro Department patients:\n");
	printf ("==============================\n");
	vNeuro.uPatients.Print ();

}

void Hospital :: DisplayAllNurses () 
{

	printf ("\nList of all the nurses\n");
	printf ("==============================\n");
	vNurses.Print ();

}

Patient * Hospital :: FindPatientById () 
{

		HospitalString		str;
		Patient			*   temp  = nullptr;
		int					id;

	printf ("\nEnter a valid patient Id\n");
	str.InputString ();
	
	if (str[1] != 'P' && str[1] != 'p') {

		printf ("\nNot a valid patient id\n");
		return nullptr;

	}

	id = StrToInt (str.GetString ());

	if (str[0] == 'G' || str[0] == 'g') {

		temp = vGeneral.SearchPatientsById (id);

	} else if (str[0] == 'O' || str[0] == 'o') {

		temp = vOrtho.SearchPatientsById (id);

	} else if (str[0] == 'C' || str[0] == 'c') {

		temp = vCardio.SearchPatientsById (id);

	} else if (str[0] == 'N' || str[0] == 'n') {

		temp = vNeuro.SearchPatientsById (id);

	} 

	return temp;

}

Doctor * Hospital :: FindDoctorById () 
{

		HospitalString		str;
		int					id;
		Doctor			*   temp  = nullptr;

	printf ("\nEnter a valid doctor Id\n");
	str.InputString ();
	
	if (str[1] != 'D' && str[1] != 'd') {

		printf ("\nNot a valid doctor id\n");

	}

	id = StrToInt (str.GetString ());

	if (str[0] == 'G' || str[0] == 'g') {

		temp = vGeneral.SearchDoctorsById (id);

	} else if (str[0] == 'O' || str[0] == 'o') {

		temp = vOrtho.SearchDoctorsById (id);

	} else if (str[0] == 'C' || str[0] == 'c') {

		temp = vCardio.SearchDoctorsById (id);

	} else if (str[0] == 'N' || str[0] == 'n') {

		temp = vNeuro.SearchDoctorsById (id);

	} 

	return temp;

}


void Hospital :: RemoveNurse () 
{

		HospitalString		str;
		int					id;
		int					ind			= 0;
		Nurse			*   temp		= nullptr;
		Patient			*	pat_ptr		= nullptr;
		tNode <Nurse *> *	nurse_itr	= vNurses.GetTail ();

	printf ("\nEnter a valid nurse Id\n");
	str.InputString ();
	
	if ((str[0] != 'N' && str[0] != 'n') && (str[1] != 'N' && str[1] != 'n')) {

		printf ("\nNot a valid nurse id\n");
		return;

	}

	id = StrToInt (str.GetString ());

	temp = SearchNursesById (id);

	if (temp == nullptr) {
		
		printf ("\nNo nurse with matching id found\n");
		return;

	}
	
	pat_ptr = temp -> uPatient;

	CheckNurseAvailability (pat_ptr);
	
	while (nurse_itr != nullptr) {
		
		if (nurse_itr -> uData -> GetId () == temp -> GetId ()) {

			vNurses.DeleteAt (ind);
			break;

		}

		nurse_itr = nurse_itr -> uPrev;

		id++;

	}

}

void Hospital :: RemoveDoctor () 
{

		Doctor				* temp			= FindDoctorById ();
		tNode <Patient *>	* patlist_tail	= nullptr;
		int					  ind			= 0;
		int					  dep			= 0;

	if (temp == nullptr) {

		printf ("\nNo doctor found with a matching Id\n");
		return;

	}

	dep = temp -> GetDept ();

	if (dep == 0) {

		ind = vGeneral.uDoctors.FindId (temp);
		vGeneral.uDoctors.DeleteAt (ind);

	} else if (dep == 1) {

		ind = vOrtho.uDoctors.FindId (temp);
		vOrtho.uDoctors.DeleteAt (ind);

	} else if (dep == 2) {

		ind = vCardio.uDoctors.FindId (temp);
		vCardio.uDoctors.DeleteAt (ind);

	} else if (dep == 3) {

		ind = vNeuro.uDoctors.FindId (temp);
		vNeuro.uDoctors.DeleteAt (ind);

	}

	patlist_tail = temp -> uPatients.GetTail ();

	while (patlist_tail != nullptr) {

		ind = patlist_tail -> uData -> uDoctors.FindId (temp);

		if (ind >= 0) {

			patlist_tail -> uData -> uDoctors.DeleteAt (ind);
			printf ("\nYou need to assign a doctor to the patients.\n");
			AssignDoctorToPatient (patlist_tail -> uData);

		}

		patlist_tail = patlist_tail -> uPrev;

	}
	
}

void Hospital :: RemovePatient () 
{

		Patient				* temp			= FindPatientById ();
		tNode <Doctor *>	* doclist_tail	= nullptr;
		tNode <Nurse *>		* nurse_tail    = vNurses.GetTail ();
		int					  ind			= 0;
		int					  dep			= 0;

	if (temp == nullptr) {

		printf ("\nNo patient found with a matching Id\n");
		return;

	}

	doclist_tail = temp -> uDoctors.GetTail ();

	while (doclist_tail != nullptr) {

		ind = doclist_tail -> uData -> uPatients.FindId (temp);

		if (ind >= 0) {

			doclist_tail -> uData -> uPatients.DeleteAt (ind);

		}

		doclist_tail = doclist_tail -> uPrev;

	}

	dep = temp -> GetDept ();

	if (dep == 0) {

		ind = vGeneral.uPatients.FindId (temp);
		vGeneral.uPatients.DeleteAt (ind);

	} else if (dep == 1) {

		ind = vOrtho.uPatients.FindId (temp);
		vOrtho.uPatients.DeleteAt (ind);

	} else if (dep == 2) {

		ind = vCardio.uPatients.FindId (temp);
		vCardio.uPatients.DeleteAt (ind);

	} else if (dep == 3) {

		ind = vNeuro.uPatients.FindId (temp);
		vNeuro.uPatients.DeleteAt (ind);

	}
	
	while (nurse_tail != nullptr) {

		if (nurse_tail -> uData -> uPatient == temp) {

			nurse_tail -> uData -> uAvailable = true;
			nurse_tail -> uData -> uPatient = nullptr;
			break;

		}

		nurse_tail = nurse_tail -> uPrev;

	}

}

// Finds the patient pointer by calling FindPatientById () function
// Calls the PrintBill function of the Patient obj

void Hospital :: GenerateBill () 
{

		Patient * temp = FindPatientById ();

	if (temp != nullptr) {

		temp -> PrintBill ();

	}

}

// Takes user input for patient Id, later takes user input for doctor Id of all
// the available doctors, validates the presence of that Id
// Adds the relevant Doctor pointer to the uDoctors array.

// Currently there is no method to unassign a doctor from a patient
void Hospital :: AssignDoctorToPatient (Patient *pPatPtr) 
{

		Patient			* pat_ptr	= nullptr;
		Doctor			* doc_ptr	= nullptr;
		int				  ind		= 0;
		bool			  doc_assig = false;
		HospitalString    str;
	
	if (pPatPtr == nullptr) {

		pat_ptr = FindPatientById ();

	} else {

		pat_ptr = pPatPtr;

	}

	if (pat_ptr == nullptr) {

		printf ("\nNo patient found with matching Id\n");
		return;

	}

	while (doc_assig == false) {

		DisplayAllDoctors ();
		doc_ptr = FindDoctorById ();

		ind = pat_ptr -> uDoctors.FindId (doc_ptr);

		if (doc_ptr != nullptr and ind == -1) {

			pat_ptr -> uDoctors.InsertEnd (doc_ptr);
			doc_ptr -> uPatients.InsertEnd (pat_ptr);
			doc_assig = true;
			//return;

		} else if (ind >= 0) {

			printf ("\nDoctor already assigned to the patient\n");
			doc_assig = true;
			//return;

		} else {

			printf ("\nNo doctor found with matching Id\nAdd a new doctor instead");
			AddDoctor ();

		}

	}

}

// Finds the patient pointer by calling FindPatientById () function
// Calls the PrintBill function of the Patient obj to add charges

// Charges have 2 parts:
// 1. Particular	(String)
// 2. Cost			(float)

void Hospital :: AddBillCharges () 
{
		
		Patient * temp = FindPatientById ();

	if (temp != nullptr) {

		temp -> AddCharges ();

	}

	printf ("\nNo such patient with matching Id found\n");

}

//void Hospital :: DisplayAllDoctorsSorted () 
//{
//		
//		int choice  = 0;
//
//	printf ("\nEnter choice: \n1.Lexicographical\n2.Datewise\n");
//	scanf_s ("%d", &choice);
//
//	if (choice == 1) {
//
//		vGeneral.uDoctors.SortAlphabetically ();
//		vOrtho.uDoctors.SortAlphabetically ();
//		vCardio.uDoctors.SortAlphabetically ();
//		vNeuro.uDoctors.SortAlphabetically ();
//		DisplayAllDoctors ();
//
//	} else if (choice == 2) {
//
//		vGeneral.uDoctors.SortDatewise ();
//		vOrtho.uDoctors.SortDatewise ();
//		vCardio.uDoctors.SortDatewise ();
//		vNeuro.uDoctors.SortDatewise ();
//		DisplayAllDoctors ();
//
//	}
//
//}
//
//void Hospital :: DisplayAllPatientsSorted () 
//{
//		
//		int choice  = 0;
//
//	printf ("\nEnter choice: \n1.Lexicographical\n2.Datewise\n");
//	scanf_s ("%d", &choice);
//
//	if (choice == 1) {
//
//		vGeneral.uPatients.SortAlphabetically ();
//		vOrtho.uPatients.SortAlphabetically ();
//		vCardio.uPatients.SortAlphabetically ();
//		vNeuro.uPatients.SortAlphabetically ();
//		DisplayAllPatients ();
//
//	} else if (choice == 2) {
//
//		vGeneral.uPatients.SortDatewise ();
//		vOrtho.uPatients.SortDatewise ();
//		vCardio.uPatients.SortDatewise ();
//		vNeuro.uPatients.SortDatewise ();
//		DisplayAllPatients ();
//
//	}
//
//}
//
//
//void Hospital :: DisplayAllNursesSorted () 
//{
//		
//		int choice  = 0;
//
//	printf ("\nEnter choice: \n1.Lexicographical\n2.Datewise\n");
//	scanf_s ("%d", &choice);
//
//	if (choice == 1) {
//
//		vNurses.SortAlphabetically ();
//		DisplayAllNurses ();
//
//	} else if (choice == 2) {
//
//		vNurses.SortDatewise ();
//		DisplayAllNurses ();
//
//	}
//
//}