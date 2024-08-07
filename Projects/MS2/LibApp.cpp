/*
Citation and Sources...
Final Project Milestone 2
Module: LibApp
Filename: LibApp.cpp
Version 1.0
Author	Aung Moe Thwe
Revision History
-----------------------------------------------------------
Date      Reason
2024/7/22  Preliminary release
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
*/

#include <iostream>
#include "LibApp.h"
#include "Menu.h"

using namespace std;
namespace seneca {
	void LibApp::newPublication()
	{
		cout << "Adding new publication to library" << endl;
		if (confirm("Add this publication to library?")) {
			m_changed = true;
			cout << "Publication added" << endl;
		}
		cout << endl;
	}

	void LibApp::removePublication()
	{
		cout << "Removing publication from library" << endl;
		search();
		if (confirm("Remove this publication from the library?")) {
			m_changed = true;
			cout << "Publication removed" << endl;
		}
		cout << endl;
	}

	void LibApp::checkOutPub()
	{
		search();
		if (confirm("Check out publication?")) {
			m_changed = true;
			cout << "Publication checked out" << endl;
		}
		cout << endl;
	}


	LibApp::LibApp() : m_mainMenu("Seneca Library Application"), m_exitMenu("Changes have been made to the data, what would you like to do?") {
		m_changed = false;
		m_mainMenu << "Add New Publication" << "Remove Publication" << "Checkout publication from library" << "Return publication to library";
		m_exitMenu << "Save changes and exit" << "Cancel and go back to the main menu";
		load();
	}

	void LibApp::run()
	{
		bool done = false;
		while (!done) {
			switch (m_mainMenu.run()) {
			case 1:
				newPublication();
				break;
			case 2:
				removePublication();
				break;
			case 3:
				checkOutPub();
				break;
			case 4:
				returnPub();
				break;
			case 0:
				if (m_changed) {
					switch (m_exitMenu.run()) {
					case 0:
						if (confirm("This will discard all the changes are you sure?")) {
							done = true;

						}
						break;
					case 1:
						save();
						done = true;
						break;
					
					case 2:
						cout << endl;
					}

				}
				else {
					done = true;
				}
				break;
			}
		}
		cout << "\n-------------------------------------------" << endl;
		cout << "Thanks for using Seneca Library Application" << endl;
	}

	bool LibApp::confirm(const char* message)
	{
		Menu menu(message);
		menu << "Yes";
		return menu.run() == 1;
	}

	void LibApp::load()
	{
		cout << "Loading Data" << endl;
	}

	void LibApp::save()
	{
		cout << "Saving Data" << endl;
	}

	void LibApp::search()
	{
		cout << "Searching for publication" << endl;
	}

	void LibApp::returnPub()
	{
		search();
		cout << "Returning publication" << endl;
		cout << "Publication returned" << endl<<endl;
		m_changed = true;
	}


}
