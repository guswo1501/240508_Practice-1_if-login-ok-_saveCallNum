// �α��� ���� �� ��ȭ��ȣ �����ϱ�

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;



int main()
{
	// ���� �о����
	ifstream Read_file("member.txt");

	// ���� ���� ���� ������ �о���� ���ؼ��� ���� �۾��� �ʿ�
	string line;
	string ID;
	string PW;
	string TEL;
	string logInfo;		//ID,PW�� ������ ���� (������ �������� ������)
	vector<string> members;
	vector<string> logInfo_vector;

	while (getline(Read_file, line))
	{
		members.push_back(line);
	}

	Read_file.close();

	// �̸�, ��й�ȣ �Է� �ޱ�

	cout << endl;
	cout << "�̸�, ��й�ȣ ������ �Է��� �־��ּ��� ";
	getline(cin, logInfo);		// getline�� ����ؼ� ������ �������� 2���� �Է��� ����
	
	istringstream iss(logInfo);
	string token;
	while (iss >> token)
	{
		logInfo_vector.push_back(token);		// �̷��� �ϸ� getline�� ���� �� ���� ���� 2���� �Է��� ������ logInfo_vector�� ���ҷ� 0�� �ε������� ä����
	}

	

	// ��Ī ����� ������ �迭 ����

	string saveResult[3];

	// ��Ī ��� ����
	for (int i = 0; i < 3; i++)
	{
		if (members[i] != logInfo)
		{
			saveResult[i] = "�α��� ����";
		}

		if (members[i] == logInfo)
		{
			saveResult[i] = "�α��� ����";
		}
	}

	// ��Ī ��� Ȯ��

	int cnt = 0;

	ofstream write_file("member_tel.txt");

	while (1)
	{
		if (saveResult[cnt] == "�α��� ����")
		{
			cout << "�α��� ����" << endl;
			
			cout << "��ȭ��ȣ �Է����ּ���  ";
			cin >> TEL;

			
			write_file << logInfo_vector[0] << "  " << TEL;

			break;
		}

		else if (saveResult[cnt] != "�α��� ����")
		{
			if (cnt == 2)
			{
				cout << "�α��� ����" << endl;
				break;
			}
			else
				cnt++;
		}


	}

	write_file.close();


	// ���ο� ����� �α��� �ϴ� ��Ȳ
	

	// �̸�, ��й�ȣ �Է� �ޱ�

	cout << endl;
	cout << "�̸�, ��й�ȣ ������ �Է��� �־��ּ��� ";
	getline(cin, logInfo);		// getline�� ����ؼ� ������ �������� 2���� �Է��� ����

	istringstream iss(logInfo);
	string token;
	while (iss >> token)
	{
		logInfo_vector.push_back(token);		// �̷��� �ϸ� getline�� ���� �� ���� ���� 2���� �Է��� ������ logInfo_vector�� ���ҷ� 0�� �ε������� ä����
	}



	// ��Ī ����� ������ �迭 ����

	string saveResult[3];

	// ��Ī ��� ����
	for (int i = 0; i < 3; i++)
	{
		if (members[i] != logInfo)
		{
			saveResult[i] = "�α��� ����";
		}

		if (members[i] == logInfo)
		{
			saveResult[i] = "�α��� ����";
		}
	}

	// ��Ī ��� Ȯ��

	int cnt = 0;

	ifstream New_logInfo("member_tel.txt");

	ofstream saved_newLogInfo("member_tel.txt");
	while (1)
	{
		if (saveResult[cnt] == "�α��� ����")
		{
			cout << "�α��� ����" << endl;

			cout << "��ȭ��ȣ �Է����ּ���  ";
			cin >> TEL;

			
			New_logInfo << logInfo_vector[0] << "  " << TEL;

			break;
		}

		else if (saveResult[cnt] != "�α��� ����")
		{
			if (cnt == 2)
			{
				cout << "�α��� ����" << endl;
				break;
			}
			else
				cnt++;
		}


	}

	New_logInfo.close();


	system("pause");
}


