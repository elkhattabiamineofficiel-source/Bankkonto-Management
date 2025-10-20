#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Konto {
public:
    string name;
    int kontonummer;
    double saldo;

    Konto(string n, int k) {
        name = n;
        kontonummer = k;
        saldo = 0.0;
    }

    void einzahlen(double betrag) {
        saldo += betrag;
        cout << "✅ " << betrag << " eingezahlt. Neuer Saldo: " << saldo << " EUR\n";
    }

    void abheben(double betrag) {
        if(betrag > saldo) {
            cout << "❌ Nicht genug Guthaben!\n";
        } else {
            saldo -= betrag;
            cout << "✅ " << betrag << " abgehoben. Neuer Saldo: " << saldo << " EUR\n";
        }
    }

    void anzeigen() {
        cout << "Konto: " << kontonummer << ", Inhaber: " << name << ", Saldo: " << saldo << " EUR\n";
    }
};

int main() {
    vector<Konto> konten;
    int wahl;

    do {
        cout << "\n--- Bankkonto-Management ---\n";
        cout << "1. Konto erstellen\n2. Einzahlen\n3. Abheben\n4. Konten anzeigen\n5. Beenden\nWahl: ";
        cin >> wahl;

        if(wahl == 1) {
            string name;
            int nummer;
            cout << "Name des Kontoinhabers: ";
            cin >> name;
            cout << "Kontonummer: ";
            cin >> nummer;
            konten.push_back(Konto(name, nummer));
            cout << "✅ Konto erstellt!\n";
        } else if(wahl == 2) {
            int nummer;
            double betrag;
            cout << "Kontonummer: ";
            cin >> nummer;
            cout << "Betrag einzahlen: ";
            cin >> betrag;
            for(auto &k : konten) if(k.kontonummer == nummer) k.einzahlen(betrag);
        } else if(wahl == 3) {
            int nummer;
            double betrag;
            cout << "Kontonummer: ";
            cin >> nummer;
            cout << "Betrag abheben: ";
            cin >> betrag;
            for(auto &k : konten) if(k.kontonummer == nummer) k.abheben(betrag);
        } else if(wahl == 4) {
            for(auto &k : konten) k.anzeigen();
        }

    } while(wahl != 5);

    return 0;
}
