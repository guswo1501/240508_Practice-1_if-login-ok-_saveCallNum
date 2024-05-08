// 로그인 성공 시 전화번호 저장하기

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;



int main()
{
	// 파일 읽어오기
	ifstream Read_file("member.txt");

	// 위의 파일 내부 내용을 읽어오기 위해서는 따로 작업이 필요
	string line;
	string ID;
	string PW;
	string TEL;
	string logInfo;		//ID,PW를 저장할 변수 (공백을 기준으로 구분함)
	vector<string> members;
	vector<string> logInfo_vector;

	while (getline(Read_file, line))
	{
		members.push_back(line);
	}

	Read_file.close();

	// 이름, 비밀번호 입력 받기

	cout << endl;
	cout << "이름, 비밀번호 순으로 입력을 넣어주세요 ";
	getline(cin, logInfo);		// getline을 사용해서 공백을 기준으로 2개의 입력을 받음
	
	istringstream iss(logInfo);
	string token;
	while (iss >> token)
	{
		logInfo_vector.push_back(token);		// 이렇게 하면 getline을 통해 한 번에 받은 2개의 입력을 나눠서 logInfo_vector에 원소로 0번 인덱스부터 채워짐
	}

	

	// 매칭 결과를 저장할 배열 선언

	string saveResult[3];

	// 매칭 결과 저장
	for (int i = 0; i < 3; i++)
	{
		if (members[i] != logInfo)
		{
			saveResult[i] = "로그인 실패";
		}

		if (members[i] == logInfo)
		{
			saveResult[i] = "로그인 성공";
		}
	}

	// 매칭 결과 확인

	int cnt = 0;

	ofstream write_file("member_tel.txt");

	while (1)
	{
		if (saveResult[cnt] == "로그인 성공")
		{
			cout << "로그인 성공" << endl;
			
			cout << "전화번호 입력해주세요  ";
			cin >> TEL;

			
			write_file << logInfo_vector[0] << "  " << TEL;

			break;
		}

		else if (saveResult[cnt] != "로그인 성공")
		{
			if (cnt == 2)
			{
				cout << "로그인 실패" << endl;
				break;
			}
			else
				cnt++;
		}


	}

	write_file.close();


	// 새로운 사람이 로그인 하는 상황
	

	// 이름, 비밀번호 입력 받기

	cout << endl;
	cout << "이름, 비밀번호 순으로 입력을 넣어주세요 ";
	getline(cin, logInfo);		// getline을 사용해서 공백을 기준으로 2개의 입력을 받음

	istringstream iss(logInfo);
	string token;
	while (iss >> token)
	{
		logInfo_vector.push_back(token);		// 이렇게 하면 getline을 통해 한 번에 받은 2개의 입력을 나눠서 logInfo_vector에 원소로 0번 인덱스부터 채워짐
	}



	// 매칭 결과를 저장할 배열 선언

	string saveResult[3];

	// 매칭 결과 저장
	for (int i = 0; i < 3; i++)
	{
		if (members[i] != logInfo)
		{
			saveResult[i] = "로그인 실패";
		}

		if (members[i] == logInfo)
		{
			saveResult[i] = "로그인 성공";
		}
	}

	// 매칭 결과 확인

	int cnt = 0;

	ifstream New_logInfo("member_tel.txt");

	ofstream saved_newLogInfo("member_tel.txt");
	while (1)
	{
		if (saveResult[cnt] == "로그인 성공")
		{
			cout << "로그인 성공" << endl;

			cout << "전화번호 입력해주세요  ";
			cin >> TEL;

			
			New_logInfo << logInfo_vector[0] << "  " << TEL;

			break;
		}

		else if (saveResult[cnt] != "로그인 성공")
		{
			if (cnt == 2)
			{
				cout << "로그인 실패" << endl;
				break;
			}
			else
				cnt++;
		}


	}

	New_logInfo.close();


	system("pause");
}


