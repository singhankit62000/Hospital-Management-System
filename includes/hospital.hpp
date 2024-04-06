#ifndef HOSPITAL_HPP
#define HOSPITAL_HPP

#include "department.hpp"
#include "doctor.hpp"
#include "nurse.hpp"
#include "patient.hpp"
#include "hospital.array.hpp"
#include "hospital.linkedlist.hpp"

class Hospital {

	public:	
										~Hospital				();
		void							DisplayMainMenu			();
		void							AddDoctor				();
		void							AddNurse				();
		void							AddPatient				();
		// Function to diagnose a patient
		// * This function asks for a choice between:			
		//								<WIP>		(a) Add doctor
		//												* Displays the list of all doctors with Ids
		//												* Asks you to enter the Id of the doctor to be assigned
		//												* Traverses the list to find the doctor's pointer and add it to 
		//												  the patient's list of doctor pointers.
		//											(b) Add bill charges
		//												* Takes string input of the test/ operation/ surgery name
		//												* Takes float input of the cost of that thing.
		//												* Inserts into the list of pair<string, float> for bill in patient
		//												* Also adds the amount entered to the vTotalAmount variable in patient.
		// The user needs to add all the charges, including doctor fees as well as medications, surgeries, etc manually
		void							AddBillCharges			();
		void							AssignDoctorToPatient	(Patient *pPatPtr = nullptr);
		// 
		// Function to remove a doctor
		// * This function does the following:
		//											* Takes input of the doctor Id
		//											* Validates the Id and along the way finds the doctor pointer of that Id
		//											* Traverse the list of patients assigned to that doctor:
		//												(i) Go to that patient
		//													* Find that Id in the patient's list of doctor pointers, delete that node.
		//													* Check if the sDocCount for that department is greater than 0:
		//														(a) If Yes, display the list of that department doctors, take Id, find Id, 
		//															add to list
		//														(b) If No, call the main AddDoctor () function for the same department, 
		//															then after adding the doctor, again check if there are any doctors present
		//															in that department and continue until then.
		// 
		// TODO: Haven't implemented remove doctor functionality yet		
		void							RemoveDoctor			();
		// 
		// Function to remove a nurse
		//											* Take input of nurse Id
		//											* Validate the Id and along the way find the nurse pointer in the list,
		//											  take the patient pointer from that nurse, delete that node.
		//											* Traverse the list to check if any nurse is available
		//												(a) If Yes, Enter the patient pointer to that nurse
		//												(b) If No, Call the main AddNurse () function and attach this patient
		//													the nurse.
		void							RemoveNurse				();
		// 
		// Function to remove a patient
		//											* Take input of the patient Id
		//											* Validate the Id and along the way find the patient pointer in the list,
		//											  traverse the doctor pointers list of that patient and remove this patient pointer
		//											  from their list.
		//											* Delete the node.
		void							RemovePatient			();
		// 
		// Function to generate a bill	
		//											* Take the patient Id input
		//											* Validate the Id and along the way find the patient pointer in the list
		//											* Traverse the list of pair<string, float> print all those.
		//											* Traverse the list of doctors assigned to that patient one by one, 
		//											  display the name and Id of that doctor, ask user input for the charges mentioned 
		//											  by the doctor, add that to the vTotalAmount data member simultaenously
		//											  (EXTRA: I can add a pair of {Doctor Name, Charges} to the list of charges 
		//											  which can prevent asking for doctor charges everytime whenever a bill is generated)
		//											* Finally print the vTotalAmount value till now.
		void							GenerateBill			(); 
		//Function to display the list of doctors
		// * This asks for the choice between: 
		//									(a) Department wise								- Take the department choice, display 
		//																					  all in that department
		//									(b) All doctors:
		//										<TODO>		(i) Alphabetically sorted		- Call Linkedlist alphabetically sort fn
		//										<TODO>		(ii) Joining date order sorted	- Call Linkedlist date sort fn
		//
		void							DisplayAllDoctors		();
		//void							DisplayAllDoctorsSorted	();
		//Function to display the list of patients
		// * This asks for the choice between: 
		//									(a) Department wise								- Take the department choice, display 
		//																					  all in that department
		//									(b) All patients:
		//										<TODO>		(i) Alphabetically sorted		- Call Linkedlist alphabetically sort fn
		//										<TODO>		(ii) Admission date order       - Call Linkedlist date sort fn
		//
		void							DisplayAllPatients		();
		//void							DisplayAllPatientsSorted();
		// Function to display the list of nurses
		// * This asks for the choice between: 
		//									(a) All nurses:
		//										<TODO>		(i) Alphabetically sorted		- Call Linkedlist alphabetically sort fn
		//										<TODO>		(ii) Joining date order sorted	- Call Linkedlist date sort fn
		void							DisplayAllNurses		();
		//void							DisplayAllNursesSorted	();
		// 
		// Function to search from list
		// * This asks for the choice between:
		//									(a) Doctor	
		//													(i) By Name - Will have to traverse department wise all the lists and 
		//																display all matching names with details
		//													(ii) By Id	- Will take input in the form of G1 for General, O1 for Ortho, etc
		//																Search only in those departments whose Id is entered.
		//									(b) Patients
		//													(i) By Name - Will have to traverse department wise all the lists and 
		//																display all matching names with details
		//													(ii) By Id	- Will take input in the form of G1 for General, O1 for Ortho, etc
		//																Search only in those departments whose Id is entered.
		// 
		//									(c) Nurses
		//													(i) By Name - Will have to traverse the list and 
		//																display all matching names with details
		//													(ii) By Id	- Will have to traverse the list and 
		//																display the details of the matching Id.
		// Function to search by name:
		//									* Take string input of name.
		//									* Traverse all the lists of departments and find the matching names and display them
		//									(USE: Search____ByName () function of Department class)
		void							SearchByName			();
		// Function to search by Id:		
		//									* Take string input of Id
		//									* Take the first character, set the department to be searched in, if not among the 5 set characters,
		//									  print "Invalid Id"
		//									* Traverse the respective list of the department and find the Id, if present print otherwise print
		//									  "Invalid Id"
		//									  (USE: Search____ById () function of Department class)
		void							SearchById				();

static  int								sGeneralDocCount;
static  int								sOrthoDocCount;
static  int								sCardioDocCount;
static  int								sNeuroDocCount;
static  int								sGeneralPatCount;
static  int								sOrthoPatCount;
static  int								sCardioPatCount;
static  int								sNeuroPatCount;
static  int								sNurseCount;

// Ids are unique in my code, so an Id that has been assigned to someone in the past, 
// shall not be assigned to someone else in the future 

	private:
		Nurse				*			SearchNursesById		(int pId);
		Patient				*			FindPatientById			();
		Doctor				*			FindDoctorById			();
		void							CheckAvailability		(int pDep);
		void							CheckNurseAvailability	(Patient *pPatPtr);

		Department						vGeneral;
		Department						vOrtho;
		Department						vCardio;
		Department						vNeuro;
		HospitalLinkedList <Nurse *>	vNurses;

};

#endif // !HOSPITAL_HPP