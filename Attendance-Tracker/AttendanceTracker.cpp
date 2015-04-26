/*************************************************************
Programmer: Nate Eastland
Class: Cpts 122, Spring 2015; Lab Section 6
Programming Assignment: 
Date: 3-26-2015
Description: This program is an attendance tracker for a class of students
				whose information is stored initially in a .csv file. The user can 
				search the list by several criteria, mark, and edit absences.
*************************************************************/

#include "AttendanceTracker.h"

///////////////////////////////
//menu class member functions//
///////////////////////////////

/*******************************************************
  Function: menu()                   
  Date Created: 3-26-2015                                           
  Date Last Modified: 3-26-2015                                      
  Description: initializes the exit condition variable 'quit' to 0                                  
  Input parameters: none                                   
  Returns: nothing                                         
********************************************************/   

menu::menu()
{
	this->quit = 0;
}

/*******************************************************
  Function: ~menu()                   
  Date Created: 3-26-2015                                           
  Date Last Modified: 3-26-2015                                      
  Description: menu destructor                                 
  Input parameters: none                                  
  Returns: nothing                                         
********************************************************/   

menu::~menu()
{
}

/*******************************************************
  Function: displayMenu()                  
  Date Created: 3-26-2015                                           
  Date Last Modified: 3-26-2015                                      
  Description: This function displays the main menu for the program
				and allows the user to select operations. 
  Input parameters: List &duhList - the list object                                   
  Returns: nothing                                      
********************************************************/   

void menu::displayMenu(List &duhList)
{
	int option = 0;

	do
	{
		cout << "Main Menu" << endl;
		cout << "Please select one of the following options" << endl;
		cout << "1. Import Course List" << endl;
		cout << "2. Load Master List" << endl;
		cout << "3. Store Master List" << endl;
		cout << "4. Mark Absences" << endl;
		cout << "5. Generate Report" << endl;
		cout << "6. Edit Absences" << endl;
		cout << "7. Exit" << endl;
		putchar('\n');

		cin >> option;

	}while(option < 1 || option > 7);

	switch(option)
	{
		case 1: this->importList(duhList);
			break;
		case 2: this->loadMaster(duhList);
			break;
		case 3: this->storeMaster(duhList);
			break;
		case 4: this->markAbsence(duhList);
			break;
		case 5: this->genReport(duhList);
			break;
		case 6: this->editAbsences(duhList);
			break;
		case 7: this->exit();
			break;
		default:
			break;
	}
}

/*******************************************************
  Function: importList()                 
  Date Created: 3-26-2015                                           
  Date Last Modified: 3-26-2015                                      
  Description: this is a helper function within the menu class that
				calls the import() function in the list object.
  Input parameters: List &duhList - the list object                                   
  Returns: nothing                                        
********************************************************/   

void menu::importList(List &duhList)
{
	duhList.import();
}

/*******************************************************
  Function: loadMaster()                   
  Date Created: 3-26-2015                                           
  Date Last Modified: 3-26-2015                                      
  Description: helper function within the menu class that calls
				the load() function within the list object.
  Input parameters: List &duhList - the list object                                   
  Returns: nothing                                        
********************************************************/   

void menu::loadMaster(List &duhList)
{
	duhList.load();
}

/*******************************************************
  Function: storeMaster()                   
  Date Created: 3-26-2015                                           
  Date Last Modified: 3-26-2015                                      
  Description: helper function within the menu class that calls
				the store() function within the list object.
  Input parameters: List &duhList - the list object                                   
  Returns:                                          
********************************************************/   

void menu::storeMaster(List &duhList)
{
	duhList.store();
}

/*******************************************************
  Function: markAbsence()                    
  Date Created: 3-26-2015                                           
  Date Last Modified: 3-26-2015                                      
  Description: helper function within the menu class that calls
				the mark() functino within the list object
  Input parameters: List &duhList - the list object                                   
  Returns: nothing                                          
********************************************************/   

void menu::markAbsence(List &duhList)
{
	duhList.mark();
}

/*******************************************************
  Function: editAbsences()                    
  Date Created: 3-26-2015                                           
  Date Last Modified: 3-26-2015                                      
  Description: helper function within the menu class that calls 
				the edit() function within the list object
  Input parameters: List &duhList - the list object                                   
  Returns: nothing                                        
********************************************************/   

