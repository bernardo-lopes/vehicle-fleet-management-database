#include "pch.h"
#include "myconnectorclassDB.h"

myconnectorclassDB::myconnectorclassDB()
{
}
myconnectorclassDB::~myconnectorclassDB()
{
}

void myconnectorclassDB::connect(void)
{
	CString message;

	connection = mysql_init(NULL); //Initialise the instance
	connection = mysql_real_connect(connection, SERVER, USER, PASSWORD, DATABASE, 0, NULL, 0);
	// The command mysql_real_connect is included in the
	// libraries
	/*if (connection == NULL) {
		message.Format(_T("Unable to connect!"));
		AfxMessageBox(message);

	}
	else {
		message.Format(_T("Connection successful!"));
		AfxMessageBox(message);
	}*/
}

CString myconnectorclassDB::CheckPlate(CString nome, CString ano)
{
	CString value; // Create the object to receive the answer to the query
	CString queryPlate = _T("SELECT atribuicao.matricula FROM atribuicao inner join colaborador on colaborador.id = atribuicao.id where colaborador.nome = '") + nome + _T("' AND atribuicao.ano = '") + ano + _T("'");
			//Create a query by combining CStrings, including an
			//input CString
			QueryPlate(queryPlate); // Pass the query. The result will be
			//stored in the result object.
	while ((row = mysql_fetch_row(result)) != NULL)
		// Method to fetch rows from result
	{
		value = CPtoUnicode(row[0], 1251);
	}
	return value;
}
// CAST AS DECIMAL(9, 2))

CString myconnectorclassDB::CheckBrand(CString nome, CString ano)
{
	CString value; // Create the object to receive the answer to the query
	CString queryBrand = _T("SELECT marca from (viatura INNER JOIN atribuicao ON viatura.matricula = atribuicao.matricula) INNER JOIN colaborador ON atribuicao.id = colaborador.id WHERE colaborador.nome = '") + nome + _T("' AND atribuicao.ano = '") + ano + _T("'");

	//Create a query by combining CStrings, including an
	//input CString
	QueryBrand(queryBrand); // Pass the query. The result will be
	//stored in the result object.
	while ((row = mysql_fetch_row(result)) != NULL)
		// Method to fetch rows from result
	{
		value = CPtoUnicode(row[0], 1251);
	}
	return value;
}

CString myconnectorclassDB::CheckModel(CString nome, CString ano)
{
	CString value; // Create the object to receive the answer to the query
	CString queryModel = _T("SELECT modelo from (viatura INNER JOIN atribuicao ON viatura.matricula = atribuicao.matricula) INNER JOIN colaborador ON atribuicao.id = colaborador.id WHERE colaborador.nome = '") + nome + _T("' AND atribuicao.ano = '") + ano + _T("'");

	//Create a query by combining CStrings, including an
	//input CString
	QueryModel(queryModel); // Pass the query. The result will be
	//stored in the result object.
	while ((row = mysql_fetch_row(result)) != NULL)
		// Method to fetch rows from result
	{
		value = CPtoUnicode(row[0], 1251);
	}
	return value;
}

CString myconnectorclassDB::CheckColor(CString nome, CString ano)
{
	CString value; // Create the object to receive the answer to the query
	CString queryColor = _T("SELECT cor from (viatura INNER JOIN atribuicao ON viatura.matricula = atribuicao.matricula) INNER JOIN colaborador ON atribuicao.id = colaborador.id WHERE colaborador.nome = '") + nome + _T("' AND atribuicao.ano = '") + ano + _T("'");

	//Create a query by combining CStrings, including an
	//input CString
	QueryColor(queryColor); // Pass the query. The result will be
	//stored in the result object.
	while ((row = mysql_fetch_row(result)) != NULL)
		// Method to fetch rows from result
	{
		value = CPtoUnicode(row[0], 1251);
	}
	return value;
}

CString myconnectorclassDB::CheckAuto(CString nome, CString ano)
{
	CString value; // Create the object to receive the answer to the query
	CString queryAuto = _T("SELECT transmissao from (viatura INNER JOIN atribuicao ON viatura.matricula = atribuicao.matricula) INNER JOIN colaborador ON atribuicao.id = colaborador.id WHERE colaborador.nome = '") + nome + _T("' AND atribuicao.ano = '") + ano + _T("'");

	//Create a query by combining CStrings, including an
	//input CString
	QueryAuto(queryAuto); // Pass the query. The result will be
	//stored in the result object.
	while ((row = mysql_fetch_row(result)) != NULL)
		// Method to fetch rows from result
	{
		value = CPtoUnicode(row[0], 1251);
	}
	return value;
}

