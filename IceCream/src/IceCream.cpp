//============================================================================
// Name        : IceCream.cpp
// Author      : Mick Campittelli
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string.h>
using namespace std;

void menuUI();
void requestCones();
int getScoops();
int getFlavor();
void flavorUI();
void createOrder(int numCones);
int pricePerCone(int numScoops);

int main() {

	menuUI();
	requestCones();

	return 0;
}

void menuUI() {
	//displays menu only
	cout << "\t     Mick's Soft Serve!\n" << "\t-----------------------------" << endl;
	cout << "\t1 scoop \t\t 3$\n" << "\t2 scoops \t\t 5$\n"
			<< "\tEach scoop after \t 1$" << endl;
	cout << "\tMaximum number of scoops is 5\n"<< "\t-----------------------------" << endl;
}

void requestCones() {
	//request number of cones and calls createOrder(numCones)
	int numCones;
	int MAX_CONES = 10;
	cout << "How many cones do you want?" << endl;
	cin >> numCones;
	if (cin.fail())
		cout << "I only understand numbers! Come back once you can count to 10.";
	else if (numCones == 0)
		cout << "Then why are you here?? Come back when you change your mind.";
	else if (numCones > MAX_CONES)
		cout << "We can only make 10 cones at a time. Come back when you need less ice cream.";
	else createOrder(numCones);
}

int getScoops() {

	//asks for number of scoops, if greater than MAX_SCOOPS(5) it asks again
	int numScoops;
	int MAX_SCOOPS = 5;

	cout << "How many scoops do you want for this one? (Max 5)" << endl;

	while (true) {
		cin >> numScoops;
		if (cin.fail())
			cout << "Pardon?" << endl;
		else if (numScoops <= MAX_SCOOPS)
			break;
		else if (numScoops > MAX_SCOOPS)
			cout << "Moderation is key! We can't give you that many\n"
					<< "How about a few less?";
	}
	return numScoops;
}

int getFlavor() {

	//gets scoops for 1 cone, calls flavor menu, and asks for the flavors of each scoop
	int numScoops = getScoops();
	int flavor, i;
	char coneImg[1000];
	coneImg[0] = 0;
	flavorUI();

	for (i = 0; i < numScoops; i++) {
		cout << "What flavor do you want for scoop #" << i + 1 << "?" << endl;
		cin >> flavor;
		if (flavor != 1 && flavor != 2 && flavor != 3) {
			cout << "Not a valid flavor. Let's try that again." << endl;
			i--;
			continue;
		}
		//create coneImg with the right flavors
		else if (flavor == 1)
			strcat(coneImg, "\t( S )\n");
		else if (flavor == 2)
			strcat(coneImg, "\t( M )\n");
		else if (flavor == 3)
			strcat(coneImg, "\t( V )\n");

	}
	//if flavor was invalid, reruns getFlavor()
	if (i != numScoops)
		getFlavor();

	strcat(coneImg, "\t\\   /\n\t  |\n");
	cout << "Here is your cone!" << endl;
	cout << coneImg;
	coneImg[0] = 0;

	return pricePerCone(numScoops);


}

void createOrder(int numCones) {
	//loops through each flavor and scoops per cone, and returns the total price
	int totalPrice = 0;

	for (int i = 1; i <= numCones; i++) {
		totalPrice += getFlavor();

	}
	cout << "Your total is " << totalPrice << " dollars.\nThanks for coming!" << endl;
}

void flavorUI() {
	cout << "\tOur flavors!\n" << "\t[1] Strawberry\n" << "\t[2] Mango\n"
			<< "\t[3] Vanilla" << endl;
}

int pricePerCone(int numScoops) {
	//calculate price per cone
	int price;
	if (numScoops > 2)
		price = numScoops - 2 + 5;
	else if (numScoops == 1)
		price = 3;
	else if (numScoops == 2)
		price = 5;
	return price;
}