void menu::editAbsences(List &duhList)
{
	duhList.edit();
}

/*******************************************************
  Function: genReport()                    
  Date Created: 3-26-2015                                           
  Date Last Modified: 3-26-2015                                      
  Description: helper function in the menu class that prompts 
				the user to select an option for generating a
				specific report. calls the report() function 
				within the list object and passes along the option.
  Input parameters: List &duhList - the list object                                    
  Returns: nothing                                       
********************************************************/   

void menu::genReport(List &duhList)
{
	int option = 0;

	do{
		cout << "Select a report type to display" << endl;
		cout << "1. Full Report" << endl;
		cout << "2. Threshold Report" << endl;
		cout << "3. Absences on Date" << endl;

		cin >> option;
	}while(option < 1 || option > 3);

	duhList.report(option);
}

/*******************************************************
  Function: exit()                  
  Date Created: 3-26-2015                                           
  Date Last Modified: 3-26-2015                                      
  Description: function that changes the exit variable to true (1)                                   
  Input parameters:  nothing                                  
  Returns: none                                       
********************************************************/   

void menu::exit()
{
	setQuit(1);
}

/*******************************************************
  Function: getQuit() const               
  Date Created: 3-26-2015                                           
  Date Last Modified: 3-26-2015                                      
  Description: getter                                  
  Input parameters: none                                   
  Returns: int quit                                         
********************************************************/   

int menu::getQuit() const
{
	return this->quit;
}

/*******************************************************
  Function: setQuit()                    
  Date Created: 3-26-2015                                           
  Date Last Modified: 3-26-2015                                      
  Description: setter                                   
  Input parameters: int set - new quit value to set                                 
  Returns: nothing                                         
********************************************************/   

void menu::setQuit(int set)
{
	this->quit = set;
}


/*******************************************************
  Function: List()                  
  Date Created: 3-26-2015                                           
  Date Last Modified: 3-26-2015                                      
  Description: initializes mpHead to NULL                                  
  Input parameters: none                                   
  Returns:  nothing                                        
********************************************************/   
///////////////////////////////
//List class member functions//
///////////////////////////////
List::List()
{
	this->mpHead = NULL;
}

/*******************************************************
  Function: ~List()                    
  Date Created: 3-26-2015                                           
  Date Last Modified: 3-26-2015                                      
  Description: List destructor                           
  Input parameters: none                                   
  Returns: nothing                                        
********************************************************/   

List::~List()
{
}

/*******************************************************
  Function: makeNode()                   
  Date Created: 3-26-2015                                           
  Date Last Modified: 3-26-2015                                      
  Description: initializes a new node containing student information                                  
  Input parameters: int record - record number, string id - student's ID number
					string name - student's name, string email - student's email
					string units - course units, string major - student's major, 
					string level - student's school standing, string absences - number of absences,
					string absenceDate[] - record of date for each absence, node* next - next pointer
  Returns: node* pMem                                        
********************************************************/   

node *List::makeNode(int record, string id, string name, string email, string units,
				string major, string level, string absences, string absenceDate[], node* next)
{
	node *pMem = NULL;

	pMem = new node(record, id, name, email, units, major, level, absences, absenceDate, next);

	return pMem;
}

/*******************************************************
  Function: insert()                   
  Date Created: 3-26-2015                                           
  Date Last Modified: 3-26-2015                                      
  Description: inserts nodes at the front of the linked list                                   
  Input parameters: int record - record number, string id - student's ID number
					string name - student's name, string email - student's email
					string units - course units, string major - student's major, 
					string level - student's school standing, string absences - number of absences,
					string absenceDate[] - record of date for each absence, node* next - next pointer                                   
  Returns: nothing                                         
********************************************************/   

void List::insert(int record, string id, string name, string email, string units,
				string major, string level, string absences, string absenceDate[], node* next)
{
	node *pMem = NULL;
	
	if(this->mpHead == NULL)
	{
		pMem = makeNode(record, id, name, email, units, major, level, absences, absenceDate, NULL);
	}
	else
	{
		pMem = makeNode(record, id, name, email, units, major, level, absences, absenceDate, this->mpHead);
	}

	this->mpHead = pMem;
}

