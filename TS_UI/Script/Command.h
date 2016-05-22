//#####################################
//
//	class CCommand
//
//	�����ࣨ�ű���Լ�е����
//
//	�������ű���Լ�е���Ӧ�����ָ���޹�
//
//	ע�⣺
//	���й�������ķ����ж����в��� RefreshFlag �����ò���ֵΪtrueʱ����������ָ����Զ����������ɵĽű������У�
//	�ַ������ȣ�����ַ������ַ���������"12346578"���ַ�������Ϊ8��
//	�ֽ������ַ�����ÿ�����ַ���Ϊһ���ֽڣ���"12345678"���ֽ���Ϊ4��
//
//	����޸����ڣ�2015-09-01 18:52
//#####################################


#ifndef COMMAND_H
#define COMMAND_H

#include "Parameter.h"
#include "Information.h"
#include <string>
#include <sstream>
using namespace std;

#define STYLE_ASSIGNMENT	0x80	//�ڱ�����ֵ��>��ǰ�����ӿո��硰[ATR(9,8)] > 1��
#define STYLE_FUNTION_NAME	0x40	//�ں�������������ǰ�����ӿո��硰[ATR (9,8)]>1��
#define STYLE_COMMA			0x20	//�ں��������б��Ķ��ź����ӿո��硰[ATR(9, 8)]>1��



//ע�⣺����string�͵Ĳ���������������մ�""����ò���ȷʵ���贫���κ��������ݣ��봫��"00"
class CCommand
{
public:
	CCommand( CInformation *inf );
	~CCommand();

		/**************************************
		���ܣ���������־
		������
		�ڹ�������Ĺ����У�ֻҪ�����˴����ڲ������־�ͻᱻ��־Ϊ"true"��
		ʹ�ø÷������Խ������־����Ϊ"false"���뷽�� Error() ���ʹ�á�
		**************************************/
	void ReSetErrFlag();
		/**************************************
		���ܣ��жϴ���
		���أ�
		true����������
		false����û�д���
		������
		�ڹ�������Ĺ����У�ֻҪ�����˴����ڲ������־�ͻᱻ��־Ϊ"true"��
		��ʹ�÷��� ReSetErrFlag() ���ڲ������־��Ϊ"false"֮�󣬿�ʹ�ø÷�������ȡ�����־�������ж�֮����������һ������������Ƿ���ȷ��
		**************************************/
	bool Error();
		/**************************************
		���ܣ��򿪻�رղ������
		������
		IN��Swf������ֵΪtrueʱ��ÿ����һ������ǰ����Ը�����������Ӧ�ļ�飬�����ֵΪfalse������Բ����ļ��
		������
		��class CCommandʵ����ʱĬ�ϴ򿪹�������ʱ�Ĳ�����飬������齫��ʹһЩ�������淶����������ɹ���������Ҫ����ͨ���˷�������ر�
		**************************************/
	void Error_Check(bool Swf);
		/**************************************
		���ܣ��������ɽű��������ʽ
		��������������һ�������궨�尴λ�����ƴ����ɣ���
		STYLE_ASSIGNMENT���ڱ�����ֵ��>��ǰ�����ӿո��硰[ATR(9,8)] > 1��
		STYLE_FUNTION_NAME���ں�������������ǰ�����ӿո��硰[ATR (9,8)]>1��
		STYLE_COMMA���ں��������б��Ķ��ź����ӿո��硰[ATR(9, 8)]>1��
		������
		��ͨ���������������������ɽű�����ʽ
		**************************************/
	void Style_Set( unsigned char Sty );


