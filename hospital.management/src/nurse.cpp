#include "nurse.hpp"

Nurse :: Nurse (char const * pName, HospitalDate &pDate, int pId) 
{

	vName = pName;
	vJoinDate = pDate;
	uPatient = nullptr;
	uAvailable = true;
	vId = pId;

}

int Nurse :: GetId () 
{

	return vId;

}

char const * Nurse :: GetName () 
{
	
	return vName.GetString ();

}

void Nurse :: Display () 
{

	printf ("\nNurse: NN%d\n", vId);
	printf ("Name: %s\n", vName.GetString ());

}

HospitalDate Nurse :: GetDate () 
{

	return vJoinDate;

}