/*******************************************************
  Function: import()                   
  Date Created: 3-26-2015                                           
  Date Last Modified: 3-26-2015                                      
  Description: imports student information from an original list within
				a .csv file. If no list exists, a new list is generated. 
				If a list currently exists and the user chooses so, the current
				list is overwritten with the import information.
  Input parameters: none                                   
  Returns: nothing                                        
********************************************************/   

void List::import()
{
	int i = 0, num = 0, option = 0;
	char myString[100];
	string str[100], studentName, filename, absenceDates[10];
	node *head = NULL;

	filename = "classList.csv";

	ifstream input;
	input.open(filename, std::ios::in);

	//message that pops up if user tries to import after a list already exists
	if(this->mpHead != NULL)
	{
		cout << "*****The import option may overwrite data you are currently working on.*****" << endl;
		cout << "*Enter an option*" << endl;
		cout << "1. Import anyway" << endl;
		cout << "2. Do Not Import" << endl;

		cin >> option;
	}

	if(option == 1)
	{
		for(i = 0; i < 6; i++)
			input.getline(myString, 100, ',');

		input.getline(myString, 100, '\n');

		for(i = 0; i < 10; i++)
			absenceDates[i] = "-";

		i = 0;

		head = this->mpHead;

		while(!input.eof())
		{
			input >> num;
			input.getline(myString, 100, ',');

			for(i = 0; i < 6; i++)
			{
				input.getline(myString, 100, ',');
				str[i] = myString;
			}

			input.getline(myString, 100, '\n');
			str[i] = myString;

			studentName = str[1] + ',' + str[2];

			this->mpHead->recordNum = num;
			this->mpHead->idNum = str[0];
			this->mpHead->studentName = studentName;
			this->mpHead->email = str[3];
			this->mpHead->units =str[4];
			this->mpHead->major = str[5];
			this->mpHead->studentLevel = str[6];
			this->mpHead->numAbsences = "0";

			for(i = 0; i < 10; i++)
				this->mpHead->absenceDate[i] = absenceDates[i];

			this->mpHead = this->mpHead->mpNext;
		}

		this->mpHead = head;
	}

	if(this->mpHead == NULL || option == 1)
	{
		for(i = 0; i < 6; i++)
			input.getline(myString, 100, ',');

		input.getline(myString, 100, '\n');

		for(i = 0; i < 10; i++)
			absenceDates[i] = "-";

		i = 0;

		while(!input.eof())
		{
			input >> num;
			input.getline(myString, 100, ',');

			for(i = 0; i < 6; i++)
			{
				input.getline(myString, 100, ',');
				str[i] = myString;
			}

			input.getline(myString, 100, '\n');
			str[i] = myString;

			studentName = str[1] + ',' + str[2];

			this->insert(num, str[0], studentName, str[3], str[4], str[5], str[6], "0", absenceDates, NULL);
		}
	}
	input.close();
}

/*******************************************************
  Function: load()                   
  Date Created: 3-26-2015                                           
  Date Last Modified: 3-26-2015                                      
  Description: reads in information from a MasterList.txt file
				and populates a linked list.
  Input parameters: none                                   
  Returns: nothing                                         
********************************************************/   

void List::load()
{
	ifstream input;
	char myString[100];
	string str[10], dates[10];
	int i = 0, num = 0;

	input.open("MasterList.txt");

	while(!input.eof())
	{
		input >> num;	
		input.getline(myString, 100, '\n');

		for(i = 0; i < 7; i++)
		{
			input.getline(myString, 100, '\n');
			str[i] = myString;
		}

		for(i = 0; i < 10; i++)
		{
			input.getline(myString, 100, '\n');
			dates[i] = myString;
		}

		this->insert(num, str[0], str[1], str[2], str[3], str[4], str[5], str[6], dates, NULL);
	}

	input.close();
}

/*******************************************************
  Function: store()                   
  Date Created: 3-26-2015                                           
  Date Last Modified: 3-26-2015                                      
  Description: writes the current data fields in each node of the linked
				list to the MasterList.txt file for future access.
  Input parameters: none                                 
  Returns: nothing                                        
********************************************************/   