CString myconnectorclassDB::CheckFuel(CString nome, CString ano)
{
	CString value; // Create the object to receive the answer to the query
	CString queryFuel = _T("SELECT combustivel from (viatura INNER JOIN atribuicao ON viatura.matricula = atribuicao.matricula) INNER JOIN colaborador ON atribuicao.id = colaborador.id WHERE colaborador.nome = '") + nome + _T("' AND atribuicao.ano = '") + ano + _T("'");

	//Create a query by combining CStrings, including an
	//input CString
	QueryFuel(queryFuel); // Pass the query. The result will be
	//stored in the result object.
	while ((row = mysql_fetch_row(result)) != NULL)
		// Method to fetch rows from result
	{
		value = CPtoUnicode(row[0], 1251);
	}
	return value;
}

void myconnectorclassDB::QueryPlate(CString queryPlate)
{
	wchar_t* p = queryPlate.GetBuffer();
	char bufUTF8[MAX_PATH];
	WideCharToMultiByte(CP_UTF8, 0, p, -1, bufUTF8,
		sizeof(bufUTF8), NULL, NULL);
	/* MySQL uses a different character set from MFC's in
	VS. A weird conversion has to be done. The good newis
	you only have to copy and paste this code once. */
	mysql_query(connection, bufUTF8); // Send a query
	result = mysql_store_result(connection); // Store the
	//result
}

void myconnectorclassDB::QueryBrand(CString queryBrand)
{
	wchar_t* p = queryBrand.GetBuffer();
	char bufUTF8[MAX_PATH];
	WideCharToMultiByte(CP_UTF8, 0, p, -1, bufUTF8,
		sizeof(bufUTF8), NULL, NULL);
	/* MySQL uses a different character set from MFC's in
	VS. A weird conversion has to be done. The good newis
	you only have to copy and paste this code once. */
	mysql_query(connection, bufUTF8); // Send a query
	result = mysql_store_result(connection); // Store the
	//result
}

void myconnectorclassDB::QueryModel(CString queryModel)
{
	wchar_t* p = queryModel.GetBuffer();
	char bufUTF8[MAX_PATH];
	WideCharToMultiByte(CP_UTF8, 0, p, -1, bufUTF8,
		sizeof(bufUTF8), NULL, NULL);
	/* MySQL uses a different character set from MFC's in
	VS. A weird conversion has to be done. The good newis
	you only have to copy and paste this code once. */
	mysql_query(connection, bufUTF8); // Send a query
	result = mysql_store_result(connection); // Store the
	//result
}

void myconnectorclassDB::QueryColor(CString queryColor)
{
	wchar_t* p = queryColor.GetBuffer();
	char bufUTF8[MAX_PATH];
	WideCharToMultiByte(CP_UTF8, 0, p, -1, bufUTF8,
		sizeof(bufUTF8), NULL, NULL);
	/* MySQL uses a different character set from MFC's in
	VS. A weird conversion has to be done. The good newis
	you only have to copy and paste this code once. */
	mysql_query(connection, bufUTF8); // Send a query
	result = mysql_store_result(connection); // Store the
	//result
}

void myconnectorclassDB::QueryAuto(CString queryAuto)
{
	wchar_t* p = queryAuto.GetBuffer();
	char bufUTF8[MAX_PATH];
	WideCharToMultiByte(CP_UTF8, 0, p, -1, bufUTF8,
		sizeof(bufUTF8), NULL, NULL);
	/* MySQL uses a different character set from MFC's in
	VS. A weird conversion has to be done. The good newis
	you only have to copy and paste this code once. */
	mysql_query(connection, bufUTF8); // Send a query
	result = mysql_store_result(connection); // Store the
	//result
}

void myconnectorclassDB::QueryFuel(CString queryFuel)
{
	wchar_t* p = queryFuel.GetBuffer();
	char bufUTF8[MAX_PATH];
	WideCharToMultiByte(CP_UTF8, 0, p, -1, bufUTF8,
		sizeof(bufUTF8), NULL, NULL);
	/* MySQL uses a different character set from MFC's in
	VS. A weird conversion has to be done. The good newis
	you only have to copy and paste this code once. */
	mysql_query(connection, bufUTF8); // Send a query
	result = mysql_store_result(connection); // Store the
	//result
}

CString myconnectorclassDB::CPtoUnicode(const char* CPString, UINT
	CodePage)
{
	CString retValue;
	int len = MultiByteToWideChar(CodePage, 0, CPString, -1, NULL, 0);
	if (len == 0) { return retValue; }
	LPWSTR buffer = retValue.GetBuffer(len);
	MultiByteToWideChar(CodePage, 0, CPString, -1, buffer, len);
	retValue.ReleaseBuffer();
	return retValue;
}

