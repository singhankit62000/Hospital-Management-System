#ifndef HOSPITAL_ARRAY_HPP
#define HOSPITAL_ARRAY_HPP

#include "hospital.string.hpp"
#include <stdio.h>
#include <new>
using namespace std;

//#include <type_traits>

#define					INITIAL_ARRAY_CAPACITY			200

struct tCharges;

template <typename T> 
class HospitalArray {

	static_assert (is_same_v <T, HospitalString> || is_integral_v <T> || is_same_v <T, tCharges> , "Array declaration not allowed!\n");

	public: 
						HospitalArray					();
						HospitalArray					(size_t pSize);
						~HospitalArray					();
		void			PushBack						(T pParam);
		void			PopBack							();
		void			SendToEnd						(size_t pInd);
		size_t			Capacity						();
		size_t			Size							();
		T				operator		[]				(size_t pInd);
	private:
		void			IncreaseCapacity				(size_t pSize);

		T		*		vArray;
		size_t			vSize;
		size_t			vCapacity;

};

#include "hospital.array.hxx"

#endif //!HOSPITAL_ARRAY_HPP
