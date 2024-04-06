#ifndef HOSPITAL_DATE_HPP
#define HOSPITAL_DATE_HPP

#include <stdio.h>

class HospitalDate {

	public: 
							HospitalDate		();
							HospitalDate		(unsigned int pDay, unsigned int pMonth, unsigned int pYear);
		HospitalDate &		operator		=	(HospitalDate &pObj);
		bool				operator		<	(HospitalDate &pObj);
		void				GetDate				();
		void				PrintDate			();

	private:
		bool				ValidateDate		();
		unsigned int		vDay;
		unsigned int		vMonth;
		unsigned int		vYear;


};

#endif // !HOSPITAL_DATE_HPP