		/**************************************
		���ܣ�����������ֵ����
		���Data > No
		������
		IN��No������ֵ��������ţ���Ч��Χ0-99
		IN��Data������ֵ����
		IN��RefreshFlag��ˢ�±�־������ֵΪtrueʱ����������������Զ����������ɵĽű�������
		���أ�
		��������������緢������������մ�
		��ע��
		���Խ����ո���������ַ���ֵ���������ű�ִ�г�������Զ�ȥ����ֵ���еĿո񣬲�����������������
		��ν���ִ�������˫����""�ʹ���AN���ݣ�ֻ���ڷ���COSָ��ʱ�Ż���Ч���������ط���˫���Żᱻ��Ϊ���ַ�����һ���֣�
		��򵥵Ĳ��ԣ�ʹ��ͬ������Կ���� "12345678" �� 3132333435363738 ִ��DES�㷨������ǲ�һ���ġ�
		**************************************/	
	string VAR( string Data, int No, bool RefreshFlag = true );
		/**************************************
		���ܣ�������λ����
		���RESET
		������
		IN��RefreshFlag��ˢ�±�־������ֵΪtrueʱ����������������Զ����������ɵĽű�������
		���أ�
		��������������緢������������մ�
		**************************************/
	string RESET( bool RefreshFlag = true );
		/**************************************
		���ܣ���ȡATR��Ӧ
		���[ATR(Pos, Len)]�� > VarNo ����ȫ�������š����е�����Ϊ��ѡ����
		������
		IN��ATR_pos�����ȡATR����ʼƫ�ƣ���0��ʼ�����ֽ�Ϊ��λ
		IN��ATR_len�����ȡATR�ĳ��ȣ�����ʼƫ�ƿ�ʼ�����ֽ�Ϊ��λ
		IN��VarNo��������ţ�����������������ֵС��0�򲻹����洢����
		IN��RefreshFlag��ˢ�±�־������ֵΪtrueʱ����������������Զ����������ɵĽű�������
		���أ�
		��������������緢������������մ�
		**************************************/
	string ATR(int Pos, int Len, int VarNo = -1, bool RefreshFlag = true );
		/**************************************
		���ܣ�DES����
		���[DES(Data, Key)]�� > VarNo ����ȫ�������š����е�����Ϊ��ѡ����
		������
		IN��Data�������ܵ����ݣ�Ҫ�������16λ�ַ���ɣ���"1234567812345678"
		IN��Key��ʹ�õ���Կ��Ҫ�������16λ�ַ���ɣ���"1234567812345678"
		IN��VarNo��������ţ�����������������ֵС��0�򲻹����洢����
		IN��RefreshFlag��ˢ�±�־������ֵΪtrueʱ����������������Զ����������ɵĽű�������
		���أ�
		��������������緢������������մ�
		��ע��
		������ Data �� Key �����Ϲ��򣬽ű�ִ�г��򽫻��Զ������´�����
		�񣺳������Զ�ɾ���������ȵ����ݣ����µ����ݿ��ܻẬ�зǷ��ַ�������еڶ���������
		�򣺷Ƿ��ַ��������ֽڶ��ǷǷ��ַ���ֱ����"A4"���滻��ֻ�и��ֽ��ǷǷ��ַ��������ֽ��滻Ϊ'4'��ֻ�е��ֽ��ǷǷ��ַ�������ֽ�ʮ������ֵΪX���Ƚ����ֽڸ���Ϊ��X+6��%0x10��Ȼ���ٽ����ֽ��滻Ϊ'4'��
		�󣺲��㳤���Ѳ��㳤���ֵ����Ƿ��ַ������ڶ�������
		**************************************/	
	string DES( string Data, string Key, int VarNo = -1, bool RefreshFlag = true );
		/**************************************
		���ܣ�3DES����
		���[3DES(Data, Key)]�� > VarNo ����ȫ�������š����е�����Ϊ��ѡ����
		������
		IN��Data�������ܵ����ݣ�Ҫ�������16λ�ַ���ɣ���"1234567812345678"
		IN��Key��ʹ�õ���Կ��Ҫ�������32λ�ַ���ɣ���"12345678123456781234567812345678"
		IN��VarNo��������ţ�����������������ֵС��0�򲻹����洢����
		IN��RefreshFlag��ˢ�±�־������ֵΪtrueʱ����������������Զ����������ɵĽű�������
		���أ�
		��������������緢������������մ�
		��ע��
		������������Ϲ��򣬽ű�ִ�г��򽫻��Զ����д�������������� DES ������ע�Ͳ��֡�
		**************************************/
	string TDES( string Data, string Key, int VarNo = -1, bool RefreshFlag = true );
		/**************************************
		���ܣ��������
		���[XOR(Par1, Par2)]�� > VarNo ����ȫ�������š����е�����Ϊ��ѡ����
		������
		IN��Par1������1������Ҫ�����Ϊ2�ı���
		IN��Par2������2������Ҫ�����Ϊ2�ı��������������1�ĳ������
		IN��VarNo��������ţ�����������������ֵС��0�򲻹����洢����
		IN��RefreshFlag��ˢ�±�־������ֵΪtrueʱ����������������Զ����������ɵĽű�������
		���أ�
		��������������緢������������մ�
		ע�⣺
		������ν���������ָ���ǽ�Par1��Par2ת����ʮ���������ݺ����������㣬��par1="33"��Par2="0F"���õ����Ϊ"3C"��
		��Ȼ�÷��������ý��ǹ��������������������������
		��ע��
		һ�����Ҫ��������������һ�£�������������Ȳ�һ�£��ű�ִ�г����Զ��ڽ϶̲��������'0'���ȳ���
		���������ĳ��ȶ�Ҫ����2�ı������������2�ı������ű�ִ�г��򽫻��Զ�ʹ��ȫ'0'���ַ����滻��������������ʱ���ܻ��������Ԥ�ϵĽ����
		������ַǷ��ַ����ű�ִ�г��򽫻��Զ�ʹ��'0'���滻
		**************************************/
	string XOR( string Par1, string Par2, int VarNo = -1, bool RefreshFlag = true );
		/**************************************
		���ܣ��̶���Կ����MAC
		���Data[CMAC(Pos, Len, Key)]�� > VarNo ����ȫ�������š����е�����Ϊ��ѡ����
		������
		IN��Data�������MAC�����ݣ�����Ҫ�����Ϊ2�ı������ű��ڲ����Զ���8�ֽ���������չ
		IN��Pos�������MAC���ݵ���ʼ�ֽ�ƫ�ƣ�һ��Ϊ0��Data�е�ÿ�����ַ���һ���ֽ�
		IN��Len�������MAC���ݵ��ֽ���������Pos��Lenָ������Data�м���MAC�����ݿ�
		IN��Key����ʹ�õ���Կ��Ҫ�������32���ַ����
		IN��VarNo��������ţ�����������������ֵС��0�򲻹����洢����
		IN��RefreshFlag��ˢ�±�־������ֵΪtrueʱ����������������Զ����������ɵĽű�������
		���أ�
		��������������緢������������մ�
		��ע��
		��� Data ����һ��������MAC���㣬���� Pos �� Len ��ָ�����ű��ڲ����Զ���8�ֽ���������չ
		������ Key �ĳ��Ȳ�����
		**************************************/
	string CMAC( string Data, int Pos, int Len, string Key, int VarNo = -1, bool RefreshFlag = true );
		/**************************************
		���ܣ��ַ�����ȡ
		���[SUBSTR(Pos, Len, Data)]�� > VarNo ����ȫ�������š����е�����Ϊ��ѡ����
		������
		IN��Pos����ȡ���ֵ���ʼ�ֽ�ƫ�ƣ�Data�е�ÿ�����ַ���һ���ֽ�
		IN��Len�����ȡ���ݵ��ֽ���
		IN��Data��ԭ�ַ��������Ӹ��ַ����н�ȡ���µ��Ӵ�������Ҫ�����Ϊ2�ı���
		IN��VarNo��������ţ�����������������ֵС��0�򲻹����洢����
		IN��RefreshFlag��ˢ�±�־������ֵΪtrueʱ����������������Զ����������ɵĽű�������
		���أ�
		��������������緢������������մ�
		**************************************/
	string SUBSTR( int Pos, int Len, string Data, int VarNo = -1, bool RefreshFlag = true );
		/**************************************
		���ܣ�ȡ��ƬӦ��
		���[RESP(Pos, Len)]�� > VarNo ����ȫ�������š����е�����Ϊ��ѡ����
		������
		IN��Pos�������ȡ��ƬӦ�����ʼ�ֽ�ƫ��
		IN��Len����ȡ�����ݵ��ֽ���
		IN��VarNo��������ţ�����������������ֵС��0�򲻹����洢����
		IN��RefreshFlag��ˢ�±�־������ֵΪtrueʱ����������������Զ����������ɵĽű�������
		���أ�
		��������������緢������������մ�
		**************************************/
	string RESP( int Pos, int Len, int VarNo = -1, bool RefreshFlag = true );
		/**************************************
		���ܣ����Ӽ��ܻ�
		���[CONNECTJMJ(DevType, IP, Port)]
		������
		IN��DevType����Ч�������ò��������κ����ã�����ȡֵΪ"0"
		IN��IP�����ܻ���IP��ַ��Ҫ�����IP��ַ�ı�д�淶����"192.168.0.1"
		IN��Port���˿ںţ���ֱ������ʮ���Ƶ���ֵ������"80"��ʾΪʮ������ֵ80��ȡֵ��Χ0-65535
		IN��RefreshFlag��ˢ�±�־������ֵΪtrueʱ����������������Զ����������ɵĽű�������
		���أ�
		��������������緢������������մ�
		**************************************/
	string CONNECTJMJ( string DevType, string IP, string Port, bool RefreshFlag = true );
		/**************************************
		���ܣ��رռ��ܻ�
		���[CLOSEJMJ]
		���أ�
		��������������緢������������մ�
		**************************************/
	string CLOSEJMJ(bool RefreshFlag = true);
		/**************************************
		���ܣ����ܻ�װ����Կ
		���[LOADKEY(CosManu, Stowage, KeyNo, PKeyNo, Keyfsjs, PKeyfsjs, Keyfsyz, PKeyfsyz, Comm, KeyHead, KeyLen, PKeyLen)]
		������
		IN��CosManu��COS���̣�0-����1-������3-���磬4-ͬ����5-���ƣ�6-��򿨣�7-���磬8-�����¿���20-ͨ�ð汾32K����
		IN��Stowage��װ�ط�ʽ��0-���ģ�1-���ģ�10-���ĸ��£�11-���ĸ���
		IN��KeyNo�����ܻ�������Կ����Կ��ַ����ֱ������ʮ�����Ƶ���ֵ������"173"��ʾ0x173
		IN��PKeyNo�����ܻ�������Կ��ID����ֱ������ʮ�����Ƶ���ֵ��
		IN��Keyfsjs��������Կ�ķ�ɢ��������ȡֵΪ"1"��"2"��"3"�����ű���������Ϊ"1"����ʱ���ɻ�
		IN��PKeyfsjs��������Կ�ķ�ɢ������һ��Ϊ"0"
		IN��Keyfsyz��������Կ�ķ�ɢ���ӣ�Ҫ�������16λ�ַ���ɣ���ֵҪ��ΪATRӦ���е������ֽ�����
		IN��PKeyfsyz��������Կ�ķ�ɢ���ӣ�һ��Ϊ�մ�
		IN��Comm��װ����Կ������ͷ��һ��Ҫ����10λ�ַ���ɣ���"00D4000018"
		IN��KeyHead��������Կ����Կͷ������Ҫ�����Ϊ2�ı���
		IN��KeyLen��������Կ���ֽڳ��ȣ�0-8�ֽڣ�1-16�ֽ�
		IN��PKeyLen��������Կ���ֽڳ��ȣ�0-8�ֽڣ�1-16�ֽ�
		IN��RefreshFlag��ˢ�±�־������ֵΪtrueʱ����������������Զ����������ɵĽű�������
		���أ�
		��������������緢������������մ�
		**************************************/
	string LOADKEY( string CosManu, string Stowage, string KeyNo, string PKeyNo, string Keyfsjs, string PKeyfsjs, string Keyfsyz, string PKeyfsyz, string Comm, string KeyHead, string KeyLen, string PKeyLen, bool RefreshFlag = true );
		/**************************************	
		���ܣ����ÿ���
		���[SETNAD(CardNad)]
		������
		IN��CardNad��������0-��������1-�Ͽ�����2-�ڿ���
		IN��RefreshFlag��ˢ�±�־������ֵΪtrueʱ����������������Զ����������ɵĽű�������
		���أ�
		��������������緢������������մ�
		**************************************/
	string SETNAD( string CardNad, bool RefreshFlag = true );
		/**************************************
		���ܣ��ⲿ��֤
		���[GERNERALEXTERNALAUTH(AuthType, DF, EF, KeyIndex, KeyVer, DivFactor, PSAMKeyType, PSAMorJMJKeyID, ConstKey, Flag)]
		������
		IN��AuthType����֤�ķ�ʽ��0-�̶���Կ��1-���ܻ���2-PSAM��
		IN��DF������֤��Կ����Ŀ¼��FID��������4λ�ַ���ɣ���ȡֵΪ"3F00"��"DDF1"��"DF01"�ȣ�����ѡ��Ŀ¼ΪADF�ļ����ű��ڲ������Զ���ѡ��SSSE�������ѡ��ָ����ADF
		IN��EF������֤��Կ����Ŀ¼�µ��ļ���������4λ�ַ���ɣ���ȡֵΪ"EF05"��"EF06"�ȣ�����ر�֤���ļ���ѡ�����򽫷��ش���
		IN��KeyIndex��������֤��Կ����Կ��־��Ҫ�������2λ�ַ���ɣ���"06"��"0A"��
		IN��KeyVer������֤��Կ����Կ�汾��Ҫ�������2λ�ַ���ɣ���ȡֵ��"00"��"01"��"02"��"03"
		IN��DivFactor����ɢ���ӣ�ʹ��PSAMʱ��ֵҪ�������48λ�ַ���ɣ���ʽΪ���������ӣ�����־��+�������ӣ��б�־��+һ�����ӣ�ʡ��־������ʹ�ü��ܻ�ʱҪ�������16λ�ַ���ɣ���ʽΪATRӦ�������ֽ�����
		IN��PSAMKeyType����Կ��;������ʹ��PSAMʱ��Ч��Ҫ�������2λ�ַ���ɣ���"27"��"48"��
		IN��PSAMorJMJKeyID��PSAM��Կ��־����ܻ���Կ��ַ��ʹ��PSAMʱҪ�������2λ�ַ���ɣ���"08"��"10"�ȣ�ʹ�ü��ܻ�ʱ��ֱ������ʮ�����Ƶ���ֵ������"173"��ʾ0x173
		IN��ConstKey���̶���Կֵ������ʹ�ù̶���Կʱ��Ч��Ҫ�������32λ�ַ����
		IN��Flag�����ݲ������;�Ĳ�����
		IN��RefreshFlag��ˢ�±�־������ֵΪtrueʱ����������������Զ����������ɵĽű�������
		���أ�
		��������������緢������������մ�
		ע�⣺
		����� DF �� EF ��ָ�����ļ�Ŀ¼�����Զ�ѡ�����ѡ����᷵�ش��󣬼�ʹ�� EF ѡ�񲻳ɹ�Ҳ�᷵�ش���
		**************************************/
	string GERNERALEXTERNALAUTH( string AuthType, string DF, string EF, string KeyIndex, string KeyVer, string DivFactor, string PSAMKeyType, string PSAMorJMJKeyID, string ConstKey, string Flag, bool RefreshFlag = true );
		/**************************************
		���ܣ����µ�������Դ���ע�⣺�Խű��ڲ�������ԣ�������Ա�����
		���BEGINGO
		������
		IN��RefreshFlag��ˢ�±�־������ֵΪtrueʱ����������������Զ����������ɵĽű�������
		���أ�
		��������������緢������������մ�
		������
		�� BEGINGO �� FINALGO �����䣬�����������飬�����Ǽ�������ִ�У�
		ע�⣺
		BEGINGO �� FINALGO ��ԵĽű��ڲ����򣬶������Ǳ��������������
		**************************************/
	string BEGINGO( bool RefreshFlag = true );
		/**************************************
		���ܣ���ֹBEGINGO����Ч��
		���FINALGO
		������
		IN��RefreshFlag��ˢ�±�־������ֵΪtrueʱ����������������Զ����������ɵĽű�������
		���أ�
		��������������緢������������մ�
		������
		�� BEGINGO �� FINALGO �����䣬�����������飬�����Ǽ�������ִ�У�
		ע�⣺
		�� FINALGO ���治�����ڴ˳��� BEGINGO �� FINALGO ��䣬����ű��ڲ����򽫻ᱨ����
		BEGINGO �� FINALGO ��ԵĽű��ڲ����򣬶������Ǳ��������������
		**************************************/
	string FINALGO( bool RefreshFlag = true );
		/**************************************
		���ܣ�ʹ�ü��ܻ���PSAM����MAC
		���[GETMAC(Type, Serial, DivFactor, DivType, KeyID, Radom, InitData, ProtectKey, GetRandom, Pad)]�� > VarNo ����ȫ�������š����е�����Ϊ��ѡ����
		������
		IN��Type���������ͣ�1-���ܻ�������֤�룬2-PSAM������֤�룬3-���ܻ���������Կ��4-PSAM����������Կ����֤��ָ���ǿ���ʶ�����е���֤�룩
		IN��Serial����δ���ã�����Ϊ"1"
		IN��DivFactor����ɢ���ӣ�ʹ��PSAMʱ��ֵҪ�������48λ�ַ���ɣ���ʽΪ���������ӣ�����־��+�������ӣ��б�־��+һ�����ӣ�ʡ��־������ʹ�ü��ܻ�ʱҪ�������16λ�ַ���ɣ���ʽΪATRӦ�������ֽ�����
		IN��DivType��PSAM����Կ��;������ʹ��PSAM��ʱ��Ч��Ҫ�������2λ�ַ���ɣ���"27"��"48"��
		IN��KeyID��PSAM��Կ��־����ܻ���Կ��ַ��ʹ��PSAMʱҪ�������2λ�ַ���ɣ���"08"��"10"�ȣ�ʹ�ü��ܻ�ʱ��ֱ������ʮ�����Ƶ���ֵ������"173"��ʾ0x173
		IN��Radom����ʼ������������ GetRandom ����Ϊ 0 ʱ��Ч�������Զ�ȡ�����������ЧʱҪ�������16λ�ַ����
		IN��InitData�������MAC�����ݣ�����Ҫ�����Ϊ2�ı���
		IN��ProtectKey�����ܻ�������Կ��һ��Ϊ"1"
		IN��GetRandom��ȡ�������־������ֵ��Ϊ 0 ʱ��ʾ���Զ�ȡ�������Ϊ��ʼ����������������ȡ�����������ֵ��Ϊ"1"
		IN��Pad������β������δ��ȫŪ����ò��������ã�InitData��β������Ӧ����"8000..."�𣿻��������Զ�ȡ�����ʱ��β����������Ϊ"00000000"
		IN��VarNo��������ţ�����������������ֵС��0�򲻹����洢����
		IN��RefreshFlag��ˢ�±�־������ֵΪtrueʱ����������������Զ����������ɵĽű�������
		���أ�
		��������������緢������������մ�
		**************************************/
	string GETMAC( string Type, string Serial, string DivFactor, string DivType, string KeyID, string Radom, string InitData, string ProtectKey, string GetRandom, string Pad, int VarNo = -1, bool RefreshFlag = true );
		/**************************************
		���ܣ��˷�����
		���[PRODUCT(Par1, Par2)]�� > VarNo ����ȫ�������š����е�����Ϊ��ѡ����
		������
		IN��Par1������1����ֱ������ʮ���Ƶ���ֵ������"100"��ʾʮ������ֵ100
		IN��Par2������2����ֱ������ʮ���Ƶ���ֵ������"100"��ʾʮ������ֵ100
		IN��VarNo��������ţ�����������������ֵС��0�򲻹����洢����
		IN��RefreshFlag��ˢ�±�־������ֵΪtrueʱ����������������Զ����������ɵĽű�������
		���أ�
		��������������緢������������մ�
		������
		�������� Par1 �� Par2 ��˵Ľ�������Ϊʮ���Ƶ���ֵ����������Է��ش����������'0'����
		**************************************/
	string PRODUCT( string Par1, string Par2, int VarNo = -1, bool RefreshFlag = true );
		/**************************************
		���ܣ�ʮ������ֵ��ת����ʮ��������ֵ��
		���[HEX(Decimal)]�� > VarNo ����ȫ�������š����е�����Ϊ��ѡ����
		������
		IN��Decimal����ת����ʮ������ֵ������"100"����ʾʮ���Ƶ���ֵ100
		IN��VarNo��������ţ�����������������ֵС��0�򲻹����洢����
		IN��RefreshFlag��ˢ�±�־������ֵΪtrueʱ����������������Զ����������ɵĽű�������
		���أ�
		��������������緢������������մ�
		������
		�����ʮ��������ֵ���̶�Ϊ8λ����������������߲�0��������������ȡ���ұߵ�8λ��
		����ʮ������ֵ������Ϊ������������"-1"�������"FFFFFFFF"������"-3"�������"FFFFFFFD"��
		**************************************/
	string HEX( string Decimal, int VarNo = -1, bool RefreshFlag = true );
		/**************************************
		���ܣ�ʮ��������ֵ��ת����ʮ������ֵ��
		���[DHEX(Hexadecimal)]�� > VarNo ����ȫ�������š����е�����Ϊ��ѡ����
		������
		IN��Hexadecimal����ת����ʮ��������ֵ������"1AB"����ʾʮ���Ƶ���ֵ0x1AB����������Ϊ8λ
		IN��VarNo��������ţ�����������������ֵС��0�򲻹����洢����
		IN��RefreshFlag��ˢ�±�־������ֵΪtrueʱ����������������Զ����������ɵĽű�������
		���أ�
		��������������緢������������մ�
		������
		�����ʮ�����ƴ�������������8λ������������ű��ڲ������Զ���ȡ����8λ��
		���������ȡ��ģ�������ֵ�պ�Ϊ8λ���������λ��ֵ���ڵ���'8'������������Ϊ�������������������е��з�����������
		**************************************/
	string DHEX( string Hexadecimal, int VarNo = -1, bool RefreshFlag = true );
		/**************************************
		���ܣ�ʮ������ֵ��ת����ʮ��������ֵ��
		���[EX_HEX(Decimal, Len)]�� > VarNo ����ȫ�������š����е�����Ϊ��ѡ����
		������
		IN��Decimal����ת����ʮ������ֵ������"100"����ʾʮ���Ƶ���ֵ100
		IN��Len��Ҫ�����ʮ��������ֵ������Сλ�������ʵ��λ��С�ڸ�ֵ������߲�0��������ڸ�ֵ�������κδ���
		IN��VarNo��������ţ�����������������ֵС��0�򲻹����洢����
		IN��RefreshFlag��ˢ�±�־������ֵΪtrueʱ����������������Զ����������ɵĽű�������
		���أ�
		��������������緢������������մ�
		������
		����ʮ������ֵ������Ϊ������������"-1"�������"FFFFFFFF"������"-3"�������"FFFFFFFD"��
		ע�⣺
		���ת�����ò�δ�� Len ������������ʮ��������ֵ����λ���Ѿ�������8λ���ű��ڲ����򽫻��Զ���ȡ����8λ��Ȼ��Ÿ��� Len ������������
		**************************************/
	string EX_HEX( string Decimal, string Len, int VarNo = -1, bool RefreshFlag = true );
		/**************************************
		���ܣ����ַ�������
		���[LEN(Data)]�� > VarNo ����ȫ�������š����е�����Ϊ��ѡ����
		������
		IN��Data�����󳤶ȵ��ַ���
		IN��VarNo��������ţ�����������������ֵС��0�򲻹����洢����
		IN��RefreshFlag��ˢ�±�־������ֵΪtrueʱ����������������Զ����������ɵĽű�������
		���أ�
		��������������緢������������մ�
		������
		��ȡ�ַ����ĳ��ȣ���"12345678"������8��������ֵ����ʮ����������ʾ
		���棺
		˵���ĵ���ע������������ȡ�ַ������ֽ�������ʵ����֤ȴ���ַ��ص����ַ�����
		**************************************/
	string LEN( string Data, int VarNo = -1, bool RefreshFlag = true );
		/**************************************
		���ܣ���ȡϵͳʱ��
		���[GETTIME(Format, RFU)]�� > VarNo ����ȫ�������š����е�����Ϊ��ѡ����
		������
		IN��Format����ʽ���Ʋ�����1-��yyyy-MM-dd hh:mm:ss����2-��yyyyMMddhhmmss����3-��yyyy-MM-dd����4-��yyyyMMdd��
		IN��RFU��Ԥ����������δ����
		IN��VarNo��������ţ�����������������ֵС��0�򲻹����洢����
		IN��RefreshFlag��ˢ�±�־������ֵΪtrueʱ����������������Զ����������ɵĽű�������
		���أ�
		��������������緢������������մ�
		������
		�ڽű��ڲ������У�ֻҪ��ʽ���Ʋ�����ֵ�������оٵ�1-4������ʹ��4�ĸ�ʽ
		**************************************/
	string GETTIME( string Format, string RFU, int VarNo = -1, bool RefreshFlag = true );
		/**************************************
		���ܣ���������
		���[SUBTRACT(Minuend, Subtrahend)]�� > VarNo ����ȫ�������š����е�����Ϊ��ѡ����
		������
		IN��Minuend����������������ʮ������ֵ������"100"��ʾʮ������ֵ100
		IN��Subtrahend��������������ʮ������ֵ������"100"��ʾʮ������ֵ100
		IN��VarNo��������ţ�����������������ֵС��0�򲻹����洢����
		IN��RefreshFlag��ˢ�±�־������ֵΪtrueʱ����������������Զ����������ɵĽű�������
		���أ�
		��������������緢������������մ�
		������
		����Ľ��Ϊʮ������ֵ�������Ҳ������κ�λ����չ����
		**************************************/
	string SUBTRACT( string Minuend, string Subtrahend, int VarNo = -1, bool RefreshFlag = true );
		/**************************************
		���ܣ�������Ϣ
		���[RETURN(......)]
		������
		IN��KeyType����ʶ�ű���ʹ����Կ�����ͣ�0-�̶���Կ��1-���ܻ���2-PSAM��
		IN��RefreshFlag��ˢ�±�־������ֵΪtrueʱ����������������Զ����������ɵĽű�������
		���أ�
		��������������緢������������մ�
		������
		��ʹ�� RETURN_Value_Add �������������������Ϣ
		**************************************/
	string RETURN( int KeyType, bool RefreshFlag = true );
		/**************************************
		���ܣ����ӷ�����Ϣ
		������
		IN��Tag�������Ϣ�ı�ǩ
		IN��VarNo��������������ڵı������
		IN��Format����ʽ������0-��������1-an��ʽ��2-cn��ʽ��3-ǰ��0����ֵ����Ϊ0�򷵻�0����4-��F����ֵ����Ϊ0�򷵻�0����5--ǰ��0����ֵ����Ϊ0�򷵻ؿմ�����6-��F����ֵ����Ϊ0�򷵻ؿմ���
		������
		�ɶ�ε��ø÷��������Ӷ�����Ϣ����ִ�� RETURN ��������󻺴���Զ���ա�
		**************************************/
	void RETURN_Value_Add( string Tag, int VarNo, int Format );



private:
	class CReturnValue
	{
	public:
		string Tag;
		int VarNo;
		int ForMat;
	};
	vector<CReturnValue> RetValue;