void List::store()
{
	ofstream output;
	int i = 0;
	node *temp = NULL;

	output.open("MasterList.txt");

	temp = this->mpHead;

	do
	{
		output.flush();

		output << temp->recordNum << endl;
		output << temp->idNum << endl;
		output << temp->studentName << endl;
		output << temp->email << endl;
		output << temp->units << endl;
		output << temp->major << endl;
		output << temp->studentLevel << endl;
		output << temp->numAbsences << endl;

		for(i = 0; i < 10; i++)
		{
			if((temp->mpNext == NULL) && (i == 9))
			{
				output << temp->absenceDate[i];
			}
			else
			{
				output << temp->absenceDate[i] << endl;
			}
		}

		temp = temp->mpNext;
	}while(temp != NULL);

	output.close();
}

/*******************************************************
  Function: mark()                  
  Date Created: 3-26-2015                                           
  Date Last Modified: 3-26-2015                                      
  Description: walks through the linked list one node at a time and
				prompts the user to select whether the student was present or
				absent for the current day. If absent, the function updates
				the absences field for that node and records the date/time.
  Input parameters: none                                   
  Returns: nothing                                        
********************************************************/   

void List::mark()
{
	node* temp = this->mpHead;
	int option = 0, i = 0, num = 0;

	cout << "This operation will walk through the Master List entry by entry." << endl;
	cout << "Please indicate wheter or not the student was absent on each entry." << endl;

	do
	{
		cout << endl;
		cout << "Please enter the number of the option you want to select." << endl;
		cout << "Student Name: " << temp->idNum << endl;
		cout << "Student ID Number: " << temp->studentName << endl;
		cout << "1. Present" << endl;
		cout << "2. Absent" << endl;

		cin >> option;

		if(option == 2)
		{
			while(temp->absenceDate[i] != "-")
				i++;

			temp->setAbsenceDate(i, currentDateTime());

			num = atoi(temp->numAbsences.c_str());
			num++;
			temp->setNumAbsences(to_string(num));

			i = 0;
		}

		temp = temp->mpNext;
	}while(temp != NULL);
}

/*******************************************************
  Function: edit()                    
  Date Created: 3-26-2015                                           
  Date Last Modified: 3-26-2015                                      
  Description: allows the user to edit absences for a specific student entry
				from the list. This clears the absence date and corrects the 
				number of absence entries
  Input parameters: none                                 
  Returns: nothing                                         
********************************************************/   

void List::edit()
{
	node *temp = this->mpHead, *hold = NULL;
	int i = 0, j = 0, check = 0, tNum = 0;
	string search;

	cout << "The following is a list of student names and ID numbers." << endl;
	cout << "Please enter the ID number of the student for whom you would like to make an absence correction." << endl;
	
	system("pause");

	do
	{
		cout.flush();

		cout << endl;
		cout << "Record Number: " << temp->getRecordNum() << endl;
		cout << "ID Number: " << temp->getIdNum() << endl;
		cout << "Student Name: " << temp->getName() << endl;
			
		cout << endl;

		temp = temp->mpNext;
	}while(temp != NULL);

	cout << "Please enter the ID number of the student for whom you would like to make a correction" << endl;
	cin >> search;

	temp = this->mpHead;

	for(i = 0; (temp != NULL) && (check == 0); i++)
	{
		if(!temp->idNum.compare(0, 9, search))
		{
			check = 1;
		}
		else
		{
			temp = temp->mpNext;
		}
	}

	if(check)
	{
		cout << endl;
		cout << "Record Number: " << temp->getRecordNum() << endl;
		cout << "ID Number: " << temp->getIdNum() << endl;
		cout << "Student Name: " << temp->getName() << endl;
		cout << "Dates of Absences: " << endl;

		for(i = 0; i < 10; i++)
			cout << i << ". " << temp->getAbsenceDate(i) << endl;
	}

	cout << "Please enter the entry number you would like to edit." << endl;

	cin >> check;

	
	if(temp->absenceDate[check].compare("-"))
	{
		temp->setAbsenceDate(check, "-");

		tNum = atoi(temp->numAbsences.c_str());

		tNum--;

		temp->setNumAbsences(to_string(tNum));

		
		for(i = 0; i < 10; i++)
		{
			if(!temp->absenceDate[i].compare("-"))
			{

				for(j = i; (j < 10) && !temp->getAbsenceDate(j).compare("-"); j++);

				if(j == 10)
				{
					temp->setAbsenceDate(i, temp->absenceDate[j-1]);
				}
				else
				{
					temp->setAbsenceDate(i, temp->absenceDate[j]);
				}
			}

				temp->setAbsenceDate(j, "-");
		}
	}
}

