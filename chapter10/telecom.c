struct PHONE_NUMBER {
	int areacode[3];
	int exchange[3];
	int station[4];
};

struct LONG_DISTANCE_BILL{
	short month;
	short day;
	short year;
	int time;
	struct PHONE_NUMBER callto;
	struct PHONE_NUMBER callfrom;
	struct PHONE_NUMBER billed;
};
