﻿#include <ctime>
#include <algorithm>

#ifndef canDataH
#define canDataH

enum CanVersion {
	a = 0,	//2.0A
	b = 1,  //2.0B
};

class TCanDataFrame : public TObject {
//public inheritance, to enable adding of object to TObjectList
private:
	int m_id;       //message Identifier
	int m_dlc;      //data length code
	int m_data[8];  //data
	CanVersion m_version;   //message Identifier version, 2.0A or 2.0B
public:
	TCanDataFrame() = default;
	~TCanDataFrame() {};

	int getId();
	void setId(int value);
	int getDlc();
	void setDlc(int value);
	const int * getData();
	void setData(int value[], int length);
	CanVersion getVersion();
	void setVersion(CanVersion value);
};

class TCanDataFrameEx : TCanDataFrame {
private:
    struct tm time;
};

#endif //canDataH
