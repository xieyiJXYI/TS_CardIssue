//#####################################
//
//	class CScript_YK
//
//	�鿨�ű��ࣨͨ��������ָ������һ����С����鿨�ű����ܣ�,Ŀǰ��֧����֤SSSE�Ľű�����
//  ����޸����ڣ�20151109 17:30
//#####################################
#pragma once

#include "Information.h"
#include "Parameter.h"
#include "Instruction.h"
#include "Command.h"

#define _CARD_SN 2		//VAR2   ��ƬSN
#define _DIVFACTOR 92	//VAR92	 ��ɢ����
#define _DIVFACTOR1 93	//VAR93  ������ɢ����
#define _DIVFACTOR2 94	//VAR94	 ������ɢ����+������ɢ����
#define _DIVFACTOR3 95	//VAR95	 ������ɢ����+������ɢ����+һ����ɢ����

class CScript_YK
{
public:
	CScript_YK(CInformation *cInfo);
	~CScript_YK(void);
	
	/************************************************************************/
	/*��    ��:	IssueCardProcess
	/*��    ��:	���������ű�����
	/*�������:	nMode���ⲿ��֤��ʽ  0���̶���Կ  1�����ܻ�  2��PSAM��
	/*�������:	null
	/*�� �� ֵ:	false	�ɹ�	true	�����ű����̷�������
	/************************************************************************/
	bool IssueCardProcess(int nMode);

protected:
	CInstruction *cInst;
	CInformation *const cInfo;
	CParameter *cParameter;
	CCommand *cCmd;
	bool m_bRefreshFlag;//ˢ�±�־��true:��������ָ����Զ����������ɵĽű�������
	stringstream m_sstrTemp;//��ʱ�洢����
	string m_strTemp;

	/************************************************************************/
	/*��    ��:	LineFeed
	/*��    ��:	�ű������ӻ���
	/*�������:	nLineNum: ��ʾ������
	/*�������:	null
	/*�� �� ֵ:	null
	/************************************************************************/
	void LineFeed( int nLineNum );
	/************************************************************************/
	/*��    ��:	LvOne_Annotations
	/*��    ��:	һ��ע��,����һ��ע��,ע�ͷ�ʽ�� ;------ע������
	/*�������:	strDatas: ע������	
	/*			RefreshFlag��ˢ�±�־������ֵΪtrueʱ����������ָ����Զ����������ɵĽű������У��ò�������дʱ��Ĭ��Ϊtrue
	/*�������:	null
	/*�� �� ֵ:	null
	/************************************************************************/
	string LvOne_Annotations( string strDatas, bool RefreshFlag = true );
	/************************************************************************/
	/*��    ��:	LvTwo_Annotations
	/*��    ��:	����ע��,���ڷָ�ע��,ע�ͷ�ʽ�� ;==============ע������==============
	/*�������:	strDatas: ע������	
	/*			RefreshFlag��ˢ�±�־������ֵΪtrueʱ����������ָ����Զ����������ɵĽű������У��ò�������дʱ��Ĭ��Ϊtrue
	/*�������:	null
	/*�� �� ֵ:	null
	/************************************************************************/
	string LvTwo_Annotations( string strDatas, bool RefreshFlag = true  );
	/************************************************************************/
	/*��    ��:	GetAndSetParama
	/*��    ��:	���ýű�����,������ȡ����������ݡ��������Ӽ��ܻ���������֤�����Ƚű�ͨ������
	/*�������:	nMode���ⲿ��֤��ʽ  0���̶���Կ  1�����ܻ�  2��PSAM��
	/*�������:	null
	/*�� �� ֵ:	null
	/************************************************************************/
	void GetAndSetParama(int nMode);
	/************************************************************************/
	/*��    ��:	ScriptModeStatement
	/*��    ��:	�ű����ߺ��޸����ڵ�����
	/*�������:	null
	/*�������:	null
	/*�� �� ֵ:	null
	/************************************************************************/
	void ScriptModeStatement();
	/************************************************************************/
	/*��    ��:	ExternalAuthentication
	/*��    ��:	�����ⲿ��֤�����̣����̰�������ȡxml���õ���Կ���ݣ�������֤SSSE����Կ�Ľű�����
	/*�������:	nMode���ⲿ��֤��ʽ  0���̶���Կ  1�����ܻ�  2��PSAM��
	/*�������:	null
	/*�� �� ֵ:	null
	/************************************************************************/
	void ExternalAuthentication(int nMode);
	/************************************************************************/
	/*��    ��:	PIN_Certify
	/*��    ��:	������֤PIN�����̣����̰�������ȡXML���õ�PIN��Ȼ�������У��SSSE�µ�PIN�Ľű�����
	/*�������:	null
	/*�������:	null
	/*�� �� ֵ:	null
	/************************************************************************/
	void PIN_Certify();
};
