#include <iostream>
#include <vector>
using namespace std;

int main() {
    int numItems;
    cout << "Cuantos alimentos quieres agregar al menu?: ";
    cin >> numItems;
    cin.ignore();

    
    vector<string> Food(numItems);
    float Price[6] = {12.00, 15.00, 20.00, 8.00, 12.00, 25.00};  
    int Quantity[6] = {0, 0, 0, 0, 0, 0}; 
    string decision;
    int select;
    int unitFood;
    float total = 0;

    
    for (int i = 0; i < numItems; ++i) {
        cout << "Ingresa el nombre del alimento #" << i + 1 << ": ";
        getline(cin, Food[i]);  
    }
    
    cout << "BOKI - CHAN  =^.^= " << endl;
   
    for (int i = 0; i < numItems; ++i) {
        cout << i + 1  << "  " << Food[i] << " ----- $ " << Price[i] << endl;
    }
    
    cout << "\nDesea ordenar algo (si/no)? ";
    cin >> decision;

    do {
        if (decision != "si") {
            break;
        }
        
        cout << "\nIndica el numero del alimento: ";
        cin >> select;
        
        if (select > 0 && select <= numItems) {  
            cout << "Cuantas piezas de " << Food[select - 1] << " quieres? ";
            cin >> unitFood;
            Quantity[select - 1] += unitFood;  
            cout << "Has pedido " << unitFood << " pzas de " << Food[select - 1] << endl;
        } else {
            cout << "Opcion inválida." << endl;
        }
        
        cout << "Deseas pedir algo mas? (si/no): ";
        cin >> decision;
        
    } while (decision != "no");


    cout << "\nResumen de tu pedido: " << endl;
    for (int i = 0; i < numItems; ++i) {
        if (Quantity[i] > 0) {
            cout << Food[i] << " x " << Quantity[i] << " = $" << Quantity[i] * Price[i] << endl;
            total += Quantity[i] * Price[i];
        }
    }
    
    cout << "Total a pagar: $" << total << endl;
    
    return 0;
}
