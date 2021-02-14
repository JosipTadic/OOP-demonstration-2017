#include <iostream>
#include <cmath>
using namespace std;

const double Pi = 3.1415926535897;
int i = 0;	//global counter

class Geometry{
	public:
	float CalculateRectangleArea (){
		system("cls");
		cout << "Enter rectangle dimensions:\n";
		float a,b;
		cin >> a >> b;
		float rectangleArea = a * b;
		cout << "Rectangle area is: " << rectangleArea << "\n";
		return rectangleArea;
	}
	float CalculateCircleArea (){
		system("cls");
		cout << "Enter circle radius\n";
		float R;
		cin >> R;
		float circleArea =  Pi * pow(R, 2);
		cout << "Circle area is: " << circleArea << "\n";
		return circleArea;
	}
	float CalculateTriangleArea (){
		system("cls");
		cout << "Enter triangle dimensions: \n";
		float a,b,c;
		cin >> a >> b >> c;
		float S = ( a + b + c ) / 2;
		float triangleArea =  sqrt( S * ( S - a ) * ( S - b ) * ( S - c ));
		cout << "Triangle area is: " << triangleArea << "\n";
		return triangleArea;
	}
	void CalculateLengthByCoordinates(){
		cout << "Enter x, then y coordinates: " << "\n";
		float x1,x2,y1,y2;
		cin >> x1 >> x2 >> y1 >> y2;

		float Raz1,Raz2; //helper variables
		Raz1 = pow((x2 - x1), 2);
		Raz2 = pow((y2 - y1), 2);
		float d = sqrt((Raz1)+(Raz2)); //calculation of distance
		
		pointsL[i].Xko1 = x1; //saving data
		pointsL[i].Xko2 = x2;
		pointsL[i].Yko1 = y1;
		pointsL[i].Yko2 = y2;
		pointsL[i].d = d;
		
		:: i++;	//global scope operator (::) change of global variable counter
		
		cout << "\n" << "There is currently " << i << " lenghts\n";
		for(int j = 0; j < i; j++){
			cout << "X coordinates " << pointsL[j].Xko1  << " ";
			cout << pointsL[j].Xko2  << "\n";
			cout << "Y coordinates " << pointsL[j].Yko1  << " ";
			cout << pointsL[j].Yko2  << "\n";
			cout << j+1 << ".lenght "<< pointsL[j].d << "\n\n";
		}
		return;
	}
	
	private:
		struct Points{
		float Xko1,Xko2,Yko1,Yko2; //ko=coordinate
		float d;
		};
		Points pointsL[100];
};

main(){
	int menu = 1;
	Geometry *Pr, Kr, Tr, Ud;	//object declaration
do{
	system("cls");
	cout << "1. Calculate Rectangle Area\n";
	cout << "2. Calculate Circle Area\n";
	cout << "3. Calculate Triangle Area(Heron's formula)\n";
	cout << "4. Calculate distance between 2 Points\n";
	cout << "9. Izlaz\n";
	cout << "\nChoose option from menu: ";	
	
	if ( menu < 1 || menu > 9 || menu > 4 && menu < 9 )	cout << "Incorrect entry! :";
	cin >> menu;
	
	switch ( menu ) {
		
		case 1:
			Pr = new Geometry;
			Pr -> CalculateRectangleArea(); //accessing dinamically allocated object
    		delete Pr;
    		system("pause");
    	break;
    	
		case 2:
			Kr.CalculateCircleArea();
    		system("pause");
		break;
		
		case 3:
			Tr.CalculateTriangleArea();
    		system("pause");
    	break;
    	
		case 4:
			system("cls");
			Tr.CalculateLengthByCoordinates();
			system("pause");
		break;
			
		case 9:
 			menu = 9;
 			cout << "Goodbye!!\n";
 		break;
	}
	
}while ( menu !=9 );

system("pause");
return 0;
}
