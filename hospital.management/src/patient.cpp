#include "patient.hpp"

Patient :: Patient (char const * pName, HospitalDate &pDate, int pId, int pDep) 
{

	vName = pName;
	vAdmitDate = pDate;
	vId = pId;
	vDep = pDep;
	vTotalAmount = 0;

}

Patient :: ~Patient () 
{

	uDoctors.DeleteAll ();

}

int Patient :: GetId () 
{

	return vId;

}

char const * Patient :: GetName () 
{

	return vName.GetString ();

}

void Patient :: Display () 
{

		HospitalArray <HospitalString> arr;

	arr.PushBack ("General");
	arr.PushBack ("Ortho");
	arr.PushBack ("Cardio");
	arr.PushBack ("Neuro");

	printf ("\nPatient  : %cP%d\n", arr[vDep][0], vId);
	printf ("Name     : %s\n", vName.GetString ());
	printf ("Dept	 : %s\n", arr[vDep].GetString ());
	printf ("\n - Assigned Doctors :");
	uDoctors.Print ();

}

void Patient :: AddCharges () 
{
		float				charge = 0;
		HospitalString		medium;
		tCharges			bill;

	printf ("\nThe charges are for: ");
	medium.InputString ();
	printf ("\nEnter the amount: ");
	scanf_s ("%f", &charge);
	printf ("\n");

	bill.uPart = medium;
	bill.uCost = charge;
	
	vBill.PushBack (bill);
	vTotalAmount += charge;

}

void Patient :: PrintBill () 
{

		size_t it		= 0;
		size_t size		= vBill.Size ();
		
	printf ("\n============\n");
	printf ("Hospital Bill\n");
	printf ("============\n");

	Display ();

	printf ("\nParticular\t\t\t\tCost\n");
	printf ("------------------------------------------------------------\n");
	for (it = 0; it < size; it++) {

		printf ("\n%s\t\t\t\t", vBill[it].uPart.GetString());
		printf ("%f\n", vBill[it].uCost);

	}

	printf ("\nTotal amount to be paid: \t\t%f", vTotalAmount);

}

HospitalDate Patient :: GetDate () 
{

	return vAdmitDate;

}

int Patient :: GetDept () 
{

	return vDep;

}