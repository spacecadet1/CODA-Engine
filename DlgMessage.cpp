// DlgMessage.cpp : Implementation of DlgMessage
#include "stdafx.h"
#include "DlgMessage.h"

/////////////////////////////////////////////////////////////////////////////
// DlgMessage

void DlgMessage::SetWarning(string str)
{
	
	
	m_str = str; flag = TRUE;
	
	
}

void DlgMessage::SetInformation(string str)
{
	
	
	m_str = str; flag = FALSE; 
	
	
}