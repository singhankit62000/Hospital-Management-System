#ifndef DEPARTMENT_HPP
#define DEPARTMENT_HPP

#include "doctor.hpp"
#include "hospital.array.hpp"
#include "patient.hpp"

class Department {

	public:		
										~Department										();
		void							SearchDoctorsByName								(char const * pName);
		Doctor		*					SearchDoctorsById								(int pId);
		void							SearchPatientsByName							(char const * pName);
		Patient		*					SearchPatientsById								(int pId);

		HospitalLinkedList <Doctor *>	uDoctors;
		HospitalLinkedList <Patient *>	uPatients;

};

#endif // !DEPARTMENT_HPP