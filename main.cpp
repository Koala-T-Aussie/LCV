#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

//create a person class for the signees
class Person {
    public:
        string fname, lname, address, email;
        string mailtype, number, numtype, area;
        string number2, petite, age, zip;
};

int main()
{
    //color the console
    //not in app version
	system("color F0");

    //declare and initiate variables
    string canvass, option, decision;
	int vary, choice, i, j, k;
    choice = 1;
    i = 0;
    j = 0;
    k = 0;
    ofstream outfile, outfile2;

    //open the text file
    outfile.open("data.txt", ios::app);
    outfile2.open("mydata.csv", ios::app);

    //input canvasser for this round of data collection
	cout << "Canvasser First Name: ";
	cin >> canvass;
	cout << endl;
	outfile << "session " << canvass << endl << endl;

	//creates a vector of objects
	vector<Person> indivs;

    //while loop to repeat for each door
    while (choice == 1) {
        cout << "Did they answer the door? (y/n): ";
        cin >> option;
        //counter for doors knocked
        k++;
        if (option == "y") {
            cout << "Do they want to sign the petition? (y/n): ";
            cin >> decision;
            //counter for how many engaged
            j++;
            if (decision == "y") {
                //counter for how many sign
                i++;
                cout << "League of Conservation Voters" << endl;
                cout << "By taking this action, you are affirming your membership in the League of Conservation Voters ('LCV') and Virginia "
                     << "League of Conservation Voters ('VALCV') and will receive regular LCV and VALCV communications such as text messages "
                     << "and are entitled to vote for a member of the LCV Board of Directors." << endl << endl;

                //create an object for the signee
                indivs.push_back(Person());

                int loopy = 2;
                while (loopy == 2) {
                //input signee's data
                    //would like to make the petition question into a switch
                    //but that would require an ability to update remotely
                    cout << "What petition are you signing?: ";
                    cin >> indivs[i - 1].petite;
                    cout << "Put N or n for any field you would like to skip" << endl;
                    cout << "First Name: ";
                    cin >> indivs[i - 1].fname;
                    cout << "Last Name: ";
                    cin >> indivs[i - 1].lname;
                    cout << "Age: ";
                    cin >> indivs[i - 1].age;
                    cout << "Address: " << endl;
                    cin.ignore();
                    getline(cin, indivs[i - 1].address);
                    cout << "ZIP Code: " << endl;
                    cin >> indivs[i - 1].zip;
                    int looper = 1;
                    while (looper == 1) {
                        cout << "Phone Number (10 digit form, no hyphens or parenthesis): " << endl;
                        cin >> indivs[i - 1].number;
                        //if and switch to determine if question necessary
                        if (indivs[i - 1].number == "n" || indivs[i - 1].number == "N") {
                            vary = 1;
                            looper = 2;
                        } else {
                            vary = 2;
                        }
                        switch (vary) {
                            case 1 :
                                indivs[i - 1].numtype = "n";
                            break;
                            case 2 :
                                //make phone string
                                if (indivs[i - 1].number.length() == 10) {
                                    looper = 2;
                                    indivs[i - 1].area = indivs[i - 1].number.substr(0,3);
                                    indivs[i - 1].number2 = "(" + indivs[i - 1].area + ")" + indivs[i - 1].number.substr(3,3) + "-" + indivs[i - 1].number.substr(6,4);
                                    int circular = 1;
                                    while (circular == 1) {
                                        cout << "Type M or m if this is a mobile number, H or h if it is a home number, or W or w if this a work number: ";
                                        cin >> indivs[i - 1].numtype;
                                        if (indivs[i-1].numtype == "m" || indivs[i-1].numtype == "M") {
                                            indivs[i-1].numtype = "mobile";
                                            circular = 2;
                                        } else if (indivs[i-1].numtype == "h" || indivs[i-1].numtype == "H") {
                                            indivs[i-1].numtype = "home";
                                            circular = 2;
                                        } else if (indivs[i-1].numtype == "w" || indivs[i-1].numtype == "W") {
                                            indivs[i-1].numtype = "work";
                                            circular = 2;
                                        } else {
                                            cout << "Please input a valid phone type" << endl;
                                            circular = 1;
                                        }
                                    }
                                } else {
                                    looper = 1;
                                }
                            break;
                        }
                    }
                    cout << "E-mail: " << endl;
                    cin >> indivs[i - 1].email;
                    //last 3 letters of e-mail
                    if (indivs[i - 1].email == "n" || indivs[i - 1].email == "N") {
                        indivs[i - 1].mailtype = "n";
                    } else {
                        indivs[i - 1].mailtype = indivs[i - 1].email.substr(indivs[i - 1].email.length() - 3, 3);
                    }
                    //repost to signee for confirm
                    cout << "Check to confirm the information is correct." << endl << endl;
                    cout << "First Name: " << indivs[i - 1].fname << endl;
                    cout << "Last Name: " << indivs[i - 1].lname << endl;
                    cout << "Age: " << indivs[i - 1].age << endl;
                    cout << "Address: " << indivs[i - 1].address << endl;
                    cout << "Zip Code: " << indivs[i - 1].zip << endl;
                    cout << "Phone Number: " << indivs[i - 1].number2 << "   " << indivs[i - 1].numtype << endl;
                    cout << "E-mail: " << indivs[i - 1].email << endl << endl;
                    // confirmation choice
                    cout << "Is the above information correct? (press 1 for yes and 2 for no)" << endl;
                    cin >> loopy;
                }

                cout << "Thank you for your participation. Please hand the device back to the canvasser." << endl;

                //send collected info to the text file for lcv general
                outfile << "person " << i << endl;
                outfile << indivs[i - 1].petite << endl;
                outfile << "First Name: " << indivs[i - 1].fname << endl;
                outfile << "Last Name: " << indivs[i - 1].lname << endl;
                outfile << "Age: " << indivs[i - 1].age << endl;
                outfile << "Address: " << indivs[i - 1].address << endl;
                outfile << "Zip Code: " << indivs[i - 1].zip << endl;
                outfile << "Phone Number: " << indivs[i - 1].number << "   " << indivs[i - 1].numtype << endl;
                outfile << "E-mail: " << indivs[i - 1].email << endl;
                outfile << "------------------------------------------------" << endl;

                //send collected data to text file for me
                outfile2 << indivs[i - 1].petite << "," << indivs[i - 1].fname << "," << indivs[i - 1].lname
                         << "," << indivs[i - 1].age << "," << indivs[i - 1].address << "," << indivs[i - 1].zip
                         << "," << indivs[i - 1].number << "," << indivs[i - 1].area << "," << indivs[i - 1].numtype
                         << "," << indivs[i - 1].email << "," << indivs[i - 1].mailtype << endl;
            }
        }

        //inquire canvasser for more input
        cout << "Would you like to continue canvassing?: ";
        cin >> choice;

        //clear screen
        //replaced with cout << endl x25 in app version
        system ("CLS");
    }

    outfile << "doors knocked this session: " << k << endl;
    outfile << "people engaged this session: " << j << endl;

    //close the text file
    outfile.close();
    outfile2.close();

    return 0;
}