/*******************************************************
  Function: report()                  
  Date Created: 3-26-2015                                           
  Date Last Modified: 3-26-2015                                      
  Description: generates a report of the students' current information within
				the linked list based on an option value passed to it. Generates
				full report, absence threshold report, or absence date report.
  Input parameters: int option - identifier for the type of report selected                                    
  Returns: nothing                                          
********************************************************/   

void List::report(int option)
{
	node* temp = this->mpHead;
	int i = 0, check = 0, num = 0;
	string threshold;

	if(option == 1)
	{
		do
		{
			cout.flush();

			cout << endl;
			cout << "Record Number: " << temp->getRecordNum() << endl;
			cout << "ID Number: " << temp->getIdNum() << endl;
			cout << "Student Name: " << temp->getName() << endl;
			cout << "Student Email: " << temp->getEmail() << endl;
			cout << "Course Units: " << temp->getUnits() << endl;
			cout << "Field of Study: " << temp->getMajor() << endl;
			cout << "Student Academic Level: " << temp->getLevel() << endl;
			cout << "Number of Absences: " << temp->getNumAbsences() << endl;
		
			cout << "Dates of Absences: " << endl;
			for(i = 0; i < 10; i++)
				cout << temp->getAbsenceDate(i) << endl;

			cout << endl;

			temp = temp->mpNext;
		}while(temp != NULL);
	}
	else if(option == 2)
	{
		do
		{
			cout << "What threshold number would you like to search by?" << endl;
			cin >> threshold;

			check = atoi(threshold.c_str());
		}while(check < 0 || check > 10);

		do
		{
			num = atoi(temp->numAbsences.c_str());

			if(num >= check)
			{
				cout.flush();

				cout << endl;
				cout << "Record Number: " << temp->getRecordNum() << endl;
				cout << "ID Number: " << temp->getIdNum() << endl;
				cout << "Student Name: " << temp->getName() << endl;
				cout << "Student Email: " << temp->getEmail() << endl;
				cout << "Course Units: " << temp->getUnits() << endl;
				cout << "Field of Study: " << temp->getMajor() << endl;
				cout << "Student Academic Level: " << temp->getLevel() << endl;
				cout << "Number of Absences: " << temp->getNumAbsences() << endl;
		
				cout << "Dates of Absences: " << endl;
				for(i = 0; i < 10; i++)
					cout << temp->getAbsenceDate(i) << endl;

				cout << endl;
			}

			temp = temp->mpNext;
		}while(temp != NULL);
	}
	else
	{
		cout << "Please enter a date you would like to search for in the following format: " << endl;
		cout << "ex. 2015-03-25" << endl;

		cin >> threshold;

		do
		{
			for(i = 0; i < 10; i++)
			{
				if(!temp->absenceDate[i].compare(0, 10, threshold))
					check = 1;
			}

			if(check)
			{
				cout.flush();

				cout << endl;
				cout << "Record Number: " << temp->getRecordNum() << endl;
				cout << "ID Number: " << temp->getIdNum() << endl;
				cout << "Student Name: " << temp->getName() << endl;
				cout << "Student Email: " << temp->getEmail() << endl;
				cout << "Course Units: " << temp->getUnits() << endl;
				cout << "Field of Study: " << temp->getMajor() << endl;
				cout << "Student Academic Level: " << temp->getLevel() << endl;
				cout << "Number of Absences: " << temp->getNumAbsences() << endl;
		
				cout << "Dates of Absences: " << endl;
				for(i = 0; i < 10; i++)
					cout << temp->getAbsenceDate(i) << endl;

				cout << endl;
			}

			temp = temp->mpNext;

			check = 0;
		}while(temp != NULL);
	}
}

/*******************************************************
  Function: getPointer()                   
  Date Created: 3-26-2015                                           
  Date Last Modified: 3-26-2015                                      
  Description: getter                                  
  Input parameters: none                                   
  Returns: node* mpHead                                        
********************************************************/   

node* List::getPointer()
{
	return this->mpHead;
}


