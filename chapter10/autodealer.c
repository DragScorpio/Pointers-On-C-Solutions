struct BASIC_INFO{
	char cust_name[20];
	char cust_addr[20];
	char model[20];
};

struct ALLCASH{
	float sugg_price;
	float actl_price;
	float tax;
	float lisc_fee;
	struct BASIC_INFO basic_info;
};

struct LEASE{
	float sugg_price;
	float actl_price;
	float d_payment;
	float s_deposit;
	float m_payment;
	int lease_term;
	struct BASIC_INFO basic_info;
};

struct LOAN{
	float sugg_price;
        float actl_price;
        float tax;
        float lisc_fee;
	float d_payment;
	int loan_duration;
	float interest;
	float m_payment;
	char bank[20];
	struct BASIC_INFO basic_info;
};

struct SALE_RECORD{
	enum {AllCash, Lease, Loan} TYPE;
	union {
		struct ALLCASH allcash
		struct LEASE lease;
		struct LOAN loan;
	} sale_info;
};