	CInformation *const Info;

	bool ErrFlag;				//�����־���������ʧ�ܺ�ñ�־���ᱻ��Ϊtrue
	bool ErrCheckFlag;			//�������־������ֵΪtrueʱ����������ʱ��������������������ܻ�ʹһ����������ɹ���������Ҫ�뽫��ֵ��Ϊfalse
	string Style_FuntionName;	//�ں�������������ǰҪ���ӵ��ַ��������ӿո�[ATR (9,8)]>1����һ����Ը�ֵֻ��ȡֵΪ�մ�""��һ���ո��ַ�" "
	string Style_Comma;			//�ں��������б��Ķ��ź�Ҫ���ӵ��ַ��������ӿո�[ATR(9, 8)]>1����һ����Ը�ֵֻ��ȡֵΪ�մ�""��һ���ո��ַ�" "
	string Style_Assignment;	//�ڱ�����ֵ��>��ǰ��Ҫ���ӵ��ַ��������ӿո�[ATR(9,8)] > 1����һ����Ը�ֵֻ��ȡֵΪ�մ�""��һ���ո��ַ�" "
	stringstream sstr;			//���ڹ�������
	stringstream serr;			//�����齨������Ϣ

		/**************************************
		���ܣ����ô����ʶ
		�������������ʶ��Ϊtrue��������Stream�Ļ���
		**************************************/
	void Set_Error_Flag();//���ô����ʶ
		/**************************************
		���ܣ��������Ƿ���ȷ
		������
		IN��Data�������Ĳ���
		IN��Len����Data�в�������������ʱ�������������ַ��Ƿ���ϸ�ֵ��Ҫ�������ֵΪ0����Data���ַ��Ƿ�Ϊż���������ֵС��0�򲻶��������
		���أ�
		true�����ͨ��
		false�����ʧ��
		����о٣�
		A��Data���г����������ʣ�����ݺ��зǷ��ַ������� false;
		B��Data���г����������ʣ�����ݲ����Ƿ��ַ������� true;
		C��Data��������������������к��зǷ��ַ������� false;
		D��Data��������������������в����Ƿ��ַ�������LenֵС��0������ true;
		E��Data��������������������в����Ƿ��ַ�������Lenֵ����0��Data����Ч�ַ���ĿΪż�������� true;
		F��Data��������������������в����Ƿ��ַ�������Lenֵ����0��Data����Ч�ַ���ĿΪ���������� false;
		G��Data��������������������в����Ƿ��ַ�������Lenֵ����0��Data����Ч�ַ���Ŀ������Lenֵ������ false;
		H��Data��������������������в����Ƿ��ַ�������Lenֵ����0��Data����Ч�ַ���Ŀ����Lenֵ������ true;
		�������������ʶ��Ϊtrue��������Stream�Ļ���
		**************************************/
	bool CheckData(string Data, int Len);

};


#endif//COMMAND_H