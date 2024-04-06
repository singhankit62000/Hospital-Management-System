#ifndef PATIENT_HPP
#define PATIENT_HPP

#include "hospital.date.hpp"
#include "hospital.string.hpp"
#include "hospital.linkedlist.hpp"
#include "hospital.array.hpp"

class Doctor;

struct tCharges {

	HospitalString	uPart;
	float			uCost;

};

class Patient {

	public:
										Patient				(char const * pName, HospitalDate &pDate, int pId, int pDep);
										~Patient			();
		int								GetId				();
		char const *					GetName				();
		void							Display				();
		void							AddCharges			();
		void							PrintBill			();
		int								GetDept				();
		HospitalDate					GetDate				();
		HospitalLinkedList <Doctor *>	uDoctors;

	private:
		int								vDep;
		int								vId;
		float							vTotalAmount;
		HospitalString					vName;
		HospitalDate					vAdmitDate;
		HospitalArray <tCharges>		vBill;

};


#endif // !PATIENT_HPP