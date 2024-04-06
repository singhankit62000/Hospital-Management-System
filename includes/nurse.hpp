#ifndef NURSE_HPP
#define NURSE_HPP

#include "hospital.date.hpp"
#include "patient.hpp"

class Nurse {

	public:
								Nurse			(char const *pName, HospitalDate &pJoinDate, int pId);
		int						GetId			();
		char const	  *			GetName			();
		void					Display			();
		HospitalDate			GetDate			();
		bool					uAvailable;
		Patient		  *			uPatient;

	private:
		HospitalString			vName;
		HospitalDate			vJoinDate;	
		int						vId;

};

#endif // !NURSE_HPP