/*******************************************************
  Function: node()                  
  Date Created: 3-26-2015                                           
  Date Last Modified: 3-26-2015                                      
  Description: a default constructor, all values initialized to null...ish                                
  Input parameters: none                                   
  Returns: nothing                                      
********************************************************/   
///////////////////////////////
//node class member funcitons//
///////////////////////////////
node::node()
{
	this->recordNum = 0;
	this->idNum = nullptr;
	this->studentName = nullptr;
	this->email = nullptr;
	this->units = nullptr;
	this->major = nullptr;
	this->studentLevel = nullptr;
	this->numAbsences = nullptr;
	this->absenceDate;

	this->mpNext = nullptr;
}

/*******************************************************
  Function: node()                   
  Date Created: 3-26-2015                                           
  Date Last Modified: 3-26-2015                                      
  Description: constructor for a node object                                  
  Input parameters: int record - record number, string id - student's ID number
					string name - student's name, string email - student's email
					string units - course units, string major - student's major, 
					string level - student's school standing, string absences - number of absences,
					string absenceDate[] - record of date for each absence, node* next - next pointer                                 
  Returns: nothing                                         
********************************************************/   

node::node(int recordNum, string idNum, string studentName, string email, string units,
	string major, string studentLevel, string numAbsences, string absenceDate[], node* next)
{
	int i = 0;

	this->recordNum = recordNum;
	this->idNum = idNum;
	this->studentName = studentName;
	this->email = email;
	this->units = units;
	this->major = major;
	this->studentLevel = studentLevel;
	this->numAbsences = numAbsences;

	for(i = 0; i < 10; i++)
		this->absenceDate[i] = absenceDate[i];

	this->mpNext = next;
}

/*******************************************************
  Function: ~node()                  
  Date Created: 3-26-2015                                           
  Date Last Modified: 3-26-2015                                      
  Description: node destructor                                  
  Input parameters: none                                    
  Returns: nothing                                         
********************************************************/   

node::~node()
{
}

/*******************************************************
  Function: getRecordNum() const                  
  Date Created: 3-26-2015                                           
  Date Last Modified: 3-26-2015                                      
  Description: getter                                  
  Input parameters: none                                   
  Returns: int recordNum                                       
********************************************************/   

int node::getRecordNum() const
{
	return this->recordNum;
}

/*******************************************************
  Function: getIdNum() const                   
  Date Created: 3-26-2015                                           
  Date Last Modified: 3-26-2015                                      
  Description: getter                                  
  Input parameters: none                                   
  Returns: string idNu                                         
********************************************************/   

string node::getIdNum() const
{
	return this->idNum;
}

/*******************************************************
  Function: getName() const                   
  Date Created: 3-26-2015                                           
  Date Last Modified: 3-26-2015                                      
  Description: getter                                  
  Input parameters: none                                   
  Returns: string studentName                                       
********************************************************/   

string node::getName() const
{
	return this->studentName;
}

/*******************************************************
  Function: getEmail() const                  
  Date Created: 3-26-2015                                           
  Date Last Modified: 3-26-2015                                      
  Description: getter                                   
  Input parameters: none                                   
  Returns: string email                                         
********************************************************/   

string node::getEmail() const
{
	return this->email;
}

/*******************************************************
  Function: getUnits() const              
  Date Created: 3-26-2015                                           
  Date Last Modified: 3-26-2015                                      
  Description: getter                                   
  Input parameters: none                                    
  Returns: string units                                      
********************************************************/   

string node::getUnits() const
{
	return this->units;
}

/*******************************************************
  Function: getMajor() const    
  Date Created: 3-26-2015                                           
  Date Last Modified: 3-26-2015                                      
  Description: getter                                   
  Input parameters: none                             
  Returns: string major                                          
********************************************************/   

string node::getMajor() const
{
	return this->major;
}

/*******************************************************
  Function: getLevel() const                 
  Date Created: 3-26-2015                                           
  Date Last Modified: 3-26-2015                                      
  Description: getter                                  
  Input parameters: none                                    
  Returns: string studentLevel                                     
********************************************************/   

string node::getLevel() const
{
	return this->studentLevel;
}

