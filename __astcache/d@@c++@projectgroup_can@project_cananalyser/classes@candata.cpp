#include "CanData.h"

int TCanDataFrame::getId()
{
	return m_id;
};

void TCanDataFrame::setId(int value)
{
	m_id = value;
}

int TCanDataFrame::getDlc()
{
	return m_dlc;
}

void TCanDataFrame::setDlc(int value)
{
	m_dlc = value;
}

const int * TCanDataFrame::getData()
{
	return m_data;
};

void TCanDataFrame::setData(int value[], int length)
{
	for (int i = 0; i < std::min(length,8); i++) {
		m_data[i] = value[i];
	}
};

CanVersion TCanDataFrame::getVersion()
{
	return m_version;
}

void TCanDataFrame::setVersion(CanVersion value)
{
	m_version = value;
}
