#include<iostream>
#include<string>


using namespace std;


int CRC(string message)
{
	int control_sum = 0;
	if (message.size() % 2 != 0)
	{
		message += 's';
	}

	for (int i = 0; i < message.size(); i+=2)
	{
		//getting new value
		int mult = message[i] * message[i + 1];
		int div = message[i] / message[i + 1];

		//adding to control sum
		control_sum += mult;
		control_sum += div;
	}
	return control_sum;
}

void main()
{
	string message;
	bool flag = false;
	string got_message;
	int CRC_OF_getted_M;
	int CRC_OF_sended_M;
	
	do
	{
		cout << "Enter message to send: ";
		getline(std::cin, message);
		
		cout << endl << "-----------------------------------------------------------------------" << endl;
		CRC_OF_sended_M = CRC(message);


		cout << "Control sum is: " << CRC_OF_sended_M << endl;
		cout << endl << "-----------------------------------------------------------------------" << endl;

		cout << "Enter what message you got to check control sum: ";
		getline(std::cin, got_message);
		cout <<endl<< "-----------------------------------------------------------------------" << endl;
		

		CRC_OF_getted_M = CRC(got_message);

		cout << "Control sum of getted message: " << CRC_OF_getted_M << endl;
		cout << endl << "-----------------------------------------------------------------------" << endl;

		if (CRC_OF_getted_M == CRC_OF_sended_M)
		{
			cout << "Message successfully recieved (Completely)!!!" << endl;
			cout << endl << "-----------------------------------------------------------------------" << endl;
		}
		else
		{
			cout << "CRC of the message is not correct (Please ask to get message again)!!! " << endl;
			cout << endl << "-----------------------------------------------------------------------" << endl;
		}

	} while (!flag);



	

	
	
}