/*******************************************************
  Function: getNumAbsences() const                  
  Date Created: 3-26-2015                                           
  Date Last Modified: 3-26-2015                                      
  Description: getter                                   
  Input parameters: none                                   
  Returns: string numAbsences                                         
********************************************************/   

string node::getNumAbsences() const
{
	return this->numAbsences;
}

/*******************************************************
  Function: getAbsenceDate() const                   
  Date Created: 3-26-2015                                           
  Date Last Modified: 3-26-2015                                      
  Description: getter                                   
  Input parameters: int index - specific date entry in array                                   
  Returns: string absenceDate[index]                                        
********************************************************/   

string node::getAbsenceDate(int index) const
{
	return this->absenceDate[index];
}

/*******************************************************
  Function: setRecordNum()                   
  Date Created: 3-26-2015                                           
  Date Last Modified: 3-26-2015                                      
  Description: setter                                  
  Input parameters: int newNum                                   
  Returns: nothing                                         
********************************************************/   

void node::setRecordNum(int newNum)
{
	this->recordNum = newNum;
}

/*******************************************************
  Function: setIdNum()                   
  Date Created: 3-26-2015                                           
  Date Last Modified: 3-26-2015                                      
  Description: setter                                   
  Input parameters: string newId                                   
  Returns: nothing                                         
********************************************************/   

void node::setIdNum(string newId)
{
	this->idNum = newId;
}

/*******************************************************
  Function: setName()                  
  Date Created: 3-26-2015                                           
  Date Last Modified: 3-26-2015                                      
  Description: setter                                  
  Input parameters: string newName                                   
  Returns: nothing                                        
********************************************************/   

void node::setName(string newName)
{
	this->studentName = newName;
}

/*******************************************************
  Function: setEmail()                  
  Date Created: 3-26-2015                                           
  Date Last Modified: 3-26-2015                                      
  Description: setter                                  
  Input parameters: string newEmail                                   
  Returns: nothing                                         
********************************************************/   

void node::setEmail(string newEmail)
{
	this->email = newEmail;
}

/*******************************************************
  Function: setUnits()                  
  Date Created: 3-26-2015                                           
  Date Last Modified: 3-26-2015                                      
  Description: setter                                 
  Input parameters: string newUnits                                   
  Returns: nothing                                        
********************************************************/   

void node::setUnits(string newUnits)
{
	this->units = newUnits;
}

/*******************************************************
  Function: setMajor()                   
  Date Created: 3-26-2015                                           
  Date Last Modified: 3-26-2015                                      
  Description: setter                                 
  Input parameters: string newMajor                                   
  Returns: nothing                                          
********************************************************/   

void node::setMajor(string newMajor)
{
	this->major = newMajor;
}

/*******************************************************
  Function: setLevel()                   
  Date Created: 3-26-2015                                           
  Date Last Modified: 3-26-2015                                      
  Description: setter                                  
  Input parameters: string newLevle                                  
  Returns: nothing                                         
********************************************************/   

void node::setLevel(string newLevel)
{
	this->studentLevel = newLevel;
}

/*******************************************************
  Function: setNumAbsences()                    
  Date Created: 3-26-2015                                           
  Date Last Modified: 3-26-2015                                      
  Description: setter                                  
  Input parameters: string newAbsence                                 
  Returns: nothing                                         
********************************************************/   

void node::setNumAbsences(string newAbsence)
{
	this->numAbsences = newAbsence;
}

/*******************************************************
  Function: setAbsenceDate()                  
  Date Created: 3-26-2015                                           
  Date Last Modified: 3-26-2015                                      
  Description: setter                                  
  Input parameters: int index - specific field in array
					string newDate - date to set
  Returns: nothing                                      
********************************************************/   

void node::setAbsenceDate(int index, string newDate)
{
	this->absenceDate[index] = newDate;
}

/*******************************************************
  Function: currentDateTime()                  
  Date Created: 3-26-2015                                           
  Date Last Modified: 3-26-2015                                      
  Description: gets system date and time at time it is called                                  
  Input parameters: none                                    
  Returns: string buf - string storing the date/time information                                         
********************************************************/   

const string currentDateTime()
{
	time_t now = time(0);
	struct tm tstruct;
	char buf[80];
	tstruct = *localtime(&now);

	strftime(buf, sizeof(buf), "%Y-%m-%d.%X", &tstruct);

	return buf;
}
