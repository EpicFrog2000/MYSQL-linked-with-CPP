#include <mysql.h>
#include <iostream>
#include <string>
#include <iostream>
#include <sstream>
using namespace std;

int main()
{	
	int qstate;
	const char* za;
	
	MYSQL* conn; /* pointer to connection handler */
	MYSQL_ROW row;
	MYSQL_RES *res; /* holds the result set */
	conn = mysql_init(NULL);/* INITIALIZE CONNECTION HANDLER, DO NOT CHANGE */
	conn = mysql_real_connect(conn, "localhost", "root", "Koperek28", "testdb", 3306, NULL, 0);/* THIS CONNECTS TO SERVER, */
										 // change "Koperek28" to your password and "testdb" to your db name
	signed short int choice;
	string id;
	string name;
	string quer;
	string score;
	string del;
	//clearing strings to help later with looping main();
	id.clear();
	name.clear();
	quer.clear();
	score.clear();
	score.clear();
	del.clear();

	cout << "1. insert" << endl << "2. view" << endl << "3. delete" << endl << "4. custom query" << endl << "5. clear console" << endl << "6. exit" << endl;
	cin >> choice;
	switch (choice)
	{
	case 1:
		cout << "id:";
		cin >> id;
		cout << "name:";
		cin >> name;
		cout << "score:";
		cin >> score;	//change values to matching your table
		quer = "INSERT INTO test (id, name, score) VALUES (" + id + ", '" + name + "', " + score + ");";
		cout << quer << endl;
		za = quer.c_str();
			mysql_query(conn, za);
			cout << mysql_error(conn);
			cout << endl;
			main();
		break;
	case 2:
		if (conn)
		{
			string query = "SELECT * FROM test"; // change test for your table name
			const char* q = query.c_str();
			qstate = mysql_query(conn, q);
			if (!qstate)
			{
				res = mysql_store_result(conn);
				while (row = mysql_fetch_row(res))
				{
					printf("ID: %s, Name: %s Value: %s\n", row[0], row[1], row[2]);
					
				}
				cout << endl;
			}
			else
			{
				cout << "failed quary: " << mysql_error(conn) << endl;
				cout << endl;
			}
		}
		else
		{
			puts("failed to connect to db");
			cout << endl;
		}
		main();
		break;
	case 3:
		if (conn)
		{
			cout << "DELETE FROM test WHERE " << endl;
			cin.ignore();
			getline(cin, del); // example: id = 5;
			quer = "DELETE FROM test WHERE " + del;
			cout << quer << endl;
			za = quer.c_str();
			qstate = mysql_query(conn, za);
			if (!qstate)
			{
				mysql_query(conn, za);
				cout << mysql_error(conn);
				cout << endl;
				main();
			}
			else
			{
				cout << "failed quary: " << mysql_error(conn) << endl;
				cout << endl;
				main();
			}
			break;
		}
		else
		{
			puts("failed to connect to db");
			cout << endl;
		}
	case 4:
		if (conn)
		{
			cout << "write querry: " << endl; //select deos not work here
			cin.ignore();
			getline(cin, quer);
			cout << quer << endl;
			za = quer.c_str();
			qstate = mysql_query(conn, za);
			if (!qstate)
			{
				mysql_query(conn, za);
				cout << mysql_error(conn) << endl;
				cout << endl;
				main();
			}
			else
			{
				cout << "failed quary: " << mysql_error(conn) << endl;
				cout << endl;
				main();
			}
			break;
		}
		else
		{
			puts("failed to connect to db");
			cout << endl;
		}
	case 5:
		system("cls");
		main();
		break;
	case 6:
		return 0;
		break;

	default:
		break;
	}
	mysql_close(conn);
return 0;
}
