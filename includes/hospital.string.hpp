#ifndef HOSPITAL_STRING_HPP
#define HOSPITAL_STRING_HPP

#define								INITIAL_STRING_SIZE					200
#define								BACKSPACE							8
#define								ENTER_KEY							13
#define								ESCAPE								27
#define								END_OF_STRING						'\0'

class HospitalString {

	public:
									HospitalString						();
									HospitalString						(char const * pStr);
									HospitalString						(HospitalString &pObj);
									~HospitalString						();
		bool						operator			==				(HospitalString &pObj);
		HospitalString &			operator			=				(HospitalString &pObj);
		HospitalString &			operator			=				(char const * pStr);
		char						operator			[]				(int pInd);
		bool						operator			<				(HospitalString &pObj);
		void						PushBack							(char pCh);
		void						PopBack								();
		size_t						Length								();
		size_t						Capacity							();
		char const *				GetString							();
		void						InputString							();
		void						Clear								();
		bool						Empty								();

	private:
		char  *						vStr;
		size_t						vSize;
		size_t						vCapacity;

};

#endif //!HOSPITAL_STRING_HPP