#include <mysql.h>
#include <iostream>
#include <string>
#include <iostream>
using namespace std;
string Tname = "test";
int main()
{	
	int qstate;
	const char* za;
	
	
	MYSQL* conn; /* pointer to connection handler */
	MYSQL_ROW row;
	MYSQL_RES *res; /* holds the result set */
	conn = mysql_init(NULL);/* INITIALIZE CONNECTION HANDLER, DO NOT CHANGE */
	conn = mysql_real_connect(conn, "localhost", "root", "", "testdb", 3306, NULL, 0);/* THIS CONNECTS TO SERVER, */
										 // change "testdb" to your db name
	signed short int choice;
	string id;
	string name;
	string quer;
	string score;
	string del;
	string NewTableName;
	string column;
	string datatype;
	string values;
	string variables;
	
	//clearing strings to help later with looping main();
	id.clear();
	name.clear();
	quer.clear();
	score.clear();
	score.clear();
	del.clear();
	NewTableName.clear();
	datatype.clear();
	column.clear();
	values.clear();
	variables.clear();
	//XD
	cout << "0. show databases" << endl << "1.switch table ('test' is set by default)" << endl << "2. insert to table" << endl <<
		"3. viev all in table" << endl << "4. delete from table" << endl << "5. custom query" << endl << "6. clear console" <<
		endl << "7. exit" << endl << "8. add table to db" << endl << "9. viev all tables" << endl <<
		"10. alter table" << endl;
	// Just use option 5 xd
	cin >> choice;
	switch (choice)
	{
	case 0:
		quer = "SHOW DATABASES;";
		za = quer.c_str();
		mysql_query(conn, za);
		cout << mysql_error(conn) << endl;
		cout << endl;
		res = mysql_store_result(conn);
		cout << "DATABASES: " << endl;
		cout << "+-----------------------" << endl;
		while (row = mysql_fetch_row(res))
		{
			cout << "| " << *row << endl;
			cout << "+-----------------------" << endl;
		}
		main();
		break;
	case 1:
		cout << "current table: "+Tname << endl;
		cout << "type in table name: " << endl;
		cin >> Tname;
		cout << endl;
		cin.ignore();
		main();
		break;
	case 2:
		cout << "Enter table name";
		cin >> Tname;
		cout << "values:";
		cin >> values;
		cout << "variables:";
		cin >> variables;
		quer = "INSERT INTO " + Tname + " ("+values+") VALUES (" + variables + ");";
		cout << quer << endl;
		za = quer.c_str();
			mysql_query(conn, za);
			cout << mysql_error(conn);
			cout << endl;
			main();
		break;
	case 3:
		if (conn)
		{
			string query = "SELECT * FROM "+ Tname; // change test for your table name
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
	case 4:
		if (conn)
		{
			cout << "DELETE FROM " + Tname + " WHERE " << endl;
			cin.ignore();
			getline(cin, del); // example: id = 5;
			quer = "DELETE FROM " + Tname + " WHERE " + del;
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
	case 5:
		if (conn)
		{
			cout << "write querry: " << endl; //select deos not work here
			cin.ignore();
			getline(cin, quer);
			cout << quer << endl;
			za = quer.c_str();
				mysql_query(conn, za);
				cout << mysql_error(conn) << endl;
				cout << endl;
				main();
			break;
		}
		else
		{
			puts("failed to connect to db");
			cout << endl;
		}
	case 6:
		system("cls");
		main();
		break;
	case 7:
		return 0;
		break;
	case 8:
		cout << "Enter New table name: " << endl;
		cin >> NewTableName;
		cout << "Enter New column name: " << endl;
		cin >> column;
		cout << "Enter New datatype name: " << endl;
		cin >> datatype;
		quer = "CREATE TABLE " + NewTableName + "(" + column + " " + datatype+ " );";
		cout << quer << endl;
		za = quer.c_str();
		mysql_query(conn, za);
		cout << mysql_error(conn);
		cout << endl;
		main();
		break;
	case 9:
		quer = "SHOW TABLES;";
		cout << quer << endl;
		za = quer.c_str();
		mysql_query(conn, za);
		cout << mysql_error(conn);
		cout << endl;
		res = mysql_store_result(conn);
		cout << "TABLES: " << endl;
		cout << "+-----------------------" << endl;
		while (row = mysql_fetch_row(res))
		{
			cout << "| " << *row << endl;
			cout << "+-----------------------" << endl;
		}
		main();
		break;

	case 10:
		if (conn)
		{
			cout << "ALTER TABLE " << endl; //select deos not work here
			cin.ignore();
			getline(cin, quer);
			quer = "ALTER TABLE " + quer;
			cout << quer << endl;
			za = quer.c_str();
				mysql_query(conn, za);
				cout << mysql_error(conn) << endl;
				cout << endl;
				main();

			break;
		}
		else
		{
			puts("failed to connect to db");
			cout << endl;
		}
		break;
	default:
		break;
	}
	mysql_close(conn);
return 0;
}
