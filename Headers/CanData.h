#include <ctime>

#ifndef canDataH
#define canDataH

enum CanVersion {
	a = 0,
	b = 1,
};

struct CanDataFrame {
	int id;
	int dlc;
	int data[8];
    CanVersion version;
};

struct CanDataFrameEx : CanDataFrame {
    struct tm time;
};

#endif //canDataH
