#ifndef DOCTOR_HPP
#define DOCTOR_HPP

#include "hospital.string.hpp"
#include "hospital.array.hpp"
#include "hospital.date.hpp"
#include "hospital.linkedlist.hpp"

class Patient;

class Doctor {

	public:
											Doctor					(char const * pName, HospitalDate &pDate, int pId, int pDep);
											~Doctor					();
		int									GetId					();
		char const *						GetName					();
		void								Display					();
		HospitalDate						GetDate					();
		int									GetDept					();
		HospitalLinkedList <Patient *>		uPatients;
	private:
		int									vDep;
		HospitalString						vName;
		HospitalDate						vJoinDate;
		int									vId;

};

#endif // !DOCTOR_HPP