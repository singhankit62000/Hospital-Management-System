#include "doctor.hpp"

Doctor :: Doctor (char const * pName, HospitalDate &pDate, int pId, int pDep) 
{

	vName = pName;
	vJoinDate = pDate;
	vId = pId;
	vDep = pDep;

}

Doctor :: ~Doctor () 
{

	uPatients.DeleteAll ();

}

int Doctor :: GetId () 
{

	return vId;

}

char const * Doctor :: GetName () 
{

	return vName.GetString ();

}

void Doctor :: Display () 
{

		HospitalArray <HospitalString> arr;

	arr.PushBack ("General");
	arr.PushBack ("Ortho");
	arr.PushBack ("Cardio");
	arr.PushBack ("Neuro");

	printf ("\nDoctor : %cD%d\n", arr[vDep][0], vId);
	printf ("Name   : %s\n", vName.GetString ());
	printf ("Dept   : %s\n", arr[vDep].GetString ());

}


HospitalDate Doctor :: GetDate () 
{

	return vJoinDate;

}

int Doctor :: GetDept () 
{

	return vDep;

}