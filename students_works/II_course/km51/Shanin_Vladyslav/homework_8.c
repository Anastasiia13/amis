#include <stdio.h>

enum groups_list {
	KM_51, KM_52, KM_53, KP_51, KP_52, KP_53, KV_51, KV_52, KV_53, IO_51, IO_52, IO_53, IS_51, IS_52, IS_53, IP_51, IP_52, IP_53
};

enum faculties_list {
	FAM, FICT
};

enum scholarship_type {
	Academical, Social, Postgraduate
};

enum banks_list {
	PrivatBank, PraveksBank, OshchadBank, UkrSibBank, CreditAgricole
};

struct bank_account {
	int account_number;
	enum banks_list bank;
	float comission;
};

struct scholarship {
	float average_mark;
	struct bank_account account;
	float size;
	enum scholarship_type type;
};

struct student{
	char Name[20];
	char Surname[20];
	enum groups_list group;
	enum faculties_list faculty;
	struct scholarship student_scholarship;
};

int main(){	
	return 0;
}
