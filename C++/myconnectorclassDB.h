#pragma once
#include "mysql.h"
#include "afxwin.h"
//#include "my_global.h"

class myconnectorclassDB
{
private:
#define SERVER "db.tecnico.ulisboa.pt"
#define USER "ist181762" // Your IST number
#define PASSWORD "pgir7625" // NOT IST password
#define DATABASE "ist181762" // Your IST number

	void QueryPlate(CString queryPlate);
	void QueryBrand(CString queryBrand); 
	void QueryModel(CString queryModel); 
	void QueryColor(CString queryColor);
	void QueryAuto(CString queryAuto);
	void QueryFuel(CString queryFuel);

	MYSQL* connection; // Pointer allocation for a connection
		// This is an object creation of an existing class in
		// the mySQL libraries we added.

public:
	MYSQL_ROW row; // Another object based on the existing
	// library, this one stores a single row from queries
	MYSQL_RES* result; // and this one the entire result
	// from a query
	void connect(); // Connection function. Notice how
	// this is public, but the connection itself is
	// private.
	CString CPtoUnicode(const char* CPString, UINT CodePage);
	// Converts data from MySQL format to MFC's CString.
	// My Queries
	CString CheckPlate(CString nome, CString ano);
	CString CheckBrand(CString nome, CString ano);
	CString CheckModel(CString nome, CString ano);
	CString CheckColor(CString nome, CString ano);
	CString CheckAuto(CString nome, CString ano);
	CString CheckFuel(CString nome, CString ano);
	myconnectorclassDB(void);
	virtual ~myconnectorclassDB(void);
};



