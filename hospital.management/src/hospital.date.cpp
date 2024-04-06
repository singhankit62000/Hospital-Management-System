#include "hospital.date.hpp"

bool IsLeap (unsigned int pYear) 
{

	// If a year is divisible by 400, it's a leap year
	// If a year is divisible by 4 and 100, it should also be divisible by 400
	// If a year is divisible by 4 and not 100, it is a leap year
	// If a year is divisible by 4 and 100 but not 400, it's not a leap year.
	// Otherwise not a leap year.

    if (pYear % 4 == 0) {

        if (pYear % 100 == 0) {

			return (pYear % 400 == 0);

        }

        return true;
    }

    return false;
}

HospitalDate :: HospitalDate () 
{

	vDay = 1;
	vMonth = 1;
	vYear = 2023;

}

HospitalDate :: HospitalDate (unsigned int pDay, unsigned int pMonth, unsigned int pYear) 
{

	vDay = pDay;
	vMonth = pMonth;
	vYear = pYear;

}


HospitalDate & HospitalDate :: operator = (HospitalDate & pObj) 
{
	
	if (this == &pObj) {

		return *this;

	}

	vDay = pObj.vDay;
	vMonth = pObj.vMonth;
	vYear = pObj.vYear;

	return *this;

}

bool HospitalDate :: ValidateDate () 
{

	bool leap = IsLeap (vYear);

	// Validating year, only considering years within 1900 to 2024 as valid
	if (vYear < 1900 || vYear > 2024) {

		printf ("\nInvalid date. Please try again!\n");
		return false;

	}

    // Check for February
    if ((vMonth == 2 && leap && vDay < 30) || (vMonth == 2 && !leap && vDay < 29)) {                     

        return true;

    }
    
    // Check for months having maximum 30 days
    if ((vMonth == 4 && vDay < 31) || (vMonth == 6 && vDay < 31) || 
        (vMonth == 9 && vDay < 31) || (vMonth == 11 && vDay < 31)) {    

        return true;

    }

    // Check for months having maximum 31 days
    if ((vMonth == 1 && vDay < 32) || (vMonth == 3 && vDay < 32) || (vMonth == 5 && vDay < 32) || (vMonth == 7 && vDay < 32) || 
        (vMonth == 8 && vDay < 32) || (vMonth == 10 && vDay < 32) || (vMonth == 12 && vDay < 32)) {

        return true;

    }

    printf ("\nInvalid date. Please try again!\n");
    return false;

}


// The GetDate () function here requires the user to 
// carefully enter only numeric values

void HospitalDate :: GetDate () 
{

	do {
		
		printf ("Enter the day in dd format\n");
		scanf_s ("%u", &vDay);
		printf ("Enter the month in mm format\n");
		scanf_s ("%u", &vMonth);
		printf ("Enter the day in yyyy format\n");
		scanf_s ("%u", &vYear);

	} while (ValidateDate () == false);

}

void HospitalDate :: PrintDate () 
{

	printf (" %u - %u - %u ", vDay, vMonth, vYear);

}

bool HospitalDate :: operator < (HospitalDate &pObj) 
{

	if (vYear < pObj.vYear) {

		return true;
	
	} else if (vYear == pObj.vYear && vMonth < pObj.vMonth) {

		return true;

	} else if (vYear == pObj.vYear && vMonth == pObj.vMonth && vDay < pObj.vDay) {

		return true;

	}

	return false;
}